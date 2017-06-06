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

#ifndef GfxPixelFormat_hpp
#define GfxPixelFormat_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxPixelFormatEnum.hpp"
#include "GfxPixelType.hpp"
#include "GfxPackedOrder.hpp"
#include "GfxArrayOrder.hpp"
#include "GfxPackedLayout.hpp"
#include "GfxBitmapOrder.hpp"
#include "GfxBool.hpp"
#include "GfxPalette.hpp"
#include "GfxGammaRamp.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelFormat final : public GfxObject
{
public:
    typedef sdl2::SDL_PixelFormat* SdlTypePtr;

    static const char ClassName[];

    static const int32_t kGfxAlphaOpaque = 255;
    static const int32_t kGfxAlphaTransparent = 0;

    GfxPixelFormat() noexcept;
    explicit GfxPixelFormat(GfxPixelFormatEnum const& format) noexcept;
    explicit GfxPixelFormat(const uint32_t format) noexcept;

    /* No copy-ctor */
    GfxPixelFormat(const GfxPixelFormat& other) = delete;
    GfxPixelFormat(GfxPixelFormat&& other) noexcept;

    // No copy-oprtr
    GfxPixelFormat& operator=(const GfxPixelFormat& other) = delete;
    GfxPixelFormat& operator=(GfxPixelFormat&& other) noexcept;

    virtual ~GfxPixelFormat() noexcept;

    virtual explicit operator bool() const noexcept;

    void allocFormat(GfxPixelFormatEnum const& format) noexcept;
    void freeFormat(void) noexcept;
    GfxPixelFormatEnum getFormat(void) noexcept;

    uint32_t pixelFlag(void) const noexcept;
    GfxPixelType pixelType(void) const noexcept;
    GfxPackedOrder pixelOrderPacked(void) const noexcept;
    GfxArrayOrder pixelOrderArray(void) const noexcept;
    GfxBitmapOrder pixelOrderBitmap(void) const noexcept;
    GfxPackedLayout pixelLayout(void) const noexcept;
    uint32_t bitsPerPixel(void) const noexcept;
    uint32_t bytesPerPixel(void) const noexcept;
    bool isPixelFormatIndexed(void) const noexcept;
    bool isPixelFormatPacked(void) const noexcept;
    bool isPixelFormatArray(void) const noexcept;
    bool isPixelFormatAlpha(void) const noexcept;
    bool isPixelFormatFourCC(void) const noexcept;
    std::string getPixelFormatName(void) const noexcept;
    GfxBool pixelFormatEnumToMasks(int32_t * bpp, uint32_t * Rmask, uint32_t * Gmask,
                                   uint32_t * Bmask, uint32_t * Amask) const noexcept;
    GfxPixelFormatEnum masksToPixelFormatEnum(const int32_t bpp, const uint32_t Rmask, const uint32_t Gmask,
                                              const uint32_t Bmask, const uint32_t Amask) const noexcept;
    void setPixelFormatPalette(GfxPalette const& palette) const noexcept;
    pixels::GfxColor mapRGB(pixels::GfxColor const& color) const noexcept;
    pixels::GfxColor mapRGBA(pixels::GfxColor const& color) const noexcept;
    pixels::GfxColor getRGB(const uint32_t pixel) const noexcept;
    pixels::GfxColor getRGBA(const uint32_t pixel) const noexcept;
    void calculateGammaRamp(const float gamma, xtra::GfxGammaRamp const& ramp) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr pix_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelFormat_hpp */
