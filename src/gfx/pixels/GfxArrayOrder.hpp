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

#ifndef GfxArrayOrder_hpp
#define GfxArrayOrder_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxArrayOrder final : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        arrayOrderNone = SDL_ARRAYORDER_NONE,
        arrayOrderRGB = SDL_ARRAYORDER_RGB,
        arrayOrderRGBA = SDL_ARRAYORDER_RGBA,
        arrayOrderARGB = SDL_ARRAYORDER_ARGB,
        arrayOrderBGR = SDL_ARRAYORDER_BGR,
        arrayOrderBGRA = SDL_ARRAYORDER_BGRA,
        arrayOrderABGR = SDL_ARRAYORDER_ABGR
    };

    GfxArrayOrder() noexcept;
    explicit GfxArrayOrder(const ValueType value) noexcept;
    explicit GfxArrayOrder(const SdlType value) noexcept;

    GfxArrayOrder(const GfxArrayOrder& other) noexcept;
    GfxArrayOrder(GfxArrayOrder&& other) noexcept;

    GfxArrayOrder& operator=(const GfxArrayOrder& other) noexcept;
    GfxArrayOrder& operator=(GfxArrayOrder&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isNone(void) const noexcept;
    bool isRGB(void) const noexcept;
    bool isRGBA(void) const noexcept;
    bool isARGB(void) const noexcept;
    bool isBGR(void) const noexcept;
    bool isBGRA(void) const noexcept;
    bool isABGR(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxArrayOrder_hpp */
