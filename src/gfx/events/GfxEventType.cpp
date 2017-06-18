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

#include "GfxEventType.hpp"

namespace gfx
{

namespace events
{

const char GfxEventType::ClassName[] = "GfxEventType";

GfxEventType::GfxEventType() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxEventType::GfxEventType(const ValueType evtype) noexcept : GfxObject(ClassName)
{
    evType_ = static_cast<SdlType>(evtype);
}

GfxEventType::GfxEventType(const SdlType evtype) noexcept : GfxObject(ClassName)
{
    evType_ = evtype;
}

GfxEventType::GfxEventType(const GfxEventType& other) noexcept : GfxObject(ClassName)
{
    evType_ = other.evType_;
}

GfxEventType::GfxEventType(GfxEventType&& other) noexcept : GfxObject(ClassName)
{
    evType_ = other.evType_;
    // Delete other's data
    other.clear();
}

GfxEventType::operator bool() const noexcept
{
    return true;
}

GfxEventType& GfxEventType::operator=(const GfxEventType& other) noexcept
{
    if (this != &other)
    {
        evType_ = other.evType_;
    }
    return *this;
}

GfxEventType& GfxEventType::operator=(GfxEventType&& other) noexcept
{
    if (this != &other)
    {
        evType_ = other.evType_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxEventType::ValueType GfxEventType::getEventType(void) const noexcept
{
    return static_cast<ValueType>(false);
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
