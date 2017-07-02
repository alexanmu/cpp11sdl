/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/

#include <cassert>
#include <cstdint>
#include <fstream>
#include <ctime>
#include <string>
#include <chrono>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace _gfx
{

const char GfxBasicLogger::logFileName_[] = "gfxbasiclog.log";

GfxBasicLogger& GfxBasicLogger::getInstance(void) noexcept
{
    static GfxBasicLogger instance_;

    return instance_;
}

// TRACE
void GfxBasicLogger::logTrace(const char * module, const logTracePriority prio, const char * file,
                              const int32_t line, const char * func, const int32_t instance) noexcept
{
    if (logTraceLevels_[static_cast<uint8_t>(prio)] == logTraceEnaDisState::logTraceEnabled)
    {
        if (doTrace(module) == true)
        {
            auto nowtime = std::chrono::high_resolution_clock::now();
            std::stringstream ss;

            ss << "TRACE: ";
            ss << 'P' << getTraceTextForPrio(prio) << ' ';
            ss << std::chrono::duration_cast<std::chrono::milliseconds>(nowtime - startTime_).count() << "ms ";
            ss << instance << ' ' << module << ' ' << file << ':' << line << ' ';
            ss <<  '[' << func << ']';
            // Try log to file
            if (logTraceToFileState_ == logTraceEnaDisState::logTraceEnabled)
            {
                logFile_ << ss.str() << '\n';
            }
        }
    }
}

GfxBasicLogger::logTraceEnaDisState GfxBasicLogger::getTracePriority(const logTracePriority prio) const noexcept
{
    return logTraceLevels_[static_cast<uint8_t>(prio)];
}

void GfxBasicLogger::setTracePriority(const logTracePriority prio, const logTraceEnaDisState state) noexcept
{
    logTraceLevels_[static_cast<uint8_t>(prio)] = state;
}

GfxBasicLogger::logTraceEnaDisState GfxBasicLogger::getTraceToFileState(void) const noexcept
{
    return logTraceToFileState_;
}

void GfxBasicLogger::setTraceToFileState(const logTraceEnaDisState state) noexcept
{
    logTraceToFileState_ = state;
}

std::vector<std::string> const& GfxBasicLogger::getTraceModules(void) const noexcept
{
    return logTraceFilterModules_;
}

void GfxBasicLogger::addTraceModule(std::string const& module) noexcept
{
    assert(module.length() > 0);

    if (module == "*")
    {
        logTraceAllowAll_ = true;
    }
    auto pos = std::find(std::begin(logTraceFilterModules_), std::end(logTraceFilterModules_), module);
    if (pos == std::end(logTraceFilterModules_))
    {
        logTraceFilterModules_.push_back(module);
    }
}

void GfxBasicLogger::clearTraceModules(void) noexcept
{
    logTraceFilterModules_.clear();
}

// LOG
void GfxBasicLogger::logMessage(const char * msg) noexcept
{
    logFile_ << "MESSAGE: " << msg << '\n';
}

void GfxBasicLogger::logInfo(const char * msg) noexcept
{
    logFile_ << "INFO: " << msg << '\n';
}

// Private methods
GfxBasicLogger::GfxBasicLogger() noexcept
{
    for (uint8_t index = 0; index < 4; index++)
    {
        logTraceLevels_[index] = logTraceEnaDisState::logTraceDisabled;
    }
    startTime_ = std::chrono::high_resolution_clock::now();
    logTraceToFileState_ = logTraceEnaDisState::logTraceDisabled;
    logTraceFilterModules_.clear();
    logTraceAllowAll_ = false;
    createLogFile();
}

GfxBasicLogger::~GfxBasicLogger() noexcept
{
    closeLogFile();
}

char GfxBasicLogger::getTraceTextForPrio(const logTracePriority prio) const noexcept
{
    char ret = 0;

    switch (prio)
    {
        case logTracePriority::logTracePrioLow:
            ret = 'L';
            break;
        case logTracePriority::logTracePrioMedium:
            ret = 'M';
            break;
        case logTracePriority::logTracePrioHigh:
            ret = 'H';
            break;
        case logTracePriority::logTracePrioTop:
            ret = 'T';
            break;
    }
    return ret;
}

std::string GfxBasicLogger::getCurrentDateAsString(void) const noexcept
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::string y = std::to_string(tm.tm_year + 1900);
    std::string m = std::to_string(tm.tm_mon + 1);
    std::string d = std::to_string(tm.tm_mday);

    return y + '.' + _lz(m, 2) + '.' + _lz(d, 2);
}

std::string GfxBasicLogger::getCurrentTimeAsString(void) const noexcept
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::string h = std::to_string(tm.tm_hour);
    std::string m = std::to_string(tm.tm_min);
    std::string s = std::to_string(tm.tm_sec);

    return _lz(h, 2) + ':' + _lz(m, 2) + ':' + _lz(s, 2);
}

std::string GfxBasicLogger::_lz(std::string const& str, const uint32_t elen) const noexcept
{
    std::string s;

    if (str.length() < elen)
    {
        for (uint32_t i = 0; i < elen - str.length(); i++)
        {
            s += "0";
        }
    }
    else
    {
        s = "";
    }
    return s + str;
}

void GfxBasicLogger::createLogFile(void) noexcept
{
    std::string fname = logFileName_;

    std::transform(fname.begin(), fname.end(), fname.begin(), ::toupper);
    logFile_.open(logFileName_, std::fstream::out | std::fstream::trunc);
    logFile_ << fname << ' ' << getCurrentDateAsString() << ' ' << getCurrentTimeAsString() << std::endl;
    logFile_ << "Trace configuration:" << std::endl;
    logFile_ << " _ENABLE_LOG_PRIO_PRIO_LOW  = " << _ENABLE_LOG_PRIO_PRIO_LOW << std::endl;
    logFile_ << " _ENABLE_LOG_PRIO_PRIO_MED  = " << _ENABLE_LOG_PRIO_PRIO_MED << std::endl;
    logFile_ << " _ENABLE_LOG_PRIO_PRIO_HIGH = " << _ENABLE_LOG_PRIO_PRIO_HIGH << std::endl;
    logFile_ << " _ENABLE_LOG_PRIO_PRIO_TOP  = " << _ENABLE_LOG_PRIO_PRIO_TOP << std::endl;
    logFile_ << std::endl;
}

void GfxBasicLogger::closeLogFile(void) noexcept
{
    std::string fname = logFileName_;

    std::transform(fname.begin(), fname.end(), fname.begin(), ::toupper);
    logFile_ << fname << ' ' << getCurrentDateAsString() << ' ' << getCurrentTimeAsString() << std::endl;
    logFile_.close();
}

bool GfxBasicLogger::doTrace(std::string const& module) const noexcept
{
    if (logTraceAllowAll_ == true)
    {
        return true;
    }
    else
    {
        auto pos = std::find(std::begin(logTraceFilterModules_), std::end(logTraceFilterModules_), module);

        if (pos != std::end(logTraceFilterModules_))
        {
            return true;
        }
    }
    return false;
}

}  // namespace _gfx

}  // namespace gfx

/* EOF */
