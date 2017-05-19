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

#include "GfxTtfFontRenderer.hpp"

namespace gfx
{

namespace ttf
{

const char GfxTtfFontRenderer::ClassName[] = "GfxTtfFontRenderer";

GfxTtfFontRenderer::GfxTtfFontRenderer(GfxTtfFont * ttf) : GfxRootClass(ClassName)
{
    ttf_ = ttf;
}

GfxTtfFont * GfxTtfFontRenderer::getFont(void) const
{
    return ttf_;
}

void GfxTtfFontRenderer::setFont(GfxTtfFont * ttf)
{
    ttf_ = ttf;
}

bool GfxTtfFontRenderer::sizeText(std::string const& text, int32_t * w, int32_t * h) const
{
    return (sdl2::TTF_SizeText(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
}

bool GfxTtfFontRenderer::sizeUtf8(std::string const& text, int32_t * w, int32_t * h) const
{
    return (sdl2::TTF_SizeUTF8(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
}

bool GfxTtfFontRenderer::sizeUnicode(std::string text, int32_t * w, int32_t * h) const throw(std::runtime_error)
{
    text = text;
    w = w;
    h = h;
    throw std::runtime_error("Not supported");
}

gfx::GfxSurface * GfxTtfFontRenderer::renderTextSolid(std::string const& text, gfx::GfxColor const& fg)
{
    gfx::GfxSurface::SdlTypePtr surf;

    surf = sdl2::TTF_RenderText_Solid(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
    return new gfx::GfxSurface(surf);
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
