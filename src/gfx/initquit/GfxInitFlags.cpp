/*
  Giotto
  Copyright (C) 2020 George Oros

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
#include <string>
#include <utility>

#include "GfxInitFlags.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxinitflags::initquit::gfx");

namespace gfx
{

namespace initquit
{

const char GfxInitFlags::ClassName[] = "GfxInitFlags";

GfxInitFlags::GfxInitFlags() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxInitFlags::GfxInitFlags(const int32_t flags) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags >= 0);

    flags_ = flags;
}

GfxInitFlags::GfxInitFlags(const ValueType flags) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flags_ = static_cast<int32_t>(flags);
}

GfxInitFlags::GfxInitFlags(const GfxInitFlags& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_LOW();

    flags_ = other.flags_;
}

GfxInitFlags::GfxInitFlags(GfxInitFlags&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxInitFlags& GfxInitFlags::operator=(const GfxInitFlags& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flags_ = other.flags_;
    }
    return *this;
}

GfxInitFlags& GfxInitFlags::operator=(GfxInitFlags&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxInitFlags::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxInitFlags::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxInitFlags::isNothing(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flags_ == 0);
}

bool GfxInitFlags::isTimer(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_TIMER;

    return (r != 0);
}

bool GfxInitFlags::isAudio(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_AUDIO;

    return (r != 0);
}

bool GfxInitFlags::isVideo(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_VIDEO;

    return (r != 0);
}

bool GfxInitFlags::isJoystick(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_JOYSTICK;

    return (r != 0);
}

bool GfxInitFlags::isHaptic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_HAPTIC;

    return (r != 0);
}

bool GfxInitFlags::isGameController(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_GAMECONTROLLER;

    return (r != 0);
}

bool GfxInitFlags::isEvents(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_EVENTS;

    return (r != 0);
}

bool GfxInitFlags::isEverything(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_EVERYTHING;

    return (r != 0);
}

bool GfxInitFlags::isNoParachute(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t r = flags_ & SDL_INIT_NOPARACHUTE;

    return (r != 0);
}

void GfxInitFlags::setTimer(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_TIMER;
}

void GfxInitFlags::resetTimer(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_TIMER;
}

void GfxInitFlags::setAudio(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_AUDIO;
}

void GfxInitFlags::resetAudio(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_AUDIO;
}

void GfxInitFlags::setVideo(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_VIDEO;
}

void GfxInitFlags::resetVideo(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_VIDEO;
}

void GfxInitFlags::setJoystick(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_JOYSTICK;
}

void GfxInitFlags::resetJoystick(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_JOYSTICK;
}

void GfxInitFlags::setHaptic(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_HAPTIC;
}

void GfxInitFlags::resetHaptic(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_HAPTIC;
}

void GfxInitFlags::setGameController(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::resetGameController(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::setEvents(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_EVENTS;
}

void GfxInitFlags::resetEvents(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_EVENTS;
}

void GfxInitFlags::setEverything(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_EVERYTHING;
}

void GfxInitFlags::resetEverything(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_EVERYTHING;
}

void GfxInitFlags::setNoParachute(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ | SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::resetNoParachute(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    flags_ = flags_ & ~SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flags_ = static_cast<uint32_t>(ValueType::initNothing);
}

GfxInitFlags::SdlType GfxInitFlags::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return flags_;
}

}  // namespace initquit

}  // namespace gfx

/* EOF */
