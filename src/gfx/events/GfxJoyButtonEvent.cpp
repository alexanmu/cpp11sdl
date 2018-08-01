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

#include "GfxJoyButtonEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoybuttonevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxJoyButtonEvent::ClassName[] = "GfxJoyButtonEvent";

GfxJoyButtonEvent::GfxJoyButtonEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoyButtonEvent::GfxJoyButtonEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = event;
}

GfxJoyButtonEvent::GfxJoyButtonEvent(const GfxJoyButtonEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = other.jbEvent_;
}

GfxJoyButtonEvent::GfxJoyButtonEvent(GfxJoyButtonEvent&& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = other.jbEvent_;
    // Delete other's data
    other.clear();
}

GfxJoyButtonEvent& GfxJoyButtonEvent::operator=(const GfxJoyButtonEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        jbEvent_ = other.jbEvent_;
    }
    return *this;
}

GfxJoyButtonEvent& GfxJoyButtonEvent::operator=(GfxJoyButtonEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        jbEvent_ = other.jbEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxJoyButtonEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoyButtonEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxJoyButtonEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(jbEvent_.type, jbEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxJoyButtonEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(jbEvent_.which);
}

uint8_t GfxJoyButtonEvent::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jbEvent_.button;
}

GfxButtonState GfxJoyButtonEvent::getState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<GfxButtonState>(jbEvent_.state);
}

void GfxJoyButtonEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jbEvent_ = event;
}

void GfxJoyButtonEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jbEvent_.type = 0;
    jbEvent_.timestamp = 0;
    jbEvent_.which = 0;
    jbEvent_.button = 0;
    jbEvent_.state = 0;
}

GfxJoyButtonEvent::SdlType GfxJoyButtonEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)jbEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
