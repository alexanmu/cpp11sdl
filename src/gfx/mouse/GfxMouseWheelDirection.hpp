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

#ifndef GfxMouseWheelDirection_hpp
#define GfxMouseWheelDirection_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace mouse
{

class GfxMouseWheelDirection final : public GfxObject
{
public:
    typedef sdl2::SDL_MouseWheelDirection SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        mouseWheelNormal = sdl2::SDL_MOUSEWHEEL_NORMAL,
        mouseWheelFlipped = sdl2::SDL_MOUSEWHEEL_FLIPPED
    };

    GfxMouseWheelDirection() noexcept;
    explicit GfxMouseWheelDirection(const ValueType wheel) noexcept;
    explicit GfxMouseWheelDirection(const SdlType wheel) noexcept;

    GfxMouseWheelDirection(GfxMouseWheelDirection const& other) noexcept;
    GfxMouseWheelDirection(GfxMouseWheelDirection&& other) noexcept;

    GfxMouseWheelDirection& operator=(GfxMouseWheelDirection const& other) noexcept;
    GfxMouseWheelDirection& operator=(GfxMouseWheelDirection&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setDirectionNormal(void) noexcept;
    void setDirectionFlipped(void) noexcept;

    bool isDirectionNormal(void) const noexcept;
    bool isDirectionFlipped(void) const noexcept;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType wheel_;
};

}  // namespace mouse

}  // namespace gfx

#endif /* GfxMouseWheelDirection_hpp */
