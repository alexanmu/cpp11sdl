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

#include "GfxFontInfo.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace supp
{

const char GfxFontInfo::ClassName[] = "GfxFontInfo";

const char GfxFontInfo::kDefaultFontName[] = "Raleway";
const uint8_t GfxFontInfo::kDefaultFontSize = 16;
const int32_t GfxFontInfo::kDefaultFontOutline = 0;
const bool GfxFontInfo::kDefaultFontBold = false;
const bool GfxFontInfo::kDefaultFontItalic = false;
const bool GfxFontInfo::kDefaultFontUnderline = false;
const bool GfxFontInfo::kDefaultFontStrikethrough = false;
const int32_t GfxFontInfo::kDefaultFontHinting = TTF_HINTING_NORMAL;
const bool GfxFontInfo::kDefaultFontKerning = true;

const uint8_t GfxFontInfo::kMinFontSize = 4;

GfxFontInfo::GfxFontInfo() : GfxRootClass(ClassName)
{
    clear();
}

GfxFontInfo::GfxFontInfo(std::string const& fontName) : GfxRootClass(ClassName)
{
    assert(fontName.length() > 0);

    clear();
    fontName_ = fontName;
}

GfxFontInfo::GfxFontInfo(std::string const& fontName, const uint8_t fontSize) : GfxRootClass(ClassName)
{
    assert(fontName.length() > 0);
    assert(fontSize >= kMinFontSize);

    clear();
    fontName_ = fontName;
    fontSize_ = fontSize;
}

GfxFontInfo::GfxFontInfo(GfxFontInfo const& other) : GfxRootClass(ClassName)
{
    fontName_ = other.fontName_;
    fontSize_ = other.fontSize_;
    fontOutline_ = other.fontOutline_;
    fontBold_ = other.fontBold_;
    fontItalic_ = other.fontItalic_;
    fontUnderline_ = other.fontUnderline_;
    fontStrikethrough_ = other.fontStrikethrough_;
    fontHinting_ = other.fontHinting_;
    fontKerning_ = other.fontKerning_;
}

GfxFontInfo::GfxFontInfo(GfxFontInfo&& other) : GfxRootClass(ClassName)
{
    fontName_ = other.fontName_;
    fontSize_ = other.fontSize_;
    fontOutline_ = other.fontOutline_;
    fontBold_ = other.fontBold_;
    fontItalic_ = other.fontItalic_;
    fontUnderline_ = other.fontUnderline_;
    fontStrikethrough_ = other.fontStrikethrough_;
    fontHinting_ = other.fontHinting_;
    fontKerning_ = other.fontKerning_;
    // Delete other's data
    other.clear();
}

GfxFontInfo& GfxFontInfo::operator=(GfxFontInfo const& other)
{
    if (this != &other)
    {
        fontName_ = other.fontName_;
        fontSize_ = other.fontSize_;
        fontOutline_ = other.fontOutline_;
        fontBold_ = other.fontBold_;
        fontItalic_ = other.fontItalic_;
        fontUnderline_ = other.fontUnderline_;
        fontStrikethrough_ = other.fontStrikethrough_;
        fontHinting_ = other.fontHinting_;
        fontKerning_ = other.fontKerning_;
    }
    return *this;
}

GfxFontInfo& GfxFontInfo::operator=(GfxFontInfo&& other)
{
    if (this != &other)
    {
        fontName_ = other.fontName_;
        fontSize_ = other.fontSize_;
        fontOutline_ = other.fontOutline_;
        fontBold_ = other.fontBold_;
        fontItalic_ = other.fontItalic_;
        fontUnderline_ = other.fontUnderline_;
        fontStrikethrough_ = other.fontStrikethrough_;
        fontHinting_ = other.fontHinting_;
        fontKerning_ = other.fontKerning_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxFontInfo::operator bool() const
{
    return true;
}

void GfxFontInfo::setFontName(std::string const& fontName)
{
    assert(fontName.length() > 0);

    fontName_ = fontName;
}

void GfxFontInfo::setFontNameDefault(void)
{
    fontName_ = kDefaultFontName;
}

std::string const& GfxFontInfo::getFontName(void) const
{
    return fontName_;
}

void GfxFontInfo::setFontSize(const uint8_t fontSize)
{
    assert(fontSize >= kMinFontSize);

    fontSize_ = fontSize;
}

void GfxFontInfo::setFontSizeDefault(void)
{
    fontSize_ = kDefaultFontSize;
}

uint8_t GfxFontInfo::getFontSize(void) const
{
    return fontSize_;
}

void GfxFontInfo::setFontOutline(const int32_t fontOutline)
{
    assert(fontOutline >= 0);

    fontOutline_ = fontOutline;
}

void GfxFontInfo::setFontOutlineDefault(void)
{
    fontOutline_ = kDefaultFontOutline;
}

int32_t GfxFontInfo::getFontOutline(void) const
{
    return fontOutline_;
}

void GfxFontInfo::setFontBold(const bool fontBold)
{
    fontBold_ = fontBold;
}

void GfxFontInfo::setFontBoldDefault(void)
{
    fontBold_ = kDefaultFontBold;
}

bool GfxFontInfo::getFontBold(void) const
{
    return fontBold_;
}

void GfxFontInfo::setFontItalic(const bool fontItalic)
{
    fontItalic_ = fontItalic;
}

void GfxFontInfo::setFontItalicDefault(void)
{
    fontItalic_ = kDefaultFontItalic;
}

bool GfxFontInfo::getFontItalic(void) const
{
    return fontItalic_;
}

void GfxFontInfo::setFontUnderline(const bool fontUnderline)
{
    fontUnderline_ = fontUnderline;
}

void GfxFontInfo::setFontUnderlineDefault(void)
{
    fontUnderline_ = kDefaultFontUnderline;
}

bool GfxFontInfo::getFontUnderline(void) const
{
    return fontUnderline_;
}

void GfxFontInfo::setFontStrikethrough(const bool fontStrikethrough)
{
    fontStrikethrough_ = fontStrikethrough;
}

void GfxFontInfo::setFontStrikethroughDefault(void)
{
    fontStrikethrough_ = kDefaultFontStrikethrough;
}

bool GfxFontInfo::getFontStrikethrough(void) const
{
    return fontStrikethrough_;
}

void GfxFontInfo::setFontHinting(const int32_t fontHinting)
{
    assert(fontHinting >= 0);

    fontHinting_ = fontHinting;
}

void GfxFontInfo::setFontHintingDefault(void)
{
    fontHinting_ = kDefaultFontHinting;
}

int32_t GfxFontInfo::getFontHinting(void) const
{
    return fontHinting_;
}

void GfxFontInfo::setFontKerning(const bool fontKerning)
{
    fontKerning_ = fontKerning;
}

void GfxFontInfo::setFontKerningDefault(void)
{
    fontKerning_ = kDefaultFontKerning;
}

bool GfxFontInfo::getFontKerning(void) const
{
    return fontKerning_;
}

void GfxFontInfo::clear(void)
{
    fontName_ = kDefaultFontName;
    fontSize_ = kDefaultFontSize;
    fontOutline_ = kDefaultFontOutline;
    fontBold_ = kDefaultFontBold;
    fontItalic_ = kDefaultFontItalic;
    fontUnderline_ = kDefaultFontUnderline;
    fontStrikethrough_ = kDefaultFontStrikethrough;
    fontHinting_ = kDefaultFontHinting;
    fontKerning_ = kDefaultFontKerning;
}

}  // namespace supp

}  // namespace gfx

/* EOF */
