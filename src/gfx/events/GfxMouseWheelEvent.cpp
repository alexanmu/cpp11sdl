/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include "GfxMouseWheelEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmousewheelevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxMouseWheelEvent::ClassName[] = "GfxMouseWheelEvent";

GfxMouseWheelEvent::GfxMouseWheelEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMouseWheelEvent::GfxMouseWheelEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    mwEvent_ = event;
}

GfxMouseWheelEvent::GfxMouseWheelEvent(const GfxMouseWheelEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    mwEvent_ = other.mwEvent_;
}

GfxMouseWheelEvent::GfxMouseWheelEvent(GfxMouseWheelEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    mwEvent_ = other.mwEvent_;
    // Delete other's data
    other.clear();
}

GfxMouseWheelEvent& GfxMouseWheelEvent::operator=(const GfxMouseWheelEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        mwEvent_ = other.mwEvent_;
    }
    return *this;
}

GfxMouseWheelEvent& GfxMouseWheelEvent::operator=(GfxMouseWheelEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        mwEvent_ = other.mwEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMouseWheelEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMouseWheelEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxMouseWheelEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(mwEvent_.type, mwEvent_.timestamp);

    return cEv;
}

uint32_t GfxMouseWheelEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mwEvent_.windowID;
}

uint32_t GfxMouseWheelEvent::getMouseID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mwEvent_.which;
}

int32_t GfxMouseWheelEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mwEvent_.x;
}

int32_t GfxMouseWheelEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mwEvent_.y;
}

const mouse::GfxMouseWheelDirection GfxMouseWheelEvent::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mouse::GfxMouseWheelDirection(mwEvent_.direction);
}

void GfxMouseWheelEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mwEvent_ = event;
}

void GfxMouseWheelEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mwEvent_.type = 0;
    mwEvent_.timestamp = 0;
    mwEvent_.windowID = 0;
    mwEvent_.which = 0;
    mwEvent_.x = 0;
    mwEvent_.y = 0;
    mwEvent_.direction = 0;
}

GfxMouseWheelEvent::SdlType GfxMouseWheelEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)mwEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
