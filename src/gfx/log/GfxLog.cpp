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

#include "GfxLog.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlog::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLog::ClassName[] = "GfxLog";

namespace prv
{

GfxLogOutputFunction * logOutputFunctionObject = nullptr;

extern "C" {
static void logOutputFunction(void * userdata, int category, sdl2::SDL_LogPriority priority, const char * message)
{
    if (logOutputFunctionObject != nullptr)
    {
        GfxLogCategory cat(category);
        GfxLogPriority prio(priority);
        std::string msg(message);

        (*logOutputFunctionObject)(userdata, cat, prio, msg);
    }
}
}  // extern "C"

}  // namespace prv

GfxLog::GfxLog() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
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

GfxLogOutputFunction * GfxLog::logGetOutputFunction(void ** userdata) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_LogOutputFunction sdlLogOutFunc = nullptr;

    sdl2::SDL_LogGetOutputFunction(&sdlLogOutFunc, userdata);
    if ((sdlLogOutFunc != nullptr) &&
        (*sdlLogOutFunc == &prv::logOutputFunction))
    {
        return prv::logOutputFunctionObject;
    }
    return nullptr;
}

void GfxLog::logSetOutputFunction(GfxLogOutputFunction * callback, void * userdata) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (callback != nullptr)
    {
        if (prv::logOutputFunctionObject == nullptr)
        {
            prv::logOutputFunctionObject = callback;
            sdl2::SDL_LogSetOutputFunction(prv::logOutputFunction, userdata);
        }
    }
    else
    {
        // SDL bugzilla issue 3666; revert does not work; just throw
        throw std::runtime_error("SDL Bugzilla, issue 3666");
        // These lines will not be executed before issue 3666 is fixed
        sdl2::SDL_LogSetOutputFunction(NULL, NULL);
        prv::logOutputFunctionObject = nullptr;
    }
}

}  // namespace log

}  // namespace gfx

/* EOF */
