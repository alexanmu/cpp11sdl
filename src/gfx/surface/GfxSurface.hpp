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
#include "GfxYuvConversionMode.hpp"

namespace gfx
{

namespace surface
{

class GfxSurface final : public GfxObject
{
public:
    typedef SDL_Surface * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxSurface() noexcept;
    explicit GfxSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                        const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                        const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                        const int32_t height, const int32_t depth,
                        const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                        const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                        const uint32_t bmask, const uint32_t amask) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                        const int32_t depth, const int32_t pitch,
                        const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, const std::string& filename) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, const SdlTypePtr surf,
                        const bool doNotFree) throw(std::runtime_error);
    explicit GfxSurface(const std::string& surfname, const int32_t w, const int32_t h) throw(std::runtime_error);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& other) noexcept;

    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& other) noexcept;

    virtual ~GfxSurface() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth, const uint32_t Rmask, const uint32_t Gmask,
                       const uint32_t Bmask, const uint32_t Amask) throw(std::runtime_error);
    void createSurface(const std::string& surfname, const GfxSurfaceFlags& flags, const int32_t width,
                       const int32_t height, const int32_t depth,
                       const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error);
    void createSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch, const uint32_t rmask, const uint32_t gmask,
                       const uint32_t bmask, const uint32_t amask) throw(std::runtime_error);
    void createSurface(const std::string& surfname, void * pixels, const int32_t width, const int32_t height,
                       const int32_t depth, const int32_t pitch,
                       const pixels::GfxPixelFormatEnum& format) throw(std::runtime_error);
    void createSurface(const std::string& surfname, const std::string& filename) throw(std::runtime_error);
    void createSurface(const std::string& surfname, const SdlTypePtr surf,
                       const bool doNotFree) throw(std::runtime_error);
    void createSurface(const std::string& surfname, const int32_t w, const int32_t h) throw(std::runtime_error);

    void freeSurface(void) noexcept;

    void setSurfacePalette(const pixels::GfxPalette& palette) const noexcept;
    void lockSurface(void) const noexcept;
    void unlockSurface(void) const noexcept;
    const GfxBool mustLock(void) const noexcept;
    void saveBMP(const std::string& filename) const throw(std::runtime_error);
    void setSurfaceRLE(const GfxBool& flag) const noexcept;
    void setColorKey(const GfxBool& flag, const pixels::GfxColor& color) const noexcept;
    const pixels::GfxColor getColorKey(void) const noexcept;
    void setSurfaceColorMod(const pixels::GfxColor& color) const noexcept;
    const pixels::GfxColor getSurfaceColorMod(void) const noexcept;
    void setSurfaceAlphaMod(const uint8_t alpha) const noexcept;
    uint8_t getSurfaceAlphaMod(void) const noexcept;
    void setSurfaceBlendMode(const blendmode::GfxBlendMode& blendmode) const noexcept;
    const blendmode::GfxBlendMode getSurfaceBlendMode(void) const noexcept;
    const GfxBool setClipRectOff(void) const noexcept;
    const GfxBool setClipRect(const rect::GfxRect& rect) const noexcept;
    const rect::GfxRect getClipRect(void) const noexcept;
    SdlTypePtr duplicateSurface(void) const noexcept;
    SdlTypePtr convertSurface(const pixels::GfxPixelFormat& fmt, const GfxSurfaceFlags& sflags) const noexcept;
    SdlTypePtr convertSurfaceFormat(const pixels::GfxPixelFormatEnum& fmten,
                                    const GfxSurfaceFlags& sflags) const noexcept;
    void convertPixels(const int32_t width, const int32_t height, const pixels::GfxPixelFormatEnum& srcfmten,
                       void * src, const int32_t pitch, const pixels::GfxPixelFormatEnum& dstfmten, void * dst,
                       const int32_t dst_pitch) const noexcept;
    void fillRect(const rect::GfxRect& rect, const pixels::GfxColor& color) const noexcept;
    void fillRect(const pixels::GfxColor& color) const noexcept;
    void fillRects(const std::vector<rect::GfxRect>& rects, const pixels::GfxColor& color) const noexcept;
    void upperBlit(const GfxSurface& src, const rect::GfxRect& srcrect, const rect::GfxRect& dstrect) const noexcept;
    void lowerBlit(const GfxSurface& src, const rect::GfxRect& srcrect, const rect::GfxRect& dstrect) const noexcept;
    void softStrech(const GfxSurface& src, const rect::GfxRect& srcrect, const rect::GfxRect& dstrect) const noexcept;
    void upperBlitScaled(const GfxSurface& src, const rect::GfxRect& srcrect,
                         const rect::GfxRect& dstrect) const noexcept;
    void lowerBlitScaled(const GfxSurface& src, const rect::GfxRect& srcrect,
                         const rect::GfxRect& dstrect) const noexcept;

    void blitSurface(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept;
    void blitSurface(const GfxSurface& src) const noexcept;
    void blitScaled(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr) const noexcept;
    void blitScaled(const GfxSurface& src) const noexcept;

    const GfxSurfaceFlags getSurfaceFlags(void) const noexcept;
    const pixels::GfxPixelFormatEnum getPixelFormat(void) const noexcept;
    int32_t getWidth(void) const noexcept;
    int32_t getHeight(void) const noexcept;
    int32_t getPitch(void) const noexcept;
    const void * getPixels(void) const noexcept;
    const void * getUserData(void) const noexcept;
    bool locked(void) const noexcept;
    const void * lockData(void) const noexcept;
    uint32_t getBitsPerPixel(void) const noexcept;
    uint32_t getBytesPerPixel(void) const noexcept;

    const std::string& getSurfaceName(void) const noexcept;
    void setSurfaceName(const std::string& name) noexcept;

    void putPixel(const int32_t x, const int32_t y, pixels::GfxColor const& clr) const noexcept;
    const pixels::GfxColor getPixel(const int32_t x, const int32_t y) const noexcept;
    void setYUVConversionMode(const GfxYuvConversionMode& convMode) const noexcept;
    const GfxYuvConversionMode getYUVConversionMode(void) const noexcept;
    const GfxYuvConversionMode getYUVConversionModeForResolution(const int32_t width,
                                                                 const int32_t height) const noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void putPixelPrv(const int32_t x, const int32_t y, const pixels::GfxColor& clr) const noexcept;
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
