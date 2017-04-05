//
//  GfxSurface.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxSurface.hpp"

GfxSurface::GfxSurface(int w,int h,int d,int rmask,int gmask,int bmask,int amask)
{
    w_ = w;
    h_ = h;
    d_ = d;
    rmask_ = rmask;
    gmask_ = gmask;
    bmask_ = bmask;
    amask_ = amask;
    surf_ = SDL_CreateRGBSurface(0,w_,h_,d_,rmask_,gmask_,bmask_,amask_);
}

GfxSurface::GfxSurface(GfxSurfaceSdlType** surf)
{
    surf_ = *surf;
    w_ = surf_->w;
    h_ = surf_->h;
    d_ = surf_->format->BitsPerPixel;
    rmask_ = surf_->format->Rmask;
    gmask_ = surf_->format->Gmask;
    bmask_ = surf_->format->Bmask;
    amask_ = surf_->format->Amask;
    
    *surf = nullptr;
}

GfxSurface::GfxSurface(GfxSurface&& surf)
{
    w_ = surf.w_;
    h_ = surf.h_;
    d_ = surf.d_;
    rmask_ = surf.rmask_;
    gmask_ = surf.gmask_;
    bmask_ = surf.bmask_;
    amask_ = surf.amask_;
    surf_ = surf.surf_;
    
    surf.w_ = -1;
    surf.h_ = -1;
    surf.d_ = -1;
    surf.surf_ = nullptr;
}

GfxSurface& GfxSurface::operator=(GfxSurface&& surf)
{
    if (this != &surf)
    {
        w_ = surf.w_;
        h_ = surf.h_;
        d_ = surf.d_;
        rmask_ = surf.rmask_;
        gmask_ = surf.gmask_;
        bmask_ = surf.bmask_;
        amask_ = surf.amask_;
        surf_ = surf.surf_;
        
        surf.w_ = -1;
        surf.h_ = -1;
        surf.d_ = -1;
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
    return w_;
}

int GfxSurface::getHeight(void) const
{
    return h_;
}

int GfxSurface::getDepth(void) const
{
    return d_;
}

int GfxSurface::getRedMask(void) const
{
    return rmask_;
}

int GfxSurface::getGreenMask(void) const
{
    return gmask_;
}

int GfxSurface::getBlueMask(void) const
{
    return bmask_;
}

int GfxSurface::getAlphaMask(void) const
{
    return amask_;
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

GfxSurface::GfxSurfaceSdlType* GfxSurface::getAsGfxSurfaceSdlTypePtr(void) const
{
    return surf_;
}
