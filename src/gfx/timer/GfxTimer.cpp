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

#include <stdexcept>
#include <cstdint>
#include <cassert>
#include <string>
#include <utility>

#include "GfxTimer.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtimer::timer::gfx");

namespace gfx
{

namespace timer
{

const char GfxTimer::ClassName[] = "GfxTimer";

GfxTimer::GfxTimer() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTimer::GfxTimer(GfxTimer&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    callbackMap_ = other.callbackMap_;
    // Delete other's data
    other.clear();
}

GfxTimer& GfxTimer::operator=(GfxTimer&& other) noexcept
{
    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        callbackMap_ = other.callbackMap_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTimer::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTimer::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

uint32_t GfxTimer::getTicks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_GetTicks();
}

int32_t GfxTimer::ticksPassed(const uint32_t a, const uint32_t b) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ((int32_t)((b) - (a)) <= 0);
}

uint64_t GfxTimer::getPerformanceCounter(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_GetPerformanceCounter();
}

uint64_t GfxTimer::getPerformanceFrequency(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_GetPerformanceFrequency();
}

void GfxTimer::delay_(const uint32_t ms) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(ms > 0);

    sdl2::SDL_Delay(ms);
}

GfxTimerID GfxTimer::addTimer(const uint32_t interval, GfxTimerCallback const& callback) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(interval > 0);
    assert(callback);

    GfxTimerID::SdlType tid = -1;
    void * param = static_cast<void *>(this);

    tid = sdl2::SDL_AddTimer(interval, timerCallbackFunction, param);
    callbackMap_[tid] = const_cast<GfxTimerCallback *>(&callback);
    return GfxTimerID(tid);
}

GfxBool GfxTimer::removeTimer(GfxTimerID const& id) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(id);

    GfxBool::SdlType sdlbool;

    auto pos = callbackMap_.find(id.getAsSdlType());
    if (pos != callbackMap_.end())
    {
        callbackMap_.erase(pos);
        sdlbool = sdl2::SDL_RemoveTimer(id.getAsSdlType());
    }
    else
    {
        throw std::runtime_error("Callback does not exist!");
    }
    return GfxBool(sdlbool);
}

void GfxTimer::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    callbackMap_.clear();
}

void GfxTimer::delay(const uint32_t ms) noexcept
{
    assert(ms > 0);

    sdl2::SDL_Delay(ms);
}

// Private methods
uint32_t GfxTimer::timerCallbackFunction(uint32_t interval, void * param)
{
    GfxTimer * thisptr = static_cast<GfxTimer *>(param);
    GfxTimerCallback * inmap = nullptr;
    uint32_t ret = 0;
    GfxTimerID::SdlType tid;

    if (thisptr != nullptr)
    {
        if (thisptr->callbackMap_.size() > 0)
        {
            // Compute TimerID here, somehow
            // Hope for fix to SDL2 bugzilla Bug #3802, until then set TimerID to -1; it will not be found
            // in the callbackMap_ map variable
#warning SDL2 bugzilla Bug #3802
            tid = -1;
            auto pos = thisptr->callbackMap_.find(tid);
            if (pos != thisptr->callbackMap_.end())
            {
                inmap = thisptr->callbackMap_.operator[](tid);
                ret = (*inmap)(interval);
            }
        }
    }
    return ret;
}

}  // namespace timer

}  // namespace gfx

/* EOF */
