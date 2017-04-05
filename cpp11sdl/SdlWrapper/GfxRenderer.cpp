//
//  GfxRenderer.cpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxRenderer.hpp"

GfxRenderer::GfxRenderer(const GfxWindow& win) :
    renderer_(nullptr), window_(&win)
{
    GfxRendererSdlType* renderertmp;
    
    renderertmp = SDL_CreateRenderer(window_->getAsGfxWindowSdlTypePtr(), -1, SDL_RENDERER_ACCELERATED);
    if (!renderertmp)
    {
        renderertmp = SDL_CreateRenderer(window_->getAsGfxWindowSdlTypePtr(), -1, SDL_RENDERER_SOFTWARE);
    }
    renderer_ = renderertmp;
}

GfxRenderer::GfxRenderer(GfxRenderer&& rend)
{
    renderer_ = rend.renderer_;
    window_ = rend.window_;
    rend.renderer_ = nullptr;
    rend.window_ = nullptr;
}

GfxRenderer::~GfxRenderer()
{
    if (renderer_)
        SDL_DestroyRenderer(renderer_);
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
    if (renderer_)
        SDL_DestroyRenderer(renderer_);
}

void GfxRenderer::renderClear()
{
    if (renderer_)
    {
        SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer_);
    }
}

void GfxRenderer::renderCopy(const GfxTexture& tex,GfxRect* const src,GfxRect* const dest)
{
    if (renderer_)
        SDL_RenderCopy(renderer_,
                       tex.getAsGfxTextureSdlTypePtr(),
                       src->getAsGfxRectSdlTypePtr(),
                       dest->getAsGfxRectSdlTypePtr());
}

void GfxRenderer::renderCopy(const GfxTexture& tex)
{
    if (renderer_)
        SDL_RenderCopy(renderer_,tex.getAsGfxTextureSdlTypePtr(),NULL,NULL);
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex,GfxRect* const src, GfxRect* const dest,const double angle,const GfxPoint& pt,const GfxFlip& flip)
{
    if (renderer_)
        SDL_RenderCopyEx(renderer_,
                         tex.getAsGfxTextureSdlTypePtr(),
                         src->getAsGfxRectSdlTypePtr(),
                         dest->getAsGfxRectSdlTypePtr(),
                         angle,
                         pt.getAsSdlTypePtr(),
                         flip.getAsSdlType());
}

void GfxRenderer::renderCopyEx(const GfxTexture& tex,const double angle,const GfxPoint& pt,const GfxFlip& flip)
{
    if (renderer_)
        SDL_RenderCopyEx(renderer_,
                         tex.getAsGfxTextureSdlTypePtr(),
                         NULL,
                         NULL,
                         angle,
                         pt.getAsSdlTypePtr(),
                         flip.getAsSdlType() );
}

void GfxRenderer::renderPresent(void)
{
    if (renderer_)
        SDL_RenderPresent(renderer_);
}

GfxRenderer::GfxRendererSdlType* GfxRenderer::getAsGfxRendererSdlTypePtr() const
{
    return renderer_;
}
