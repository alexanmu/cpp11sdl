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
#include <cassert>
#include <cstdint>
#include <string>

#include "GfxTtfFont.hpp"

namespace gfx
{

namespace ttf
{

const char GfxTtfFont::ClassName[] = "GfxTtfFont";

GfxTtfFont::GfxTtfFont() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxTtfFont::GfxTtfFont(std::string const& filename, const int32_t pointsize) throw(std::runtime_error) :
            GfxObject(ClassName)
{
    assert(filename.length() > 0);
    assert(pointsize > 0);

    ttf_ = sdl2::TTF_OpenFont(filename.c_str(), pointsize);
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

GfxTtfFont::GfxTtfFont(std::string const& filename, const int32_t pointsize, const int32_t index)
            throw(std::runtime_error) : GfxObject(ClassName)
{
    assert(filename.length() > 0);
    assert(pointsize > 0);
    assert(index >= 0);

    ttf_ = sdl2::TTF_OpenFontIndex(filename.c_str(), pointsize, index);
    if (ttf_ == nullptr)
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
}

GfxTtfFont::GfxTtfFont(GfxTtfFont&& other) noexcept : GfxObject(ClassName)
{
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
    if (this != &other)
    {
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
    if (ttf_ != nullptr)
    {
        sdl2::TTF_CloseFont(ttf_);
    }
    ttf_ = nullptr;
}

GfxTtfFont::operator bool() const noexcept
{
    return (ttf_ != nullptr);
}

void GfxTtfFont::openFont(std::string const& filename, const int32_t pointsize) throw(std::runtime_error)
{
    assert(filename.length() > 0);
    assert(pointsize > 0);

    SdlTypePtr tmpttf;

    tmpttf = sdl2::TTF_OpenFont(filename.c_str(), pointsize);
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

void GfxTtfFont::openFont(std::string const& filename, const int32_t pointsize,
                          const int32_t index) throw(std::runtime_error)
{
    assert(filename.length() > 0);
    assert(pointsize > 0);
    assert(index >= 0);

    SdlTypePtr tmpttf;

    tmpttf = sdl2::TTF_OpenFontIndex(filename.c_str(), pointsize, index);
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
    if (ttf_ != nullptr)
    {
        sdl2::TTF_CloseFont(ttf_);
        clear();
    }
}

void GfxTtfFont::setByteSwappedUnicode(const bool swapped) const noexcept
{
    sdl2::TTF_ByteSwappedUNICODE(static_cast<int>(swapped));
}

GfxTtfFontStyle const& GfxTtfFont::getFontStyle(void) const noexcept
{
    return fontStyle_;
}

void GfxTtfFont::setFontStyle(GfxTtfFontStyle const& fontstyle) noexcept
{
    fontStyle_ = fontstyle;
    if (ttf_ != nullptr)
    {
        sdl2::TTF_SetFontStyle(ttf_, fontstyle.getAsSdlType());
    }
}

GfxTtfFontHinting const& GfxTtfFont::getFontHinting(void) const noexcept
{
    return fontHinting_;
}

void GfxTtfFont::setFontHinting(GfxTtfFontHinting const& fonthinting) noexcept
{
    fontHinting_ = fonthinting;
    if (ttf_ != nullptr)
    {
        sdl2::TTF_SetFontHinting(ttf_, fonthinting.getAsSdlType());
    }
}

int32_t GfxTtfFont::getFontOutline(void) const noexcept
{
    return outline_;
}

void GfxTtfFont::setFontOutline(const int32_t outline) noexcept
{
    assert(outline >= 0);

    outline_ = outline;
    if (ttf_ != nullptr)
    {
        sdl2::TTF_SetFontOutline(ttf_, outline);
    }
}

bool GfxTtfFont::getFontKerning(void) const noexcept
{
    return kerning_;
}

void GfxTtfFont::setFontKerning(const bool kerning) noexcept
{
    kerning_ = kerning;
    if (ttf_ != nullptr)
    {
        sdl2::TTF_SetFontKerning(ttf_, kerning);
    }
}

int32_t GfxTtfFont::getFontHeight(void) const noexcept
{
    int32_t h = 0;

    if (ttf_ != nullptr)
    {
        h = sdl2::TTF_FontHeight(ttf_);
    }
    return h;
}

int32_t GfxTtfFont::getFontAscent(void) const noexcept
{
    int32_t a = 0;

    if (ttf_ != nullptr)
    {
        a = sdl2::TTF_FontAscent(ttf_);
    }
    return a;
}

int32_t GfxTtfFont::getFontDescent(void) const noexcept
{
    int32_t d = 0;

    if (ttf_ != nullptr)
    {
        d = sdl2::TTF_FontDescent(ttf_);
    }
    return d;
}

int32_t GfxTtfFont::getFontLineSkip(void) const noexcept
{
    int32_t s = 0;

    if (ttf_ != nullptr)
    {
        s = sdl2::TTF_FontLineSkip(ttf_);
    }
    return s;
}

int64_t GfxTtfFont::getFontFaces(void) const noexcept
{
    int64_t ff = 0;

    if (ttf_ != nullptr)
    {
        ff = sdl2::TTF_FontFaces(ttf_);
    }
    return ff;
}

bool GfxTtfFont::isFontFaceFixedWidth(void) const noexcept
{
    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (sdl2::TTF_FontFaceIsFixedWidth(ttf_) != 0);
    }
    return ret;
}

std::string GfxTtfFont::getFontFaceFamilyName(void) const noexcept
{
    char * pChar = nullptr;

    if (ttf_ != nullptr)
    {
        pChar = sdl2::TTF_FontFaceFamilyName(ttf_);
        if (pChar != nullptr)
        {
            return std::string(pChar);
        }
    }
    return "";
}

std::string GfxTtfFont::getFontFaceStyleName(void) const noexcept
{
    char * pChar = nullptr;

    if (ttf_ != nullptr)
    {
        pChar = sdl2::TTF_FontFaceStyleName(ttf_);
        if (pChar != nullptr)
        {
            return std::string(pChar);
        }
    }
    return "";
}

int32_t GfxTtfFont::glyphIsProvided(const uint16_t ch) const noexcept
{
    bool is = false;

    if (ttf_ != nullptr)
    {
        is = sdl2::TTF_GlyphIsProvided(ttf_, ch);
    }
    return is;
}

bool GfxTtfFont::glyphMetrics(const uint16_t ch, int32_t * minx, int32_t * maxx, int32_t * miny,
                              int32_t * maxy, int32_t * advance) const noexcept
{
    assert(minx != nullptr);
    assert(maxx != nullptr);
    assert(miny != nullptr);
    assert(maxy != nullptr);
    assert(advance != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (sdl2::TTF_GlyphMetrics(ttf_, ch, minx, maxx, miny, maxy, advance) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeText(std::string const& text, int32_t * w, int32_t * h) const noexcept
{
    assert(w != nullptr);
    assert(h != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (sdl2::TTF_SizeText(ttf_, text.c_str(), w, h) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const noexcept
{
    assert(w != nullptr);
    assert(h != nullptr);

    bool ret = false;

    if (ttf_ != nullptr)
    {
        ret = (sdl2::TTF_SizeUTF8(ttf_, text.c_str(), w, h) == 0);
    }
    return ret;
}

bool GfxTtfFont::sizeUnicode(std::string const& text, int32_t * w, int32_t * h) const throw(std::runtime_error)
{
    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    throw std::runtime_error("Not supported");
}

void GfxTtfFont::clear(void) noexcept
{
    ttf_ = nullptr;
    fileName_ = "";
    pointSize_ = -1;
    index_ = -1;
    fontStyle_.clear();
    fontHinting_.clear();
    outline_ = 0;
    kerning_ = true;
}

GfxTtfFont::SdlTypePtr GfxTtfFont::getAsSdlTypePtr(void) const noexcept
{
    return ttf_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
