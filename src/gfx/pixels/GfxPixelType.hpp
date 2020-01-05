/*
 Giotto
 Copyright (C) 2020 George Oros
 
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
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPixelType final : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        pixelTypeUnknown = SDL_PIXELTYPE_UNKNOWN,
        pixelTypeIndex1 = SDL_PIXELTYPE_INDEX1,
        pixelTypeIndex4 = SDL_PIXELTYPE_INDEX4,
        pixelTypeIndex8 = SDL_PIXELTYPE_INDEX8,
        pixelTypePacked8 = SDL_PIXELTYPE_PACKED8,
        pixelTypePacked16 = SDL_PIXELTYPE_PACKED16,
        pixelTypePacked32 = SDL_PIXELTYPE_PACKED32,
        pixelTypeArrayU8 = SDL_PIXELTYPE_ARRAYU8,
        pixelTypeArrayU16 = SDL_PIXELTYPE_ARRAYU16,
        pixelTypeArrayU32 = SDL_PIXELTYPE_ARRAYU32,
        pixelTypeArrayF16 = SDL_PIXELTYPE_ARRAYF16,
        pixelTypeArrayF32 = SDL_PIXELTYPE_ARRAYF32
    };

    GfxPixelType() noexcept;
    explicit GfxPixelType(const ValueType value) noexcept;
    explicit GfxPixelType(const SdlType value) noexcept;

    GfxPixelType(const GfxPixelType& other) noexcept;
    GfxPixelType(GfxPixelType&& other) noexcept;

    GfxPixelType& operator=(const GfxPixelType& other) noexcept;
    GfxPixelType& operator=(GfxPixelType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isUnknwon(void) const noexcept;
    bool isIndex1(void) const noexcept;
    bool isIndex4(void) const noexcept;
    bool isIndex8(void) const noexcept;
    bool isPacked8(void) const noexcept;
    bool isPacked16(void) const noexcept;
    bool isPacked32(void) const noexcept;
    bool isArrayU8(void) const noexcept;
    bool isArrayU16(void) const noexcept;
    bool isArrayU32(void) const noexcept;
    bool isArrayF16(void) const noexcept;
    bool isArrayF32(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPixelType_hpp */
