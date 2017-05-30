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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPackedOrder : public gfx::GfxRootClass
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];

    enum class ValueType : uint32_t
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

    GfxPackedOrder();
    explicit GfxPackedOrder(ValueType value);
    explicit GfxPackedOrder(SdlType value);

    GfxPackedOrder(GfxPackedOrder const& other);
    GfxPackedOrder(GfxPackedOrder&& other);

    GfxPackedOrder& operator=(GfxPackedOrder const& other);
    GfxPackedOrder& operator=(GfxPackedOrder&& other);

    virtual explicit operator bool() const;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPackedOrder_hpp */
