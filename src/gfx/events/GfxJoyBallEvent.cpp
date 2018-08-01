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

#include "GfxJoyBallEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoyballevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxJoyBallEvent::ClassName[] = "GfxJoyBallEvent";

GfxJoyBallEvent::GfxJoyBallEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoyBallEvent::GfxJoyBallEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = event;
}

GfxJoyBallEvent::GfxJoyBallEvent(const GfxJoyBallEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = other.jbEvent_;
}

GfxJoyBallEvent::GfxJoyBallEvent(GfxJoyBallEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    jbEvent_ = other.jbEvent_;
    // Delete other's data
    other.clear();
}

GfxJoyBallEvent& GfxJoyBallEvent::operator=(const GfxJoyBallEvent& other) noexcept
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

GfxJoyBallEvent& GfxJoyBallEvent::operator=(GfxJoyBallEvent&& other) noexcept
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

GfxJoyBallEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoyBallEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxJoyBallEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(jbEvent_.type, jbEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxJoyBallEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(jbEvent_.which);
}

uint8_t GfxJoyBallEvent::getBall(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jbEvent_.ball;
}

int16_t GfxJoyBallEvent::getXRel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jbEvent_.xrel;
}

int16_t GfxJoyBallEvent::getYRel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return jbEvent_.yrel;
}

void GfxJoyBallEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jbEvent_ = event;
}

void GfxJoyBallEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    jbEvent_.type = 0;
    jbEvent_.timestamp = 0;
    jbEvent_.which = 0;
    jbEvent_.ball = 0;
    jbEvent_.xrel = 0;
    jbEvent_.yrel = 0;
}

GfxJoyBallEvent::SdlType GfxJoyBallEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)jbEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
