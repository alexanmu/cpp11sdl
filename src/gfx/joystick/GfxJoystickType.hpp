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

#ifndef GfxJoystickType_hpp
#define GfxJoystickType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace joystick
{

class GfxJoystickType final : public GfxObject
{
public:
    typedef sdl2::SDL_JoystickType SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        typeUnknown = sdl2::SDL_JOYSTICK_TYPE_UNKNOWN,
        typeGameController = sdl2::SDL_JOYSTICK_TYPE_GAMECONTROLLER,
        typeWheel = sdl2::SDL_JOYSTICK_TYPE_WHEEL,
        typeArcadeStick = sdl2::SDL_JOYSTICK_TYPE_ARCADE_STICK,
        typeFlightStick = sdl2::SDL_JOYSTICK_TYPE_FLIGHT_STICK,
        typeDancePad = sdl2::SDL_JOYSTICK_TYPE_DANCE_PAD,
        typeGuitar = sdl2::SDL_JOYSTICK_TYPE_GUITAR,
        typeDrumKit = sdl2::SDL_JOYSTICK_TYPE_DRUM_KIT,
        typeArcadePad = sdl2::SDL_JOYSTICK_TYPE_ARCADE_PAD,
        typeThrottle = sdl2::SDL_JOYSTICK_TYPE_THROTTLE
    };

    GfxJoystickType() noexcept;

    explicit GfxJoystickType(const SdlType type) noexcept;
    explicit GfxJoystickType(const ValueType type) noexcept;

    GfxJoystickType(const GfxJoystickType& other) noexcept;
    GfxJoystickType(GfxJoystickType&& other) noexcept;

    GfxJoystickType& operator=(const GfxJoystickType& other) noexcept;
    GfxJoystickType& operator=(GfxJoystickType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isUnknown(void) const noexcept;
    bool isGameController(void) const noexcept;
    bool isWheel(void) const noexcept;
    bool isArcadeStick(void) const noexcept;
    bool isFlightStick(void) const noexcept;
    bool isDancePad(void) const noexcept;
    bool isGuitar(void) const noexcept;
    bool isDrumKit(void) const noexcept;
    bool isArcadePad(void) const noexcept;
    bool isThrottle(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType type_;
};

}  // namespace joystick

}  // namespace gfx

#endif /* GfxJoystickType_hpp */
