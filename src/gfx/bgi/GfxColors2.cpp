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

GfxColors2::GfxColors2(const ValueType clr) noexcept : GfxObject(ClassName)
{
    clr_ = clr;
}

GfxColors2::GfxColors2(const BgiType clr) noexcept : GfxObject(ClassName)
{
    clr_ = clr;
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

bool GfxColors2::isCustomColor(void) const noexcept
{
    return !isBgiColor();
}

void GfxColors2::clear(void) noexcept
{
    clr_ = static_cast<BgiType>(0);
}

GfxColors2::BgiType GfxColors2::getAsBgiType(void) const noexcept
{
    return getBgiColor();
}

bool GfxColors2::isBgiColor(void) const noexcept
{
    if (clr_ == kBlack) return true;
    if (clr_ == kBlue) return true;
    if (clr_ == kGreen) return true;
    if (clr_ == kCyan) return true;
    if (clr_ == kRed) return true;
    if (clr_ == kMagenta) return true;
    if (clr_ == kBrown) return true;
    if (clr_ == kLightGray) return true;
    if (clr_ == kDarkGray) return true;
    if (clr_ == kLightBlue) return true;
    if (clr_ == kLightGreen) return true;
    if (clr_ == kLightCyan) return true;
    if (clr_ == kLightRed) return true;
    if (clr_ == kLightMagenta) return true;
    if (clr_ == kYellow) return true;
    if (clr_ == kWhite) return true;
    return false;
}

GfxColors2::BgiType GfxColors2::getBgiColor(void) const noexcept
{
    if (clr_ == GfxColors2::kBlack) return prv::GfxCanvasBgi::BLACK;
    if (clr_ == GfxColors2::kBlue) return prv::GfxCanvasBgi::BLUE;
    if (clr_ == GfxColors2::kGreen) return prv::GfxCanvasBgi::GREEN;
    if (clr_ == GfxColors2::kCyan) return prv::GfxCanvasBgi::CYAN;
    if (clr_ == GfxColors2::kRed) return prv::GfxCanvasBgi::RED;
    if (clr_ == GfxColors2::kMagenta) return prv::GfxCanvasBgi::MAGENTA;
    if (clr_ == GfxColors2::kBrown) return prv::GfxCanvasBgi::BROWN;
    if (clr_ == GfxColors2::kLightGray) return prv::GfxCanvasBgi::LIGHTGRAY;
    if (clr_ == GfxColors2::kDarkGray) return prv::GfxCanvasBgi::DARKGRAY;
    if (clr_ == GfxColors2::kLightBlue) return prv::GfxCanvasBgi::LIGHTBLUE;
    if (clr_ == GfxColors2::kLightGreen) return prv::GfxCanvasBgi::LIGHTGREEN;
    if (clr_ == GfxColors2::kLightCyan) return prv::GfxCanvasBgi::LIGHTCYAN;
    if (clr_ == GfxColors2::kLightRed) return prv::GfxCanvasBgi::LIGHTRED;
    if (clr_ == GfxColors2::kLightMagenta) return prv::GfxCanvasBgi::LIGHTMAGENTA;
    if (clr_ == GfxColors2::kYellow) return prv::GfxCanvasBgi::YELLOW;
    if (clr_ == GfxColors2::kWhite) return prv::GfxCanvasBgi::WHITE;
    // CUSTOM color; _FG, _BG or _FILL; I choose _FG
    return prv::GfxCanvasBgi::CUSTOM_FG;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
