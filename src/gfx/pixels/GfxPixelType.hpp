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

#ifndef GfxPixelType_hpp
#define GfxPixelType_hpp

#include <cstdint>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelType : public gfx::GfxRootClass
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];

    enum class ValueType : uint32_t
    {
        pixelTypeUnknown = sdl2::SDL_PIXELTYPE_UNKNOWN,
        pixelTypeIndex1 = sdl2::SDL_PIXELTYPE_INDEX1,
        pixelTypeIndex4 = sdl2::SDL_PIXELTYPE_INDEX4,
        pixelTypeIndex8 = sdl2::SDL_PIXELTYPE_INDEX8,
        pixelTypePacked8 = sdl2::SDL_PIXELTYPE_PACKED8,
        pixelTypePacked16 = sdl2::SDL_PIXELTYPE_PACKED16,
        pixelTypePacked32 = sdl2::SDL_PIXELTYPE_PACKED32,
        pixelTypeArrayU8 = sdl2::SDL_PIXELTYPE_ARRAYU8,
        pixelTypeArrayU16 = sdl2::SDL_PIXELTYPE_ARRAYU16,
        pixelTypeArrayU32 = sdl2::SDL_PIXELTYPE_ARRAYU32,
        pixelTypeArrayF16 = sdl2::SDL_PIXELTYPE_ARRAYF16,
        pixelTypeArrayF32 = sdl2::SDL_PIXELTYPE_ARRAYF32
    };

    GfxPixelType();
    explicit GfxPixelType(ValueType value);
    explicit GfxPixelType(SdlType value);

    GfxPixelType(GfxPixelType const& other);
    GfxPixelType(GfxPixelType&& other);

    GfxPixelType& operator=(GfxPixelType const& other);
    GfxPixelType& operator=(GfxPixelType&& other);

    virtual explicit operator bool() const;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelType_hpp */
