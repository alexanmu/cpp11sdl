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

#include <cassert>
#include <string>
#include <utility>

#include "GfxCommonEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcommonevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxCommonEvent::ClassName[] = "GfxCommonEvent";

GfxCommonEvent::GfxCommonEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxCommonEvent::GfxCommonEvent(const uint32_t type, const uint32_t timestamp) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    commonEvent_.type = type;
    commonEvent_.timestamp = timestamp;
}

GfxCommonEvent::GfxCommonEvent(const SdlType ev) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    commonEvent_ = ev;
}

GfxCommonEvent::GfxCommonEvent(const GfxCommonEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    commonEvent_ = other.commonEvent_;
}

GfxCommonEvent::GfxCommonEvent(GfxCommonEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    commonEvent_ = other.commonEvent_;
    // Delete other's data
    other.clear();
}

GfxCommonEvent& GfxCommonEvent::operator=(const GfxCommonEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        commonEvent_ = other.commonEvent_;
    }
    return *this;
}

GfxCommonEvent& GfxCommonEvent::operator=(GfxCommonEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        commonEvent_ = other.commonEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxCommonEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxCommonEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxEventType GfxCommonEvent::getType(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return GfxEventType(commonEvent_.type);
}

uint32_t GfxCommonEvent::getTimeStamp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return commonEvent_.timestamp;
}

void GfxCommonEvent::setType(const GfxEventType& evtype) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(evtype);

    commonEvent_.type = evtype.getEventTypeValue();
}

void GfxCommonEvent::setTimeStamp(const uint32_t timestamp) noexcept
{
    LOG_TRACE_PRIO_LOW();

    commonEvent_.timestamp = timestamp;
}

void GfxCommonEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    commonEvent_.type = 0;
    commonEvent_.timestamp = 0;
}

}  // namespace events

}  // namespace gfx

/* EOF */
