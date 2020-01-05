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

#include "GfxJoyDeviceEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoydeviceevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxJoyDeviceEvent::ClassName[] = "GfxJoyDeviceEvent";

GfxJoyDeviceEvent::GfxJoyDeviceEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoyDeviceEvent::GfxJoyDeviceEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    jdEvent_ = event;
}

GfxJoyDeviceEvent::GfxJoyDeviceEvent(const GfxJoyDeviceEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jdEvent_ = other.jdEvent_;
}

GfxJoyDeviceEvent::GfxJoyDeviceEvent(GfxJoyDeviceEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    jdEvent_ = other.jdEvent_;
    // Delete other's data
    other.clear();
}

GfxJoyDeviceEvent& GfxJoyDeviceEvent::operator=(const GfxJoyDeviceEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        jdEvent_ = other.jdEvent_;
    }
    return *this;
}

GfxJoyDeviceEvent& GfxJoyDeviceEvent::operator=(GfxJoyDeviceEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        jdEvent_ = other.jdEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxJoyDeviceEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoyDeviceEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxJoyDeviceEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(jdEvent_.type, jdEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxJoyDeviceEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(jdEvent_.which);
}

void GfxJoyDeviceEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jdEvent_ = event;
}

void GfxJoyDeviceEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jdEvent_.type = 0;
    jdEvent_.timestamp = 0;
    jdEvent_.which = 0;
}

GfxJoyDeviceEvent::SdlType GfxJoyDeviceEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)jdEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
