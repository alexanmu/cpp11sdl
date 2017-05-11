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

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxPowerState final : public GfxRootClass
{
public:
    typedef sdl2::SDL_PowerState SdlType;
    typedef sdl2::SDL_PowerState* SdlTypePtr;

    static const char ClassName[];

    enum class GfxPowerStateValues : int
    {
        stateUnknown = sdl2::SDL_POWERSTATE_UNKNOWN,
        stateOnBattery = sdl2::SDL_POWERSTATE_ON_BATTERY,
        stateNoBattery = sdl2::SDL_POWERSTATE_NO_BATTERY,
        stateCharging = sdl2::SDL_POWERSTATE_CHARGING,
        stateCharged = sdl2::SDL_POWERSTATE_CHARGED
    };

    GfxPowerState();

    explicit GfxPowerState(const GfxPowerStateValues value);
    explicit GfxPowerState(const SdlType value);

    GfxPowerState(GfxPowerState const& other);
    GfxPowerState(GfxPowerState&& other);

    GfxPowerState& operator=(GfxPowerState const& other);
    GfxPowerState& operator=(GfxPowerState&& other);

    bool isUnknown(void) const;
    bool isOnBattery(void) const;
    bool isNoBattery(void) const;
    bool isCharging(void) const;
    bool isCharged(void) const;

    std::string getAsString(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType value_;
};

}  // namespace gfx

#endif /* GfxPowerState_hpp */
