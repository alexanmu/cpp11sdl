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

#include "GfxDirection.hpp"

namespace gfx
{

namespace bgi
{

const char GfxDirection::ClassName[] = "GfxDirection";

GfxDirection::GfxDirection() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxDirection::GfxDirection(const ValueType dir) noexcept : GfxObject(ClassName)
{
    dir_ = static_cast<BgiType>(dir);
}

GfxDirection::GfxDirection(const BgiType dir) noexcept : GfxObject(ClassName)
{
    dir_ = dir;
}

GfxDirection::GfxDirection(GfxDirection const& other) noexcept : GfxObject(ClassName)
{
    dir_ = other.dir_;
}

GfxDirection::GfxDirection(GfxDirection&& other) noexcept : GfxObject(ClassName)
{
    dir_ = other.dir_;
    // Delete other's value
    other.clear();
}

GfxDirection& GfxDirection::operator=(GfxDirection const& other) noexcept
{
    if (this != &other)
    {
        dir_ = other.dir_;
    }
    return *this;
}

GfxDirection& GfxDirection::operator=(GfxDirection&& other) noexcept
{
    if (this != &other)
    {
        dir_ = other.dir_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxDirection::operator bool() const noexcept
{
    return true;
}

GfxDirection::ValueType GfxDirection::getValue(void) const noexcept
{
    return static_cast<ValueType>(dir_);
}

void GfxDirection::setValue(const ValueType dir) noexcept
{
    dir_ = static_cast<BgiType>(dir);
}

void GfxDirection::clear(void) noexcept
{
    dir_ = static_cast<BgiType>(ValueType::horizontalDirection);
}

GfxDirection::BgiType GfxDirection::getAsBgiType(void) const noexcept
{
    return dir_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
