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
#include <string>
#include <utility>

#include "GfxLog.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlog::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLog::ClassName[] = "GfxLog";

GfxLog::GfxLog() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    logOutputFunctionObject_ = nullptr;
}

GfxLog::GfxLog(GfxLog&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    void * userdata = static_cast<void *>(this);

    logOutputFunctionObject_ = other.logOutputFunctionObject_;
    sdl2::SDL_LogSetOutputFunction(logOutputFunction, userdata);
    // Delete other's data
    other.logOutputFunctionObject_ = nullptr;
}

GfxLog& GfxLog::operator=(GfxLog&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    void * userdata = static_cast<void *>(this);

    if (this != & other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        logOutputFunctionObject_ = other.logOutputFunctionObject_;
        sdl2::SDL_LogSetOutputFunction(logOutputFunction, userdata);
        // Delete other's data
        other.logOutputFunctionObject_ = nullptr;
    }
    return *this;
}

GfxLog::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLog::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxLog::setAllPriority(GfxLogPriority const& prio) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(prio);

    sdl2::SDL_LogSetAllPriority(prio.getAsSdlType());
}

void GfxLog::setPriority(GfxLogCategory const& cat, GfxLogPriority const& prio) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(cat);
    assert(prio);

    sdl2::SDL_LogSetPriority(cat.getAsSdlType(), prio.getAsSdlType());
}

GfxLogPriority GfxLog::getPriority(GfxLogCategory const& cat) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(cat);

    GfxLogPriority::SdlType sdlprio;

    sdlprio = sdl2::SDL_LogGetPriority(cat.getAsSdlType());
    return GfxLogPriority(sdlprio);
}

void GfxLog::resetPriorities(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_LogResetPriorities();
}

GfxLogOutputFunction * GfxLog::logGetOutputFunction(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_LogOutputFunction sdlLogOutFunc = nullptr;
    void * userdata = nullptr;

    sdl2::SDL_LogGetOutputFunction(&sdlLogOutFunc, &userdata);
    if (userdata != static_cast<void *>(const_cast<GfxLog *>(this)))
    {
        throw std::runtime_error("this pointer error");
    }
    if ((sdlLogOutFunc != nullptr) &&
        (*sdlLogOutFunc == &logOutputFunction))
    {
        return logOutputFunctionObject_;
    }
    return nullptr;
}

void GfxLog::logSetOutputFunction(GfxLogOutputFunction * callback) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    void * userdata = static_cast<void *>(const_cast<GfxLog *>(this));

    if (callback != nullptr)
    {
        if (logOutputFunctionObject_ == nullptr)
        {
            logOutputFunctionObject_ = callback;
            sdl2::SDL_LogSetOutputFunction(logOutputFunction, userdata);
        }
    }
    else
    {
        // SDL bugzilla issue 3666; revert does not work; just throw
        throw std::runtime_error("SDL Bugzilla, issue 3666");
        // These lines will not be executed before issue 3666 is fixed
        sdl2::SDL_LogSetOutputFunction(NULL, NULL);
        logOutputFunctionObject_ = nullptr;
    }
}

// Private methods
void GfxLog::callCustomLogOutputFunctionObject(const int32_t category, const GfxLogPriority::SdlType priority,
                                               std::string const& message) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(category >= 0);
    assert(message.length() > 0);

    GfxLogCategory cat(category);
    GfxLogPriority prio(priority);

    if (logOutputFunctionObject_ != nullptr)
    {
        (*logOutputFunctionObject_)(cat, prio, message);
    }
}

// Will be called from C by SDL
void GfxLog::logOutputFunction(void * userdata, int category, sdl2::SDL_LogPriority priority, const char * message)
{
    GfxLog * thisptr;

    thisptr = static_cast<GfxLog *>(userdata);
    if (thisptr != nullptr)
    {
        thisptr->callCustomLogOutputFunctionObject(category, priority, message);
    }
}

}  // namespace log

}  // namespace gfx

/* EOF */
