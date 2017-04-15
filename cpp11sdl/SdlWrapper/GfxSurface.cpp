//
//  GfxSurface.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxSurface.hpp"

GfxSurface::GfxSurface(const uint16_t w,const uint16_t h) : GfxRootClass("GfxSurface")
{
    uint32_t format = SDL_PIXELFORMAT_RGBA32;

    surf_ = SDL_CreateRGBSurfaceWithFormat(0,w,h,32,format);
    if (surf_ == nullptr)
    {
        // error handling here ...
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
    SDL_Surface* tmpsurfptr;

    tmpsurfptr = SDL_LoadBMP(filename.c_str());
    if (tmpsurfptr == nullptr)
    {
        // error handling here
        return;
    }
    if (tmpsurfptr->format != nullptr)
    {
        if (tmpsurfptr->format->format != SDL_PIXELFORMAT_RGBA32)
        {
            // convert here
        }
    }
    else
    {
        // error handling here
    }
    surf_ = tmpsurfptr;
}

GfxSurface::GfxSurface(std::string&& filename) : GfxRootClass("GfxSurface")
{
    SDL_Surface* tmpsurfptr;

    tmpsurfptr = SDL_LoadBMP(filename.c_str());
    if (tmpsurfptr == nullptr)
    {
        // error handling here
        return;
    }
    if (tmpsurfptr->format != nullptr)
    {
        if (tmpsurfptr->format->format != SDL_PIXELFORMAT_RGBA32)
        {
            // convert here
        }
    }
    else
    {
        // error handling here
    }
    surf_ = tmpsurfptr;
    // Delete other's data
    filename = "";
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
    if (surf_ != nullptr)
    {
        SDL_FreeSurface(surf_);
    }
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
    {
        for (const GfxRect& r : rects)
        {
            fillRect(r,color);
        }
    }
}

void GfxSurface::blitSurface(const GfxSurface& src,const GfxRect& srcr,const GfxRect& dstr)
{
    SDL_BlitSurface(src.getAsSdlTypePtr(),srcr.getAsSdlTypePtr(),surf_,dstr.getAsSdlTypePtr());
}

void GfxSurface::blitSurface(const GfxSurface& src)
{
    SDL_BlitSurface(src.getAsSdlTypePtr(),NULL,surf_,NULL);
}

void GfxSurface::putPixel(const uint16_t x,const uint16_t y,const GfxColor& color)
{
    if (surf_ == nullptr)
    {
        // error handling here
        return;
    }
    if ((x >= surf_->w) || (y >= surf_->h))
    {
        // error handling here
        return;
    }
    putPixelPrv(x,y,color);
}

std::unique_ptr<GfxColor> GfxSurface::getPixel(const uint16_t x, const uint16_t y)
{
    if (surf_ == nullptr)
    {
        // error handling here
        return nullptr;
    }
    if ((x >= surf_->w) || (y >= surf_->h))
    {
        // error handling here
        return nullptr;
    }
    return getPixelPrv(x,y);
}

void GfxSurface::destroySurface(void)
{
    if (surf_ != nullptr)
    {
        SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

GfxSurface::SdlTypePtr GfxSurface::getAsSdlTypePtr(void) const
{
    return surf_;
}

void GfxSurface::putPixelPrv(const uint16_t x,const uint16_t y,const GfxColor& color)
{
    uint32_t* ptr;
    uint32_t clr;
    
    clr = SDL_MapRGBA(surf_->format,color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    ptr = (uint32_t*)surf_->pixels;
    ptr[y * surf_->w + x] = clr;
}

std::unique_ptr<GfxColor> GfxSurface::getPixelPrv(const uint16_t x, const uint16_t y)
{
    uint8_t* ptr;
    
    ptr = (uint8_t*)surf_->pixels;
    std::unique_ptr<GfxColor> clr{new GfxColor(ptr[y * surf_->w + 0], ptr[y * surf_->w + 1],
                                               ptr[y * surf_->w + 2], ptr[y * surf_->w + 3])};
    return clr;
}
