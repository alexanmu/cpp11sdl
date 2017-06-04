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

#include "GfxRadius.hpp"

namespace gfx
{

namespace bgi
{

const char GfxRadius::ClassName[] = "GfxRadius";

GfxRadius::GfxRadius() noexcept : GfxRootClass(ClassName), value_(0)
{
    // Nothing to do
}

GfxRadius::GfxRadius(const GfxValueType value) noexcept : GfxRootClass(ClassName), value_(value)
{
    // Nothing to do
}

GfxRadius::GfxRadius(GfxRadius const& other) noexcept : GfxRootClass(ClassName)
{
    value_ = other.value_;
}

GfxRadius::GfxRadius(GfxRadius&& other) noexcept : GfxRootClass(ClassName)
{
    value_ = other.value_;
    // Delete other's value
    other.value_ = 0;
}

GfxRadius& GfxRadius::operator=(GfxRadius const& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxRadius& GfxRadius::operator=(GfxRadius&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = 0;
    }
    return *this;
}

bool GfxRadius::operator==(GfxRadius const& other) noexcept
{
    return (value_ == other.value_);
}

bool GfxRadius::operator>(GfxRadius const& other) noexcept
{
    return (value_ > other.value_);
}

bool GfxRadius::operator<(GfxRadius const& other) noexcept
{
    return (value_ < other.value_);
}

GfxRadius::operator bool() const noexcept
{
    return true;
}

GfxRadius::GfxValueType GfxRadius::getValue() const noexcept
{
    return value_;
}

void GfxRadius::setValue(const GfxValueType value) noexcept
{
    value_ = value;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
