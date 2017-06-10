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

#include "GfxString.hpp"

namespace gfx
{

namespace bgi
{

const char GfxString::ClassName[] = "GfxString";

GfxString::GfxString() noexcept : GfxObject(ClassName), value_("")
{
    // Nothing to do
}

GfxString::GfxString(GfxValueType const& value) noexcept : GfxObject(ClassName), value_(value)
{
    // Nothing to do
}

GfxString::GfxString(GfxString const& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
}

GfxString::GfxString(GfxString&& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
    // Delete other's value
    other.value_ = "";
}

GfxString& GfxString::operator=(GfxString const& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxString& GfxString::operator=(GfxString&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = "";
    }
    return *this;
}

bool GfxString::operator==(GfxString const& other) const noexcept
{
    return (value_ == other.value_);
}

bool GfxString::operator>(GfxString const& other) const noexcept
{
    return (value_ > other.value_);
}

bool GfxString::operator<(GfxString const& other) const noexcept
{
    return (value_ < other.value_);
}

GfxString::operator bool() const noexcept
{
    return true;
}

GfxString::GfxValueType GfxString::getValue() const noexcept
{
    return value_;
}

void GfxString::setValue(GfxValueType const& value) noexcept
{
    value_ = value;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
