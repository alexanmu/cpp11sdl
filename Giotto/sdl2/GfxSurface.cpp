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

#include <memory>
#include <string>
#include <vector>

#include "GfxSurface.hpp"

namespace gfx
{

const char GfxSurface::ClassName[] = "GfxSurface";

GfxSurface::GfxSurface(const GfxSurfaceFlags& flags, const uint16_t w, const uint16_t h) throw(std::runtime_error) :
        GfxRootClass(ClassName)
{
    uint32_t format = sdl2::SDL_PIXELFORMAT_ARGB8888;

    surf_ = sdl2::SDL_CreateRGBSurfaceWithFormat(flags.getAsSdlType(), w, h, 32, format);
    if (surf_ == nullptr)
    {
        // error handling here ...
        throw std::runtime_error("Not implemented; branch 1");
    }
}

GfxSurface::GfxSurface(SdlTypePtr surf) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    if (surf == nullptr)
    {
        // error handling here
        throw std::runtime_error("Not implemented; branch 2");
    }
    surf_ = surf;
}

GfxSurface::GfxSurface(const std::string& filename) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    sdl2::SDL_Surface* tmpsurfptr;

    auto rw = sdl2::SDL_RWFromFile(filename.c_str(), "rb");
    if (rw == nullptr)
    {
        throw std::runtime_error(sdl2::SDL_GetError());
    }
    tmpsurfptr = sdl2::SDL_LoadBMP_RW(rw, 1);
                    //  sdl2::SDL_LoadBMP(filename.c_str());
    if (tmpsurfptr == nullptr)
    {
        //  error handling here
        throw std::runtime_error("Not implemented; branch 3");
    }
    if (tmpsurfptr->format == nullptr)
    {
        //  error handling here
        throw std::runtime_error("Not implemented; branch 4");
    }
    else
    {
        if (tmpsurfptr->format->format != sdl2::SDL_PIXELFORMAT_ARGB8888)
        {
            //  convert here
        }
    }
    surf_ = tmpsurfptr;
}

GfxSurface::GfxSurface(void * pixels, const int32_t width, const int32_t height, const int32_t depth,
                        const int32_t pitch, const uint32_t rmask, const uint32_t gmask, const uint32_t bmask,
                        const uint32_t amask) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    sdl2::SDL_Surface* tmpsurfptr;

    tmpsurfptr = sdl2::SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (tmpsurfptr == nullptr)
    {
        //  error handling here
        throw std::runtime_error("Not implemented; branch 5");
    }
    if (tmpsurfptr->format == nullptr)
    {
        //  error handling here
        throw std::runtime_error("Not implemented; branch 6");
    }
    else
    {
        if (tmpsurfptr->format->format != sdl2::SDL_PIXELFORMAT_ARGB8888)
        {
            //  convert here
        }
    }
    surf_ = tmpsurfptr;
}

GfxSurface::GfxSurface(GfxSurface&& surf) : GfxRootClass(ClassName)
{
    surf_ = surf.surf_;
    surf.surf_ = nullptr;
}

GfxSurface& GfxSurface::operator=(GfxSurface&& surf)
{
    if (this != &surf)
    {
        if (surf_ != nullptr)
        {
            sdl2::SDL_FreeSurface(surf_);
        }
        surf_ = surf.surf_;
        surf.surf_ = nullptr;
    }
    return *this;
}

GfxSurface::~GfxSurface()
{
    if (surf_ != nullptr)
    {
        sdl2::SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

int GfxSurface::getWidth(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->w;
}

int GfxSurface::getHeight(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->h;
}

int GfxSurface::getDepth(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->format->BitsPerPixel;
}

GfxPixelFormat GfxSurface::getFormat(void)
{
    if (surf_ == nullptr)
    {
        return GfxPixelFormat();
    }

    return GfxPixelFormat { surf_->format };
}

void GfxSurface::fillRect(const GfxRect& rect, const GfxColor& color)
{
    uint32_t clr;

    if (surf_ == nullptr)
    {
        return;
    }
    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    sdl2::SDL_FillRect(surf_, rect.getAsSdlTypePtr(), clr);
}

void GfxSurface::fillRect(const GfxColor& color)
{
    uint32_t clr;

    if (surf_ == nullptr)
    {
        return;
    }
    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    sdl2::SDL_FillRect(surf_, NULL, clr);
}

void GfxSurface::fillRects(const std::vector<GfxRect>& rects, const GfxColor& color)
{
    if (rects.size() > 0)
    {
        for (const GfxRect& r : rects)
        {
            fillRect(r, color);
        }
    }
}

void GfxSurface::blitSurface(const GfxSurface& src, const GfxRect& srcr, const GfxRect& dstr)
{
    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitSurface(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
}

void GfxSurface::blitSurface(const GfxSurface& src)
{
    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitSurface(src.getAsSdlTypePtr(), NULL, surf_, NULL);
}

void GfxSurface::blitScaled(const GfxSurface& src, const GfxRect& srcr, const GfxRect& dstr)
{
    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitScaled(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
}

void GfxSurface::putPixel(const uint16_t x, const uint16_t y, const GfxColor& color)
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
    sdl2::SDL_LockSurface(surf_);
    putPixelPrv(x, y, color);
    sdl2::SDL_UnlockSurface(surf_);
}

GfxColor GfxSurface::getPixel(const uint16_t x, const uint16_t y)
{
    GfxColor pix;

    if (surf_ == nullptr)
    {
        // error handling here
        return GfxColor();
    }
    if ((x >= surf_->w) || (y >= surf_->h))
    {
        // error handling here
        return GfxColor();
    }
    sdl2::SDL_LockSurface(surf_);
    pix = getPixelPrv(x, y);
    sdl2::SDL_UnlockSurface(surf_);
    return pix;
}

void GfxSurface::destroySurface(void)
{
    if (surf_ != nullptr)
    {
        sdl2::SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

GfxSurface::SdlTypePtr GfxSurface::getAsSdlTypePtr(void) const
{
    return surf_;
}

void GfxSurface::putPixelPrv(const uint16_t x, const uint16_t y, const GfxColor& color)
{
    uint32_t* ptr;
    uint32_t clr;

    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    ptr = reinterpret_cast<uint32_t *>(surf_->pixels);
    ptr[y * surf_->w + x] = clr;
}

GfxColor GfxSurface::getPixelPrv(const uint16_t x, const uint16_t y)
{
    uint8_t* ptr;

    ptr = reinterpret_cast<uint8_t*>(surf_->pixels);
    return GfxColor { GfxColor(ptr[y * surf_->w + x + 0], ptr[y * surf_->w + x + 1],
                               ptr[y * surf_->w + x + 2], ptr[y * surf_->w + x + 3]) };
}

}  // namespace gfx

/* EOF */
