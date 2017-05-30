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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelFormatEnum : public gfx::GfxRootClass
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];

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
        pixelFormatNV21 = sdl2::SDL_PIXELFORMAT_NV21
    };

    GfxPixelFormatEnum();
    explicit GfxPixelFormatEnum(ValueType value);
    explicit GfxPixelFormatEnum(SdlType value);

    GfxPixelFormatEnum(GfxPixelFormatEnum const& other);
    GfxPixelFormatEnum(GfxPixelFormatEnum&& other);

    GfxPixelFormatEnum& operator=(GfxPixelFormatEnum const& other);
    GfxPixelFormatEnum& operator=(GfxPixelFormatEnum&& other);

    virtual explicit operator bool() const;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelFormatEnum_hpp */
