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

GfxCommonEvent::GfxCommonEvent(GfxEventType const& evtype, const uint32_t timestamp) noexcept : GfxObject(ClassName)
{
    assert(evtype);

    evType_ = evtype;
    timeStamp_ = timestamp;
}

GfxCommonEvent::GfxCommonEvent(const SdlType ev) noexcept
{
    evType_.setEventType(ev.type);
    timeStamp_ = ev.timestamp;
}

GfxCommonEvent::GfxCommonEvent(const GfxCommonEvent& other) noexcept : GfxObject(ClassName)
{
    evType_ = other.evType_;
    timeStamp_ = other.timeStamp_;
}

GfxCommonEvent::GfxCommonEvent(GfxCommonEvent&& other) noexcept : GfxObject(ClassName)
{
    evType_ = other.evType_;
    timeStamp_ = other.timeStamp_;
    // Delete other's data
    other.clear();
}

GfxCommonEvent& GfxCommonEvent::operator=(const GfxCommonEvent& other) noexcept
{
    if (this != &other)
    {
        evType_ = other.evType_;
        timeStamp_ = other.timeStamp_;
    }
    return *this;
}

GfxCommonEvent& GfxCommonEvent::operator=(GfxCommonEvent&& other) noexcept
{
    if (this != &other)
    {
        evType_ = other.evType_;
        timeStamp_ = other.timeStamp_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxCommonEvent::operator bool() const noexcept
{
    return true;
}

GfxEventType const& GfxCommonEvent::getType(void) const noexcept
{
    return evType_;
}

uint32_t GfxCommonEvent::getTimeStamp(void) const noexcept
{
    return timeStamp_;
}

void GfxCommonEvent::setType(GfxEventType const& evtype) noexcept
{
    assert(evtype);

    evType_ = evtype;
}

void GfxCommonEvent::setTimeStamp(const uint32_t timestamp) noexcept
{
    timeStamp_ = timestamp;
}

void GfxCommonEvent::clear(void) noexcept
{
    evType_.clear();
    timeStamp_ = 0;
}

}  // namespace events

}  // namespace gfx

/* EOF */
