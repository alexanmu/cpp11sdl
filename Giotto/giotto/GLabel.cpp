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

namespace giotto
{

namespace objects
{

GLabel::GLabel(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height,
                std::string const& text) :
        GGraphicControl(vname, owner, width, height)
{
    text_ = text;
    textRenderMode_ = kDefaultTextRenderMode;
    gfx::sdl2::TTF_Init();
}

GLabel::~GLabel()
{
    gfx::sdl2::TTF_Quit();
}

std::string const& GLabel::getText(void) const noexcept
{
    return text_;
}

void GLabel::setText(std::string const& text) noexcept
{
    text_ = text;
}

GTextRenderMode GLabel::getTextRenderMode(void) const noexcept
{
    return textRenderMode_;
}

void GLabel::setTextRenderMode(GTextRenderMode const& textrendermode) noexcept
{
    textRenderMode_ = textrendermode;
}

void GLabel::draw(void)
{
    std::string fontfile = std::string(__base_path) + "/Raleway/Raleway-Regular.ttf";
    gfx::sdl2::TTF_Font * ff;

    ff = gfx::sdl2::TTF_OpenFont(fontfile.c_str(), 24);

    surf_().fillRect(clientBounds_, backgroundColor_);
    if (ff != nullptr)
    {
        const char * cstr = text_.c_str();
        gfx::sdl2::SDL_Surface * txtsrf;

        switch (textRenderMode_)
        {
            case GTextRenderMode::solidText:
                txtsrf = gfx::sdl2::TTF_RenderText_Solid(ff, cstr, foregroundColor_.getAsSdlType());
                break;
            case GTextRenderMode::shadedText:
                txtsrf = gfx::sdl2::TTF_RenderText_Shaded(ff, cstr, foregroundColor_.getAsSdlType(),
                                                            backgroundColor_.getAsSdlType());
                break;
            case GTextRenderMode::blendedText:
                txtsrf = gfx::sdl2::TTF_RenderText_Blended(ff, cstr, foregroundColor_.getAsSdlType());
                break;
        }
        gfx::GfxRect textbounds(0, 0, txtsrf->w, txtsrf->h);

        surf_().blitSurface(gfx::GfxSurface(txtsrf), textbounds, clientBounds_);
        gfx::sdl2::TTF_CloseFont(ff);
    }
    GGraphicControl::draw();
}

}  // namespace objects

}  // namespace giotto

/* EOF */
