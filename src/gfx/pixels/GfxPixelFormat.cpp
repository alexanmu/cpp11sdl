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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxPixelFormat.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpixelformat::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxPixelFormat::ClassName[] = "GfxPixelFormat";

GfxPixelFormat::GfxPixelFormat() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    clear();
};

GfxPixelFormat::GfxPixelFormat(const GfxPixelFormatEnum& format) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(format);

    SdlTypePtr pixptr;

    pixptr = SDL_AllocFormat(format.getAsSdlType());
    if (pixptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create pixel format (" + sdlErr + ")");
    }
    pix_ = pixptr;
}

GfxPixelFormat::GfxPixelFormat(const uint32_t format) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    SdlTypePtr pixptr;

    pixptr = SDL_AllocFormat(format);
    if (pixptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create pixel format (" + sdlErr + ")");
    }
    pix_ = pixptr;
}

GfxPixelFormat::GfxPixelFormat(GfxPixelFormat&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_HIGH();

    pix_ = other.pix_;
    // Delete other's data
    other.clear();
}

GfxPixelFormat& GfxPixelFormat::operator=(GfxPixelFormat&& other) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        if (pix_ != nullptr)
        {
            SDL_FreeFormat(pix_);
        }
        pix_ = other.pix_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPixelFormat::~GfxPixelFormat() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if (pix_ != nullptr)
    {
        SDL_FreeFormat(pix_);
    }
    pix_ = nullptr;
}

GfxPixelFormat::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (pix_ != nullptr);
}

std::string GfxPixelFormat::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxPixelFormat::createFormat(const GfxPixelFormatEnum& format) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(format);

    SdlTypePtr pixptr;

    if (pix_ != nullptr)
    {
        throw std::runtime_error("Format already created");
    }
    pixptr = SDL_AllocFormat(format.getAsSdlType());
    if (pixptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create pixel format (" + sdlErr + ")");
    }
    pix_ = pixptr;
}

void GfxPixelFormat::createFormat(const uint32_t format) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    SdlTypePtr pixptr;

    if (pix_ != nullptr)
    {
        throw std::runtime_error("Format already created");
    }
    pixptr = SDL_AllocFormat(format);
    if (pixptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create pixel format (" + sdlErr + ")");
    }
    pix_ = pixptr;
}

void GfxPixelFormat::freeFormat(void) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if (pix_ != nullptr)
    {
       SDL_FreeFormat(pix_);
       pix_ = nullptr;
    }
}

const GfxPixelFormatEnum GfxPixelFormat::getFormat(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ != nullptr)
    {
        return GfxPixelFormatEnum(pix_->format);
    }
    return GfxPixelFormatEnum(GfxPixelFormatEnum::ValueType::pixelFormatUnknown);
}

uint32_t GfxPixelFormat::pixelFlag(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return 0;
    }
    return SDL_PIXELFLAG(pix_->format);
}

const GfxPixelType GfxPixelFormat::pixelType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return GfxPixelType(GfxPixelType::ValueType::pixelTypeUnknown);
    }
    return GfxPixelType(SDL_PIXELTYPE(pix_->format));
}

const GfxPackedOrder GfxPixelFormat::pixelOrderPacked(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return GfxPackedOrder(GfxPackedOrder::ValueType::packedOrderNone);
    }
    return GfxPackedOrder(SDL_PIXELORDER(pix_->format));
}

const GfxArrayOrder GfxPixelFormat::pixelOrderArray(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return GfxArrayOrder(GfxArrayOrder::ValueType::arrayOrderNone);
    }
    return GfxArrayOrder(SDL_PIXELORDER(pix_->format));
}

const GfxBitmapOrder GfxPixelFormat::pixelOrderBitmap(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return GfxBitmapOrder(GfxBitmapOrder::ValueType::bitmapOrderNone);
    }
    return GfxBitmapOrder(SDL_PIXELORDER(pix_->format));
}

const GfxPackedLayout GfxPixelFormat::pixelLayout(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return GfxPackedLayout(GfxPackedLayout::ValueType::packedLayoutNone);
    }
    return GfxPackedLayout(SDL_PIXELLAYOUT(pix_->format));
}

uint32_t GfxPixelFormat::bitsPerPixel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return 0;
    }
    return SDL_BITSPERPIXEL(pix_->format);
}

uint32_t GfxPixelFormat::bytesPerPixel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

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

bool GfxPixelFormat::isPixelFormatIndexed(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeIndex1) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeIndex4) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeIndex8));
    return temp;
}

bool GfxPixelFormat::isPixelFormatPacked(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypePacked8) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypePacked16) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypePacked32));
    return temp;
}

bool GfxPixelFormat::isPixelFormatArray(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = !isPixelFormatFourCC() &&
            (
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeArrayU8) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeArrayU16) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeArrayU32) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeArrayF16) ||
                (pixelType().getValue() == GfxPixelType::ValueType::pixelTypeArrayF32));
    return temp;
}

bool GfxPixelFormat::isPixelFormatAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool temp;

    if (pix_ == nullptr)
    {
        return false;
    }
    temp = false;
    if (isPixelFormatPacked() == true &&
        (
            (pixelOrderPacked().getValue() == GfxPackedOrder::ValueType::packedOrderARGB) ||
            (pixelOrderPacked().getValue() == GfxPackedOrder::ValueType::packedOrderRGBA) ||
            (pixelOrderPacked().getValue() == GfxPackedOrder::ValueType::packedOrderABGR) ||
            (pixelOrderPacked().getValue() == GfxPackedOrder::ValueType::packedOrderBGRA)))
    {
        temp = true;
    }
    if (isPixelFormatArray() == true &&
        (
            (pixelOrderArray().getValue() == GfxArrayOrder::ValueType::arrayOrderARGB) ||
            (pixelOrderArray().getValue() == GfxArrayOrder::ValueType::arrayOrderRGBA) ||
            (pixelOrderArray().getValue() == GfxArrayOrder::ValueType::arrayOrderABGR) ||
            (pixelOrderArray().getValue() == GfxArrayOrder::ValueType::arrayOrderBGRA)))
    {
        temp = true;
    }
    return temp;
}

bool GfxPixelFormat::isPixelFormatFourCC(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pix_ == nullptr)
    {
        return false;
    }
    return ((pix_->format != 0) && (pixelFlag() != 1));
}

const std::string GfxPixelFormat::getPixelFormatName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string str {"$nullptr$"};

    if (pix_ != nullptr)
    {
        str = SDL_GetPixelFormatName(pix_->format);
    }
    return str;
}

const GfxBool GfxPixelFormat::pixelFormatEnumToMasks(int32_t * bpp, uint32_t * Rmask, uint32_t * Gmask,
                                                     uint32_t * Bmask, uint32_t * Amask) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(bpp != nullptr);
    assert(Rmask != nullptr);
    assert(Gmask != nullptr);
    assert(Bmask != nullptr);
    assert(Amask != nullptr);

    GfxBool::SdlType sdlbool;

    if (pix_ != nullptr)
    {
        sdlbool = SDL_PixelFormatEnumToMasks(pix_->format, bpp, Rmask, Gmask, Bmask, Amask);
    }
    else
    {
        sdlbool = SDL_FALSE;
    }
    return GfxBool(sdlbool);
}

const GfxPixelFormatEnum GfxPixelFormat::masksToPixelFormatEnum(const int32_t bpp, const uint32_t Rmask,
                                                                const uint32_t Gmask, const uint32_t Bmask,
                                                                const uint32_t Amask) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(bpp > 0);

    GfxPixelFormatEnum::SdlType sdlpixfmten;

    sdlpixfmten = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
    return GfxPixelFormatEnum(sdlpixfmten);
}

void GfxPixelFormat::setPixelFormatPalette(const GfxPalette& palette) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(palette);

    int32_t ret = 1;

    if (pix_ != nullptr)
    {
        ret = SDL_SetPixelFormatPalette(pix_, palette.getAsSdlTypePtr());
        assert(ret == 0);
    }
}

const pixels::GfxColor GfxPixelFormat::mapRGB(const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(color);

    uint32_t clru32;

    if (pix_ != nullptr)
    {
        clru32 = SDL_MapRGB(pix_, color.getRed(), color.getGreen(), color.getBlue());
        return pixels::GfxColor(clru32);
    }
    return pixels::GfxColor();
}

const pixels::GfxColor GfxPixelFormat::mapRGBA(const pixels::GfxColor& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(color);

    uint32_t clru32;

    if (pix_ != nullptr)
    {
        clru32 = SDL_MapRGBA(pix_, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        return pixels::GfxColor(clru32);
    }
    return pixels::GfxColor();
}

const pixels::GfxColor GfxPixelFormat::getRGB(const uint32_t pixel) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint8_t r;
    uint8_t g;
    uint8_t b;

    if (pix_ != nullptr)
    {
        SDL_GetRGB(pixel, pix_, &r, &g, &b);
        return pixels::GfxColor(r, g, b);
    }
    return pixels::GfxColor();
}

const pixels::GfxColor GfxPixelFormat::getRGBA(const uint32_t pixel) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    if (pix_ != nullptr)
    {
        SDL_GetRGBA(pixel, pix_, &r, &g, &b, &a);
        return pixels::GfxColor(r, g, b, a);
    }
    return pixels::GfxColor();
}

void GfxPixelFormat::calculateGammaRamp(const float gamma, const xtra::GfxGammaRamp& ramp) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((gamma >= 0.0f) && (gamma <= 1.0f));
    assert(ramp);

    SDL_CalculateGammaRamp(gamma, ramp.getAsSdlTypePtr());
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)pix_;
}

// Private methods
void GfxPixelFormat::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pix_ = nullptr;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
