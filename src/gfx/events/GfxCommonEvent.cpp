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

#include <cassert>

#include "GfxCommonEvent.hpp"

namespace gfx
{

namespace events
{

const char GfxCommonEvent::ClassName[] = "GfxCommonEvent";

GfxCommonEvent::GfxCommonEvent() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxCommonEvent::GfxCommonEvent(const uint32_t type, const uint32_t timestamp) noexcept : GfxObject(ClassName)
{
    commonEvent_.type = type;
    commonEvent_.timestamp = timestamp;
}

GfxCommonEvent::GfxCommonEvent(const SdlType ev) noexcept : GfxObject(ClassName)
{
    commonEvent_ = ev;
}

GfxCommonEvent::GfxCommonEvent(const GfxCommonEvent& other) noexcept : GfxObject(ClassName)
{
    commonEvent_ = other.commonEvent_;
}

GfxCommonEvent::GfxCommonEvent(GfxCommonEvent&& other) noexcept : GfxObject(ClassName)
{
    commonEvent_ = other.commonEvent_;
    // Delete other's data
    other.clear();
}

GfxCommonEvent& GfxCommonEvent::operator=(const GfxCommonEvent& other) noexcept
{
    if (this != &other)
    {
        commonEvent_ = other.commonEvent_;
    }
    return *this;
}

GfxCommonEvent& GfxCommonEvent::operator=(GfxCommonEvent&& other) noexcept
{
    if (this != &other)
    {
        commonEvent_ = other.commonEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxCommonEvent::operator bool() const noexcept
{
    return true;
}

GfxEventType GfxCommonEvent::getType(void) const noexcept
{
    return GfxEventType(commonEvent_.type);
}

uint32_t GfxCommonEvent::getTimeStamp(void) const noexcept
{
    return commonEvent_.timestamp;
}

void GfxCommonEvent::setType(GfxEventType const& evtype) noexcept
{
    assert(evtype);

    commonEvent_.type = evtype.getEventTypeValue();
}

void GfxCommonEvent::setTimeStamp(const uint32_t timestamp) noexcept
{
    commonEvent_.timestamp = timestamp;
}

void GfxCommonEvent::clear(void) noexcept
{
    commonEvent_.type = 0;
    commonEvent_.timestamp = 0;
}

}  // namespace events

}  // namespace gfx

/* EOF */
