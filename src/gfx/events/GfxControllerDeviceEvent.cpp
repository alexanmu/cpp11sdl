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

#include "GfxControllerDeviceEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcontrollerdeviceevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxControllerDeviceEvent::ClassName[] = "GfxControllerDeviceEvent";

GfxControllerDeviceEvent::GfxControllerDeviceEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxControllerDeviceEvent::GfxControllerDeviceEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    cdEvent_ = event;
}

GfxControllerDeviceEvent::GfxControllerDeviceEvent(const GfxControllerDeviceEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    cdEvent_ = other.cdEvent_;
}

GfxControllerDeviceEvent::GfxControllerDeviceEvent(GfxControllerDeviceEvent&& other) noexcept :
        GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    cdEvent_ = other.cdEvent_;
    // Delete other's data
    other.clear();
}

GfxControllerDeviceEvent& GfxControllerDeviceEvent::operator=(const GfxControllerDeviceEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        cdEvent_ = other.cdEvent_;
    }
    return *this;
}

GfxControllerDeviceEvent& GfxControllerDeviceEvent::operator=(GfxControllerDeviceEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        cdEvent_ = other.cdEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxControllerDeviceEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxControllerDeviceEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxControllerDeviceEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(cdEvent_.type, cdEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxControllerDeviceEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(cdEvent_.which);
}

void GfxControllerDeviceEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cdEvent_ = event;
}

void GfxControllerDeviceEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cdEvent_.type = 0;
    cdEvent_.timestamp = 0;
    cdEvent_.which = 0;
}

GfxControllerDeviceEvent::SdlType GfxControllerDeviceEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)cdEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
