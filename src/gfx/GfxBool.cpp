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

#include "GfxBool.hpp"

namespace gfx
{

const char GfxBool::ClassName[] = "GfxBool";

GfxBool::GfxBool() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxBool::GfxBool(const ValueType value) noexcept : GfxObject(ClassName)
{
    value_ = static_cast<SdlType>(value);
}

GfxBool::GfxBool(const SdlType value) noexcept : GfxObject(ClassName)
{
    value_ = value;
}

GfxBool::GfxBool(const bool value) noexcept : GfxObject(ClassName)
{
    value_ = static_cast<SdlType>(value);
}

GfxBool::GfxBool(const GfxBool& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
}

GfxBool::GfxBool(GfxBool&& other) noexcept : GfxObject(ClassName)
{
    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxBool::operator bool() const noexcept
{
    return true;
}

GfxBool& GfxBool::operator=(const GfxBool& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxBool& GfxBool::operator=(GfxBool&& other) noexcept
{
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxBool::getBool(void) const noexcept
{
    return static_cast<bool>(value_);
}

void GfxBool::clear(void) noexcept
{
    value_ = static_cast<SdlType>(false);
}

GfxBool::SdlType GfxBool::getAsSdlType(void) const noexcept
{
    return value_;
}

}  // namespace gfx

/* EOF */
