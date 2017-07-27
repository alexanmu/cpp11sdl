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

#include "GfxMouseButtonEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmousebuttonevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxMouseButtonEvent::ClassName[] = "GfxMouseButtonEvent";

GfxMouseButtonEvent::GfxMouseButtonEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMouseButtonEvent::GfxMouseButtonEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    mbEvent_ = event;
}

GfxMouseButtonEvent::GfxMouseButtonEvent(GfxMouseButtonEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    mbEvent_ = other.mbEvent_;
}

GfxMouseButtonEvent::GfxMouseButtonEvent(GfxMouseButtonEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    mbEvent_ = other.mbEvent_;
    // Delete other's data
    other.clear();
}

GfxMouseButtonEvent& GfxMouseButtonEvent::operator=(GfxMouseButtonEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        mbEvent_ = other.mbEvent_;
    }
    return *this;
}

GfxMouseButtonEvent& GfxMouseButtonEvent::operator=(GfxMouseButtonEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        mbEvent_ = other.mbEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMouseButtonEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMouseButtonEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxCommonEvent GfxMouseButtonEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(mbEvent_.type, mbEvent_.timestamp);

    return cEv;
}

uint32_t GfxMouseButtonEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mbEvent_.windowID;
}

uint32_t GfxMouseButtonEvent::getMouseID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mbEvent_.which;
}

mouse::GfxButton GfxMouseButtonEvent::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mouse::GfxButton(mbEvent_.button);
}

GfxButtonState GfxMouseButtonEvent::getState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (mbEvent_.state == SDL_RELEASED)
    {
        return GfxButtonState::kGfxReleased;
    }
    return GfxButtonState::kGfxPressed;
}

uint8_t GfxMouseButtonEvent::getClicks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mbEvent_.clicks;
}

int32_t GfxMouseButtonEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mbEvent_.x;
}

int32_t GfxMouseButtonEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mbEvent_.y;
}

void GfxMouseButtonEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mbEvent_ = event;
}

void GfxMouseButtonEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mbEvent_.type = 0;
    mbEvent_.timestamp = 0;
    mbEvent_.windowID = 0;
    mbEvent_.which = 0;
    mbEvent_.button = 0;
    mbEvent_.state = 0;
    mbEvent_.clicks = 0;
    mbEvent_.x = 0;
    mbEvent_.y = 0;
}

GfxMouseButtonEvent::SdlType GfxMouseButtonEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)mbEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
