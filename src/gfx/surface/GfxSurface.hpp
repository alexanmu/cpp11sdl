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

#ifndef GfxSurface_hpp
#define GfxSurface_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxPixelFormatEnum.hpp"
#include "GfxRect.hpp"
#include "GfxColor.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxPalette.hpp"
#include "GfxBlendMode.hpp"
#include "GfxPixelFormat.hpp"

namespace gfx
{

namespace surface
{

class GfxSurface final : public GfxObject
{
public:
    typedef sdl2::SDL_Surface * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxSurface();
    explicit GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                        const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                        const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                        const int32_t height, const int32_t depth,
                        pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height,
                        const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                        const uint32_t bmask, const uint32_t amask) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height,
                        const int32_t depth, const int32_t pitch,
                        pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, std::string const& filename) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, const SdlTypePtr surf,
                        const bool doNotFree) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, const int32_t w, const int32_t h) throw(std::runtime_error);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& other) noexcept;

    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& other) noexcept;

    virtual ~GfxSurface() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createSurface(std::string const& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                       const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error);
    void createSurface(std::string const& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth,
                       pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    void createSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                       const uint32_t bmask, const uint32_t amask) throw(std::runtime_error);
    void createSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch,
                       pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    void createSurface(std::string const& surfname, std::string const& filename) throw(std::runtime_error);
    void createSurface(std::string const& surfname, const SdlTypePtr surf,
                       const bool doNotFree) throw(std::runtime_error);
    void createSurface(std::string const& surfname, const int32_t w, const int32_t h) throw(std::runtime_error);

    void freeSurface(void) noexcept;

    void setSurfacePalette(pixels::GfxPalette const& palette) const noexcept;
    void lockSurface(void) const noexcept;
    void unlockSurface(void) const noexcept;
    GfxBool mustLock(void) const noexcept;
    void saveBMP(std::string const& filename) const throw(std::runtime_error);
    void setSurfaceRLE(GfxBool const& flag) const noexcept;
    void setColorKey(GfxBool const& flag, pixels::GfxColor const& color) const noexcept;
    pixels::GfxColor getColorKey(void) const noexcept;
    void setSurfaceColorMod(pixels::GfxColor const& color) const noexcept;
    pixels::GfxColor getSurfaceColorMod(void) const noexcept;
    void setSurfaceAlphaMod(const uint8_t alpha) const noexcept;
    uint8_t getSurfaceAlphaMod(void) const noexcept;
    void setSurfaceBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept;
    blendmode::GfxBlendMode getSurfaceBlendMode(void) const noexcept;
    GfxBool setClipRectOff(void) const noexcept;
    GfxBool setClipRect(rect::GfxRect const& rect) const noexcept;
    rect::GfxRect getClipRect(void) const noexcept;
    SdlTypePtr duplicateSurface(void) const noexcept;
    SdlTypePtr convertSurface(pixels::GfxPixelFormat const& fmt, GfxSurfaceFlags const& sflags) const noexcept;
    SdlTypePtr convertSurfaceFormat(pixels::GfxPixelFormatEnum const& fmten,
                                    GfxSurfaceFlags const& sflags) const noexcept;
    void convertPixels(const int32_t width, const int32_t height, pixels::GfxPixelFormatEnum const& srcfmten,
                       void * src, const int32_t pitch, pixels::GfxPixelFormatEnum const& dstfmten, void * dst,
                       const int32_t dst_pitch) const noexcept;
    void fillRect(rect::GfxRect const& rect, pixels::GfxColor const& color) const noexcept;
    void fillRect(pixels::GfxColor const& color) const noexcept;
    void fillRects(std::vector<rect::GfxRect> const& rects, pixels::GfxColor const& color) const noexcept;
    void upperBlit(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect) const noexcept;
    void lowerBlit(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect) const noexcept;
    void softStrech(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect) const noexcept;
    void upperBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect,
                         rect::GfxRect const& dstrect) const noexcept;
    void lowerBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect,
                         rect::GfxRect const& dstrect) const noexcept;

    void blitSurface(GfxSurface const& src, rect::GfxRect const& srcr, rect::GfxRect const& dstr) const noexcept;
    void blitSurface(GfxSurface const& src) const noexcept;
    void blitScaled(GfxSurface const& src, rect::GfxRect const& srcr, rect::GfxRect const& dstr) const noexcept;
    void blitScaled(GfxSurface const& src) const noexcept;

    GfxSurfaceFlags getSurfaceFlags(void) const noexcept;
    pixels::GfxPixelFormatEnum getPixelFormat(void) const noexcept;
    int32_t getWidth(void) const noexcept;
    int32_t getHeight(void) const noexcept;
    int32_t getPitch(void) const noexcept;
    void * getPixels(void) const noexcept;
    void * getUserData(void) const noexcept;
    bool locked(void) const noexcept;
    void * lockData(void) const noexcept;
    uint32_t getBitsPerPixel(void) const noexcept;
    uint32_t getBytesPerPixel(void) const noexcept;

    std::string const& getSurfaceName(void) const noexcept;
    void setSurfaceName(std::string const& name) noexcept;

    void putPixel(const int32_t x, const int32_t y, pixels::GfxColor const& clr) const noexcept;
    pixels::GfxColor getPixel(const int32_t x, const int32_t y) const noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void putPixelPrv(const int32_t x, const int32_t y, pixels::GfxColor const& clr) const noexcept;
    pixels::GfxColor getPixelPrv(const int32_t x, const int32_t y) const noexcept;

    SdlTypePtr surf_;
    std::string surfName_;
    bool doNotFree_;

    static const int32_t kDefaultSurfaceColorDepth = 32;
    static const pixels::GfxPixelFormatEnum::ValueType kDefaultSurfaceColorFormatValue;
};

}  // namespace surface

}  // namespace gfx

#endif /* GfxSurface_hpp */
