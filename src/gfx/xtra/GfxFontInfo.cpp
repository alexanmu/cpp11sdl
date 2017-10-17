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

#include "GfxFontInfo.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxfontinfo::xtra::gfx");

namespace gfx
{

namespace xtra
{

const char GfxFontInfo::ClassName[] = "GfxFontInfo";

const char GfxFontInfo::kDefaultFontName[] = "DefaultFontName";
const uint8_t GfxFontInfo::kDefaultFontSize = 16;
const int32_t GfxFontInfo::kDefaultFontOutline = 0;
const bool GfxFontInfo::kDefaultFontBold = false;
const bool GfxFontInfo::kDefaultFontItalic = false;
const bool GfxFontInfo::kDefaultFontUnderline = false;
const bool GfxFontInfo::kDefaultFontStrikethrough = false;
const int32_t GfxFontInfo::kDefaultFontHinting = TTF_HINTING_NORMAL;
const bool GfxFontInfo::kDefaultFontKerning = true;

const uint8_t GfxFontInfo::kMinFontSize = 4;

GfxFontInfo::GfxFontInfo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxFontInfo::GfxFontInfo(std::string const& fontName) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(fontName.length() > 0);

    clear();
    fontName_ = fontName;
}

GfxFontInfo::GfxFontInfo(std::string const& fontName, const uint8_t fontSize) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(fontName.length() > 0);
    assert(fontSize >= kMinFontSize);

    clear();
    fontName_ = fontName;
    fontSize_ = fontSize;
}

GfxFontInfo::GfxFontInfo(GfxFontInfo const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

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

GfxFontInfo::GfxFontInfo(GfxFontInfo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

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

GfxFontInfo& GfxFontInfo::operator=(GfxFontInfo const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
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

GfxFontInfo& GfxFontInfo::operator=(GfxFontInfo&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
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

GfxFontInfo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxFontInfo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxFontInfo::setFontName(std::string const& fontName) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(fontName.length() > 0);

    fontName_ = fontName;
}

void GfxFontInfo::setFontNameDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontName_ = kDefaultFontName;
}

std::string const& GfxFontInfo::getFontName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontName_;
}

void GfxFontInfo::setFontSize(const uint8_t fontSize) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(fontSize >= kMinFontSize);

    fontSize_ = fontSize;
}

void GfxFontInfo::setFontSizeDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontSize_ = kDefaultFontSize;
}

uint8_t GfxFontInfo::getFontSize(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontSize_;
}

void GfxFontInfo::setFontOutline(const int32_t fontOutline) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(fontOutline >= 0);

    fontOutline_ = fontOutline;
}

void GfxFontInfo::setFontOutlineDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontOutline_ = kDefaultFontOutline;
}

int32_t GfxFontInfo::getFontOutline(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontOutline_;
}

void GfxFontInfo::setFontBold(const bool fontBold) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontBold_ = fontBold;
}

void GfxFontInfo::setFontBoldDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontBold_ = kDefaultFontBold;
}

bool GfxFontInfo::getFontBold(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontBold_;
}

void GfxFontInfo::setFontItalic(const bool fontItalic) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontItalic_ = fontItalic;
}

void GfxFontInfo::setFontItalicDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontItalic_ = kDefaultFontItalic;
}

bool GfxFontInfo::getFontItalic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontItalic_;
}

void GfxFontInfo::setFontUnderline(const bool fontUnderline) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontUnderline_ = fontUnderline;
}

void GfxFontInfo::setFontUnderlineDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontUnderline_ = kDefaultFontUnderline;
}

bool GfxFontInfo::getFontUnderline(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontUnderline_;
}

void GfxFontInfo::setFontStrikethrough(const bool fontStrikethrough) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontStrikethrough_ = fontStrikethrough;
}

void GfxFontInfo::setFontStrikethroughDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontStrikethrough_ = kDefaultFontStrikethrough;
}

bool GfxFontInfo::getFontStrikethrough(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontStrikethrough_;
}

void GfxFontInfo::setFontHinting(const int32_t fontHinting) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(fontHinting >= 0);

    fontHinting_ = fontHinting;
}

void GfxFontInfo::setFontHintingDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontHinting_ = kDefaultFontHinting;
}

int32_t GfxFontInfo::getFontHinting(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontHinting_;
}

void GfxFontInfo::setFontKerning(const bool fontKerning) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontKerning_ = fontKerning;
}

void GfxFontInfo::setFontKerningDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontKerning_ = kDefaultFontKerning;
}

bool GfxFontInfo::getFontKerning(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontKerning_;
}

void GfxFontInfo::setDefault(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    clear();
}

void GfxFontInfo::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

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

}  // namespace xtra

}  // namespace gfx

/* EOF */
