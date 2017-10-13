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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxJoyAxisEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoyaxisevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxJoyAxisEvent::ClassName[] = "GfxJoyAxisEvent";

GfxJoyAxisEvent::GfxJoyAxisEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoyAxisEvent::GfxJoyAxisEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    jaxEvent_ = event;
}

GfxJoyAxisEvent::GfxJoyAxisEvent(GfxJoyAxisEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jaxEvent_ = other.jaxEvent_;
}

GfxJoyAxisEvent::GfxJoyAxisEvent(GfxJoyAxisEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    jaxEvent_ = other.jaxEvent_;
    // Delete other's data
    other.clear();
}

GfxJoyAxisEvent& GfxJoyAxisEvent::operator=(GfxJoyAxisEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        jaxEvent_ = other.jaxEvent_;
    }
    return *this;
}

GfxJoyAxisEvent& GfxJoyAxisEvent::operator=(GfxJoyAxisEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        jaxEvent_ = other.jaxEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxJoyAxisEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoyAxisEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxJoyAxisEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(jaxEvent_.type, jaxEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxJoyAxisEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(jaxEvent_.which);
}

uint8_t GfxJoyAxisEvent::getAxis(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jaxEvent_.axis;
}

int16_t GfxJoyAxisEvent::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jaxEvent_.value;
}

void GfxJoyAxisEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jaxEvent_ = event;
}

void GfxJoyAxisEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jaxEvent_.type = 0;
    jaxEvent_.timestamp = 0;
    jaxEvent_.which = 0;
    jaxEvent_.axis = 0;
    jaxEvent_.value = 0;
}

GfxJoyAxisEvent::SdlType GfxJoyAxisEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)jaxEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
