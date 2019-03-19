/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#ifndef GfxHatPosition_hpp
#define GfxHatPosition_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace joystick
{

class GfxHatPosition final : public GfxObject
{
public:
    typedef int32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        hatCentered = SDL_HAT_CENTERED,
        hatUp = SDL_HAT_UP,
        hatRight = SDL_HAT_RIGHT,
        hatDown = SDL_HAT_DOWN,
        hatLeft = SDL_HAT_LEFT,
        hatRightUp = SDL_HAT_RIGHTUP,
        hatRightDown = SDL_HAT_RIGHTDOWN,
        hatLeftUp = SDL_HAT_LEFTUP,
        hatLeftDown = SDL_HAT_LEFTDOWN
    };

    GfxHatPosition() noexcept;

    explicit GfxHatPosition(const ValueType position) noexcept;
    explicit GfxHatPosition(const SdlType position) noexcept;

    GfxHatPosition(const GfxHatPosition& other) noexcept;
    GfxHatPosition(GfxHatPosition&& other) noexcept;

    GfxHatPosition& operator=(const GfxHatPosition& other) noexcept;
    GfxHatPosition& operator=(GfxHatPosition&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isCentered(void) const noexcept;
    bool isUp(void) const noexcept;
    bool isRight(void) const noexcept;
    bool isDown(void) const noexcept;
    bool isLeft(void) const noexcept;
    bool isRightUp(void) const noexcept;
    bool isRightDown(void) const noexcept;
    bool isLeftUp(void) const noexcept;
    bool isLeftDown(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType hatPosition_;
};

}  // namespace joystick

}  // namespace gfx

#endif /* GfxHatPosition_hpp */
