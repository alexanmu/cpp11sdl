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

#include <cassert>
#include <string>
#include <utility>

#include "GfxTtfFontStyle.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttffontstyle::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfFontStyle::ClassName[] = "GfxTtfFontStyle";

GfxTtfFontStyle::GfxTtfFontStyle() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTtfFontStyle::GfxTtfFontStyle(const bool bold, const bool italic, const bool underline,
    const bool strikethrough) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
    if (bold == true)
    {
        setBold();
    }
    if (italic == true)
    {
        setItalic();
    }
    if (underline == true)
    {
        setUnderline();
    }
    if (strikethrough == true)
    {
        setStrikethrough();
    }
}

GfxTtfFontStyle::GfxTtfFontStyle(const SdlType style) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(style >= 0);

    style_ = style;
}

GfxTtfFontStyle::GfxTtfFontStyle(GfxTtfFontStyle const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    style_ = other.style_;
}

GfxTtfFontStyle::GfxTtfFontStyle(GfxTtfFontStyle&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    style_ = other.style_;
    // Delete other's data
    other.clear();
}

GfxTtfFontStyle& GfxTtfFontStyle::operator=(GfxTtfFontStyle const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        style_ = other.style_;
    }
    return *this;
}

GfxTtfFontStyle& GfxTtfFontStyle::operator=(GfxTtfFontStyle&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        style_ = other.style_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTtfFontStyle::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTtfFontStyle::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxTtfFontStyle::isNormal(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (style_ == 0);
}

bool GfxTtfFontStyle::isBold(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = style_ & TTF_STYLE_BOLD;

    return (r != 0);
}

bool GfxTtfFontStyle::isItalic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = style_ & TTF_STYLE_ITALIC;

    return (r != 0);
}

bool GfxTtfFontStyle::isUnderline(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = style_ & TTF_STYLE_UNDERLINE;

    return (r != 0);
}

bool GfxTtfFontStyle::isStrikethrough(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = style_ & TTF_STYLE_STRIKETHROUGH;

    return (r != 0);
}

void GfxTtfFontStyle::setBold(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ | TTF_STYLE_BOLD;
}

void GfxTtfFontStyle::resetBold(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ & ~TTF_STYLE_BOLD;
}

void GfxTtfFontStyle::setItalic(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ | TTF_STYLE_ITALIC;
}

void GfxTtfFontStyle::resetItalic(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ & ~TTF_STYLE_ITALIC;
}

void GfxTtfFontStyle::setUnderline(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ | TTF_STYLE_UNDERLINE;
}

void GfxTtfFontStyle::resetUnderline(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ & ~TTF_STYLE_UNDERLINE;
}

void GfxTtfFontStyle::setStrikethrough(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ | TTF_STYLE_STRIKETHROUGH;
}

void GfxTtfFontStyle::resetStrikethrough(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = style_ & ~TTF_STYLE_STRIKETHROUGH;
}

void GfxTtfFontStyle::setNormal(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    clear();
}

void GfxTtfFontStyle::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    style_ = static_cast<SdlType>(GfxTtfFontStyleValues::styleNormal);
}

GfxTtfFontStyle::SdlType GfxTtfFontStyle::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return style_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
