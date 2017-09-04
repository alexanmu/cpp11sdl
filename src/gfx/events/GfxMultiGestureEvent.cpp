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

#include "GfxMultiGestureEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmultigestureevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxMultiGestureEvent::ClassName[] = "GfxMultiGestureEvent";

GfxMultiGestureEvent::GfxMultiGestureEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMultiGestureEvent::GfxMultiGestureEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    mgEvent_ = event;
}

GfxMultiGestureEvent::GfxMultiGestureEvent(GfxMultiGestureEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    mgEvent_ = other.mgEvent_;
}

GfxMultiGestureEvent::GfxMultiGestureEvent(GfxMultiGestureEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    mgEvent_ = other.mgEvent_;
    // Delete other's data
    other.clear();
}

GfxMultiGestureEvent& GfxMultiGestureEvent::operator=(GfxMultiGestureEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        mgEvent_ = other.mgEvent_;
    }
    return *this;
}

GfxMultiGestureEvent& GfxMultiGestureEvent::operator=(GfxMultiGestureEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        mgEvent_ = other.mgEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMultiGestureEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMultiGestureEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxCommonEvent GfxMultiGestureEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(mgEvent_.type, mgEvent_.timestamp);

    return cEv;
}

uint32_t GfxMultiGestureEvent::getTouchID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.touchId;
}

float GfxMultiGestureEvent::getdTetha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.dTheta;
}

float GfxMultiGestureEvent::getdDist(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.dDist;
}

float GfxMultiGestureEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.x;
}

float GfxMultiGestureEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.y;
}

uint16_t GfxMultiGestureEvent::getNumFingers(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mgEvent_.numFingers;
}

void GfxMultiGestureEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mgEvent_ = event;
}

void GfxMultiGestureEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    mgEvent_.type = 0;
    mgEvent_.timestamp = 0;
    mgEvent_.touchId = 0;
    mgEvent_.dTheta = 0.0f;
    mgEvent_.dDist = 0.0f;
    mgEvent_.x = 0.0f;
    mgEvent_.y = 0.0f;
    mgEvent_.numFingers = 0;
}

GfxMultiGestureEvent::SdlType GfxMultiGestureEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)mgEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
