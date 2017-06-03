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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
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

class GfxSurface final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Surface SdlType;
    typedef sdl2::SDL_Surface* SdlTypePtr;

    static const char ClassName[];

    GfxSurface() = delete;

    explicit GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, int32_t width, int32_t height, int32_t depth, uint32_t Rmask,
                        uint32_t Gmask, uint32_t Bmask, uint32_t Amask) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, int32_t width, int32_t height, int32_t depth,
                        pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, void * pixels, const int32_t width, const int32_t height, const int32_t depth,
                        const int32_t pitch, const uint32_t rmask, const uint32_t gmask, const uint32_t bmask,
                        const uint32_t amask) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, void * pixels, int32_t width, int32_t height, int32_t depth, int32_t pitch,
                        pixels::GfxPixelFormatEnum const& format) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, std::string const& filename) throw(std::runtime_error);
    explicit GfxSurface(std::string const& surfname, const SdlTypePtr surf) throw(std::runtime_error);

    explicit GfxSurface(std::string const& surfname, const GfxSurfaceFlags& flags, int32_t width, int32_t height) throw(std::runtime_error);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& surf);

    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& surf);

    virtual ~GfxSurface();

    virtual explicit operator bool() const;

    void freeSurface(void);

    void setSurfacePalette(pixels::GfxPalette const& palette) const;
    void lockSurface(void) const;
    void unlockSurface(void) const;
    void saveBMP(std::string const& filename) const;
    void setSurfaceRLE(GfxBool const& flag) const;
    void setColorKey(GfxBool const& flag, pixels::GfxColor const& color) const;
    uint32_t getColorKey(void) const;
    void setSurfaceColorMod(pixels::GfxColor const& color) const;
    pixels::GfxColor getSurfaceColorMod(void) const;
    void setSurfaceAlphaMod(const uint8_t alpha) const;
    uint8_t getSurfaceAlphaMod(void) const;
    void setSurfaceBlendMode(blendmode::GfxBlendMode const& blendmode) const;
    blendmode::GfxBlendMode getSurfaceBlendMode(void) const;
    GfxBool setClipRect(void) const;
    GfxBool setClipRect(rect::GfxRect const& rect) const;
    rect::GfxRect getClipRect(void) const;
    SdlTypePtr convertSurface(pixels::GfxPixelFormat const& fmt, GfxSurfaceFlags const& sflags) const;
    SdlTypePtr convertSurfaceFormat(pixels::GfxPixelFormatEnum const& fmten, GfxSurfaceFlags const& sflags) const;
    void convertPixels(const int32_t width, const int32_t height, pixels::GfxPixelFormatEnum const& srcfmten, void * src,
                       const int32_t pitch, pixels::GfxPixelFormatEnum const& dstfmten, void * dst,
                       const int32_t dst_pitch) const;
    void fillRect(rect::GfxRect const& rect, pixels::GfxColor const& color);
    void fillRect(pixels::GfxColor const& color);
    void fillRects(std::vector<rect::GfxRect> const& rects, pixels::GfxColor const& color);
    void upperBlit(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect);
    void lowerBlit(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect);
    void softStrech(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect);
    void upperBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect);
    void lowerBlitScaled(GfxSurface const& src, rect::GfxRect const& srcrect, rect::GfxRect const& dstrect);

    void blitSurface(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr);
    void blitSurface(const GfxSurface& src);
    void blitScaled(const GfxSurface& src, const rect::GfxRect& srcr, const rect::GfxRect& dstr);

    GfxSurfaceFlags getSurfaceFlags(void) const;
    pixels::GfxPixelFormatEnum getPixelFormat(void);
    int32_t getWidth(void) const;
    int32_t getHeight(void) const;
    int32_t getPitch(void) const;
    void * getPixels(void) const;
    void * getUserData(void) const;
    bool locked(void) const;
    void * lockData(void) const;

    void putPixel(const int32_t x, const int32_t y, const pixels::GfxColor& clr);
    pixels::GfxColor getPixel(const int32_t x, const int32_t y);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    void putPixelPrv(const int32_t x, const int32_t y, const pixels::GfxColor& clr);
    pixels::GfxColor getPixelPrv(const int32_t x, const int32_t y);

    SdlTypePtr surf_;
    std::string surfName_;
};

}  // namespace surface

}  // namespace gfx

#endif /* GfxSurface_hpp */
