//
//  GfxSurface.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxSurface.hpp"

GfxSurface::GfxSurface(int w,int h,int rmask,int gmask,int bmask,int amask)
{
    surf_ = SDL_CreateRGBSurface(0,w,h,32,rmask,gmask,bmask,amask);
}

GfxSurface::GfxSurface(SdlTypePtr surf)
{
    surf_ = surf;
    surf = nullptr;
}

GfxSurface::GfxSurface(GfxSurface&& surf)
{
    surf_ = surf.surf_;
    surf.surf_ = nullptr;
}

GfxSurface& GfxSurface::operator=(GfxSurface&& surf)
{
    if (this != &surf)
    {
        surf_ = surf.surf_;
        surf.surf_ = nullptr;
    }
    return *this;
}

GfxSurface::~GfxSurface()
{
    if (surf_)
        SDL_FreeSurface(surf_);
}

int GfxSurface::getWidth(void) const
{
    return surf_->w;
}

int GfxSurface::getHeight(void) const
{
    return surf_->h;
}

int GfxSurface::getDepth(void) const
{
    return surf_->format->BitsPerPixel;
}

int GfxSurface::getRedMask(void) const
{
    return surf_->format->Rmask;
}

int GfxSurface::getGreenMask(void) const
{
    return surf_->format->Gmask;
}

int GfxSurface::getBlueMask(void) const
{
    return surf_->format->Bmask;
}

int GfxSurface::getAlphaMask(void) const
{
    return surf_->format->Amask;
}

GfxPixelFormat GfxSurface::getFormat(void)
{
    return GfxPixelFormat(*surf_->format);
}

void GfxSurface::destroySurface(void)
{
    if (surf_)
    {
        SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

GfxSurface::SdlTypePtr GfxSurface::getAsSdlTypePtr(void) const
{
    return surf_;
}
