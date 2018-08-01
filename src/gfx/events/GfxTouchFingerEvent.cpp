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

#include "GfxTouchFingerEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtouchfingerevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxTouchFingerEvent::ClassName[] = "GfxTouchFingerEvent";

GfxTouchFingerEvent::GfxTouchFingerEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTouchFingerEvent::GfxTouchFingerEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    tfEvent_ = event;
}

GfxTouchFingerEvent::GfxTouchFingerEvent(const GfxTouchFingerEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    tfEvent_ = other.tfEvent_;
}

GfxTouchFingerEvent::GfxTouchFingerEvent(GfxTouchFingerEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    tfEvent_ = other.tfEvent_;
    // Delete other's data
    other.clear();
}

GfxTouchFingerEvent& GfxTouchFingerEvent::operator=(const GfxTouchFingerEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        tfEvent_ = other.tfEvent_;
    }
    return *this;
}

GfxTouchFingerEvent& GfxTouchFingerEvent::operator=(GfxTouchFingerEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        tfEvent_ = other.tfEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTouchFingerEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTouchFingerEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxTouchFingerEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(tfEvent_.type, tfEvent_.timestamp);

    return cEv;
}

const touch::GfxTouchID GfxTouchFingerEvent::getTouchID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return touch::GfxTouchID(tfEvent_.touchId);
}

const touch::GfxFingerID GfxTouchFingerEvent::getFingerID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return touch::GfxFingerID(tfEvent_.fingerId);
}

float GfxTouchFingerEvent::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tfEvent_.x;
}

float GfxTouchFingerEvent::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tfEvent_.y;
}

float GfxTouchFingerEvent::getdX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tfEvent_.dx;
}

float GfxTouchFingerEvent::getdY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tfEvent_.dy;
}

float GfxTouchFingerEvent::getPressure(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tfEvent_.pressure;
}

void GfxTouchFingerEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    tfEvent_ = event;
}

void GfxTouchFingerEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    tfEvent_.type = 0;
    tfEvent_.timestamp = 0;
    tfEvent_.touchId = 0;
    tfEvent_.fingerId = 0;
    tfEvent_.x = 0.0f;
    tfEvent_.y = 0.0f;
    tfEvent_.dx = 0.0f;
    tfEvent_.dy = 0.0f;
    tfEvent_.pressure = 0.0f;
}

GfxTouchFingerEvent::SdlType GfxTouchFingerEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)tfEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
