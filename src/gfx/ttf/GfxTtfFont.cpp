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
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxTtfFont.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttffont::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfFont::ClassName[] = "GfxTtfFont";
const char GfxTtfFont::kUnknown[] = "Unknown";

GfxTtfFont::GfxTtfFont() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTtfFont::GfxTtfFont(const std::string& filename, const int32_t pointsize) throw(std::runtime_error) :
            GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(filename.length() > 0);
    assert(pointsize > 0);

    ttf_ = TTF_OpenFont(filename.c_str(), pointsize);
    if (ttf_ == nullptr)
    {
        throw std::runtime_error("Unable to load font");
    }
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = -1;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
}

GfxTtfFont::GfxTtfFont(const std::string& filename, const int32_t pointsize, const int32_t index)
            throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(filename.length() > 0);
    assert(pointsize > 0);
    assert(index >= 0);

    SdlTypePtr ttfptr;

    ttf_ = nullptr;
    ttfptr = TTF_OpenFontIndex(filename.c_str(), pointsize, index);
    if (ttfptr == nullptr)
    {
        throw std::runtime_error("Unable to load font");
    }
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = index;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
    ttf_ = ttfptr;
}

GfxTtfFont::GfxTtfFont(GfxTtfFont&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    ttf_ = other.ttf_;
    fileName_ = other.fileName_;
    pointSize_ = other.pointSize_;
    index_ = other.index_;
    fontStyle_ = other.fontStyle_;
    fontHinting_ = other.fontHinting_;
    outline_ = other.outline_;
    kerning_ = other.kerning_;
    // Delete other's data
    other.clear();
}

GfxTtfFont& GfxTtfFont::operator=(GfxTtfFont&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        ttf_ = other.ttf_;
        fileName_ = other.fileName_;
        pointSize_ = other.pointSize_;
        index_ = other.index_;
        fontStyle_ = other.fontStyle_;
        fontHinting_ = other.fontHinting_;
        outline_ = other.outline_;
        kerning_ = other.kerning_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTtfFont::~GfxTtfFont(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (ttf_ != nullptr)
    {
        TTF_CloseFont(ttf_);
    }
    ttf_ = nullptr;
}

GfxTtfFont::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (ttf_ != nullptr);
}

std::string GfxTtfFont::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxTtfFont::openFont(const std::string& filename, const int32_t pointsize) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(filename.length() > 0);
    assert(pointsize > 0);

    SdlTypePtr tmpttf;

    tmpttf = TTF_OpenFont(filename.c_str(), pointsize);
    if (tmpttf == nullptr)
    {
        throw std::runtime_error("Unable to load font");
    }
    if (ttf_ != nullptr)
    {
        closeFont();
    }
    ttf_ = tmpttf;
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = -1;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
}

void GfxTtfFont::openFont(const std::string& filename, const int32_t pointsize,
                          const int32_t index) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(filename.length() > 0);
    assert(pointsize > 0);
    assert(index >= 0);

    SdlTypePtr tmpttf;

    tmpttf = TTF_OpenFontIndex(filename.c_str(), pointsize, index);
    if (tmpttf == nullptr)
    {
        throw std::runtime_error("Unable to load font");
    }
    if (ttf_ != nullptr)
    {
        closeFont();
    }
    ttf_ = tmpttf;
    fileName_ = filename;
    pointSize_ = pointsize;
    index_ = index;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
}

void GfxTtfFont::closeFont(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (ttf_ != nullptr)
    {
        TTF_CloseFont(ttf_);
        clear();
    }
}

void GfxTtfFont::setByteSwappedUnicode(const bool swapped) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    TTF_ByteSwappedUNICODE(static_cast<int>(swapped));
}

const GfxTtfFontStyle& GfxTtfFont::getFontStyle(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontStyle_;
}

void GfxTtfFont::setFontStyle(const GfxTtfFontStyle& fontstyle) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontStyle_ = fontstyle;
    if (ttf_ != nullptr)
    {
        TTF_SetFontStyle(ttf_, fontstyle.getAsSdlType());
    }
}

const GfxTtfFontHinting& GfxTtfFont::getFontHinting(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fontHinting_;
}

void GfxTtfFont::setFontHinting(const GfxTtfFontHinting& fonthinting) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fontHinting_ = fonthinting;
    if (ttf_ != nullptr)
    {
        TTF_SetFontHinting(ttf_, fonthinting.getAsSdlType());
    }
}

int32_t GfxTtfFont::getFontOutline(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return outline_;
}

void GfxTtfFont::setFontOutline(const int32_t outline) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(outline >= 0);

    outline_ = outline;
    if (ttf_ != nullptr)
    {
        TTF_SetFontOutline(ttf_, outline);
    }
}

bool GfxTtfFont::getFontKerning(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return kerning_;
}

void GfxTtfFont::setFontKerning(const bool kerning) noexcept
{
    LOG_TRACE_PRIO_LOW();

    kerning_ = kerning;
    if (ttf_ != nullptr)
    {
        TTF_SetFontKerning(ttf_, kerning);
    }
}

int32_t GfxTtfFont::getFontHeight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t h = 0;

    if (ttf_ != nullptr)
    {
        h = TTF_FontHeight(ttf_);
    }
    return h;
}

int32_t GfxTtfFont::getFontAscent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t a = 0;

    if (ttf_ != nullptr)
    {
        a = TTF_FontAscent(ttf_);
    }
    return a;
}

int32_t GfxTtfFont::getFontDescent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t d = 0;

    if (ttf_ != nullptr)
    {
        d = TTF_FontDescent(ttf_);
    }
    return d;
}

int32_t GfxTtfFont::getFontLineSkip(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t s = 0;

    if (ttf_ != nullptr)
    {
        s = TTF_FontLineSkip(ttf_);
    }
    return s;
}

int64_t GfxTtfFont::getFontFaces(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int64_t ff = 0;

    if (ttf_ != nullptr)
    {
        ff = TTF_FontFaces(ttf_);
    }
    return ff;
}

bool GfxTtfFont::isFontFaceFixedWidth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (TTF_FontFaceIsFixedWidth(ttf_) != 0);
    }
    return ret;
}

const std::string GfxTtfFont::getFontFaceFamilyName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    char * pChar = nullptr;

    if (ttf_ != nullptr)
    {
        pChar = TTF_FontFaceFamilyName(ttf_);
        if (pChar != nullptr)
        {
            return std::string(pChar);
        }
    }
    return std::string(kUnknown);
}

const std::string GfxTtfFont::getFontFaceStyleName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    char * pChar = nullptr;

    if (ttf_ != nullptr)
    {
        pChar = TTF_FontFaceStyleName(ttf_);
        if (pChar != nullptr)
        {
            return std::string(pChar);
        }
    }
    return std::string(kUnknown);
}

int32_t GfxTtfFont::glyphIsProvided(const uint16_t ch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool is = false;

    if (ttf_ != nullptr)
    {
        is = TTF_GlyphIsProvided(ttf_, ch);
    }
    return is;
}

bool GfxTtfFont::glyphMetrics(const uint16_t ch, int32_t * minx, int32_t * maxx, int32_t * miny,
                              int32_t * maxy, int32_t * advance) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(minx != nullptr);
    assert(maxx != nullptr);
    assert(miny != nullptr);
    assert(maxy != nullptr);
    assert(advance != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (TTF_GlyphMetrics(ttf_, ch, minx, maxx, miny, maxy, advance) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeText(const std::string& text, int32_t * w, int32_t * h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (TTF_SizeText(ttf_, text.c_str(), w, h) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeUtf8(const std::string& text, int32_t * w, int32_t * h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (TTF_SizeUTF8(ttf_, text.c_str(), w, h) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeUnicode(const std::string& text, int32_t * w, int32_t * h) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    throw std::runtime_error("Not supported");
}

GfxTtfFont::SdlTypePtr GfxTtfFont::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ttf_;
}

// Private methods
void GfxTtfFont::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    ttf_ = nullptr;
    fileName_ = "";
    pointSize_ = -1;
    index_ = -1;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
