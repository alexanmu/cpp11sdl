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
#include <string>

#include "GfxMessageBoxColorType.hpp"

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxColorType::ClassName[] = "GfxMessageBoxColorType";

GfxMessageBoxColorType::GfxMessageBoxColorType() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const SdlType type) noexcept : GfxObject(ClassName)
{
    assert(type >= 0);

    type_ = type;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(const ValueType type) noexcept :
            GfxObject(ClassName)
{
    type_ = static_cast<SdlType>(type);
}

GfxMessageBoxColorType::GfxMessageBoxColorType(GfxMessageBoxColorType const& other) noexcept :
            GfxObject(ClassName)
{
    type_ = other.type_;
}

GfxMessageBoxColorType::GfxMessageBoxColorType(GfxMessageBoxColorType&& other) noexcept :
            GfxObject(ClassName)
{
    type_ = other.type_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(GfxMessageBoxColorType const& other) noexcept
{
    if (this != &other)
    {
        type_ = other.type_;
    }
    return *this;
}

GfxMessageBoxColorType& GfxMessageBoxColorType::operator=(GfxMessageBoxColorType&& other) noexcept
{
    if (this != &other)
    {
        type_ = other.type_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMessageBoxColorType::operator bool() const noexcept
{
    return true;
}

GfxMessageBoxColorType::ValueType GfxMessageBoxColorType::getType(void) const noexcept
{
    return static_cast<ValueType>(type_);
}

void GfxMessageBoxColorType::clear(void) noexcept
{
    type_ = static_cast<SdlType>(ValueType::colorMax);
}

GfxMessageBoxColorType::SdlType GfxMessageBoxColorType::getAsSdllType(void) const noexcept
{
    return type_;
}

GfxMessageBoxColorType::SdlTypePtr GfxMessageBoxColorType::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&type_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */
