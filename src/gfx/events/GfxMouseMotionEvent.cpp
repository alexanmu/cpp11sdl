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

#include "GfxMouseMotionEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmousemotionevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxMouseMotionEvent::ClassName[] = "GfxMouseMotionEvent";

GfxMouseMotionEvent::GfxMouseMotionEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMouseMotionEvent::GfxMouseMotionEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    mmEvent_ = event;
}

GfxMouseMotionEvent::GfxMouseMotionEvent(GfxMouseMotionEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    mmEvent_ = other.mmEvent_;
}

GfxMouseMotionEvent::GfxMouseMotionEvent(GfxMouseMotionEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    mmEvent_ = other.mmEvent_;
    // Delete other's data
    other.clear();
}

GfxMouseMotionEvent& GfxMouseMotionEvent::operator=(GfxMouseMotionEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        mmEvent_ = other.mmEvent_;
    }
    return *this;
}

GfxMouseMotionEvent& GfxMouseMotionEvent::operator=(GfxMouseMotionEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        mmEvent_ = other.mmEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMouseMotionEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMouseMotionEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxCommonEvent GfxMouseMotionEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(mmEvent_.type, mmEvent_.timestamp);

    return cEv;
}

uint32_t GfxMouseMotionEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.windowID;
}

uint32_t GfxMouseMotionEvent::getMouseID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.which;
}

uint32_t GfxMouseMotionEvent::getState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.state;
}

int32_t GfxMouseMotionEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.x;
}

int32_t GfxMouseMotionEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.y;
}

int32_t GfxMouseMotionEvent::getXRel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.xrel;
}

int32_t GfxMouseMotionEvent::getYRel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mmEvent_.yrel;
}

void GfxMouseMotionEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mmEvent_ = event;
}

void GfxMouseMotionEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mmEvent_.type = 0;
    mmEvent_.timestamp = 0;
    mmEvent_.windowID = 0;
    mmEvent_.which = 0;
    mmEvent_.state = 0;
    mmEvent_.x = 0;
    mmEvent_.y = 0;
    mmEvent_.xrel = 0;
    mmEvent_.yrel = 0;
}

GfxMouseMotionEvent::SdlType GfxMouseMotionEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)mmEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
