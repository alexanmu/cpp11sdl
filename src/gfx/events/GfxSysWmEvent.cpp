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

#include "GfxSysWmEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxsyswmevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxSysWmEvent::ClassName[] = "GfxSysWmEvent";

GfxSysWmEvent::GfxSysWmEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxSysWmEvent::GfxSysWmEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    wmEvent_ = event;
}

GfxSysWmEvent::GfxSysWmEvent(GfxSysWmEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    wmEvent_ = other.wmEvent_;
}

GfxSysWmEvent::GfxSysWmEvent(GfxSysWmEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    wmEvent_ = other.wmEvent_;
    // Delete other's data
    other.clear();
}

GfxSysWmEvent& GfxSysWmEvent::operator=(GfxSysWmEvent const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        wmEvent_ = other.wmEvent_;
    }
    return *this;
}

GfxSysWmEvent& GfxSysWmEvent::operator=(GfxSysWmEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        wmEvent_ = other.wmEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxSysWmEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxSysWmEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxSysWmEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(wmEvent_.type, wmEvent_.timestamp);

    return cEv;
}

void GfxSysWmEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    wmEvent_ = event;
}

void GfxSysWmEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    wmEvent_.type = 0;
    wmEvent_.timestamp = 0;
}

GfxSysWmEvent::SdlType GfxSysWmEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)wmEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
