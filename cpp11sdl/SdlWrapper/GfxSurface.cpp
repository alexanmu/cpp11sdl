//
//  GfxSurface.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxSurface.hpp"
#include <iostream>
GfxSurface::GfxSurface(int w,int h,int rmask,int gmask,int bmask,int amask) : GfxRootClass("GfxSurface")
{
    uint32_t format = SDL_PIXELFORMAT_RGBA32;

    surf_ = SDL_CreateRGBSurfaceWithFormat(0,w,h,32,format);
    if (surf_ == nullptr)
    {
        // error handling here ...
        std::cout << SDL_GetError() << std::endl;
    }
}

GfxSurface::GfxSurface(SdlTypePtr surf) : GfxRootClass("GfxSurface")
{
    if (surf == nullptr)
    {
        // error handling here
    }
    surf_ = surf;
}

GfxSurface::GfxSurface(GfxSurface&& surf) : GfxRootClass("GfxSurface")
{
    surf_ = surf.surf_;
    surf.surf_ = nullptr;
}

GfxSurface::GfxSurface(const std::string& filename) : GfxRootClass("GfxSurface")
{
    surf_ = SDL_LoadBMP(filename.c_str());
    if (surf_ == nullptr)
    {
        // error handling here
    }
}

GfxSurface::GfxSurface(std::string&& filename) : GfxRootClass("GfxSurface")
{
    surf_ = SDL_LoadBMP(filename.c_str());
    if (surf_ == nullptr)
    {
        // error handling here
    }
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

std::unique_ptr<GfxPixelFormat> GfxSurface::getFormat(void)
{
    std::unique_ptr<GfxPixelFormat> p { new GfxPixelFormat(surf_->format) };
    
    return p;
}

void GfxSurface::fillRect(const GfxRect& rect,const GfxColor& color)
{
    uint32_t clr;
    
    clr = SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    SDL_FillRect(surf_, rect.getAsSdlTypePtr(), clr);
}

void GfxSurface::fillRect(const GfxColor& color)
{
    uint32_t clr;
    
    clr = SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    SDL_FillRect(surf_, NULL, clr);
}

void GfxSurface::fillRects(const std::vector<GfxRect>& rects,const GfxColor& color)
{
    if( rects.size() > 0)
        for (const GfxRect& r : rects)
            fillRect(r,color);
}

void GfxSurface::blitSurface(const GfxSurface& src,const GfxRect& srcr,const GfxRect& dstr)
{
    SDL_BlitSurface(src.getAsSdlTypePtr(),srcr.getAsSdlTypePtr(),surf_,dstr.getAsSdlTypePtr());
}

void GfxSurface::blitSurface(const GfxSurface& src)
{
    SDL_BlitSurface(src.getAsSdlTypePtr(),NULL,surf_,NULL);
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
