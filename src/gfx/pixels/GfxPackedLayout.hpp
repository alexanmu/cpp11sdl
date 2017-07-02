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

#ifndef GfxPackedLayout_hpp
#define GfxPackedLayout_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxPackedLayout : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        packedLayoutNone = sdl2::SDL_PACKEDLAYOUT_NONE,
        packedLayout332 = sdl2::SDL_PACKEDLAYOUT_332,
        packedLayout4444 = sdl2::SDL_PACKEDLAYOUT_4444,
        packedLayout1555 = sdl2::SDL_PACKEDLAYOUT_1555,
        packedLayout5551 = sdl2::SDL_PACKEDLAYOUT_5551,
        packedLayout565 = sdl2::SDL_PACKEDLAYOUT_565,
        packedLayout8888 = sdl2::SDL_PACKEDLAYOUT_8888,
        packedLayout2101010 = sdl2::SDL_PACKEDLAYOUT_2101010,
        packedLayout1010102 = sdl2::SDL_PACKEDLAYOUT_1010102
    };

    GfxPackedLayout() noexcept;
    explicit GfxPackedLayout(const ValueType value) noexcept;
    explicit GfxPackedLayout(const SdlType value) noexcept;

    GfxPackedLayout(GfxPackedLayout const& other) noexcept;
    GfxPackedLayout(GfxPackedLayout&& other) noexcept;

    GfxPackedLayout& operator=(GfxPackedLayout const& other) noexcept;
    GfxPackedLayout& operator=(GfxPackedLayout&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxPackedLayout_hpp */
