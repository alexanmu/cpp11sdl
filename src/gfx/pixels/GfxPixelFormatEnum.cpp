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

#include <string>
#include <utility>

#include "GfxPixelFormatEnum.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpixelformatenum::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxPixelFormatEnum::ClassName[] = "GfxPixelFormatEnum";

GfxPixelFormatEnum::GfxPixelFormatEnum() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxPixelFormatEnum::GfxPixelFormatEnum(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxPixelFormatEnum::GfxPixelFormatEnum(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxPixelFormatEnum::GfxPixelFormatEnum(GfxPixelFormatEnum const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxPixelFormatEnum::GfxPixelFormatEnum(GfxPixelFormatEnum&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxPixelFormatEnum& GfxPixelFormatEnum::operator=(GfxPixelFormatEnum const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        value_ = other.value_;
    }
    return *this;
}

GfxPixelFormatEnum& GfxPixelFormatEnum::operator=(GfxPixelFormatEnum&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPixelFormatEnum::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPixelFormatEnum::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxPixelFormatEnum::ValueType GfxPixelFormatEnum::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

bool GfxPixelFormatEnum::isUnknown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_UNKNOWN);
}

bool GfxPixelFormatEnum::isIndex1LSB(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_INDEX1LSB);
}

bool GfxPixelFormatEnum::isIndex1MSB(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_INDEX1MSB);
}

bool GfxPixelFormatEnum::isIndex4LSB(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_INDEX4LSB);
}

bool GfxPixelFormatEnum::isIndex4MSB(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_INDEX4MSB);
}

bool GfxPixelFormatEnum::isIndex8(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_INDEX8);
}

bool GfxPixelFormatEnum::isRGB332(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB332);
}

bool GfxPixelFormatEnum::isRGB444(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB444);
}

bool GfxPixelFormatEnum::isRGB555(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB555);
}

bool GfxPixelFormatEnum::isBGR555(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGR555);
}

bool GfxPixelFormatEnum::isARGB4444(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ARGB4444);
}

bool GfxPixelFormatEnum::isRGBA4444(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGBA4444);
}

bool GfxPixelFormatEnum::isABGR4444(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ABGR4444);
}

bool GfxPixelFormatEnum::isBGRA4444(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGRA4444);
}

bool GfxPixelFormatEnum::isARGB1555(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ARGB1555);
}

bool GfxPixelFormatEnum::isRGBA5551(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGBA5551);
}

bool GfxPixelFormatEnum::isABGR1555(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ABGR1555);
}

bool GfxPixelFormatEnum::isBGRA5551(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGRA5551);
}

bool GfxPixelFormatEnum::isRGB565(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB565);
}

bool GfxPixelFormatEnum::isBGR565(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGR565);
}

bool GfxPixelFormatEnum::isRGB24(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB24);
}

bool GfxPixelFormatEnum::isBGR24(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGR24);
}

bool GfxPixelFormatEnum::isRGB888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGB888);
}

bool GfxPixelFormatEnum::isRGBX8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGBX8888);
}

bool GfxPixelFormatEnum::isBGR888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGR888);
}

bool GfxPixelFormatEnum::isBGRX8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGRX8888);
}

bool GfxPixelFormatEnum::isARGB8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ARGB8888);
}

bool GfxPixelFormatEnum::isRGBA8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGBA8888);
}

bool GfxPixelFormatEnum::isABGR8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ABGR8888);
}

bool GfxPixelFormatEnum::isBGRA8888(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGRA8888);
}

bool GfxPixelFormatEnum::isARGB2101010(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ARGB2101010);
}

bool GfxPixelFormatEnum::isRGBA32(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_RGBA32);
}

bool GfxPixelFormatEnum::isARGB32(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ARGB32);
}

bool GfxPixelFormatEnum::isBGRA32(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_BGRA32);
}

bool GfxPixelFormatEnum::isABGR32(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_ABGR32);
}

bool GfxPixelFormatEnum::isYV12(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_YV12);
}

bool GfxPixelFormatEnum::isIYUV(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_IYUV);
}

bool GfxPixelFormatEnum::isYUY2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_YUY2);
}

bool GfxPixelFormatEnum::isUYVY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_UYVY);
}

bool GfxPixelFormatEnum::isYVYU(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_YVYU);
}

bool GfxPixelFormatEnum::isNV12(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_NV12);
}


bool GfxPixelFormatEnum::isNV21(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == sdl2::SDL_PIXELFORMAT_NV21);
}


void GfxPixelFormatEnum::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::pixelFormatUnknown);
}

GfxPixelFormatEnum::SdlType GfxPixelFormatEnum::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
