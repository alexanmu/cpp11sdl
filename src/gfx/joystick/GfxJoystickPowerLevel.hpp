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

#ifndef GfxJoystickPowerLevel_hpp
#define GfxJoystickPowerLevel_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace joystick
{

class GfxJoystickPowerLevel final : public GfxObject
{
public:
    typedef SDL_JoystickPowerLevel SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        powerUnknown = SDL_JOYSTICK_POWER_UNKNOWN,
        powerEmpty = SDL_JOYSTICK_POWER_EMPTY,
        powerLow = SDL_JOYSTICK_POWER_LOW,
        powerMedium = SDL_JOYSTICK_POWER_MEDIUM,
        powerFull = SDL_JOYSTICK_POWER_FULL,
        powerWired = SDL_JOYSTICK_POWER_WIRED,
        powerMax = SDL_JOYSTICK_POWER_MAX
    };

    GfxJoystickPowerLevel() noexcept;

    explicit GfxJoystickPowerLevel(const SdlType plevel) noexcept;
    explicit GfxJoystickPowerLevel(const ValueType plevel) noexcept;

    GfxJoystickPowerLevel(const GfxJoystickPowerLevel& other) noexcept;
    GfxJoystickPowerLevel(GfxJoystickPowerLevel&& other) noexcept;

    GfxJoystickPowerLevel& operator=(const GfxJoystickPowerLevel& other) noexcept;
    GfxJoystickPowerLevel& operator=(GfxJoystickPowerLevel&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isUnknown(void) const noexcept;
    bool isEmpty(void) const noexcept;
    bool isLow(void) const noexcept;
    bool isMedium(void) const noexcept;
    bool isFull(void) const noexcept;
    bool isWired(void) const noexcept;
    bool isMax(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType plevel_;
};

}  // namespace joystick

}  // namespace gfx

#endif /* GfxJoystickPowerLevel_hpp */
