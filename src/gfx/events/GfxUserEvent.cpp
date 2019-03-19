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

#include "GfxUserEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxuserevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxUserEvent::ClassName[] = "GfxUserEvent";

GfxUserEvent::GfxUserEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxUserEvent::GfxUserEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    uEvent_ = event;
}

GfxUserEvent::GfxUserEvent(const GfxUserEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    uEvent_ = other.uEvent_;
}

GfxUserEvent::GfxUserEvent(GfxUserEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    uEvent_ = other.uEvent_;
    // Delete other's data
    other.clear();
}

GfxUserEvent& GfxUserEvent::operator=(const GfxUserEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        uEvent_ = other.uEvent_;
    }
    return *this;
}

GfxUserEvent& GfxUserEvent::operator=(GfxUserEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        uEvent_ = other.uEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxUserEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxUserEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxUserEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(uEvent_.type, uEvent_.timestamp);

    return cEv;
}

uint32_t GfxUserEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return uEvent_.windowID;
}


int32_t GfxUserEvent::getCode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return uEvent_.code;
}

void * GfxUserEvent::getData1(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return uEvent_.data1;
}

void * GfxUserEvent::getData2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return uEvent_.data2;
}

void GfxUserEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    uEvent_ = event;
}

void GfxUserEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    uEvent_.type = 0;
    uEvent_.timestamp = 0;
    uEvent_.windowID = 0;
    uEvent_.code = 0;
    uEvent_.data1 = nullptr;
    uEvent_.data2 = nullptr;
}

GfxUserEvent::SdlType GfxUserEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)uEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
