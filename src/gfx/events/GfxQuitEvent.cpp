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

#include "GfxQuitEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxquitevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxQuitEvent::ClassName[] = "GfxQuitEvent";

GfxQuitEvent::GfxQuitEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxQuitEvent::GfxQuitEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    qEvent_ = event;
}

GfxQuitEvent::GfxQuitEvent(const GfxQuitEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    qEvent_ = other.qEvent_;
}

GfxQuitEvent::GfxQuitEvent(GfxQuitEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    qEvent_ = other.qEvent_;
    // Delete other's data
    other.clear();
}

GfxQuitEvent& GfxQuitEvent::operator=(const GfxQuitEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        qEvent_ = other.qEvent_;
    }
    return *this;
}

GfxQuitEvent& GfxQuitEvent::operator=(GfxQuitEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        qEvent_ = other.qEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxQuitEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxQuitEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxQuitEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(qEvent_.type, qEvent_.timestamp);

    return cEv;
}

void GfxQuitEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    qEvent_ = event;
}

void GfxQuitEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    qEvent_.type = 0;
    qEvent_.timestamp = 0;
}

GfxQuitEvent::SdlType GfxQuitEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)qEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
