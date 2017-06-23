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

#include "GfxDrawingMode.hpp"

namespace gfx
{

namespace bgi
{

const char GfxDrawingMode::ClassName[] = "GfxDrawingMode";

GfxDrawingMode::GfxDrawingMode() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxDrawingMode::GfxDrawingMode(const ValueType dmode) noexcept : GfxObject(ClassName)
{
    dmode_ = static_cast<BgiType>(dmode);
}

GfxDrawingMode::GfxDrawingMode(const BgiType dmode) noexcept : GfxObject(ClassName)
{
    dmode_ = dmode;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode const& other) noexcept : GfxObject(ClassName)
{
    dmode_ = other.dmode_;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode&& other) noexcept : GfxObject(ClassName)
{
    dmode_ = other.dmode_;
    // Delete other's value
    other.clear();
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode const& other) noexcept
{
    if (this != &other)
    {
        dmode_ = other.dmode_;
    }
    return *this;
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode&& other) noexcept
{
    if (this != &other)
    {
        dmode_ = other.dmode_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxDrawingMode::operator bool() const noexcept
{
    return true;
}

GfxDrawingMode::ValueType GfxDrawingMode::getValue(void) const noexcept
{
    return static_cast<ValueType>(dmode_);
}

void GfxDrawingMode::setValue(const ValueType dmode) noexcept
{
    dmode_ = static_cast<BgiType>(dmode);
}

void GfxDrawingMode::clear(void) noexcept
{
    dmode_ = static_cast<BgiType>(ValueType::copyPut);
}

GfxDrawingMode::BgiType GfxDrawingMode::getAsBgiType(void) const noexcept
{
    return dmode_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
