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

#include "GfxRootClass.hpp"
#include "GfxTtfFont.hpp"
#include "GfxSurface.hpp"
#include "GfxColor.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontRenderer final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxTtfFontRenderer() = delete;
    explicit GfxTtfFontRenderer(GfxTtfFont * ttf) throw(std::runtime_error);

    GfxTtfFontRenderer(GfxTtfFontRenderer const&) = delete;
    GfxTtfFontRenderer(GfxTtfFontRenderer&&) = delete;

    GfxTtfFontRenderer& operator=(GfxTtfFontRenderer const&) = delete;
    GfxTtfFontRenderer& operator=(GfxTtfFontRenderer&&) = delete;

    virtual explicit operator bool() const;

    GfxTtfFont * getFont(void) const;
    void setFont(GfxTtfFont * ttf) throw(std::runtime_error);

    bool sizeText(std::string const& text, int32_t * w, int32_t * h) const;
    bool sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const;
    bool sizeUnicode(std::string text, int32_t * w, int32_t * h) const throw(std::runtime_error);

    gfx::GfxSurface * renderTextSolid(std::string const& text, gfx::GfxColor const& fg) const;
    gfx::GfxSurface * renderTextUtf8Solid(std::string const& text, gfx::GfxColor const& fg) const;
    gfx::GfxSurface * renderTextUnicodeSolid(std::string text, gfx::GfxColor fg) const throw(std::runtime_error);
    gfx::GfxSurface * renderGlyphSolid(uint16_t ch, gfx::GfxColor const& fg) const;

    gfx::GfxSurface * renderTextShaded(std::string const& text, gfx::GfxColor const& fg,
                                        gfx::GfxColor const& bg) const;
    gfx::GfxSurface * renderTextUtf8Shaded(std::string const& text, gfx::GfxColor const& fg,
                                        gfx::GfxColor const& bg) const;
    gfx::GfxSurface * renderTextUnicodeShaded(std::string text, gfx::GfxColor fg,
                                        gfx::GfxColor bg) const throw(std::runtime_error);
    gfx::GfxSurface * renderGlyphShaded(uint16_t ch, gfx::GfxColor const& fg,
                                        gfx::GfxColor const& bg) const;

    gfx::GfxSurface * renderTextBlended(std::string const& text, gfx::GfxColor const& fg) const;
    gfx::GfxSurface * renderTextUtf8Blended(std::string const& text, gfx::GfxColor const& fg) const;
    gfx::GfxSurface * renderTextUnicodeBlended(std::string text, gfx::GfxColor fg) const throw(std::runtime_error);
    gfx::GfxSurface * renderGlyphBlended(uint16_t ch, gfx::GfxColor const& fg) const;
private:
    GfxTtfFont * ttf_;
};

}  // namespace ttf

}  // namespace gfx

#endif /* GfxTtfFontRenderer_hpp */
