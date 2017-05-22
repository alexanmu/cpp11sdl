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

#include "GfxTtfFontStyle.hpp"

namespace gfx
{

namespace ttf
{

const char GfxTtfFontStyle::ClassName[] = "GfxTtfFontStyle";

GfxTtfFontStyle::GfxTtfFontStyle() : GfxRootClass(ClassName)
{
    clear();
}

GfxTtfFontStyle::GfxTtfFontStyle(bool bold, bool italic, bool underline, bool strikethrough) : GfxRootClass(ClassName)
{
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

GfxTtfFontStyle::GfxTtfFontStyle(SdlType style) : GfxRootClass(ClassName)
{
    assert(style >= 0);

    style_ = style;
}

GfxTtfFontStyle::GfxTtfFontStyle(GfxTtfFontStyle const& other) : GfxRootClass(ClassName)
{
    style_ = other.style_;
}

GfxTtfFontStyle::GfxTtfFontStyle(GfxTtfFontStyle&& other) : GfxRootClass(ClassName)
{
    style_ = other.style_;
    // Delete other's data
    other.clear();
}

GfxTtfFontStyle& GfxTtfFontStyle::operator=(GfxTtfFontStyle const& other)
{
    if (this != &other)
    {
        style_ = other.style_;
    }
    return *this;
}

GfxTtfFontStyle& GfxTtfFontStyle::operator=(GfxTtfFontStyle&& other)
{
    if (this != &other)
    {
        style_ = other.style_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTtfFontStyle::operator bool() const
{
    return true;
}

bool GfxTtfFontStyle::isNormal(void) const
{
    return (style_ == 0);
}

bool GfxTtfFontStyle::isBold(void) const
{
    uint32_t r = style_ & TTF_STYLE_BOLD;

    return (r != 0);
}

bool GfxTtfFontStyle::isItalic(void) const
{
    uint32_t r = style_ & TTF_STYLE_ITALIC;

    return (r != 0);
}

bool GfxTtfFontStyle::isUnderline(void) const
{
    uint32_t r = style_ & TTF_STYLE_UNDERLINE;

    return (r != 0);
}

bool GfxTtfFontStyle::isStrikethrough(void) const
{
    uint32_t r = style_ & TTF_STYLE_STRIKETHROUGH;

    return (r != 0);
}

void GfxTtfFontStyle::setBold(void)
{
    style_ = style_ | TTF_STYLE_BOLD;
}

void GfxTtfFontStyle::resetBold(void)
{
    style_ = style_ & ~TTF_STYLE_BOLD;
}

void GfxTtfFontStyle::setItalic(void)
{
    style_ = style_ | TTF_STYLE_ITALIC;
}

void GfxTtfFontStyle::resetItalic(void)
{
    style_ = style_ & ~TTF_STYLE_ITALIC;
}

void GfxTtfFontStyle::setUnderline(void)
{
    style_ = style_ | TTF_STYLE_UNDERLINE;
}

void GfxTtfFontStyle::resetUnderline(void)
{
    style_ = style_ & ~TTF_STYLE_UNDERLINE;
}

void GfxTtfFontStyle::setStrikethrough(void)
{
    style_ = style_ | TTF_STYLE_STRIKETHROUGH;
}

void GfxTtfFontStyle::resetStrikethrough(void)
{
    style_ = style_ & ~TTF_STYLE_STRIKETHROUGH;
}

void GfxTtfFontStyle::setNormal(void)
{
    clear();
}

void GfxTtfFontStyle::clear(void)
{
    style_ = static_cast<SdlType>(GfxTtfFontStyleValues::styleNormal);
}

GfxTtfFontStyle::SdlType GfxTtfFontStyle::getAsSdlType(void) const
{
    return style_;
}

GfxTtfFontStyle::SdlTypePtr GfxTtfFontStyle::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&style_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
