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

#include "GfxDropEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxdropevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxDropEvent::ClassName[] = "GfxDropEvent";

GfxDropEvent::GfxDropEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxDropEvent::GfxDropEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    dEvent_ = event;
}

GfxDropEvent::GfxDropEvent(const GfxDropEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    dEvent_ = other.dEvent_;
}

GfxDropEvent::GfxDropEvent(GfxDropEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    dEvent_ = other.dEvent_;
    // Delete other's data
    other.clear();
}

GfxDropEvent& GfxDropEvent::operator=(const GfxDropEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        dEvent_ = other.dEvent_;
    }
    return *this;
}

GfxDropEvent& GfxDropEvent::operator=(GfxDropEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        dEvent_ = other.dEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxDropEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxDropEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxDropEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(dEvent_.type, dEvent_.timestamp);

    return cEv;
}

uint32_t GfxDropEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dEvent_.windowID;
}

const std::string GfxDropEvent::getFile(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string str { "" };

    if (dEvent_.file != NULL)
    {
        str = dEvent_.file;
        SDL_free(dEvent_.file);
    }
    return str;
}

void GfxDropEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dEvent_ = event;
}

void GfxDropEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dEvent_.type = 0;
    dEvent_.timestamp = 0;
    dEvent_.file = NULL;
    dEvent_.windowID = 0;
}

GfxDropEvent::SdlType GfxDropEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)dEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
