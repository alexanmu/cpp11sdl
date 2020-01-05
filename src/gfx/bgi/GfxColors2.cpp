/*
 Giotto
 Copyright (C) 2020 George Oros
 
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
#include <string>
#include <utility>

#include "GfxColors2.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcolors2::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxColors2::ClassName[] = "GfxColors2";

const uint32_t GfxColors2::kColors[kNumColors] =
{
    0xff000000,
    0xff0000ff,
    0xff00ff00,
    0xff00ffff,
    0xffff0000,
    0xffff00ff,
    0xffa52a2a,
    0xffd3d3d3,
    0xffa9a9a9,
    0xffadd8e6,
    0xff90ee90,
    0xffe0ffff,
    0xfff08080,
    0xffdb7093,
    0xffffff00,
    0xffffffff
};

GfxColors2::GfxColors2() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxColors2::GfxColors2(const ValueType clr) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clr_ = clr;
}

GfxColors2::GfxColors2(const BgiType clr) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clr_ = clr;
}

GfxColors2::GfxColors2(const GfxColors2& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    clr_ = other.clr_;
}

GfxColors2::GfxColors2(GfxColors2&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    clr_ = other.clr_;
    // Delete other's value
    other.clear();
}

GfxColors2& GfxColors2::operator=(const GfxColors2& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        clr_ = other.clr_;
    }
    return *this;
}

GfxColors2& GfxColors2::operator=(GfxColors2&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        clr_ = other.clr_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxColors2::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxColors2::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxColors2::ValueType GfxColors2::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(clr_);
}

void GfxColors2::setValue(const ValueType clr) noexcept
{
    LOG_TRACE_PRIO_LOW();

    clr_ = static_cast<BgiType>(clr);
}

bool GfxColors2::isCustomColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return !isBgiColor();
}

void GfxColors2::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    clr_ = static_cast<BgiType>(0);
}

GfxColors2::BgiType GfxColors2::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return getBgiColor();
}

bool GfxColors2::isBgiColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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
    LOG_TRACE_PRIO_LOW();

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
