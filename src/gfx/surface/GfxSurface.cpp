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
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "GfxSurface.hpp"

namespace gfx
{

namespace surface
{

const char GfxSurface::ClassName[] = "GfxSurface";

GfxSurface::GfxSurface(const GfxSurfaceFlags& flags, const int32_t w, const int32_t h) throw(std::runtime_error) :
        GfxRootClass(ClassName)
{
    assert(flags);
    assert(w >= 0);
    assert(h >= 0);

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
    assert(filename.length() > 0);

    sdl2::SDL_Surface* tmpsurfptr;

    auto rw = sdl2::SDL_RWFromFile(filename.c_str(), "rb");
    if (rw == nullptr)
    {
        throw std::runtime_error(sdl2::SDL_GetError());
    }
    tmpsurfptr = sdl2::SDL_LoadBMP_RW(rw, 0);  // 1 = auto-close file
    SDL_RWclose(rw);
    if (tmpsurfptr == nullptr)
    {
        // error handling here
        throw std::runtime_error("Not implemented; branch 3");
    }
    if (tmpsurfptr->format == nullptr)
    {
        // error handling here
        throw std::runtime_error("Not implemented; branch 4");
    }
    else
    {
        if (tmpsurfptr->format->format != sdl2::SDL_PIXELFORMAT_ARGB8888)
        {
            // convert here
        }
    }
    surf_ = tmpsurfptr;
}

GfxSurface::GfxSurface(void * pixels, const int32_t width, const int32_t height, const int32_t depth,
                        const int32_t pitch, const uint32_t rmask, const uint32_t gmask, const uint32_t bmask,
                        const uint32_t amask) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    assert(pixels != nullptr);
    assert(width >= 0);
    assert(height >= 0);
    assert(depth >= 0);
    assert(pitch >= 0);

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

GfxSurface::operator bool() const
{
    return (surf_ != nullptr);
}

int32_t GfxSurface::getWidth(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->w;
}

int32_t GfxSurface::getHeight(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->h;
}

int32_t GfxSurface::getDepth(void) const
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->format->BitsPerPixel;
}

pixels::GfxPixelFormat * GfxSurface::getFormat(void)
{
    if (surf_ == nullptr)
    {
        return new pixels::GfxPixelFormat();
    }

    return new pixels::GfxPixelFormat(surf_->format);
}

void GfxSurface::fillRect(const rect::GfxRect& rect, const pixels::GfxColor& color)
{
    assert(rect);
    assert(color);

    uint32_t clr;

    if (surf_ == nullptr)
    {
        return;
    }
    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    sdl2::SDL_FillRect(surf_, rect.getAsSdlTypePtr(), clr);
}

void GfxSurface::fillRect(const pixels::GfxColor& color)
{
    assert(color);

    uint32_t clr;

    if (surf_ == nullptr)
    {
        return;
    }
    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    sdl2::SDL_FillRect(surf_, NULL, clr);
}

void GfxSurface::fillRects(const std::vector<rect::GfxRect>& rects, const pixels::GfxColor& color)
{
    assert(color);

    if (rects.size() > 0)
    {
        for (const rect::GfxRect& r : rects)
        {
            assert(r);
            fillRect(r, color);
        }
    }
}

void GfxSurface::blitSurface(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr)
{
    assert(src);
    assert(srcr);
    assert(dstr);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitSurface(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
}

void GfxSurface::blitSurface(const GfxSurface& src)
{
    assert(src);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitSurface(src.getAsSdlTypePtr(), NULL, surf_, NULL);
}

void GfxSurface::blitScaled(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr)
{
    assert(src);
    assert(srcr);
    assert(dstr);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitScaled(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
}

void GfxSurface::putPixel(const int32_t x, const int32_t y, const pixels::GfxColor& color)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(color);

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

pixels::GfxColor GfxSurface::getPixel(const int32_t x, const int32_t y)
{
    assert(x >= 0);
    assert(y >= 0);

    pixels::GfxColor pix;

    if (surf_ == nullptr)
    {
        // error handling here
        return pixels::GfxColor();
    }
    if ((x >= surf_->w) || (y >= surf_->h))
    {
        // error handling here
        return pixels::GfxColor();
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

void GfxSurface::putPixelPrv(const int32_t x, const int32_t y, const pixels::GfxColor& color)
{
    uint32_t* ptr;
    uint32_t clr;

    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    ptr = reinterpret_cast<uint32_t *>(surf_->pixels);
    ptr[y * surf_->w + x] = clr;
}

pixels::GfxColor GfxSurface::getPixelPrv(const int32_t x, const int32_t y)
{
    uint8_t* ptr;

    ptr = reinterpret_cast<uint8_t*>(surf_->pixels);
    return pixels::GfxColor { pixels::GfxColor(ptr[y * surf_->w + x + 0], ptr[y * surf_->w + x + 1],
                               ptr[y * surf_->w + x + 2], ptr[y * surf_->w + x + 3]) };
}

}  // namespace surface

}  // namespace gfx

/* EOF */
