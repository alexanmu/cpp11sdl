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

#include "GfxControllerButtonEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcontrollerbuttonevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxControllerButtonEvent::ClassName[] = "GfxControllerButtonEvent";

GfxControllerButtonEvent::GfxControllerButtonEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxControllerButtonEvent::GfxControllerButtonEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    cbEvent_ = event;
}

GfxControllerButtonEvent::GfxControllerButtonEvent(GfxControllerButtonEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    cbEvent_ = other.cbEvent_;
}

GfxControllerButtonEvent::GfxControllerButtonEvent(GfxControllerButtonEvent&& other) noexcept :
        GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    cbEvent_ = other.cbEvent_;
    // Delete other's data
    other.clear();
}

GfxControllerButtonEvent& GfxControllerButtonEvent::operator=(GfxControllerButtonEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        cbEvent_ = other.cbEvent_;
    }
    return *this;
}

GfxControllerButtonEvent& GfxControllerButtonEvent::operator=(GfxControllerButtonEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        cbEvent_ = other.cbEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxControllerButtonEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxControllerButtonEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxControllerButtonEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(cbEvent_.type, cbEvent_.timestamp);

    return cEv;
}

const joystick::GfxJoystickID GfxControllerButtonEvent::getJoystickID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joystick::GfxJoystickID(cbEvent_.which);
}

uint8_t GfxControllerButtonEvent::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return cbEvent_.button;
}

GfxButtonState GfxControllerButtonEvent::getState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<GfxButtonState>(cbEvent_.state);
}

void GfxControllerButtonEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cbEvent_ = event;
}

void GfxControllerButtonEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cbEvent_.type = 0;
    cbEvent_.timestamp = 0;
    cbEvent_.which = 0;
    cbEvent_.button = 0;
    cbEvent_.state = 0;
}

GfxControllerButtonEvent::SdlType GfxControllerButtonEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)cbEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
