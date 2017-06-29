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

#include <cstdint>
#include <fstream>
#include <ctime>
#include <string>

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

void GfxBasicLogger::logTrace(const tracePriority prio, const char * file, const int32_t line,
                              const char * func, const int32_t instance) noexcept
{
    logFile_ << 'P' << getTextForPrio(prio) << ' ' << instance << ' ' << file << ':' << line << ' '\
             <<  '[' << func << ']' << '\n';
}

// Private methods
GfxBasicLogger::GfxBasicLogger() noexcept
{
    logFile_.open(logFileName_, std::fstream::out | std::fstream::trunc);
    logFile_ << logFileName_ << ' ' << getCurrentDateAsString() << ' ' << getCurrentTimeAsString() << std::endl;
    logFile_ << "Trace configuration:" << std::endl;
    logFile_ << " _ENABLE_TRACE_PRIO_0=" << _ENABLE_TRACE_PRIO_0 << std::endl;
    logFile_ << " _ENABLE_TRACE_PRIO_1=" << _ENABLE_TRACE_PRIO_1 << std::endl;
    logFile_ << " _ENABLE_TRACE_PRIO_2=" << _ENABLE_TRACE_PRIO_2 << std::endl;
    logFile_ << " _ENABLE_TRACE_PRIO_3=" << _ENABLE_TRACE_PRIO_3 << std::endl;
    logFile_ << " _ENABLE_TRACE_PRIO_4=" << _ENABLE_TRACE_PRIO_4 << std::endl;
    logFile_ << std::endl;
}

GfxBasicLogger::~GfxBasicLogger() noexcept
{
    logFile_.close();
}

char GfxBasicLogger::getTextForPrio(const tracePriority prio) const noexcept
{
    char ret = 0;

    switch (prio)
    {
        case tracePriority::prioPrio0:
            ret = '0';
            break;
        case tracePriority::prioPrio1:
            ret = '1';
            break;
        case tracePriority::prioPrio2:
            ret = '2';
            break;
        case tracePriority::prioPrio3:
            ret = '3';
            break;
        case tracePriority::prioPrio4:
            ret = '4';
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

}  // namespace _gfx

}  // namespace gfx

/* EOF */
