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

#include "GfxControllerAxisEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcontrolleraxisevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxControllerAxisEvent::ClassName[] = "GfxControllerAxisEvent";

GfxControllerAxisEvent::GfxControllerAxisEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxControllerAxisEvent::GfxControllerAxisEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    caEvent_ = event;
}

GfxControllerAxisEvent::GfxControllerAxisEvent(const GfxControllerAxisEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    caEvent_ = other.caEvent_;
}

GfxControllerAxisEvent::GfxControllerAxisEvent(GfxControllerAxisEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    caEvent_ = other.caEvent_;
    // Delete other's data
    other.clear();
}

GfxControllerAxisEvent& GfxControllerAxisEvent::operator=(const GfxControllerAxisEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        caEvent_ = other.caEvent_;
    }
    return *this;
}

GfxControllerAxisEvent& GfxControllerAxisEvent::operator=(GfxControllerAxisEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        caEvent_ = other.caEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxControllerAxisEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxControllerAxisEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxControllerAxisEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(caEvent_.type, caEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxControllerAxisEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(caEvent_.which);
}

uint8_t GfxControllerAxisEvent::getAxis(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return caEvent_.axis;
}

int16_t GfxControllerAxisEvent::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return caEvent_.value;
}

void GfxControllerAxisEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    caEvent_ = event;
}

void GfxControllerAxisEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    caEvent_.type = 0;
    caEvent_.timestamp = 0;
    caEvent_.which = 0;
    caEvent_.axis = 0;
    caEvent_.value = 0;
}

GfxControllerAxisEvent::SdlType GfxControllerAxisEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)caEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
