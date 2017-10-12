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
#include <utility>

#include "GfxFonts.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxfonts::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxFonts::ClassName[] = "GfxFonts";

GfxFonts::GfxFonts() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxFonts::GfxFonts(const ValueType font) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    font_ = static_cast<BgiType>(font);
}

GfxFonts::GfxFonts(const BgiType font) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    font_ = font;
}

GfxFonts::GfxFonts(GfxFonts const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    font_ = other.font_;
}

GfxFonts::GfxFonts(GfxFonts&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    font_ = other.font_;
    // Delete other's value
    other.clear();
}

GfxFonts& GfxFonts::operator=(GfxFonts const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        font_ = other.font_;
    }
    return *this;
}

GfxFonts& GfxFonts::operator=(GfxFonts&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        font_ = other.font_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxFonts::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxFonts::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxFonts::ValueType GfxFonts::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(font_);
}

void GfxFonts::setValue(const ValueType font) noexcept
{
    LOG_TRACE_PRIO_LOW();

    font_ = static_cast<BgiType>(font);
}

bool GfxFonts::isDefaultFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::DEFAULT_FONT);
}

bool GfxFonts::isTriplexFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::TRIPLEX_FONT);
}

bool GfxFonts::isSmallFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::SMALL_FONT);
}

bool GfxFonts::isSanserifFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::SANSSERIF_FONT);
}

bool GfxFonts::isGothicFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::GOTHIC_FONT);
}

bool GfxFonts::isBigFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::BIG_FONT);
}

bool GfxFonts::isScriptFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::SCRIPT_FONT);
}

bool GfxFonts::isSimplexFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::SIMPLEX_FONT);
}

bool GfxFonts::isTriplexScriptFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::TRIPLEX_SCR_FONT);
}

bool GfxFonts::isComplexFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::COMPLEX_FONT);
}

bool GfxFonts::isEuropeanFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::EUROPEAN_FONT);
}

bool GfxFonts::isBoldFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (font_ == prv::GfxCanvasBgi::bgiFonts::BOLD_FONT);
}

void GfxFonts::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    font_ = static_cast<BgiType>(ValueType::defaultFont);
}

GfxFonts::BgiType GfxFonts::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return font_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
