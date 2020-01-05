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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxJoyHatEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoyhatevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxJoyHatEvent::ClassName[] = "GfxJoyHatEvent";

GfxJoyHatEvent::GfxJoyHatEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoyHatEvent::GfxJoyHatEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    jhEvent_ = event;
}

GfxJoyHatEvent::GfxJoyHatEvent(const GfxJoyHatEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jhEvent_ = other.jhEvent_;
}

GfxJoyHatEvent::GfxJoyHatEvent(GfxJoyHatEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    jhEvent_ = other.jhEvent_;
    // Delete other's data
    other.clear();
}

GfxJoyHatEvent& GfxJoyHatEvent::operator=(const GfxJoyHatEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        jhEvent_ = other.jhEvent_;
    }
    return *this;
}

GfxJoyHatEvent& GfxJoyHatEvent::operator=(GfxJoyHatEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        jhEvent_ = other.jhEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxJoyHatEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoyHatEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxJoyHatEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(jhEvent_.type, jhEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxJoyHatEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(jhEvent_.which);
}

uint8_t GfxJoyHatEvent::getHat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jhEvent_.hat;
}

const joystick::GfxHatPosition GfxJoyHatEvent::getPosition(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxHatPosition(jhEvent_.value);
}

void GfxJoyHatEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jhEvent_ = event;
}

void GfxJoyHatEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jhEvent_.type = 0;
    jhEvent_.timestamp = 0;
    jhEvent_.which = 0;
    jhEvent_.hat = 0;
    jhEvent_.value = 0;
}

GfxJoyHatEvent::SdlType GfxJoyHatEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)jhEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
