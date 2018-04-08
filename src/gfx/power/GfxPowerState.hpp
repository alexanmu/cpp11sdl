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

#ifndef GfxPowerState_hpp
#define GfxPowerState_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace power
{

class GfxPowerState final : public GfxObject
{
public:
    typedef SDL_PowerState SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        stateUnknown = SDL_POWERSTATE_UNKNOWN,
        stateOnBattery = SDL_POWERSTATE_ON_BATTERY,
        stateNoBattery = SDL_POWERSTATE_NO_BATTERY,
        stateCharging = SDL_POWERSTATE_CHARGING,
        stateCharged = SDL_POWERSTATE_CHARGED
    };

    GfxPowerState() noexcept;

    explicit GfxPowerState(const ValueType value) noexcept;
    explicit GfxPowerState(const SdlType value) noexcept;

    GfxPowerState(GfxPowerState const& other) noexcept;
    GfxPowerState(GfxPowerState&& other) noexcept;

    GfxPowerState& operator=(GfxPowerState const& other) noexcept;
    GfxPowerState& operator=(GfxPowerState&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isUnknown(void) const noexcept;
    bool isOnBattery(void) const noexcept;
    bool isNoBattery(void) const noexcept;
    bool isCharging(void) const noexcept;
    bool isCharged(void) const noexcept;

    void clear(void) noexcept;

    const std::string getAsString(void) const noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace power

}  // namespace gfx

#endif /* GfxPowerState_hpp */

