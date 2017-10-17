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

#include "GfxEventType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxeventtype::events::gfx");

namespace gfx
{

namespace events
{

const char GfxEventType::ClassName[] = "GfxEventType";

GfxEventType::GfxEventType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxEventType::GfxEventType(const ValueType evtype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    evType_ = static_cast<SdlType>(evtype);
}

GfxEventType::GfxEventType(const SdlType evtype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    evType_ = evtype;
}

GfxEventType::GfxEventType(const uint32_t evtype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    evType_ = static_cast<SdlType>(evtype);
}

GfxEventType::GfxEventType(const GfxEventType& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    evType_ = other.evType_;
}

GfxEventType::GfxEventType(GfxEventType&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    evType_ = other.evType_;
    // Delete other's data
    other.clear();
}

GfxEventType& GfxEventType::operator=(const GfxEventType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        evType_ = other.evType_;
    }
    return *this;
}

GfxEventType& GfxEventType::operator=(GfxEventType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        evType_ = other.evType_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxEventType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxEventType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxEventType::ValueType GfxEventType::getEventType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(evType_);
}

uint32_t GfxEventType::getEventTypeValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<uint32_t>(evType_);
}

void GfxEventType::setEventType(const ValueType ev) noexcept
{
    LOG_TRACE_PRIO_LOW();

    evType_ = static_cast<SdlType>(ev);
}

void GfxEventType::setEventType(const SdlType ev) noexcept
{
    LOG_TRACE_PRIO_LOW();

    evType_ = ev;
}

void GfxEventType::setEventType(const uint32_t ev) noexcept
{
    LOG_TRACE_PRIO_LOW();

    evType_ = static_cast<SdlType>(ev);
}

bool GfxEventType::isUserEvent(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    const uint32_t userEvValue = static_cast<const uint32_t>(ValueType::evUserEvent);
    const uint32_t lastEvValue = static_cast<const uint32_t>(ValueType::evLastEvent);
    uint32_t evTypeValue = static_cast<uint32_t>(evType_);

    return ((evTypeValue >= userEvValue) && (evTypeValue < lastEvValue));
}

bool GfxEventType::isFirstOrLastEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (static_cast<ValueType>(evType_) == ValueType::evFirstEvent) ||
            (static_cast<ValueType>(evType_) == ValueType::evLastEvent);
}

void GfxEventType::clear(void) noexcept
{
    evType_ = static_cast<SdlType>(false);
}

GfxEventType::SdlType GfxEventType::getAsSdlType(void) const noexcept
{
    return evType_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
