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
#include <string>

#include "GfxRenderer.hpp"

namespace gfx
{

namespace render
{

const char GfxRenderer::ClassName[] = "GfxRenderer";

GfxRenderer::GfxRenderer(video::GfxWindow const& win, GfxRendererFlags const& flags)
    throw (std::runtime_error) : GfxObject(ClassName)
{
    assert(win);
    assert(flags);

    SdlTypePtr renderertmp;

    renderertmp = sdl2::SDL_CreateRenderer(win.getAsSdlTypePtr(), -1, flags.getAsSdlType());
    if (renderertmp == nullptr)
    {
        throw std::runtime_error("Unable to create renderer");
    }
    renderer_ = renderertmp;
}

GfxRenderer::GfxRenderer(surface::GfxSurface const& surf) throw(std::runtime_error) : GfxObject(ClassName)
{
    assert(surf);

    SdlTypePtr renderertmp;

    renderertmp = sdl2::SDL_CreateSoftwareRenderer(surf.getAsSdlTypePtr());
    if (renderertmp == nullptr)
    {
        throw std::runtime_error("Unable to create renderer");
    }
    renderer_ = renderertmp;
}

GfxRenderer::~GfxRenderer() noexcept
{
    if (renderer_ != nullptr)
    {
        try
        {
            sdl2::SDL_DestroyRenderer(renderer_);
        }
        catch (...)
        {
            throw std::runtime_error("std::terminate call will follow!");
        }
    }
}

GfxRenderer::operator bool() const noexcept
{
    return (renderer_ != nullptr);
}

GfxRenderer::SdlTypePtr GfxRenderer::getRenderer(video::GfxWindow const &win) const noexcept
{
    assert(win);

    SdlTypePtr rd;

    rd = sdl2::SDL_GetRenderer(win.getAsSdlTypePtr());
    if (rd == renderer_)
    {
        return renderer_;
    }
    else
    {
        return nullptr;
    }
}

void GfxRenderer::getRendererOutputSize(int32_t * w, int32_t * h) const noexcept
{
    assert(w != nullptr);
    assert(h != nullptr);

    int32_t ret = 1;

    if (renderer_ != nullptr)
    {
        ret = sdl2::SDL_GetRendererOutputSize(renderer_, w, h);
        assert((ret == -1) || (ret == 0));
    }
}

/******************************************** old ******************************************************/
void GfxRenderer::destroyRenderer()
{
    if (renderer_ != nullptr)
    {
        sdl2::SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
}

void GfxRenderer::renderClear()
{
    if (renderer_ != nullptr)
    {
        sdl2::SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
        sdl2::SDL_RenderClear(renderer_);
    }
}

GfxRendererInfo * GfxRenderer::getRendererInfo(void) const noexcept
{
    GfxRendererInfo::SdlType ri;

    if (renderer_ != nullptr)
    {
        sdl2::SDL_GetRendererInfo(renderer_, &ri);
        return new GfxRendererInfo(ri);
    }
    else
    {
        return nullptr;
    }
}

void GfxRenderer::renderCopy(const GfxTexture& tex, const rect::GfxRect& src, const rect::GfxRect& dest)
{
    assert(tex);
    assert(src);
    assert(dest);

    if (renderer_ != nullptr)
    {
        sdl2::SDL_RenderCopy(renderer_,
                       tex.getAsSdlTypePtr(),
                       src.getAsSdlTypePtr(),
                       dest.getAsSdlTypePtr());
    }
}

void GfxRenderer::renderCopy(const GfxTexture& tex)
{
    assert(tex);

    if (renderer_ != nullptr)
    {
        SDL_RenderCopy(renderer_, tex.getAsSdlTypePtr(), NULL, NULL);
    }
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex, const rect::GfxRect& src, const rect::GfxRect& dest,
                                const double angle, const rect::GfxPoint& pt, const GfxRendererFlip& flip)
{
    assert(tex);
    assert(src);
    assert(dest);
    assert(pt);
    assert(flip);

    if (renderer_ != nullptr)
    {
        sdl2::SDL_RenderCopyEx(renderer_,
                         tex.getAsSdlTypePtr(),
                         src.getAsSdlTypePtr(),
                         dest.getAsSdlTypePtr(),
                         angle,
                         pt.getAsSdlTypePtr(),
                         flip.getAsSdlType());
    }
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex, const double angle, const rect::GfxPoint& pt,
                                const GfxRendererFlip& flip)
{
    assert(tex);
    assert(pt);
    assert(flip);

    if (renderer_ != nullptr)
    {
        sdl2::SDL_RenderCopyEx(renderer_,
                         tex.getAsSdlTypePtr(),
                         NULL,
                         NULL,
                         angle,
                         pt.getAsSdlTypePtr(),
                         flip.getAsSdlType() );
    }
}

void GfxRenderer::renderPresent(void)
{
    if (renderer_ != nullptr)
    {
        sdl2::SDL_RenderPresent(renderer_);
    }
}

GfxRenderer::SdlTypePtr GfxRenderer::getAsSdlTypePtr() const
{
    return renderer_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
