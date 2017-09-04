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

#include "GfxDollarGestureEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxdollargestureevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxDollarGestureEvent::ClassName[] = "GfxDollarGestureEvent";

GfxDollarGestureEvent::GfxDollarGestureEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxDollarGestureEvent::GfxDollarGestureEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    dgEvent_ = event;
}

GfxDollarGestureEvent::GfxDollarGestureEvent(GfxDollarGestureEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    dgEvent_ = other.dgEvent_;
}

GfxDollarGestureEvent::GfxDollarGestureEvent(GfxDollarGestureEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    dgEvent_ = other.dgEvent_;
    // Delete other's data
    other.clear();
}

GfxDollarGestureEvent& GfxDollarGestureEvent::operator=(GfxDollarGestureEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        dgEvent_ = other.dgEvent_;
    }
    return *this;
}

GfxDollarGestureEvent& GfxDollarGestureEvent::operator=(GfxDollarGestureEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        dgEvent_ = other.dgEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxDollarGestureEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxDollarGestureEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxCommonEvent GfxDollarGestureEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(dgEvent_.type, dgEvent_.timestamp);

    return cEv;
}

uint32_t GfxDollarGestureEvent::getTouchID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.touchId;
}

uint32_t GfxDollarGestureEvent::getGestureID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.gestureId;
}

uint32_t GfxDollarGestureEvent::getNumFingers(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.numFingers;
}

float GfxDollarGestureEvent::getError(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.error;
}

float GfxDollarGestureEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.x;
}

float GfxDollarGestureEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dgEvent_.y;
}

void GfxDollarGestureEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dgEvent_ = event;
}

void GfxDollarGestureEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dgEvent_.type = 0;
    dgEvent_.timestamp = 0;
    dgEvent_.touchId = 0;
    dgEvent_.gestureId = 0;
    dgEvent_.numFingers = 0;
    dgEvent_.x = 0.0f;
    dgEvent_.y = 0.0f;
}

GfxDollarGestureEvent::SdlType GfxDollarGestureEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)dgEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
