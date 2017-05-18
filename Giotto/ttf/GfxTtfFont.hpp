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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxTtfFontStyle.hpp"
#include "GfxTtfFontHinting.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFont final : public GfxRootClass
{
public:
    typedef sdl2::TTF_Font* SdlTypePtr;

    static const char ClassName[];

    GfxTtfFont();
    GfxTtfFont(std::string const& filename, int32_t pointsize);
    GfxTtfFont(std::string const& filename, int32_t pointsize, int32_t index);

    /* GfxTtfFont(SDL_RWops * src ...)
    GfxTtfFont(SDL_RWops * src ..., long index) */

    GfxTtfFont(GfxTtfFont const& other) = delete;
    GfxTtfFont(GfxTtfFont&& other);

    GfxTtfFont& operator=(GfxTtfFont const& other) = delete;
    GfxTtfFont& operator=(GfxTtfFont&& other);

    virtual ~GfxTtfFont();

    void openFont(std::string const& filename, int32_t pointsize) throw(std::runtime_error);
    void openFont(std::string const& filename, int32_t pointsize, int32_t index) throw(std::runtime_error);
    void closeFont(void);

    GfxTtfFontStyle const& getFontStyle(void) const;
    void setFontStyle(GfxTtfFontStyle const& fontstyle);

    GfxTtfFontHinting const& getFontHinting(void) const;
    void setFontHinting(GfxTtfFontHinting const& fonthinting);

    int32_t getFontOutline(void) const;
    void setFontOutline(int32_t const& outline);

    bool getFontKerning(void) const;
    void setFontKerning(bool const& kerning);

    int32_t getFontHeight(void) const;
    int32_t getFontAscent(void) const;
    int32_t getFontDescent(void) const;
    int32_t getFontLineSkip(void) const;

    int64_t getFontFaces(void) const;

    bool isFontFaceFixedWidth(void) const;

    std::string getFontFaceFamilyName(void) const;
    std::string getFontFaceStyleName(void) const;

    int32_t glyphIsProvided(uint16_t ch) const;
    bool glyphMetrics(uint16_t ch, int32_t * minx, int32_t * maxx, int32_t * miny,
                        int32_t * maxy, int32_t * advance) const;

    bool sizeText(std::string const& text, int32_t * w, int32_t * h) const;
    bool sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const;
    bool sizeUnicode(std::string text, int32_t * w, int32_t * h) const throw(std::runtime_error);

    void clear(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
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
