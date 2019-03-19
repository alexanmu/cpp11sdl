/*
  Giotto
  Copyright (C) 2019 George Oros

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
#include <utility>

#include "GfxSurface.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxsurface::surface::gfx");

namespace gfx
{

namespace surface
{

const char GfxSurface::ClassName[] = "GfxSurface";

const pixels::GfxPixelFormatEnum::ValueType GfxSurface::kDefaultSurfaceColorFormatValue =
    pixels::GfxPixelFormatEnum::ValueType::pixelFormatARGB8888;

GfxSurface::GfxSurface() noexcept : GfxObject(ClassName)
{
    surf_ = nullptr;
    surfName_ = "$init$";
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                       const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(flags);
    assert(flags.getAsSdlType() == 0);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);

    SdlTypePtr tmpsurfptr;

    tmpsurfptr = SDL_CreateRGBSurface(flags.getAsSdlType(), width, height, depth, Rmask,
                                      Gmask, Bmask, Amask);
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth,
                       const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(flags);
    assert(flags.getAsSdlType() == 0);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(format);
    assert(format.getValue() != pixels::GfxPixelFormatEnum::ValueType::pixelFormatUnknown);

    SdlTypePtr tmpsurfptr;

    tmpsurfptr = SDL_CreateRGBSurfaceWithFormat(flags.getAsSdlType(), width, height, depth,
                                                format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                       const uint32_t bmask, const uint32_t amask) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width >= 0);
    assert(height >= 0);
    assert(depth >= 0);
    assert(pitch >= 0);

    SdlTypePtr tmpsurfptr;

    tmpsurfptr = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch,
                       const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(pitch > 0);
    assert(format);
    assert(format.getValue() != pixels::GfxPixelFormatEnum::ValueType::pixelFormatUnknown);

    SdlTypePtr tmpsurfptr;

    tmpsurfptr = SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, const std::string& filename) throw(std::runtime_error) :
            GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(filename.length() > 0);

    SdlTypePtr tmpsurfptr;

    auto rw = SDL_RWFromFile(filename.c_str(), "rb");
    if (rw == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    tmpsurfptr = SDL_LoadBMP_RW(rw, 0);  // 1 = auto-close file
    SDL_RWclose(rw);
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to load surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(const std::string& surfname, const SdlTypePtr surf, const bool doNotFree)
            throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(surf != nullptr);

    surf_ = surf;
    surfName_ = surfname;
    doNotFree_ = doNotFree;
}

GfxSurface::GfxSurface(const std::string& surfname, const int32_t w, const int32_t h) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(w > 0);
    assert(h > 0);

    SdlTypePtr tmpsurfptr;
    pixels::GfxPixelFormatEnum pixFmtEn(kDefaultSurfaceColorFormatValue);

    tmpsurfptr = SDL_CreateRGBSurfaceWithFormat(GfxSurfaceFlags().getAsSdlType(), w, h,
                                                      kDefaultSurfaceColorDepth, pixFmtEn.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

GfxSurface::GfxSurface(GfxSurface&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    freeSurface();
    surf_ = other.surf_;
    surfName_ = other.surfName_;
    doNotFree_ = other.doNotFree_;
    // Delete other's data
    other.surf_ = nullptr;
    other.surfName_.clear();
    other.doNotFree_ = false;
}

GfxSurface& GfxSurface::operator=(GfxSurface&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        freeSurface();
        surf_ = other.surf_;
        surfName_ = other.surfName_;
        doNotFree_ = other.doNotFree_;
        // Delete other's data
        other.surf_ = nullptr;
        other.surfName_.clear();
        other.doNotFree_ = false;
    }
    return *this;
}

GfxSurface::~GfxSurface() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    freeSurface();
}

GfxSurface::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (surf_ != nullptr);
}

std::string GfxSurface::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxSurface::createSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                               const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                               const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(flags);
    assert(flags.getAsSdlType() == 0);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    SdlTypePtr tmpsurfptr;

    tmpsurfptr = SDL_CreateRGBSurface(flags.getAsSdlType(), width, height, depth, Rmask,
                                      Gmask, Bmask, Amask);
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

void GfxSurface::createSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                               const int32_t height, const int32_t depth,
                               const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(flags);
    assert(flags.getAsSdlType() == 0);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(format);
    assert(format.getValue() != pixels::GfxPixelFormatEnum::ValueType::pixelFormatUnknown);

    SdlTypePtr tmpsurfptr;

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    tmpsurfptr = SDL_CreateRGBSurfaceWithFormat(flags.getAsSdlType(), width, height, depth,
                                                format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}


void GfxSurface::createSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                               const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                               const uint32_t bmask, const uint32_t amask) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width >= 0);
    assert(height >= 0);
    assert(depth >= 0);
    assert(pitch >= 0);

    SdlTypePtr tmpsurfptr;

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    tmpsurfptr = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

void GfxSurface::createSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                               const int32_t depth, const int32_t pitch,
                               const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(pixels != nullptr);
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    assert(pitch > 0);
    assert(format);
    assert(format.getValue() != pixels::GfxPixelFormatEnum::ValueType::pixelFormatUnknown);

    SdlTypePtr tmpsurfptr;

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    tmpsurfptr = SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, format.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

void GfxSurface::createSurface(const std::string& surfname, const std::string& filename) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(filename.length() > 0);

    SdlTypePtr tmpsurfptr;

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    auto rw = SDL_RWFromFile(filename.c_str(), "rb");
    if (rw == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
    tmpsurfptr = SDL_LoadBMP_RW(rw, 0);  // 1 = auto-close file
    SDL_RWclose(rw);
    if (tmpsurfptr == nullptr)
    {
        throw std::runtime_error("Unable to load surface");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

void GfxSurface::createSurface(const std::string& surfname, const SdlTypePtr surf,
                               const bool doNotFree) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(surf != nullptr);

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    surf_ = surf;
    surfName_ = surfname;
    doNotFree_ = doNotFree;
}

void GfxSurface::createSurface(const std::string& surfname, const int32_t w,
                               const int32_t h) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(surfname.length() > 0);
    assert(w > 0);
    assert(h > 0);

    if (surf_ != nullptr)
    {
        throw std::runtime_error("Surface already created");
    }
    SdlTypePtr tmpsurfptr;
    pixels::GfxPixelFormatEnum pixFmtEn(kDefaultSurfaceColorFormatValue);

    tmpsurfptr = SDL_CreateRGBSurfaceWithFormat(GfxSurfaceFlags().getAsSdlType(), w, h,
                                                      kDefaultSurfaceColorDepth, pixFmtEn.getAsSdlType());
    if (tmpsurfptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create surface (" + sdlErr + ")");
    }
    surf_ = tmpsurfptr;
    surfName_ = surfname;
    doNotFree_ = false;
}

void GfxSurface::freeSurface(void) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if ((surf_ != nullptr) && (doNotFree_ == false))
    {
        SDL_FreeSurface(surf_);
        surf_ = nullptr;
    }
}

void GfxSurface::setSurfacePalette(const pixels::GfxPalette& palette) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(palette);

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetSurfacePalette(surf_, palette.getAsSdlTypePtr());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxSurface::lockSurface(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_LockSurface(surf_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxSurface::unlockSurface(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        SDL_UnlockSurface(surf_);
    }
}

const GfxBool GfxSurface::mustLock(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool ret;

    if (surf_ != nullptr)
    {
        ret = SDL_MUSTLOCK(surf_);
        return GfxBool(ret);
    }
    return GfxBool(false);
}

void GfxSurface::saveBMP(const std::string& filename) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        auto rw = SDL_RWFromFile(filename.c_str(), "wb");
        if (rw == nullptr)
        {
            throw std::runtime_error(SDL_GetError());
        }
        ret = SDL_SaveBMP_RW(surf_, rw, 0);  // 1 = auto-close file
        SDL_RWclose(rw);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxSurface::setSurfaceRLE(const GfxBool& flag) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetSurfaceRLE(surf_, static_cast<int32_t>(flag.getValue()));
        assert((ret == 1) || (ret == 0));
    }
}

void GfxSurface::setColorKey(const GfxBool& flag, const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetColorKey(surf_, static_cast<int32_t>(flag.getValue()), color.getColor());
        assert((ret == 1) || (ret == 0));
    }
}

const pixels::GfxColor GfxSurface::getColorKey(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    uint32_t key = 0;

    if (surf_ != nullptr)
    {
        ret = SDL_GetColorKey(surf_, &key);
        assert((ret == 1) || (ret == 0));
    }
    return pixels::GfxColor(key);
}

void GfxSurface::setSurfaceColorMod(const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetSurfaceColorMod(surf_, color.getRed(), color.getGreen(), color.getBlue());
        assert((ret == 1) || (ret == 0));
    }
}

const pixels::GfxColor GfxSurface::getSurfaceColorMod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    if (surf_ != nullptr)
    {
        ret = SDL_GetSurfaceColorMod(surf_, &r, &g, &b);
        assert((ret == 1) || (ret == 0));
    }
    return pixels::GfxColor(r, g, b);
}

void GfxSurface::setSurfaceAlphaMod(uint8_t alpha) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetSurfaceAlphaMod(surf_, alpha);
        assert((ret == 1) || (ret == 0));
    }
}

uint8_t GfxSurface::getSurfaceAlphaMod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    uint8_t alpha = 0;

    if (surf_ != nullptr)
    {
        ret = SDL_GetSurfaceAlphaMod(surf_, &alpha);
        assert((ret == 1) || (ret == 0));
    }
    return alpha;
}

void GfxSurface::setSurfaceBlendMode(const blendmode::GfxBlendMode& blendmode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (surf_ != nullptr)
    {
        ret = SDL_SetSurfaceBlendMode(surf_, blendmode.getAsSdlType());
        assert((ret == 1) || (ret == 0));
    }
}

const blendmode::GfxBlendMode GfxSurface::getSurfaceBlendMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    blendmode::GfxBlendMode::SdlType bm;

    if (surf_ != nullptr)
    {
        ret = SDL_GetSurfaceBlendMode(surf_, &bm);
        assert((ret == 1) || (ret == 0));
        return blendmode::GfxBlendMode(bm);
    }
    return blendmode::GfxBlendMode();
}

const GfxBool GfxSurface::setClipRectOff(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool ret = false;

    if (surf_ != nullptr)
    {
        ret = SDL_SetClipRect(surf_, NULL);
    }
    return GfxBool(ret);
}

const GfxBool GfxSurface::setClipRect(const rect::GfxRect& rect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);

    bool ret = false;

    if (surf_ != nullptr)
    {
        ret = SDL_SetClipRect(surf_, rect.getAsSdlTypePtr());
    }
    return GfxBool(ret);
}

const rect::GfxRect GfxSurface::getClipRect(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    rect::GfxRect::SdlType r;

    if (surf_ != nullptr)
    {
        SDL_GetClipRect(surf_, &r);
        return rect::GfxRect(r);
    }
    return rect::GfxRect();
}

GfxSurface::SdlTypePtr GfxSurface::duplicateSurface(void) const noexcept
{
#warning Should create new GfxSurface object here!
    LOG_TRACE_PRIO_LOW();

    SdlTypePtr ptr = nullptr;

    if (surf_ != nullptr)
    {
        ptr = SDL_DuplicateSurface(surf_);
    }
    return ptr;
}

GfxSurface::SdlTypePtr GfxSurface::convertSurface(const pixels::GfxPixelFormat& fmt,
                                                  const GfxSurfaceFlags& sflags) const noexcept
{
#warning Either inplace conversion or return new GfxSurface object
    LOG_TRACE_PRIO_LOW();

    assert(fmt);
    assert(sflags);

    SdlTypePtr ptr = nullptr;

    if (surf_ != nullptr)
    {
        ptr = SDL_ConvertSurface(surf_, fmt.getAsSdlTypePtr(), sflags.getAsSdlType());
    }
    return ptr;
}

GfxSurface::SdlTypePtr GfxSurface::convertSurfaceFormat(const pixels::GfxPixelFormatEnum& fmten,
                                                        const GfxSurfaceFlags& sflags) const noexcept
{
#warning Either inplace conversion or return new GfxSurface object
    LOG_TRACE_PRIO_LOW();

    assert(fmten);
    assert(sflags);

    SdlTypePtr ptr = nullptr;

    if (surf_ != nullptr)
    {
        ptr = SDL_ConvertSurfaceFormat(surf_, fmten.getAsSdlType(), sflags.getAsSdlType());
    }
    return ptr;
}

void GfxSurface::convertPixels(const int32_t width, const int32_t height, const pixels::GfxPixelFormatEnum& srcfmten,
                               void * src, const int32_t pitch, const pixels::GfxPixelFormatEnum& dstfmten, void * dst,
                               const int32_t dst_pitch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(width >= 0);
    assert(height >= 0);
    assert(srcfmten);
    assert(src != nullptr);
    assert(pitch >= 0);
    assert(dstfmten);
    assert(dst != nullptr);
    assert(dst_pitch >= 0);

    int32_t ret;

    ret = SDL_ConvertPixels(width, height, srcfmten.getAsSdlType(), src, pitch, dstfmten.getAsSdlType(),
                            dst, dst_pitch);
    assert((ret == -1) || (ret == 0));
}

void GfxSurface::fillRect(const rect::GfxRect& rect, const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);
    assert(color);

    uint32_t clr;

    if (surf_ != nullptr)
    {
        clr = SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        SDL_FillRect(surf_, rect.getAsSdlTypePtr(), clr);
    }
}

void GfxSurface::fillRect(const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(color);

    uint32_t clr;

    if (surf_ != nullptr)
    {
        clr = SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        SDL_FillRect(surf_, NULL, clr);
    }
}

void GfxSurface::fillRects(const std::vector<rect::GfxRect>& rects, const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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

void GfxSurface::upperBlit(const GfxSurface& src, const rect::GfxRect& srcrect,
                           const rect::GfxRect& dstrect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ != nullptr)
    {
        SDL_UpperBlit(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
    }
}

void GfxSurface::lowerBlit(const GfxSurface& src, const rect::GfxRect& srcrect,
                           const rect::GfxRect& dstrect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ != nullptr)
    {
        SDL_LowerBlit(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
    }
}

void GfxSurface::softStrech(const GfxSurface& src, const rect::GfxRect& srcrect,
                            const rect::GfxRect& dstrect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ != nullptr)
    {
        SDL_SoftStretch(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
    }
}

void GfxSurface::upperBlitScaled(const GfxSurface& src, const rect::GfxRect& srcrect,
                                 const rect::GfxRect& dstrect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ != nullptr)
    {
        SDL_UpperBlitScaled(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
    }
}

void GfxSurface::lowerBlitScaled(const GfxSurface& src, const rect::GfxRect& srcrect,
                                 const rect::GfxRect& dstrect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcrect);
    assert(dstrect);

    if (surf_ != nullptr)
    {
        SDL_LowerBlitScaled(src.getAsSdlTypePtr(), srcrect.getAsSdlTypePtr(), surf_, dstrect.getAsSdlTypePtr());
    }
}

void GfxSurface::blitSurface(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcr);
    assert(dstr);

    if (surf_ != nullptr)
    {
        SDL_BlitSurface(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
    }
}

void GfxSurface::blitSurface(const GfxSurface& src) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);

    if (surf_ != nullptr)
    {
        SDL_BlitSurface(src.getAsSdlTypePtr(), NULL, surf_, NULL);
    }
}

void GfxSurface::blitScaled(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);
    assert(srcr);
    assert(dstr);

    if (surf_ != nullptr)
    {
        SDL_BlitScaled(src.getAsSdlTypePtr(), srcr.getAsSdlTypePtr(), surf_, dstr.getAsSdlTypePtr());
    }
}

void GfxSurface::blitScaled(const GfxSurface& src) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(src);

    if (surf_ != nullptr)
    {
        SDL_BlitScaled(src.getAsSdlTypePtr(), NULL, surf_, NULL);
    }
}

const GfxSurfaceFlags GfxSurface::getSurfaceFlags(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return GfxSurfaceFlags(surf_->flags);
    }
    return GfxSurfaceFlags();
}

const pixels::GfxPixelFormatEnum GfxSurface::getPixelFormat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return pixels::GfxPixelFormatEnum(surf_->format->format);
    }
    return pixels::GfxPixelFormatEnum();
}

int32_t GfxSurface::getWidth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->w;
    }
    return -1;
}

int32_t GfxSurface::getHeight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->h;
    }
    return -1;
}

int32_t GfxSurface::getPitch(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->pitch;
    }
    return -1;
}

const void * GfxSurface::getPixels(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->pixels;
    }
    return nullptr;
}

const void * GfxSurface::getUserData(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->userdata;
    }
    return nullptr;
}

bool GfxSurface::locked(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return static_cast<bool>(surf_->locked);
    }
    return false;
}

const void * GfxSurface::lockData(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (surf_ != nullptr)
    {
        return surf_->lock_data;
    }
    return nullptr;
}

uint32_t GfxSurface::getBitsPerPixel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = 0;

    if (surf_ != nullptr)
    {
        if (surf_->format != nullptr)
        {
            ret = surf_->format->BitsPerPixel;
        }
    }
    return ret;
}

uint32_t GfxSurface::getBytesPerPixel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = 0;

    if (surf_ != nullptr)
    {
        if (surf_->format != nullptr)
        {
            ret = surf_->format->BytesPerPixel;
        }
    }
    return ret;
}

const std::string& GfxSurface::getSurfaceName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return surfName_;
}

void GfxSurface::setSurfaceName(const std::string& name) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    surfName_ = name;
}

void GfxSurface::putPixel(const int32_t x, const int32_t y, const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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
    SDL_LockSurface(surf_);
    putPixelPrv(x, y, color);
    SDL_UnlockSurface(surf_);
}

const pixels::GfxColor GfxSurface::getPixel(const int32_t x, const int32_t y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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
    SDL_LockSurface(surf_);
    pix = getPixelPrv(x, y);
    SDL_UnlockSurface(surf_);
    return pix;
}

void GfxSurface::setYUVConversionMode(const GfxYuvConversionMode& convMode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(convMode);

    SDL_SetYUVConversionMode(convMode.getAsSdlType());
}

const GfxYuvConversionMode GfxSurface::getYUVConversionMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxYuvConversionMode::SdlType convMode;

    convMode = SDL_GetYUVConversionMode();
    return GfxYuvConversionMode(convMode);
}

const GfxYuvConversionMode GfxSurface::getYUVConversionModeForResolution(const int32_t width,
        const int32_t height) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(width > 0);
    assert(height > 0);

    GfxYuvConversionMode::SdlType convMode;

    convMode = SDL_GetYUVConversionModeForResolution(width, height);
    return GfxYuvConversionMode(convMode);
}

GfxSurface::SdlTypePtr GfxSurface::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return surf_;
}

void GfxSurface::putPixelPrv(const int32_t x, const int32_t y, const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t * ptr;
    uint32_t clr;

    clr = SDL_MapRGBA(surf_->format, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    ptr = reinterpret_cast<uint32_t *>(surf_->pixels);
    ptr[y * surf_->w + x] = clr;
}

pixels::GfxColor GfxSurface::getPixelPrv(const int32_t x, const int32_t y) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint8_t * ptr;

    ptr = reinterpret_cast<uint8_t*>(surf_->pixels);
    return pixels::GfxColor { pixels::GfxColor(ptr[y * surf_->w + x + 0], ptr[y * surf_->w + x + 1],
                               ptr[y * surf_->w + x + 2], ptr[y * surf_->w + x + 3]) };
}

}  // namespace surface

}  // namespace gfx

/* EOF */
