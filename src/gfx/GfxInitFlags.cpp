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

const char GfxInitFlags::ClassName[] = "GfxInitFlags";

GfxInitFlags::GfxInitFlags() : GfxRootClass(ClassName)
{
    flags_ = 0;
}

GfxInitFlags::GfxInitFlags(const int32_t flags) : GfxRootClass(ClassName)
{
    assert(flags >= 0);

    flags_ = flags;
}

GfxInitFlags::GfxInitFlags(ValueType const& flags) : GfxRootClass(ClassName)
{
    flags_ = static_cast<int32_t>(flags);
}

GfxInitFlags::GfxInitFlags(GfxInitFlags const& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
}

GfxInitFlags::GfxInitFlags(GfxInitFlags&& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxInitFlags& GfxInitFlags::operator=(GfxInitFlags const& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxInitFlags& GfxInitFlags::operator=(GfxInitFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxInitFlags::operator bool() const
{
    return true;
}

bool GfxInitFlags::isNothing(void) const
{
    return (flags_ == 0);
}

bool GfxInitFlags::isTimer(void) const
{
    int32_t r = flags_ & SDL_INIT_TIMER;

    return (r != 0);
}

bool GfxInitFlags::isAudio(void) const
{
    int32_t r = flags_ & SDL_INIT_AUDIO;

    return (r != 0);
}

bool GfxInitFlags::isVideo(void) const
{
    int32_t r = flags_ & SDL_INIT_VIDEO;

    return (r != 0);
}

bool GfxInitFlags::isJoystick(void) const
{
    int32_t r = flags_ & SDL_INIT_JOYSTICK;

    return (r != 0);
}

bool GfxInitFlags::isHaptic(void) const
{
    int32_t r = flags_ & SDL_INIT_HAPTIC;

    return (r != 0);
}

bool GfxInitFlags::isGameController(void) const
{
    int32_t r = flags_ & SDL_INIT_GAMECONTROLLER;

    return (r != 0);
}

bool GfxInitFlags::isEvents(void) const
{
    int32_t r = flags_ & SDL_INIT_EVENTS;

    return (r != 0);
}

bool GfxInitFlags::isEverything(void) const
{
    int32_t r = flags_ & SDL_INIT_EVERYTHING;

    return (r != 0);
}

bool GfxInitFlags::isNoParachute(void) const
{
    int32_t r = flags_ & SDL_INIT_NOPARACHUTE;

    return (r != 0);
}

void GfxInitFlags::setTimer(void)
{
    flags_ = flags_ | SDL_INIT_TIMER;
}

void GfxInitFlags::resetTimer(void)
{
    flags_ = flags_ & ~SDL_INIT_TIMER;
}

void GfxInitFlags::setAudio(void)
{
    flags_ = flags_ | SDL_INIT_AUDIO;
}

void GfxInitFlags::resetAudio(void)
{
    flags_ = flags_ & ~SDL_INIT_AUDIO;
}

void GfxInitFlags::setVideo(void)
{
    flags_ = flags_ | SDL_INIT_VIDEO;
}

void GfxInitFlags::resetVideo(void)
{
    flags_ = flags_ & ~SDL_INIT_VIDEO;
}

void GfxInitFlags::setJoystick(void)
{
    flags_ = flags_ | SDL_INIT_JOYSTICK;
}

void GfxInitFlags::resetJoystick(void)
{
    flags_ = flags_ & ~SDL_INIT_JOYSTICK;
}

void GfxInitFlags::setHaptic(void)
{
    flags_ = flags_ | SDL_INIT_HAPTIC;
}

void GfxInitFlags::resetHaptic(void)
{
    flags_ = flags_ & ~SDL_INIT_HAPTIC;
}

void GfxInitFlags::setGameController(void)
{
    flags_ = flags_ | SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::resetGameController(void)
{
    flags_ = flags_ & ~SDL_INIT_GAMECONTROLLER;
}

void GfxInitFlags::setEvents(void)
{
    flags_ = flags_ | SDL_INIT_EVENTS;
}

void GfxInitFlags::resetEvents(void)
{
    flags_ = flags_ & ~SDL_INIT_EVENTS;
}

void GfxInitFlags::setEverything(void)
{
    flags_ = flags_ | SDL_INIT_EVERYTHING;
}

void GfxInitFlags::resetEverything(void)
{
    flags_ = flags_ & ~SDL_INIT_EVERYTHING;
}

void GfxInitFlags::setNoParachute(void)
{
    flags_ = flags_ | SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::resetNoParachute(void)
{
    flags_ = flags_ & ~SDL_INIT_NOPARACHUTE;
}

void GfxInitFlags::clear(void)
{
    flags_ = static_cast<uint32_t>(ValueType::initNothing);
}

GfxInitFlags::SdlType GfxInitFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxInitFlags::SdlTypePtr GfxInitFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

}  // namespace gfx

/* EOF */
