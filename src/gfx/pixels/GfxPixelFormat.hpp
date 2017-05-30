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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxPixelFormatEnum.hpp"
#include "GfxPixelType.hpp"
#include "GfxPackedOrder.hpp"
#include "GfxArrayOrder.hpp"
#include "GfxPackedLayout.hpp"
#include "GfxBitmapOrder.hpp"
#include "GfxBool.hpp"
#include "GfxPalette.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelFormat final : public GfxRootClass
{
public:
    typedef sdl2::SDL_PixelFormat* SdlTypePtr;

    static const char ClassName[];

    static const int32_t kGfxAlphaOpaque = 255;
    static const int32_t kGfxAlphaTransparent = 0;

    GfxPixelFormat();
    explicit GfxPixelFormat(const SdlTypePtr pix);
    explicit GfxPixelFormat(GfxPixelFormatEnum const& format);

    /* No copy-ctor */
    GfxPixelFormat(const GfxPixelFormat& other) = delete;
    GfxPixelFormat(GfxPixelFormat&& other);

    // No copy-oprtr
    GfxPixelFormat& operator=(const GfxPixelFormat& other) = delete;
    GfxPixelFormat& operator=(GfxPixelFormat&& other);

    virtual ~GfxPixelFormat();

    virtual explicit operator bool() const;

    void allocFormat(GfxPixelFormatEnum const& format);
    void freeFormat(void);
    GfxPixelFormatEnum getFormat(void);

    uint32_t pixelFlag(void) const;
    GfxPixelType pixelType(void) const;
    GfxPackedOrder pixelOrderPacked(void) const;
    GfxArrayOrder pixelOrderArray(void) const;
    GfxBitmapOrder pixelOrderBitmap(void) const;
    GfxPackedLayout pixelLayout(void) const;
    uint32_t bitsPerPixel(void) const;
    uint32_t bytesPerPixel(void) const;
    bool isPixelFormatIndexed(void) const;
    bool isPixelFormatPacked(void) const;
    bool isPixelFormatArray(void) const;
    bool isPixelFormatAlpha(void) const;
    bool isPixelFormatFourCC(void) const;
    std::string getPixelFormatName(void) const;
    GfxBool pixelFormatEnumToMasks(int32_t * bpp, uint32_t * Rmask, uint32_t * Gmask,
                            uint32_t * Bmask, uint32_t * Amask);
    GfxPixelFormatEnum masksToPixelFormatEnum(int32_t bpp, uint32_t Rmask, uint32_t Gmask,
                            uint32_t Bmask, uint32_t Amask);
    void setPixelFormatPalette(GfxPalette const& palette);
    uint32_t mapRGB(uint8_t r, uint8_t g, uint8_t b);
    uint32_t mapRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void getRGB(uint32_t pixel, uint8_t * r, uint8_t * g, uint8_t * b);
    void getRGBA(uint32_t pixel, uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a);
    void calculateGammaRamp(float gamma, uint16_t * ramp);

    void clear(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlTypePtr pix_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelFormat_hpp */
