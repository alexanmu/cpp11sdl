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

#include "GfxPowerState.hpp"

GfxPowerState::GfxPowerState() : GfxRootClass("GfxPowerState")
{
    value_ = static_cast<SdlType>(GfxPowerStateValues::stateUnknown);
}

GfxPowerState::GfxPowerState(GfxPowerStateValues value) : GfxRootClass("GfxPowerState")
{
    value_ = static_cast<SdlType>(value);
}

GfxPowerState::GfxPowerState(SdlType value) : GfxRootClass("GfxPowerState")
{
    value_ = value;
}

GfxPowerState::GfxPowerState(GfxPowerState const& other) : GfxRootClass("GfxPowerState")
{
    value_ = other.value_;
}

GfxPowerState::GfxPowerState(GfxPowerState&& other) : GfxRootClass("GfxPowerState")
{
    value_ = other.value_;
    // Delete other's value
    other.value_ = static_cast<SdlType>(GfxPowerStateValues::stateUnknown);
}

GfxPowerState& GfxPowerState::operator=(GfxPowerState const& other)
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxPowerState& GfxPowerState::operator=(GfxPowerState&& other)
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = static_cast<SdlType>(GfxPowerStateValues::stateUnknown);
    }
    return *this;
}

bool GfxPowerState::isUnknown(void) const
{
    return (value_ == static_cast<SdlType>(SDL_POWERSTATE_UNKNOWN));
}

bool GfxPowerState::isOnBattery(void) const
{
    return (value_ == static_cast<SdlType>(SDL_POWERSTATE_ON_BATTERY));
}

bool GfxPowerState::isNoBattery(void) const
{
    return (value_ == static_cast<SdlType>(SDL_POWERSTATE_NO_BATTERY));
}

bool GfxPowerState::isCharging(void) const
{
    return (value_ == static_cast<SdlType>(SDL_POWERSTATE_CHARGING));
}

bool GfxPowerState::isCharged(void) const
{
    return (value_ == static_cast<SdlType>(SDL_POWERSTATE_CHARGED));
}

std::string GfxPowerState::getAsString() const
{
    std::string str;

    switch (static_cast<GfxPowerStateValues>(value_))
    {
        case GfxPowerStateValues::stateUnknown:
            str = "Unknwon";
            break;
        case GfxPowerStateValues::stateOnBattery:
            str = "On Battery";
            break;
        case GfxPowerStateValues::stateNoBattery:
            str = "No Battery";
            break;
        case GfxPowerStateValues::stateCharging:
            str = "Charging";
            break;
        case GfxPowerStateValues::stateCharged:
            str = "Charged";
            break;
    }
    return str;
}

GfxPowerState::SdlType GfxPowerState::getAsSdlType(void) const
{
    return value_;
}

GfxPowerState::SdlTypePtr GfxPowerState::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)value_;
}

/* EOF */
