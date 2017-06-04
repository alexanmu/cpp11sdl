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

GfxSurface::GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, int32_t width, int32_t height,
                       int32_t depth, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask)
            throw(std::runtime_error) : GfxRootClass(ClassName)
{
    assert(surfname.length() > 0);
    assert(flags);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);

    sdl2::SDL_Surface * tmpsurfptr;

    tmpsurfptr = sdl2::SDL_CreateRGBSurface(flags.getAsSdlType(), width, height, depth, Rmask,
                                            Gmask, Bmask, Amask);
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to create surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, int32_t width, int32_t height,
                       int32_t depth, pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error) :
            GfxRootClass(ClassName)
{
    assert(surfname.length() > 0);
    assert(flags);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(format);

    sdl2::SDL_Surface * tmpsurfptr;

    tmpsurfptr = sdl2::SDL_CreateRGBSurfaceWithFormat(flags.getAsSdlType(), width, height, depth,
                                                      format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to create surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                       const uint32_t bmask, const uint32_t amask) throw(std::runtime_error) : GfxRootClass(ClassName)
{
    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width >= 0);
    assert(height >= 0);
    assert(depth >= 0);
    assert(pitch >= 0);

    sdl2::SDL_Surface * tmpsurfptr;

    tmpsurfptr = sdl2::SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to create surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(std::string const& surfname, void * pixels, int32_t width, int32_t height, int32_t depth,
                       int32_t pitch, pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error) :
            GfxRootClass(ClassName)
{
    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(pitch > 0);
    assert(format);

    sdl2::SDL_Surface * tmpsurfptr;

    tmpsurfptr = sdl2::SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to create surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(std::string const& surfname, std::string const& filename) throw(std::runtime_error) :
            GfxRootClass(ClassName)
{
    assert(surfname.length() > 0);
    assert(filename.length() > 0);

    sdl2::SDL_Surface * tmpsurfptr;

    auto rw = sdl2::SDL_RWFromFile(filename.c_str(), "rb");
    if (rw == nullptr)
    {
        throw std::runtime_error(sdl2::SDL_GetError());
    }
    tmpsurfptr = sdl2::SDL_LoadBMP_RW(rw, 0);  // 1 = auto-close file
    SDL_RWclose(rw);
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to load surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(std::string const& surfname, const SdlTypePtr surf) throw(std::runtime_error) :
            GfxRootClass(ClassName)
{
    if (surf == nullptr)
    {
        // error handling here
        throw std::runtime_error("surf is NULL");
    }
    surf_ = surf;
    surfName_ = surfname;
}

GfxSurface::GfxSurface(GfxSurface&& other) noexcept : GfxRootClass(ClassName)
{
    surf_ = other.surf_;
    other.clear();
}

GfxSurface& GfxSurface::operator=(GfxSurface&& other) noexcept
{
    if (this != &other)
    {
        if (surf_ != nullptr)
        {
            sdl2::SDL_FreeSurface(surf_);
        }
        surf_ = other.surf_;
        other.clear();
    }
    return *this;
}

GfxSurface::~GfxSurface() noexcept
{
    if (surf_ != nullptr)
    {
        try
        {
            sdl2::SDL_FreeSurface(surf_);
        }
        catch (...)
        {
            throw std::runtime_error("std::terminate call will follow!");
        }
    }
}

GfxSurface::operator bool() const noexcept
{
    return (surf_ != nullptr);
}

void GfxSurface::freeSurface(void) noexcept
{
    if (surf_ != nullptr)
    {
        sdl2::SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

void GfxSurface::setSurfacePalette(pixels::GfxPalette const& palette) const noexcept
{
    assert(palette);

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetSurfacePalette(surf_, palette.getAsSdlTypePtr());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxSurface::lockSurface(void) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_LockSurface(surf_);
        assert((ret == 1) || (ret == 0));
    }
}

void GfxSurface::unlockSurface(void) const noexcept
{
    if (surf_ != nullptr)
    {
        sdl2::SDL_UnlockSurface(surf_);
    }
}

void GfxSurface::saveBMP(std::string const& filename) const noexcept
{
    int32_t ret;

    auto rw = sdl2::SDL_RWFromFile(filename.c_str(), "wb");
    if (rw == nullptr)
    {
        throw std::runtime_error(sdl2::SDL_GetError());
    }
    ret = sdl2::SDL_SaveBMP_RW(surf_, rw, 0);  // 1 = auto-close file
    SDL_RWclose(rw);
    assert((ret == -1) || (ret == 0));
}

void GfxSurface::setSurfaceRLE(GfxBool const& flag) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetSurfaceRLE(surf_, static_cast<int32_t>(flag.getBool()));
        assert((ret == 1) || (ret == 0));
    }
}

void GfxSurface::setColorKey(GfxBool const& flag, pixels::GfxColor const& color) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetColorKey(surf_, static_cast<int32_t>(flag.getBool()), color.getColor());
        assert((ret == 1) || (ret == 0));
    }
}

pixels::GfxColor GfxSurface::getColorKey(void) const noexcept
{
    int32_t ret = 1;
    uint32_t key = 0;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_GetColorKey(surf_, &key);
        assert((ret == 1) || (ret == 0));
    }
    return pixels::GfxColor(key);
}

void GfxSurface::setSurfaceColorMod(pixels::GfxColor const& color) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetSurfaceColorMod(surf_, color.getRed(), color.getGreen(), color.getBlue());
        assert((ret == 1) || (ret == 0));
    }
}

pixels::GfxColor GfxSurface::getSurfaceColorMod(void) const noexcept
{
    int32_t ret = 1;
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_GetSurfaceColorMod(surf_, &r, &g, &b);
        assert((ret == 1) || (ret == 0));
    }
    return pixels::GfxColor(r, g, b);
}

void GfxSurface::setSurfaceAlphaMod(uint8_t alpha) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetSurfaceAlphaMod(surf_, alpha);
        assert((ret == 1) || (ret == 0));
    }
}

uint8_t GfxSurface::getSurfaceAlphaMod(void) const noexcept
{
    int32_t ret = 1;
    uint8_t alpha = 0;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_GetSurfaceAlphaMod(surf_, &alpha);
        assert((ret == 1) || (ret == 0));
    }
    return alpha;
}

void GfxSurface::setSurfaceBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept
{
    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetSurfaceBlendMode(surf_, blendmode.getAsSdlType());
        assert((ret == 1) || (ret == 0));
    }
}

blendmode::GfxBlendMode GfxSurface::getSurfaceBlendMode(void) const noexcept
{
    int32_t ret = 1;
    blendmode::GfxBlendMode::SdlType bm;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_GetSurfaceBlendMode(surf_, &bm);
        assert((ret == 1) || (ret == 0));
        return blendmode::GfxBlendMode(bm);
    }
    return blendmode::GfxBlendMode();
}

GfxBool GfxSurface::setClipRectOff(void) const noexcept
{
    bool ret = false;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetClipRect(surf_, NULL);
    }
    return GfxBool(ret);
}

GfxBool GfxSurface::setClipRect(rect::GfxRect const& rect) const noexcept
{
    assert(rect);

    bool ret = false;

    if (surf_ != nullptr)
    {
        ret = sdl2::SDL_SetClipRect(surf_, rect.getAsSdlTypePtr());
    }
    return GfxBool(ret);
}

rect::GfxRect GfxSurface::getClipRect(void) const noexcept
{
    rect::GfxRect::SdlType r;

    sdl2::SDL_GetClipRect(surf_, &r);
    return rect::GfxRect(r);
}

GfxSurface::SdlTypePtr GfxSurface::convertSurface(pixels::GfxPixelFormat const& fmt,
                                                  GfxSurfaceFlags const& sflags) const noexcept
{
    assert(fmt);
    assert(sflags);

    SdlTypePtr ptr = nullptr;

    if (surf_ != nullptr)
    {
        ptr = sdl2::SDL_ConvertSurface(surf_, fmt.getAsSdlTypePtr(), sflags.getAsSdlType());
    }
    return ptr;
}

GfxSurface::SdlTypePtr GfxSurface::convertSurfaceFormat(pixels::GfxPixelFormatEnum const& fmten,
                                                        GfxSurfaceFlags const& sflags) const noexcept
{
    assert(fmten);
    assert(sflags);

    SdlTypePtr ptr = nullptr;

    if (surf_ != nullptr)
    {
        ptr = sdl2::SDL_ConvertSurfaceFormat(surf_, fmten.getAsSdlType(), sflags.getAsSdlType());
    }
    return ptr;
}

void GfxSurface::convertPixels(const int32_t width, const int32_t height, pixels::GfxPixelFormatEnum const& srcfmten,
                               void * src, const int32_t pitch, pixels::GfxPixelFormatEnum const& dstfmten, void * dst,
                               const int32_t dst_pitch) const noexcept
{
    assert(width >= 0);
    assert(height >= 0);
    assert(srcfmten);
    assert(src != nullptr);
    assert(pitch >= 0);
    assert(dstfmten);
    assert(dst != nullptr);
    assert(dst_pitch >= 0);

    int32_t ret;

    ret = sdl2::SDL_ConvertPixels(width, height, srcfmten.getAsSdlType(), src, pitch, dstfmten.getAsSdlType(),
                                  dst, dst_pitch);
    assert((ret == -1) || (ret == 0));
}

void GfxSurface::fillRect(const rect::GfxRect& rect, const pixels::GfxColor& color) const noexcept
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

void GfxSurface::fillRect(const pixels::GfxColor& color) const noexcept
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

void GfxSurface::fillRects(const std::vector<rect::GfxRect>& rects, const pixels::GfxColor& color) const noexcept
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

void GfxSurface::upperBlit(GfxSurface const& src, rect::GfxRect const& srcrect,
                           rect::GfxRect const& dstrect) const noexcept
{
    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_UpperBlit(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
}

void GfxSurface::lowerBlit(GfxSurface const& src, rect::GfxRect const& srcrect,
                           rect::GfxRect const& dstrect) const noexcept
{
    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_LowerBlit(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
}

void GfxSurface::softStrech(GfxSurface const& src, rect::GfxRect const& srcrect,
                            rect::GfxRect const& dstrect) const noexcept
{
    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_SoftStretch(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
}

void GfxSurface::upperBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect,
                                 rect::GfxRect const& dstrect) const noexcept
{
    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_UpperBlitScaled(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
}

void GfxSurface::lowerBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect,
                                 rect::GfxRect const& dstrect) const noexcept
{
    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_LowerBlitScaled(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
}

void GfxSurface::blitSurface(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept
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

void GfxSurface::blitSurface(const GfxSurface& src) const noexcept
{
    assert(src);

    if (surf_ == nullptr)
    {
        return;
    }
    sdl2::SDL_BlitSurface(src.getAsSdlTypePtr(), NULL, surf_, NULL);
}

void GfxSurface::blitScaled(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept
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

GfxSurfaceFlags GfxSurface::getSurfaceFlags(void) const noexcept
{
    if (surf_ != nullptr)
    {
        return GfxSurfaceFlags(surf_->flags);
    }
    return GfxSurfaceFlags();
}

pixels::GfxPixelFormatEnum GfxSurface::getPixelFormat(void) const noexcept
{
    if (surf_ == nullptr)
    {
        return pixels::GfxPixelFormatEnum();
    }
    return pixels::GfxPixelFormatEnum(surf_->format->format);
}

int32_t GfxSurface::getWidth(void) const noexcept
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->w;
}

int32_t GfxSurface::getHeight(void) const noexcept
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->h;
}

int32_t GfxSurface::getPitch(void) const noexcept
{
    if (surf_ == nullptr)
    {
        return -1;
    }
    return surf_->pitch;
}

void * GfxSurface::getPixels(void) const noexcept
{
    if (surf_ != nullptr)
    {
        return surf_->pixels;
    }
    return nullptr;
}

void * GfxSurface::getUserData(void) const noexcept
{
    if (surf_ != nullptr)
    {
        return surf_->userdata;
    }
    return nullptr;
}

bool GfxSurface::locked(void) const noexcept
{
    if (surf_ != nullptr)
    {
        return static_cast<bool>(surf_->locked);
    }
    return false;
}

void * GfxSurface::lockData(void) const noexcept
{
    if (surf_ != nullptr)
    {
        return surf_->lock_data;
    }
    return nullptr;
}

uint32_t GfxSurface::getBitsPerPixel(void) const noexcept
{
    uint32_t ret = 0;

    if (surf_ != nullptr)
    {
        ret = surf_->format->BitsPerPixel;
    }
    return ret;
}

uint32_t GfxSurface::getBytesPerPixel(void) const noexcept
{
    uint32_t ret = 0;

    if (surf_ != nullptr)
    {
        ret = surf_->format->BytesPerPixel;
    }
    return ret;
}

std::string const& GfxSurface::getSurfaceName(void) const noexcept
{
    return surfName_;
}

void GfxSurface::putPixel(const int32_t x, const int32_t y, const pixels::GfxColor& color) const noexcept
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

pixels::GfxColor GfxSurface::getPixel(const int32_t x, const int32_t y) const noexcept
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

void GfxSurface::clear(void) noexcept
{
    surf_ = nullptr;
}

GfxSurface::SdlTypePtr GfxSurface::getAsSdlTypePtr(void) const noexcept
{
    return surf_;
}

void GfxSurface::putPixelPrv(const int32_t x, const int32_t y, const pixels::GfxColor& color) const noexcept
{
    uint32_t * ptr;
    uint32_t clr;

    clr = sdl2::SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    ptr = reinterpret_cast<uint32_t *>(surf_->pixels);
    ptr[y * surf_->w + x] = clr;
}

pixels::GfxColor GfxSurface::getPixelPrv(const int32_t x, const int32_t y) const noexcept
{
    uint8_t* ptr;

    ptr = reinterpret_cast<uint8_t*>(surf_->pixels);
    return pixels::GfxColor { pixels::GfxColor(ptr[y * surf_->w + x + 0], ptr[y * surf_->w + x + 1],
                               ptr[y * surf_->w + x + 2], ptr[y * surf_->w + x + 3]) };
}

}  // namespace surface

}  // namespace gfx

/* EOF */
