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

#include "GLabel.hpp"
#include "GTypes.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"
#include "GfxTtfFont.hpp"
#include "GfxTtfFontStyle.hpp"
#include "GfxTtfFontRenderer.hpp"
#include "GfxFontInfo.hpp"

namespace gto
{

namespace gobj
{

GLabel::GLabel(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                std::string const& text, uint8_t const& textsize) :
        GGraphicControl(vname, owner, width, height)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);
    assert(width <= kMaxObjectWidth);
    assert(height <= kMaxObjectHeight);

    text_ = text;
    fontInfo_.setDefault();
    fontInfo_.setFontSize(textsize);
    textRenderMode_ = kDefaultTextRenderMode;
}

std::string const& GLabel::getText(void) const noexcept
{
    return text_;
}

void GLabel::setText(std::string const& text) noexcept
{
    text_ = text;
}

gfx::xtra::GfxFontInfo& GLabel::getFontInfo(void) noexcept
{
    return fontInfo_;
}

void GLabel::setFontInfo(gfx::xtra::GfxFontInfo const& fontinfo) noexcept
{
    assert(fontinfo);

    fontInfo_ = fontinfo;
}

GTextRenderMode GLabel::getTextRenderMode(void) const noexcept
{
    return textRenderMode_;
}

void GLabel::setTextRenderMode(GTextRenderMode const textrendermode) noexcept
{
    textRenderMode_ = textrendermode;
}

void GLabel::draw(void)
{
    std::string fontfile = std::string(__base_path) + "/Raleway/Raleway-Regular.ttf";
    int32_t w;
    int32_t h;
    gfx::ttf::GfxTtfFont font(fontfile, fontInfo_.getFontSize());
    gfx::ttf::GfxTtfFontRenderer rend(&font);
    gfx::surface::GfxSurface * rendsurf;

    surf_().fillRect(clientBounds_, getBackgroundColor());

    if (font.sizeText(text_, &w, &h) == true)
    {
        if (w > getClientBounds().getWidth())
        {
            return;
        }
        if (h > getClientBounds().getHeight())
        {
            return;
        }
    }

    font.setFontStyle(gfx::ttf::GfxTtfFontStyle(fontInfo_.getFontBold(), fontInfo_.getFontItalic(),
                                                fontInfo_.getFontUnderline(), fontInfo_.getFontStrikethrough()));
    font.setFontHinting(gfx::ttf::GfxTtfFontHinting(fontInfo_.getFontHinting()));
    font.setFontOutline(fontInfo_.getFontOutline());
    font.setFontKerning(fontInfo_.getFontKerning());

    rendsurf = nullptr;
    switch (textRenderMode_)
    {
        case GTextRenderMode::solidText:
            rendsurf = rend.renderTextSolid(text_, getForegroundColor());
            break;
        case GTextRenderMode::shadedText:
            rendsurf = rend.renderTextShaded(text_ , getForegroundColor(), getBackgroundColor());
            break;
        case GTextRenderMode::blendedText:
            rendsurf = rend.renderTextBlended(text_, getForegroundColor());
            break;
    }
    if (rendsurf != nullptr)
    {
        gfx::rect::GfxRect textbounds(0, 0, rendsurf->getWidth(), rendsurf->getHeight());

        surf_().blitSurface(*rendsurf, textbounds, clientBounds_);
        delete rendsurf;
    }

    GGraphicControl::draw();
}

}  // namespace gobj

}  // namespace gto

/* EOF */
