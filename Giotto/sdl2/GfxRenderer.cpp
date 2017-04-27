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

#include "GfxRenderer.hpp"

GfxRenderer::GfxRenderer(const GfxWindow& win) : GfxRootClass("GfxRenderer"), renderer_(nullptr), window_(&win)
{
    SdlType* renderertmp;

    renderertmp = SDL_CreateRenderer(window_->getAsSdlTypePtr(), -1, SDL_RENDERER_ACCELERATED);
    if (renderertmp == nullptr)
    {
        renderertmp = SDL_CreateRenderer(window_->getAsSdlTypePtr(), -1, SDL_RENDERER_SOFTWARE);
    }
    renderer_ = renderertmp;
}

GfxRenderer::GfxRenderer(GfxRenderer&& rend) : GfxRootClass("GfxRenderer")
{
    renderer_ = rend.renderer_;
    window_ = rend.window_;
    rend.renderer_ = nullptr;
    rend.window_ = nullptr;
}

GfxRenderer::~GfxRenderer()
{
    if (renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
    }
}

GfxRenderer& GfxRenderer::operator=(GfxRenderer&& rend)
{
    if (this != &rend)
    {
        renderer_ = rend.renderer_;
        window_ = rend.window_;
        rend.renderer_ = nullptr;
        rend.window_ = nullptr;
    }
    return *this;
}

void GfxRenderer::destroyRenderer()
{
    if (renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
}

void GfxRenderer::renderClear()
{
    if (renderer_ != nullptr)
    {
        SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer_);
    }
}

void GfxRenderer::getRendererInfo(GfxRendererInfo* infoptr)
{
    GfxRendererInfo::SdlType ri;

    if (renderer_ != nullptr)
    {
        SDL_GetRendererInfo(renderer_,&ri);
        infoptr->set(ri);
    }
    else
    {
        infoptr = nullptr;
    }
}

void GfxRenderer::renderCopy(const GfxTexture& tex, const GfxRect& src, const GfxRect& dest)
{
    if (renderer_ != nullptr)
    {
        SDL_RenderCopy(renderer_,
                       tex.getAsSdlTypePtr(),
                       src.getAsSdlTypePtr(),
                       dest.getAsSdlTypePtr());
    }
}

void GfxRenderer::renderCopy(const GfxTexture& tex)
{
    if (renderer_ != nullptr)
    {
        SDL_RenderCopy(renderer_, tex.getAsSdlTypePtr(), NULL, NULL);
    }
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex, const GfxRect& src, const GfxRect& dest,
                                const double angle, const GfxPoint& pt, const GfxRendererFlip& flip)
{
    if (renderer_ != nullptr)
    {
        SDL_RenderCopyEx(renderer_,
                         tex.getAsSdlTypePtr(),
                         src.getAsSdlTypePtr(),
                         dest.getAsSdlTypePtr(),
                         angle,
                         pt.getAsSdlTypePtr(),
                         flip.getAsSdlType());
    }
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex, const double angle, const GfxPoint& pt, const GfxRendererFlip& flip)
{
    if (renderer_ != nullptr)
    {
        SDL_RenderCopyEx(renderer_,
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
        SDL_RenderPresent(renderer_);
    }
}

GfxRenderer::SdlTypePtr GfxRenderer::getAsSdlTypePtr() const
{
    return renderer_;
}

/* EOF */
