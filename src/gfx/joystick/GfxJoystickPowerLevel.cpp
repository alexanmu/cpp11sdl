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

#include <string>
#include <utility>

#include "GfxJoystickPowerLevel.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoystickpowerlevel::joystick::gfx");

namespace gfx
{

namespace joystick
{

const char GfxJoystickPowerLevel::ClassName[] = "GfxJoystickPowerLevel";

GfxJoystickPowerLevel::GfxJoystickPowerLevel() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoystickPowerLevel::GfxJoystickPowerLevel(const SdlType plevel) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    plevel_ = plevel;
}

GfxJoystickPowerLevel::GfxJoystickPowerLevel(const ValueType plevel) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    plevel_ = static_cast<SdlType>(plevel);
}


GfxJoystickPowerLevel::GfxJoystickPowerLevel(const GfxJoystickPowerLevel& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    plevel_ = other.plevel_;
}

GfxJoystickPowerLevel::GfxJoystickPowerLevel(GfxJoystickPowerLevel&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    plevel_ = other.plevel_;
    // Delete other's value
    other.clear();
}

GfxJoystickPowerLevel& GfxJoystickPowerLevel::operator=(const GfxJoystickPowerLevel& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        plevel_ = other.plevel_;
    }
    return *this;
}

GfxJoystickPowerLevel& GfxJoystickPowerLevel::operator=(GfxJoystickPowerLevel&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        plevel_ = other.plevel_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxJoystickPowerLevel::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoystickPowerLevel::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxJoystickPowerLevel::ValueType GfxJoystickPowerLevel::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(plevel_);
}

bool GfxJoystickPowerLevel::isUnknown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_UNKNOWN);
}

bool GfxJoystickPowerLevel::isEmpty(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_EMPTY);
}

bool GfxJoystickPowerLevel::isLow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_LOW);
}

bool GfxJoystickPowerLevel::isMedium(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_MEDIUM);
}

bool GfxJoystickPowerLevel::isFull(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_FULL);
}

bool GfxJoystickPowerLevel::isWired(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_WIRED);
}

bool GfxJoystickPowerLevel::isMax(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (plevel_ == SDL_JOYSTICK_POWER_MAX);
}

void GfxJoystickPowerLevel::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    plevel_ = static_cast<SdlType>(ValueType::powerUnknown);
}

GfxJoystickPowerLevel::SdlType GfxJoystickPowerLevel::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return plevel_;
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
