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

#include "GfxPowerState.hpp"

namespace gfx
{

namespace power
{

const char GfxPowerState::ClassName[] = "GfxPowerState";

GfxPowerState::GfxPowerState() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxPowerState::GfxPowerState(const ValueType value) noexcept : GfxObject(ClassName)
{
    value_ = static_cast<SdlType>(value);
}

GfxPowerState::GfxPowerState(const SdlType value) noexcept : GfxObject(ClassName)
{
    assert(value >= 0);

    value_ = value;
}

GfxPowerState::GfxPowerState(GfxPowerState const& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
}

GfxPowerState::GfxPowerState(GfxPowerState&& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
    // Delete other's value
    other.clear();
}

GfxPowerState& GfxPowerState::operator=(GfxPowerState const& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxPowerState& GfxPowerState::operator=(GfxPowerState&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxPowerState::operator bool() const noexcept
{
    return true;
}

bool GfxPowerState::isUnknown(void) const noexcept
{
    return (value_ == static_cast<SdlType>(sdl2::SDL_POWERSTATE_UNKNOWN));
}

bool GfxPowerState::isOnBattery(void) const noexcept
{
    return (value_ == static_cast<SdlType>(sdl2::SDL_POWERSTATE_ON_BATTERY));
}

bool GfxPowerState::isNoBattery(void) const noexcept
{
    return (value_ == static_cast<SdlType>(sdl2::SDL_POWERSTATE_NO_BATTERY));
}

bool GfxPowerState::isCharging(void) const noexcept
{
    return (value_ == static_cast<SdlType>(sdl2::SDL_POWERSTATE_CHARGING));
}

bool GfxPowerState::isCharged(void) const noexcept
{
    return (value_ == static_cast<SdlType>(sdl2::SDL_POWERSTATE_CHARGED));
}

void GfxPowerState::clear(void) noexcept
{
    value_ = static_cast<SdlType>(ValueType::stateUnknown);
}

const std::string GfxPowerState::getAsString() const noexcept
{
    std::string str;

    switch (static_cast<ValueType>(value_))
    {
        case ValueType::stateUnknown:
            str = "Unknwon";
            break;
        case ValueType::stateOnBattery:
            str = "On Battery";
            break;
        case ValueType::stateNoBattery:
            str = "No Battery";
            break;
        case ValueType::stateCharging:
            str = "Charging";
            break;
        case ValueType::stateCharged:
            str = "Charged";
            break;
    }
    return str;
}

GfxPowerState::SdlType GfxPowerState::getAsSdlType(void) const noexcept
{
    return value_;
}

GfxPowerState::SdlTypePtr GfxPowerState::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)value_;
}

}  // namespace power

}  // namespace gfx

/* EOF */
