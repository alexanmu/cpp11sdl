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
#include <cstdint>
#include <string>

#include "GfxTtfFontRenderer.hpp"

namespace gfx
{

namespace ttf
{

const char GfxTtfFontRenderer::ClassName[] = "GfxTtfFontRenderer";

GfxTtfFontRenderer::GfxTtfFontRenderer(GfxTtfFont * ttf) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    if (ttf == nullptr)
    {
        throw std::runtime_error("nullptr");
    }
    ttf_ = ttf;
}

GfxTtfFontRenderer::operator bool() const
{
    return true;
}

GfxTtfFont * GfxTtfFontRenderer::getFont(void) const
{
    return ttf_;
}

void GfxTtfFontRenderer::setFont(GfxTtfFont * ttf) throw(std::runtime_error)
{
    if (ttf == nullptr)
    {
        throw std::runtime_error("nullptr");
    }
    ttf_ = ttf;
}

bool GfxTtfFontRenderer::sizeText(std::string const& text, int32_t * w, int32_t * h) const
{
    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    return (sdl2::TTF_SizeText(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
}

bool GfxTtfFontRenderer::sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const
{
    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    return (sdl2::TTF_SizeUTF8(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
}

bool GfxTtfFontRenderer::sizeUnicode(std::string text, int32_t * w, int32_t * h) const throw(std::runtime_error)
{
    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    throw std::runtime_error("Not supported");
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextSolid(std::string const& text, gfx::GfxColor const& fg) const
{
    assert(text.length() > 0);

    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderText_Solid(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Solid(std::string const& text, gfx::GfxColor const& fg) const
{
    assert(text.length() > 0);

    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderUTF8_Solid(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeSolid(std::string text, gfx::GfxColor fg)
        const throw(std::runtime_error)
{
    assert(text.length() > 0);
    assert(fg);
    throw std::runtime_error("Not implemented");
}

gfx::GfxSurface * GfxTtfFontRenderer::renderGlyphSolid(uint16_t ch, gfx::GfxColor const& fg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderGlyph_Solid(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextShaded(std::string const& text, gfx::GfxColor const& fg,
            gfx::GfxColor const& bg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderText_Shaded(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType(), bg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Shaded(std::string const& text, gfx::GfxColor const& fg,
            gfx::GfxColor const& bg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderUTF8_Shaded(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType(), bg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeShaded(std::string text, gfx::GfxColor fg,
            gfx::GfxColor bg) const throw(std::runtime_error)
{
    text = text;
    fg = fg;
    bg = bg;
    throw std::runtime_error("Not implemented");
}

gfx::GfxSurface * GfxTtfFontRenderer::renderGlyphShaded(uint16_t ch, gfx::GfxColor const& fg,
            gfx::GfxColor const& bg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderGlyph_Shaded(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType(), bg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextBlended(std::string const& text, gfx::GfxColor const& fg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderText_Blended(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Blended(std::string const& text, gfx::GfxColor const& fg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderUTF8_Blended(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeBlended(std::string text,
            gfx::GfxColor fg) const throw(std::runtime_error)
{
    text = text;
    fg = fg;
    throw std::runtime_error("Not implemented");
}

gfx::GfxSurface * GfxTtfFontRenderer::renderGlyphBlended(uint16_t ch, gfx::GfxColor const& fg) const
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderGlyph_Blended(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
