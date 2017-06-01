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
#include <string>

#include "GfxPixelFormat.hpp"

namespace gfx
{

namespace pixels
{

const char GfxPixelFormat::ClassName[] = "GfxPixelFormat";

GfxPixelFormat::GfxPixelFormat() : GfxRootClass(ClassName)
{
    pix_ = nullptr;
};

GfxPixelFormat::GfxPixelFormat(const SdlTypePtr pix) : GfxRootClass(ClassName)
{
    assert(pix != nullptr);

    pix_ = sdl2::SDL_AllocFormat(pix->format);
    if (pix_ == nullptr)
    {
        // Error handling here
    }
}

GfxPixelFormat::GfxPixelFormat(GfxPixelFormatEnum const& format) : GfxRootClass(ClassName)
{
    assert(format);

    pix_ = sdl2::SDL_AllocFormat(format.getAsSdlType());
    if (pix_ == nullptr)
    {
        // Error handling here
    }
}

GfxPixelFormat::GfxPixelFormat(GfxPixelFormat&& other) : GfxRootClass(ClassName)
{
    if (pix_ != nullptr)
    {
        sdl2::SDL_FreeFormat(pix_);
    }
    pix_ = other.pix_;
    // Delete other's data
    other.clear();
}

GfxPixelFormat& GfxPixelFormat::operator=(GfxPixelFormat&& other)
{
    if (this != &other)
    {
        if (pix_ != nullptr)
        {
            sdl2::SDL_FreeFormat(pix_);
        }
        pix_ = other.pix_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPixelFormat::~GfxPixelFormat()
{
    if (pix_ != nullptr)
    {
        sdl2::SDL_FreeFormat(pix_);
    }
}

GfxPixelFormat::operator bool() const
{
    return (pix_ != nullptr);
}

void GfxPixelFormat::allocFormat(GfxPixelFormatEnum const& format)
{
    if (pix_ != nullptr)
    {
        sdl2::SDL_FreeFormat(pix_);
    }
    pix_ = sdl2::SDL_AllocFormat(format.getAsSdlType());
    if (pix_ == nullptr)
    {
        // Error handling here
    }
}

void GfxPixelFormat::freeFormat(void)
{
    if (pix_ != nullptr)
    {
       sdl2::SDL_FreeFormat(pix_);
       pix_ = nullptr;
    }
}

GfxPixelFormatEnum GfxPixelFormat::getFormat(void)
{
    if (pix_ != nullptr)
    {
        return GfxPixelFormatEnum(pix_->format);
    }
    return GfxPixelFormatEnum(GfxPixelFormatEnum::ValueType::pixelFormatUnknown);
}

uint32_t GfxPixelFormat::pixelFlag(void) const
{
    if (pix_ == nullptr)
    {
        return 0;
    }
    return SDL_PIXELFLAG(pix_->format);
}

GfxPixelType GfxPixelFormat::pixelType(void) const
{
    if (pix_ == nullptr)
    {
        return GfxPixelType(GfxPixelType::ValueType::pixelTypeUnknown);
    }
    return GfxPixelType(SDL_PIXELTYPE(pix_->format));
}

GfxPackedOrder GfxPixelFormat::pixelOrderPacked(void) const
{
    if (pix_ == nullptr)
    {
        return GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderNone);
    }
    return GfxPackedOrder(SDL_PIXELORDER(pix_->format));
}

GfxArrayOrder GfxPixelFormat::pixelOrderArray(void) const
{
    if (pix_ == nullptr)
    {
        return GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderNone);
    }
    return GfxArrayOrder(SDL_PIXELORDER(pix_->format));
}

GfxBitmapOrder GfxPixelFormat::pixelOrderBitmap(void) const
{
    if (pix_ == nullptr)
    {
        return GfxBitmapOrder(GfxBitmapOrder::ValueType::bitmapOrderNone);
    }
    return GfxBitmapOrder(SDL_PIXELORDER(pix_->format));
}

GfxPackedLayout GfxPixelFormat::pixelLayout(void) const
{
    if (pix_ == nullptr)
    {
        return GfxPackedLayout(GfxPackedLayout::ValueType::packedLayoutNone);
    }
    return GfxPackedLayout(SDL_PIXELLAYOUT(pix_->format));
}

uint32_t GfxPixelFormat::bitsPerPixel(void) const
{
    if (pix_ == nullptr)
    {
        return 0;
    }
    return SDL_BITSPERPIXEL(pix_->format);
}

uint32_t GfxPixelFormat::bytesPerPixel(void) const
{
    uint32_t temp;

    if (pix_ == nullptr)
    {
        return 0;
    }
    if (isPixelFormatFourCC() == true)
    {
        if ((static_cast<GfxPixelFormatEnum::ValueType>(pix_->format) ==
                                GfxPixelFormatEnum::ValueType::pixelFormatYUY2) ||
            (static_cast<GfxPixelFormatEnum::ValueType>(pix_->format) ==
                                GfxPixelFormatEnum::ValueType::pixelFormatUYVY) ||
            (static_cast<GfxPixelFormatEnum::ValueType>(pix_->format) ==
                                GfxPixelFormatEnum::ValueType::pixelFormatYVYU))
        {
            temp = 2;
        }
        else
        {
            temp = 1;
        }
    }
    else
    {
        temp = pix_->format & 0xFF;
    }
    return temp;
}

bool GfxPixelFormat::isPixelFormatIndexed(void) const
{
    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeIndex1) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeIndex4) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeIndex8));
    return temp;
}

bool GfxPixelFormat::isPixelFormatPacked(void) const
{
    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypePacked8) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypePacked16) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypePacked32));
    return temp;
}

bool GfxPixelFormat::isPixelFormatArray(void) const
{
    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeArrayU8) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeArrayU16) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeArrayU32) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeArrayF16) ||
                pixelType() == GfxPixelType(GfxPixelType::ValueType::pixelTypeArrayF32));
    return temp;
}

bool GfxPixelFormat::isPixelFormatAlpha(void) const
{
    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = false;
    if (isPixelFormatPacked() == true &&
        (
            pixelOrderPacked() == GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderARGB) ||
            pixelOrderPacked() == GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderRGBA) ||
            pixelOrderPacked() == GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderABGR) ||
            pixelOrderPacked() == GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderBGRA)))
    {
        temp = true;
    }
    if (isPixelFormatArray() == true &&
        (
            pixelOrderArray() == GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderARGB) ||
            pixelOrderArray() == GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderRGBA) ||
            pixelOrderArray() == GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderABGR) ||
            pixelOrderArray() == GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderBGRA)))
    {
        temp = true;
    }
    return temp;
}

bool GfxPixelFormat::isPixelFormatFourCC(void) const
{
    if (pix_ == nullptr)
    {
        return false;
    }
    return ((pix_->format != 0) && (pixelFlag() != 1));
}

std::string GfxPixelFormat::getPixelFormatName(void) const
{
    std::string str {"$nullptr$"};

    if (pix_ != nullptr)
    {
        str = sdl2::SDL_GetPixelFormatName(pix_->format);
    }
    return str;
}

GfxBool GfxPixelFormat::pixelFormatEnumToMasks(int32_t * bpp, uint32_t * Rmask, uint32_t * Gmask,
                    uint32_t * Bmask, uint32_t * Amask)
{
    assert(bpp != nullptr);
    assert(Rmask != nullptr);
    assert(Gmask != nullptr);
    assert(Bmask != nullptr);
    assert(Amask != nullptr);

    GfxBool::SdlType sdlbool;

    if (pix_ != nullptr)
    {
        sdlbool = sdl2::SDL_PixelFormatEnumToMasks(pix_->format, bpp, Rmask, Gmask, Bmask, Amask);
    }
    else
    {
        sdlbool = sdl2::SDL_FALSE;
    }
    return GfxBool(sdlbool);
}

GfxPixelFormatEnum GfxPixelFormat::masksToPixelFormatEnum(int32_t bpp, uint32_t Rmask, uint32_t Gmask,
                    uint32_t Bmask, uint32_t Amask)
{
    GfxPixelFormatEnum::SdlType sdlpixfmten;

    sdlpixfmten = sdl2::SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
    return GfxPixelFormatEnum(sdlpixfmten);
}

void GfxPixelFormat::clear(void)
{
    if (pix_ != nullptr)
    {
        SDL_FreeFormat(pix_);
        pix_ = nullptr;
    }
}

void GfxPixelFormat::setPixelFormatPalette(GfxPalette const& palette)
{
    assert(palette);

    if (pix_ != nullptr)
    {
        sdl2::SDL_SetPixelFormatPalette(pix_, palette.getAsSdlTypePtr());
    }
}

uint32_t GfxPixelFormat::mapRGB(uint8_t r, uint8_t g, uint8_t b)
{
    if (pix_ != nullptr)
    {
        return sdl2::SDL_MapRGB(pix_, r, g, b);
    }
    return 0;
}

uint32_t GfxPixelFormat::mapRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if (pix_ != nullptr)
    {
        return sdl2::SDL_MapRGBA(pix_, r, g, b, a);
    }
    return 0;
}

void GfxPixelFormat::getRGB(uint32_t pixel, uint8_t * r, uint8_t * g, uint8_t * b)
{
    assert(r != nullptr);
    assert(g != nullptr);
    assert(b != nullptr);

    if (pix_ != nullptr)
    {
        sdl2::SDL_GetRGB(pixel, pix_, r, g, b);
    }
    else
    {
        *r = 0;
        *g = 0;
        *b = 0;
    }
}

void GfxPixelFormat::getRGBA(uint32_t pixel, uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a)
{
    assert(r != nullptr);
    assert(g != nullptr);
    assert(b != nullptr);
    assert(a != nullptr);

    if (pix_ != nullptr)
    {
        sdl2::SDL_GetRGBA(pixel, pix_, r, g, b, a);
    }
    else
    {
        *r = 0;
        *g = 0;
        *b = 0;
        *a = 0;
    }
}

void GfxPixelFormat::calculateGammaRamp(float gamma, supp::GfxGammaRamp const& ramp)
{
    assert(ramp);

    sdl2::SDL_CalculateGammaRamp(gamma, ramp.getAsSdlTypePtr());
}

/*** SDL ***/
GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)pix_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
