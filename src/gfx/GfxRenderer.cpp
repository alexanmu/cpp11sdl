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
#include <string>

#include "GfxRenderer.hpp"

namespace gfx
{

const char GfxRenderer::ClassName[] = "GfxRenderer";

GfxRenderer::GfxRenderer(const video::GfxWindow& win) : GfxRootClass(ClassName), renderer_(nullptr), window_(win)
{
    SdlType* renderertmp;

    renderertmp = sdl2::SDL_CreateRenderer(window_.getAsSdlTypePtr(), -1, sdl2::SDL_RENDERER_ACCELERATED);
    if (renderertmp == nullptr)
    {
        renderertmp = sdl2::SDL_CreateRenderer(window_.getAsSdlTypePtr(), -1, sdl2::SDL_RENDERER_SOFTWARE);
    }
    renderer_ = renderertmp;
}

GfxRenderer::~GfxRenderer()
{
    if (renderer_ != nullptr)
    {
        sdl2::SDL_DestroyRenderer(renderer_);
    }
}

GfxRenderer::operator bool() const
{
    return (renderer_ != nullptr);
}

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

void GfxRenderer::getRendererInfo(GfxRendererInfo * infoptr)
{
    assert(infoptr != nullptr);

    GfxRendererInfo::SdlType ri;

    if (renderer_ != nullptr)
    {
        sdl2::SDL_GetRendererInfo(renderer_, &ri);
        infoptr->set(ri);
    }
    else
    {
        infoptr = nullptr;
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

}  // namespace gfx

/* EOF */
