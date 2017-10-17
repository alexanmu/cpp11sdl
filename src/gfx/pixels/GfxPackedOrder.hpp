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

#ifndef GfxPackedOrder_hpp
#define GfxPackedOrder_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPackedOrder : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        packedOrderNone = sdl2::SDL_PACKEDORDER_NONE,
        packedOrderXRGB = sdl2::SDL_PACKEDORDER_XRGB,
        packedOrderRGBX = sdl2::SDL_PACKEDORDER_RGBX,
        packedOrderARGB = sdl2::SDL_PACKEDORDER_ARGB,
        packedOrderRGBA = sdl2::SDL_PACKEDORDER_RGBA,
        packedOrderXBGR = sdl2::SDL_PACKEDORDER_XBGR,
        packedOrderBGRX = sdl2::SDL_PACKEDORDER_BGRX,
        packedOrderABGR = sdl2::SDL_PACKEDORDER_ABGR,
        packedOrderBGRA = sdl2::SDL_PACKEDORDER_BGRA
    };

    GfxPackedOrder() noexcept;
    explicit GfxPackedOrder(const ValueType value) noexcept;
    explicit GfxPackedOrder(const SdlType value) noexcept;

    GfxPackedOrder(GfxPackedOrder const& other) noexcept;
    GfxPackedOrder(GfxPackedOrder&& other) noexcept;

    GfxPackedOrder& operator=(GfxPackedOrder const& other) noexcept;
    GfxPackedOrder& operator=(GfxPackedOrder&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isNone(void) const noexcept;
    bool isXRGB(void) const noexcept;
    bool isRGBX(void) const noexcept;
    bool isARGB(void) const noexcept;
    bool isRGBA(void) const noexcept;
    bool isXBGR(void) const noexcept;
    bool isBGRX(void) const noexcept;
    bool isABGR(void) const noexcept;
    bool isBGRA(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPackedOrder_hpp */
