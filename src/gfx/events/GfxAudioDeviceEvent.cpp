/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#include "GfxAudioDeviceEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxaudiodeviceevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxAudioDeviceEvent::ClassName[] = "GfxAudioDeviceEvent";

GfxAudioDeviceEvent::GfxAudioDeviceEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxAudioDeviceEvent::GfxAudioDeviceEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    adEvent_ = event;
}

GfxAudioDeviceEvent::GfxAudioDeviceEvent(const GfxAudioDeviceEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    adEvent_ = other.adEvent_;
}

GfxAudioDeviceEvent::GfxAudioDeviceEvent(GfxAudioDeviceEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    adEvent_ = other.adEvent_;
    // Delete other's data
    other.clear();
}

GfxAudioDeviceEvent& GfxAudioDeviceEvent::operator=(const GfxAudioDeviceEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        adEvent_ = other.adEvent_;
    }
    return *this;
}

GfxAudioDeviceEvent& GfxAudioDeviceEvent::operator=(GfxAudioDeviceEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        adEvent_ = other.adEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxAudioDeviceEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxAudioDeviceEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxAudioDeviceEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(adEvent_.type, adEvent_.timestamp);

    return cEv;
}

uint32_t GfxAudioDeviceEvent::getWhich(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return adEvent_.which;
}

int8_t GfxAudioDeviceEvent::isCapture(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return adEvent_.iscapture;
}

void GfxAudioDeviceEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    adEvent_ = event;
}

void GfxAudioDeviceEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    adEvent_.type = 0;
    adEvent_.timestamp = 0;
    adEvent_.which = 0;
    adEvent_.iscapture = 0;
}

GfxAudioDeviceEvent::SdlType GfxAudioDeviceEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)adEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
