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

#include <string>

#include "GfxText.hpp"

namespace gfx
{

namespace bgi
{

const char GfxText::ClassName[] = "GfxText";

GfxText::GfxText() noexcept : GfxObject(ClassName), value_("")
{
    // Nothing to do
}

GfxText::GfxText(ValueType const& value) noexcept : GfxObject(ClassName), value_(value)
{
    // Nothing to do
}

GfxText::GfxText(GfxText const& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
}

GfxText::GfxText(GfxText&& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
    // Delete other's value
    other.value_ = "";
}

GfxText& GfxText::operator=(GfxText const& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxText& GfxText::operator=(GfxText&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = "";
    }
    return *this;
}

bool GfxText::operator==(GfxText const& other) const noexcept
{
    return (value_ == other.value_);
}

bool GfxText::operator>(GfxText const& other) const noexcept
{
    return (value_ > other.value_);
}

bool GfxText::operator<(GfxText const& other) const noexcept
{
    return (value_ < other.value_);
}

GfxText::operator bool() const noexcept
{
    return true;
}

GfxText::ValueType GfxText::getValue(void) const noexcept
{
    return value_;
}

void GfxText::setValue(ValueType const& value) noexcept
{
    value_ = value;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
