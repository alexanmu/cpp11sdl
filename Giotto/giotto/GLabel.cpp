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
#include <cstdint>
#include <string>

#include "GLabel.hpp"
#include "GTypes.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"
#include "GfxTtfFont.hpp"
#include "GfxTtfGetVersion.hpp"
#include "GfxTtfFontStyle.hpp"
#include "GfxTtfFontRenderer.hpp"
#include "GfxFontInfo.hpp"

namespace giotto
{

namespace objects
{

GLabel::GLabel(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                std::string const& text, uint8_t const& textsize) :
        GGraphicControl(vname, owner, width, height)
{
    text_ = text;
    textSize_ = textsize;
    textRenderMode_ = kDefaultTextRenderMode;
    ttfiq_ = new gfx::ttf::GfxTtfInitQuit();
}

GLabel::~GLabel()
{
    delete ttfiq_;
}

std::string const& GLabel::getText(void) const noexcept
{
    return text_;
}

void GLabel::setText(std::string const& text) noexcept
{
    text_ = text;
}

uint8_t GLabel::getTextSize(void) const noexcept
{
    return textSize_;
}

void GLabel::setTextSize(uint8_t const textsize) noexcept
{
    textSize_ = textsize;
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
    gfx::ttf::GfxTtfFont ttffont(fontfile, textSize_);
    gfx::GfxVersion v;
    gfx::ttf::GfxTtfGetVersion gv;
    gfx::ttf::GfxTtfFontHinting fh;
    int32_t w;
    int32_t h;
    gfx::ttf::GfxTtfFontRenderer ttfr(&ttffont);

    gv.getVersion(&v);

    surf_().fillRect(clientBounds_, backgroundColor_);

    text_ = ttffont.getFontFaceFamilyName() + " " + v.getAsString();
    if (ttffont.sizeText(text_, &w, &h) == true)
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

    ttffont.setFontStyle(gfx::ttf::GfxTtfFontStyle(false, true, false, false));
    ttffont.setFontHinting(gfx::ttf::GfxTtfFontHinting(
        gfx::ttf::GfxTtfFontHinting::GfxTtfFontHintingValues::hintingLight));
    ttffont.setFontOutline(1);
    ttffont.setFontKerning(true);

    gfx::GfxSurface * rendsurf;

    switch (textRenderMode_)
    {
        case GTextRenderMode::solidText:
            rendsurf = ttfr.renderTextSolid(text_, foregroundColor_);
            break;
        case GTextRenderMode::shadedText:
            rendsurf = ttfr.renderTextShaded(text_ , foregroundColor_, backgroundColor_);
            break;
        case GTextRenderMode::blendedText:
            rendsurf = ttfr.renderTextBlended(text_, foregroundColor_);
            break;
    }
    gfx::GfxRect textbounds(0, 0, rendsurf->getWidth(), rendsurf->getHeight());

    surf_().blitSurface(*rendsurf, textbounds, clientBounds_);

    delete rendsurf;

    GGraphicControl::draw();
}

}  // namespace objects

}  // namespace giotto

/* EOF */
