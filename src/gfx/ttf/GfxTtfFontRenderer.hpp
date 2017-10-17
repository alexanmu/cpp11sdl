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

#ifndef GfxTtfFontRenderer_hpp
#define GfxTtfFontRenderer_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxTtfFont.hpp"
#include "GfxSurface.hpp"
#include "GfxColor.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontRenderer final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxTtfFontRenderer() noexcept;
    explicit GfxTtfFontRenderer(GfxTtfFont * ttf) throw(std::runtime_error);

    GfxTtfFontRenderer(GfxTtfFontRenderer const& other) noexcept;
    GfxTtfFontRenderer(GfxTtfFontRenderer&& other) noexcept;

    GfxTtfFontRenderer& operator=(GfxTtfFontRenderer const& other) noexcept;
    GfxTtfFontRenderer& operator=(GfxTtfFontRenderer&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    GfxTtfFont * getFont(void) const noexcept;
    void setFont(GfxTtfFont * ttf) throw(std::runtime_error);

    bool sizeText(std::string const& text, int32_t * w, int32_t * h) const noexcept;
    bool sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const noexcept;
    bool sizeUnicode(std::string const& text, int32_t * w, int32_t * h) const throw(std::runtime_error);

    surface::GfxSurface * renderTextSolid(std::string const& text, gfx::pixels::GfxColor const& fg) const noexcept;
    surface::GfxSurface * renderTextUtf8Solid(std::string const& text, gfx::pixels::GfxColor const& fg) const noexcept;
    surface::GfxSurface * renderTextUnicodeSolid(std::string const& text, gfx::pixels::GfxColor const& fg)
                                                const throw(std::runtime_error);
    surface::GfxSurface * renderGlyphSolid(const uint16_t ch, gfx::pixels::GfxColor const& fg) const noexcept;

    surface::GfxSurface * renderTextShaded(std::string const& text, gfx::pixels::GfxColor const& fg,
                                        gfx::pixels::GfxColor const& bg) const noexcept;
    surface::GfxSurface * renderTextUtf8Shaded(std::string const& text, gfx::pixels::GfxColor const& fg,
                                        gfx::pixels::GfxColor const& bg) const noexcept;
    surface::GfxSurface * renderTextUnicodeShaded(std::string const& text, gfx::pixels::GfxColor const& fg,
                                        gfx::pixels::GfxColor const& bg) const throw(std::runtime_error);
    surface::GfxSurface * renderGlyphShaded(uint16_t ch, gfx::pixels::GfxColor const& fg,
                                        gfx::pixels::GfxColor const& bg) const noexcept;

    surface::GfxSurface * renderTextBlended(std::string const& text, gfx::pixels::GfxColor const& fg) const noexcept;
    surface::GfxSurface * renderTextUtf8Blended(std::string const& text,
                                                gfx::pixels::GfxColor const& fg) const noexcept;
    surface::GfxSurface * renderTextUnicodeBlended(std::string const& text, gfx::pixels::GfxColor const& fg)
                                                const throw(std::runtime_error);
    surface::GfxSurface * renderGlyphBlended(const uint16_t ch, gfx::pixels::GfxColor const& fg) const noexcept;
private:
    GfxTtfFont * ttf_;
};

}  // namespace ttf

}  // namespace gfx

#endif /* GfxTtfFontRenderer_hpp */
