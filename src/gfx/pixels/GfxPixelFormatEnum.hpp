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

#ifndef GfxPixelFormatEnum_hpp
#define GfxPixelFormatEnum_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelFormatEnum : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        pixelFormatUnknown = sdl2::SDL_PIXELFORMAT_UNKNOWN,
        pixelFormatIndex1LSB = sdl2::SDL_PIXELFORMAT_INDEX1LSB,
        pixelFormatIndex1MSB = sdl2::SDL_PIXELFORMAT_INDEX1MSB,
        pixelFormatIndex4LSB = sdl2::SDL_PIXELFORMAT_INDEX4LSB,
        pixelFormatIndex4MSB = sdl2::SDL_PIXELFORMAT_INDEX4MSB,
        pixelFormatIndex8 = sdl2::SDL_PIXELFORMAT_INDEX8,
        pixelFormatRGB332 = sdl2::SDL_PIXELFORMAT_RGB332,
        pixelFormatRGB444 = sdl2::SDL_PIXELFORMAT_RGB444,
        pixelFormatRGB555 = sdl2::SDL_PIXELFORMAT_RGB555,
        pixelFormatBGR555 = sdl2::SDL_PIXELFORMAT_BGR555,
        pixelFormatARGB4444 = sdl2::SDL_PIXELFORMAT_ARGB4444,
        pixelFormatRGBA4444 = sdl2::SDL_PIXELFORMAT_RGBA4444,
        pixelFormatABGR4444 = sdl2::SDL_PIXELFORMAT_ABGR4444,
        pixelFormatBGRA4444 = sdl2::SDL_PIXELFORMAT_BGRA4444,
        pixelFormatARGB1555 = sdl2::SDL_PIXELFORMAT_ARGB1555,
        pixelFormatRGBA5551 = sdl2::SDL_PIXELFORMAT_RGBA5551,
        pixelFormatABGR1555 = sdl2::SDL_PIXELFORMAT_ABGR1555,
        pixelFormatBGRA5551 = sdl2::SDL_PIXELFORMAT_BGRA5551,
        pixelFormatRGB565 = sdl2::SDL_PIXELFORMAT_RGB565,
        pixelFormatBGR565 = sdl2::SDL_PIXELFORMAT_BGR565,
        pixelFormatRGB24 = sdl2::SDL_PIXELFORMAT_RGB24,
        pixelFormatBGR24 = sdl2::SDL_PIXELFORMAT_BGR24,
        pixelFormatRGB888 = sdl2::SDL_PIXELFORMAT_RGB888,
        pixelFormatRGBX8888 = sdl2::SDL_PIXELFORMAT_RGBX8888,
        pixelFormatBGR888 = sdl2::SDL_PIXELFORMAT_BGR888,
        pixelFormatBGRX8888 = sdl2::SDL_PIXELFORMAT_BGRX8888,
        pixelFormatARGB8888 = sdl2::SDL_PIXELFORMAT_ARGB8888,
        pixelFormatRGBA8888 = sdl2::SDL_PIXELFORMAT_RGBA8888,
        pixelFormatABGR8888 = sdl2::SDL_PIXELFORMAT_ABGR8888,
        pixelFormatBGRA8888 = sdl2::SDL_PIXELFORMAT_BGRA8888,
        pixelFormatARGB2101010 = sdl2::SDL_PIXELFORMAT_ARGB2101010,
        pixelFormatRGBA32 = sdl2::SDL_PIXELFORMAT_RGBA32,
        pixelFormatARGB32 = sdl2::SDL_PIXELFORMAT_ARGB32,
        pixelFormatBGRA32 = sdl2::SDL_PIXELFORMAT_BGRA32,
        pixelFormatABGR32 = sdl2::SDL_PIXELFORMAT_ABGR32,
        pixelFormatYV12 = sdl2::SDL_PIXELFORMAT_YV12,
        pixelFormatIYUV = sdl2::SDL_PIXELFORMAT_IYUV,
        pixelFormatYUY2 = sdl2::SDL_PIXELFORMAT_YUY2,
        pixelFormatUYVY = sdl2::SDL_PIXELFORMAT_UYVY,
        pixelFormatYVYU = sdl2::SDL_PIXELFORMAT_YVYU,
        pixelFormatNV12 = sdl2::SDL_PIXELFORMAT_NV12,
        pixelFormatNV21 = sdl2::SDL_PIXELFORMAT_NV21,
        pixelFormatExternalOes = sdl2::SDL_PIXELFORMAT_EXTERNAL_OES
    };

    GfxPixelFormatEnum() noexcept;
    explicit GfxPixelFormatEnum(const ValueType value) noexcept;
    explicit GfxPixelFormatEnum(const SdlType value) noexcept;

    GfxPixelFormatEnum(GfxPixelFormatEnum const& other) noexcept;
    GfxPixelFormatEnum(GfxPixelFormatEnum&& other) noexcept;

    GfxPixelFormatEnum& operator=(GfxPixelFormatEnum const& other) noexcept;
    GfxPixelFormatEnum& operator=(GfxPixelFormatEnum&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isUnknown(void) const noexcept;
    bool isIndex1LSB(void) const noexcept;
    bool isIndex1MSB(void) const noexcept;
    bool isIndex4LSB(void) const noexcept;
    bool isIndex4MSB(void) const noexcept;
    bool isIndex8(void) const noexcept;
    bool isRGB332(void) const noexcept;
    bool isRGB444(void) const noexcept;
    bool isRGB555(void) const noexcept;
    bool isBGR555(void) const noexcept;
    bool isARGB4444(void) const noexcept;
    bool isRGBA4444(void) const noexcept;
    bool isABGR4444(void) const noexcept;
    bool isBGRA4444(void) const noexcept;
    bool isARGB1555(void) const noexcept;
    bool isRGBA5551(void) const noexcept;
    bool isABGR1555(void) const noexcept;
    bool isBGRA5551(void) const noexcept;
    bool isRGB565(void) const noexcept;
    bool isBGR565(void) const noexcept;
    bool isRGB24(void) const noexcept;
    bool isBGR24(void) const noexcept;
    bool isRGB888(void) const noexcept;
    bool isRGBX8888(void) const noexcept;
    bool isBGR888(void) const noexcept;
    bool isBGRX8888(void) const noexcept;
    bool isARGB8888(void) const noexcept;
    bool isRGBA8888(void) const noexcept;
    bool isABGR8888(void) const noexcept;
    bool isBGRA8888(void) const noexcept;
    bool isARGB2101010(void) const noexcept;
    bool isRGBA32(void) const noexcept;
    bool isARGB32(void) const noexcept;
    bool isBGRA32(void) const noexcept;
    bool isABGR32(void) const noexcept;
    bool isYV12(void) const noexcept;
    bool isIYUV(void) const noexcept;
    bool isYUY2(void) const noexcept;
    bool isUYVY(void) const noexcept;
    bool isYVYU(void) const noexcept;
    bool isNV12(void) const noexcept;
    bool isNV21(void) const noexcept;
    bool isExternalOES(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelFormatEnum_hpp */
