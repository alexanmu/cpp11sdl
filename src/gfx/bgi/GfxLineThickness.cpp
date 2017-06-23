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

#include "GfxLineThickness.hpp"

namespace gfx
{

namespace bgi
{

const char GfxLineThickness::ClassName[] = "GfxLineThickness";

GfxLineThickness::GfxLineThickness() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxLineThickness::GfxLineThickness(const ValueType thick) noexcept : GfxObject(ClassName)
{
    thick_ = static_cast<BgiType>(thick);
}

GfxLineThickness::GfxLineThickness(const BgiType thick) noexcept : GfxObject(ClassName)
{
    thick_ = thick;
}

GfxLineThickness::GfxLineThickness(GfxLineThickness const& other) noexcept : GfxObject(ClassName)
{
    thick_ = other.thick_;
}

GfxLineThickness::GfxLineThickness(GfxLineThickness&& other) noexcept : GfxObject(ClassName)
{
    thick_ = other.thick_;
    // Delete other's value
    other.clear();
}

GfxLineThickness& GfxLineThickness::operator=(GfxLineThickness const& other) noexcept
{
    if (this != &other)
    {
        thick_ = other.thick_;
    }
    return *this;
}

GfxLineThickness& GfxLineThickness::operator=(GfxLineThickness&& other) noexcept
{
    if (this != &other)
    {
        thick_ = other.thick_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxLineThickness::operator bool() const noexcept
{
    return true;
}

GfxLineThickness::ValueType GfxLineThickness::getValue(void) const noexcept
{
    return static_cast<ValueType>(thick_);
}

void GfxLineThickness::setValue(const ValueType thick) noexcept
{
    thick_ = static_cast<BgiType>(thick);
}

void GfxLineThickness::clear(void) noexcept
{
    thick_ = static_cast<BgiType>(ValueType::normalWidth);
}

GfxLineThickness::BgiType GfxLineThickness::getAsBgiType(void) const noexcept
{
    return thick_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
