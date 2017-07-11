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

#include <string>
#include <utility>

#include "GfxWindowEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxwindowevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxWindowEvent::ClassName[] = "GfxWindowEvent";

GfxWindowEvent::GfxWindowEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxWindowEvent::GfxWindowEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    windowEvent_ = event;
}

GfxWindowEvent::GfxWindowEvent(GfxWindowEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    windowEvent_ = other.windowEvent_;
}

GfxWindowEvent::GfxWindowEvent(GfxWindowEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    windowEvent_ = other.windowEvent_;
    // Delete other's data
    other.clear();
}

GfxWindowEvent& GfxWindowEvent::operator=(GfxWindowEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        windowEvent_ = other.windowEvent_;
    }
    return *this;
}

GfxWindowEvent& GfxWindowEvent::operator=(GfxWindowEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        windowEvent_ = other.windowEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxWindowEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxWindowEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxCommonEvent GfxWindowEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(windowEvent_.type, windowEvent_.timestamp);

    return cEv;
}

uint32_t GfxWindowEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return windowEvent_.windowID;
}

video::GfxWindowEventID GfxWindowEvent::getWindowEventID(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    video::GfxWindowEventID evId(windowEvent_.event);

    return evId;
}

int32_t GfxWindowEvent::getData1(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return windowEvent_.data2;
}

int32_t GfxWindowEvent::getData2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return windowEvent_.data1;
}

void GfxWindowEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    windowEvent_.type = 0;
    windowEvent_.timestamp = 0;
    windowEvent_.windowID = 0;
    windowEvent_.event = 0;
    windowEvent_.padding1 = 0;
    windowEvent_.padding2 = 0;
    windowEvent_.padding3 = 0;
    windowEvent_.data1 = 0;
    windowEvent_.data2 = 0;
}

GfxWindowEvent::SdlType GfxWindowEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return windowEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
