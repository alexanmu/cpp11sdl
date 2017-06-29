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

#include "GfxFonts.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

const char GfxFonts::ClassName[] = "GfxFonts";

GfxFonts::GfxFonts() noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    clear();
}

GfxFonts::GfxFonts(const ValueType font) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    font_ = static_cast<BgiType>(font);
}

GfxFonts::GfxFonts(const BgiType font) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    font_ = font;
}

GfxFonts::GfxFonts(GfxFonts const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    font_ = other.font_;
}

GfxFonts::GfxFonts(GfxFonts&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    font_ = other.font_;
    // Delete other's value
    other.clear();
}

GfxFonts& GfxFonts::operator=(GfxFonts const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        font_ = other.font_;
    }
    return *this;
}

GfxFonts& GfxFonts::operator=(GfxFonts&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        font_ = other.font_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxFonts::operator bool() const noexcept
{
    TRACE_P0();
    return true;
}

GfxFonts::ValueType GfxFonts::getValue(void) const noexcept
{
    TRACE_P0();
    return static_cast<ValueType>(font_);
}

void GfxFonts::setValue(const ValueType font) noexcept
{
    TRACE_P0();
    font_ = static_cast<BgiType>(font);
}

void GfxFonts::clear(void) noexcept
{
    TRACE_P0();
    font_ = static_cast<BgiType>(ValueType::defaultFont);
}

GfxFonts::BgiType GfxFonts::getAsBgiType(void) const noexcept
{
    TRACE_P0();
    return font_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
