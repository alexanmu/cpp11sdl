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

#ifndef GfxTtfFont_hpp
#define GfxTtfFont_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxTtfFontStyle.hpp"
#include "GfxTtfFontHinting.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFont final : public GfxObject
{
public:
    typedef TTF_Font * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxTtfFont() noexcept;
    GfxTtfFont(std::string const& filename, const int32_t pointsize) throw(std::runtime_error);
    GfxTtfFont(std::string const& filename, const int32_t pointsize, const int32_t index) throw(std::runtime_error);

    // RWops not supported yet!
    /* GfxTtfFont(SDL_RWops * src ...)
    GfxTtfFont(SDL_RWops * src ..., long index) */

    GfxTtfFont(GfxTtfFont const& other) = delete;
    GfxTtfFont(GfxTtfFont&& other) noexcept;

    GfxTtfFont& operator=(GfxTtfFont const& other) = delete;
    GfxTtfFont& operator=(GfxTtfFont&& other) noexcept;

    virtual ~GfxTtfFont() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void openFont(std::string const& filename, const int32_t pointsize) throw(std::runtime_error);
    void openFont(std::string const& filename, const int32_t pointsize, const int32_t index) throw(std::runtime_error);
    void closeFont(void) noexcept;

    void setByteSwappedUnicode(const bool swapped) const noexcept;

    GfxTtfFontStyle const& getFontStyle(void) const noexcept;
    void setFontStyle(GfxTtfFontStyle const& fontstyle) noexcept;

    GfxTtfFontHinting const& getFontHinting(void) const noexcept;
    void setFontHinting(GfxTtfFontHinting const& fonthinting) noexcept;

    int32_t getFontOutline(void) const noexcept;
    void setFontOutline(const int32_t outline) noexcept;

    bool getFontKerning(void) const noexcept;
    void setFontKerning(const bool kerning) noexcept;

    int32_t getFontHeight(void) const noexcept;
    int32_t getFontAscent(void) const noexcept;
    int32_t getFontDescent(void) const noexcept;
    int32_t getFontLineSkip(void) const noexcept;

    int64_t getFontFaces(void) const noexcept;

    bool isFontFaceFixedWidth(void) const noexcept;

    std::string getFontFaceFamilyName(void) const noexcept;
    std::string getFontFaceStyleName(void) const noexcept;

    int32_t glyphIsProvided(const uint16_t ch) const noexcept;
    bool glyphMetrics(const uint16_t ch, int32_t * minx, int32_t * maxx, int32_t * miny,
                      int32_t * maxy, int32_t * advance) const noexcept;

    bool sizeText(std::string const& text, int32_t * w, int32_t * h) const noexcept;
    bool sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const noexcept;
    bool sizeUnicode(std::string const& text, int32_t * w, int32_t * h) const throw(std::runtime_error);

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void clear(void) noexcept;

    SdlTypePtr ttf_;
    std::string fileName_;
    int32_t pointSize_;
    int32_t index_;
    GfxTtfFontStyle fontStyle_;
    GfxTtfFontHinting fontHinting_;
    int32_t outline_;
    bool kerning_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFont_hpp
