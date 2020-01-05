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

#ifndef GfxHaptic_hpp
#define GfxHaptic_hpp

#include <string>
#include <cstdint>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxJoystick.hpp"
#include "GfxHapticEffect.hpp"
#include "GfxHapticEffectType.hpp"

namespace gfx
{

namespace haptic
{

class GfxHaptic final : public GfxObject
{
public:
    typedef SDL_Haptic * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxHaptic() noexcept;

    explicit GfxHaptic(const SdlTypePtr haptic) noexcept;
    explicit GfxHaptic(const int32_t index) throw(std::runtime_error);
    explicit GfxHaptic(const joystick::GfxJoystick& joy) throw(std::runtime_error);
    explicit GfxHaptic(const bool fromMouse) throw(std::runtime_error);

    GfxHaptic(const GfxHaptic& other) noexcept;
    GfxHaptic(GfxHaptic&& other) noexcept;

    GfxHaptic& operator=(const GfxHaptic& other) noexcept;
    GfxHaptic& operator=(GfxHaptic&& other) noexcept;

    virtual ~GfxHaptic() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void hapticOpen(const int32_t index) throw(std::runtime_error);
    void hapticOpenFromJoystick(const joystick::GfxJoystick& joy) throw(std::runtime_error);
    void hapticOpenFromMouse(void) throw(std::runtime_error);
    void hapticClose(void) noexcept;

    int32_t numHaptics(void) const noexcept;
    const std::string hapticName(const int32_t index) const noexcept;
    bool hapticOpened(const int32_t index) const noexcept;
    int32_t hapticIndex(void) const noexcept;
    int32_t hapticIndex(const SdlTypePtr haptic) const noexcept;
    bool mouseIsHaptic(void) const noexcept;
    bool joystickIsHaptic(const joystick::GfxJoystick& joy) const noexcept;
    int32_t hapticNumEffects(void) const noexcept;
    int32_t hapticNumEffectsPlaying(void) const noexcept;
    const GfxHapticEffectType hapticQuery(void) const noexcept;
    int32_t hapticNumAxes(void) const noexcept;
    bool hapticEffectSupported(const GfxHapticEffect& effect) const noexcept;
    int32_t hapticNewEffect(const GfxHapticEffect& effect) const noexcept;
    int32_t hapticUpdateEffect(const int32_t effect, const GfxHapticEffect& data) const noexcept;
    int32_t hapticRunEffect(const int32_t effect, const uint32_t iterations) const noexcept;
    int32_t hapticStopEffect(const int32_t effect) const noexcept;
    void hapticDestroyEffect(const int32_t effect) const noexcept;
    int32_t hapticGetEffectStatus(const int32_t effect) const noexcept;
    int32_t hapticSetGain(const int32_t gain) const noexcept;
    int32_t hapticSetAutocenter(const int32_t autocenter) const noexcept;
    int32_t hapticPause(void) const noexcept;
    int32_t hapticUnpause(void) const noexcept;
    int32_t hapticStopAll(void) const noexcept;
    bool hapticRumbleSupported(void) const noexcept;
    int32_t hapticRumbleInit(void) const noexcept;
    int32_t hapticRumblePlay(const float strength, const uint32_t length) const noexcept;
    int32_t hapticRumbleStop(void) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr haptic_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHaptic_hpp */
