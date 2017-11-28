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

#ifndef GfxHapticEffectType_hpp
#define GfxHapticEffectType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace haptic
{

class GfxHapticEffectType final : public GfxObject
{
public:
    typedef uint16_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint16_t
    {
        hapticConstant = SDL_HAPTIC_CONSTANT,
        hapticSine = SDL_HAPTIC_SINE,
        hapticLeftRight = SDL_HAPTIC_LEFTRIGHT,
        /* hapticSquare = SDL_HAPTIC_SQUARE, */
        hapticTriangle = SDL_HAPTIC_TRIANGLE,
        hapticSawToothUp = SDL_HAPTIC_SAWTOOTHUP,
        hapticSawToothDown = SDL_HAPTIC_SAWTOOTHDOWN,
        hapticRamp = SDL_HAPTIC_RAMP,
        hapticSpring = SDL_HAPTIC_SPRING,
        hapticDamper = SDL_HAPTIC_DAMPER,
        hapticInertia = SDL_HAPTIC_INERTIA,
        hapticFriction = SDL_HAPTIC_FRICTION,
        hapticCustom = SDL_HAPTIC_CUSTOM,
        hapticGain = SDL_HAPTIC_GAIN,
        hapticAutoCenter = SDL_HAPTIC_AUTOCENTER,
        hapticStatus = SDL_HAPTIC_STATUS,
        hapticPause = SDL_HAPTIC_PAUSE
    };

    GfxHapticEffectType() noexcept;

    explicit GfxHapticEffectType(const SdlType etype) noexcept;
    explicit GfxHapticEffectType(const ValueType etype) noexcept;

    GfxHapticEffectType(const GfxHapticEffectType& other) noexcept;
    GfxHapticEffectType(GfxHapticEffectType&& other) noexcept;

    GfxHapticEffectType& operator=(const GfxHapticEffectType& other) noexcept;
    GfxHapticEffectType& operator=(GfxHapticEffectType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isConstant(void) const noexcept;
    bool isSine(void) const noexcept;
    bool isLeftRight(void) const noexcept;
    bool isSquare(void) const noexcept;
    bool isTriangle(void) const noexcept;
    bool isSawToothUp(void) const noexcept;
    bool isSawToothDown(void) const noexcept;
    bool isRamp(void) const noexcept;
    bool isSpring(void) const noexcept;
    bool isDamper(void) const noexcept;
    bool isInertia(void) const noexcept;
    bool isFriction(void) const noexcept;
    bool isCustom(void) const noexcept;
    bool isGain(void) const noexcept;
    bool isAutoCenter(void) const noexcept;
    bool isStatus(void) const noexcept;
    bool isPause(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType eType_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticEffectType_hpp */
