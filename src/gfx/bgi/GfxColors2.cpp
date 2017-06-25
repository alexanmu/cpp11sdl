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

#include <stdexcept>

#include "GfxColors2.hpp"

namespace gfx
{

namespace bgi
{

const char GfxColors2::ClassName[] = "GfxColors2";

GfxColors2::GfxColors2() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxColors2::GfxColors2(const ValueType clr, uint32_t argb) noexcept : GfxObject(ClassName)
{
    clr_ = static_cast<BgiType>(clr);
    argb_ = argb;
}

GfxColors2::GfxColors2(const BgiType clr, uint32_t argb) noexcept : GfxObject(ClassName)
{
    clr_ = clr;
    argb_ = argb;
}

GfxColors2::GfxColors2(GfxColors2 const& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
}

GfxColors2::GfxColors2(GfxColors2&& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
    // Delete other's value
    other.clear();
}

GfxColors2& GfxColors2::operator=(GfxColors2 const& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
    }
    return *this;
}

GfxColors2& GfxColors2::operator=(GfxColors2&& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxColors2::operator bool() const noexcept
{
    return true;
}

GfxColors2::ValueType GfxColors2::getValue(void) const noexcept
{
    return static_cast<ValueType>(clr_);
}

void GfxColors2::setValue(const ValueType clr) noexcept
{
    clr_ = static_cast<BgiType>(clr);
}

uint32_t GfxColors2::getARGB(void) const throw(std::runtime_error)
{
    ValueType clr = static_cast<ValueType>(clr_);

    if ((clr != ValueType::customForeground) && (clr != ValueType::customBackground) &&
        (clr != ValueType::customFill))
    {
        throw std::runtime_error("argb not set; standard color");
    }
    return argb_;
}

void GfxColors2::setARGB(const uint32_t argb) noexcept
{
    argb_ = argb;
}

void GfxColors2::clear(void) noexcept
{
    clr_ = static_cast<BgiType>(ValueType::black);
    argb_ = 0;
}

GfxColors2::BgiType GfxColors2::getAsBgiType(void) const noexcept
{
    return clr_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
