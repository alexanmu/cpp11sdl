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
#include <string>

#include "GfxInitFlags.hpp"

namespace gfx
{

namespace initquit
{

const char GfxInitFlags::ClassName[] = "GfxInitFlags";

GfxInitFlags::GfxInitFlags() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxInitFlags::GfxInitFlags(const int32_t flags) noexcept : GfxObject(ClassName)
{
    assert(flags >= 0);

    flags_ = flags;
}

GfxInitFlags::GfxInitFlags(const ValueType flags) noexcept : GfxObject(ClassName)
{
    flags_ = static_cast<int32_t>(flags);
}

GfxInitFlags::GfxInitFlags(GfxInitFlags const& other) noexcept : GfxObject(ClassName)
{
    flags_ = other.flags_;
}

GfxInitFlags::GfxInitFlags(GfxInitFlags&& other) noexcept : GfxObject(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxInitFlags& GfxInitFlags::operator=(GfxInitFlags const& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxInitFlags& GfxInitFlags::operator=(GfxInitFlags&& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxInitFlags::operator bool() const noexcept
{
    return true;
}

bool GfxInitFlags::isNothing(void) const noexcept
{
    return (flags_ == 0);
}

bool GfxInitFlags::isTimer(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_TIMER;

    return (r != 0);
}

bool GfxInitFlags::isAudio(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_AUDIO;

    return (r != 0);
}

bool GfxInitFlags::isVideo(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_VIDEO;

    return (r != 0);
}

bool GfxInitFlags::isJoystick(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_JOYSTICK;

    return (r != 0);
}

bool GfxInitFlags::isHaptic(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_HAPTIC;

    return (r != 0);
}

bool GfxInitFlags::isGameController(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_GAMECONTROLLER;

    return (r != 0);
}

bool GfxInitFlags::isEvents(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_EVENTS;

    return (r != 0);
}

bool GfxInitFlags::isEverything(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_EVERYTHING;

    return (r != 0);
}

bool GfxInitFlags::isNoParachute(void) const noexcept
{
    int32_t r = flags_ & SDL_INIT_NOPARACHUTE;

    return (r != 0);
}

void GfxInitFlags::setTimer(void) noexcept
{
    flags_ = flags_ | SDL_INIT_TIMER;
}

void GfxInitFlags::resetTimer(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_TIMER;
}

void GfxInitFlags::setAudio(void) noexcept
{
    flags_ = flags_ | SDL_INIT_AUDIO;
}

void GfxInitFlags::resetAudio(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_AUDIO;
}

void GfxInitFlags::setVideo(void) noexcept
{
    flags_ = flags_ | SDL_INIT_VIDEO;
}

void GfxInitFlags::resetVideo(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_VIDEO;
}

void GfxInitFlags::setJoystick(void) noexcept
{
    flags_ = flags_ | SDL_INIT_JOYSTICK;
}

void GfxInitFlags::resetJoystick(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_JOYSTICK;
}

void GfxInitFlags::setHaptic(void) noexcept
{
    flags_ = flags_ | SDL_INIT_HAPTIC;
}

void GfxInitFlags::resetHaptic(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_HAPTIC;
}

void GfxInitFlags::setGameController(void) noexcept
{
    flags_ = flags_ | SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::resetGameController(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::setEvents(void) noexcept
{
    flags_ = flags_ | SDL_INIT_EVENTS;
}

void GfxInitFlags::resetEvents(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_EVENTS;
}

void GfxInitFlags::setEverything(void) noexcept
{
    flags_ = flags_ | SDL_INIT_EVERYTHING;
}

void GfxInitFlags::resetEverything(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_EVERYTHING;
}

void GfxInitFlags::setNoParachute(void) noexcept
{
    flags_ = flags_ | SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::resetNoParachute(void) noexcept
{
    flags_ = flags_ & ~SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::clear(void) noexcept
{
    flags_ = static_cast<uint32_t>(ValueType::initNothing);
}

GfxInitFlags::SdlType GfxInitFlags::getAsSdlType(void) const noexcept
{
    return flags_;
}

}  // namespace initquit

}  // namespace gfx

/* EOF */
