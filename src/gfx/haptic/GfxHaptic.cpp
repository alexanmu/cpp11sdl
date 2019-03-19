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

#include <string>
#include <cassert>
#include <utility>

#include "GfxHaptic.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhaptic::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHaptic::ClassName[] = "GfxHaptic";

GfxHaptic::GfxHaptic() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHaptic::GfxHaptic(const SdlTypePtr haptic) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    haptic_ = haptic;
}

GfxHaptic::GfxHaptic(const int32_t index) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(index >= 0);

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpen(index);
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

GfxHaptic::GfxHaptic(const joystick::GfxJoystick& joy) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(joy);

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpenFromJoystick(joy.getAsSdlTypePtr());
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

GfxHaptic::GfxHaptic(const bool fromMouse) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(fromMouse == true);

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpenFromMouse();
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

GfxHaptic::GfxHaptic(const GfxHaptic& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    haptic_ = other.haptic_;
}

GfxHaptic::GfxHaptic(GfxHaptic&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    haptic_ = other.haptic_;
    // Delete other's data
    other.clear();
}

GfxHaptic& GfxHaptic::operator=(const GfxHaptic& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        haptic_ = other.haptic_;
    }
    return *this;
}

GfxHaptic& GfxHaptic::operator=(GfxHaptic&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        haptic_ = other.haptic_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHaptic::~GfxHaptic() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (haptic_ != nullptr)
    {
        SDL_HapticClose(haptic_);
    }
}

GfxHaptic::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (haptic_ != nullptr);
}

std::string GfxHaptic::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxHaptic::hapticOpen(const int32_t index) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(index >= 0);

    if (haptic_ != nullptr)
    {
        throw std::runtime_error("Haptic device already created");
    }

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpen(index);
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

void GfxHaptic::hapticOpenFromJoystick(const joystick::GfxJoystick& joy) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(joy);

    if (haptic_ != nullptr)
    {
        throw std::runtime_error("Haptic device already created");
    }

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpenFromJoystick(joy.getAsSdlTypePtr());
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

void GfxHaptic::hapticOpenFromMouse(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    if (haptic_ != nullptr)
    {
        throw std::runtime_error("Haptic device already created");
    }

    SdlTypePtr tmphapticptr;

    tmphapticptr = SDL_HapticOpenFromMouse();
    if (tmphapticptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create haptic device (" + sdlErr + ")");
    }
    haptic_ = tmphapticptr;
}

void GfxHaptic::hapticClose(void) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    if (haptic_ != nullptr)
    {
        SDL_HapticClose(haptic_);
        haptic_ = nullptr;
    }
}

int32_t GfxHaptic::numHaptics(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = SDL_NumHaptics();
    return ret;
}

const std::string GfxHaptic::hapticName(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    const char * chr = nullptr;

    chr = SDL_HapticName(index);
    if (chr != nullptr)
    {
        return std::string(chr);
    }
    return std::string();
}

bool GfxHaptic::hapticOpened(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    int32_t ret = SDL_HapticOpened(index);
    return (ret == 1);
}

int32_t GfxHaptic::hapticIndex(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticIndex(haptic_);
    }
    return ret;
}

int32_t GfxHaptic::hapticIndex(const SdlTypePtr haptic) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(haptic != nullptr);

    int32_t ret = SDL_HapticIndex(haptic);
    return ret;
}

bool GfxHaptic::mouseIsHaptic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret;

    ret = SDL_MouseIsHaptic();
    return (ret == SDL_TRUE);
}

bool GfxHaptic::joystickIsHaptic(const joystick::GfxJoystick& joy) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(joy);

    int32_t ret;

    ret = SDL_JoystickIsHaptic(joy.getAsSdlTypePtr());
    return (ret == SDL_TRUE);
}

int32_t GfxHaptic::hapticNumEffects(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticNumEffects(haptic_);
    }
    return ret;
}

int32_t GfxHaptic::hapticNumEffectsPlaying(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticNumEffectsPlaying(haptic_);
    }
    return ret;
}

const GfxHapticEffectType GfxHaptic::hapticQuery(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = 0;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticQuery(haptic_);
    }
    return GfxHapticEffectType(ret);
}

int32_t GfxHaptic::hapticNumAxes(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticNumAxes(haptic_);
    }
    return ret;
}

bool GfxHaptic::hapticEffectSupported(const GfxHapticEffect& effect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect);

    bool ret = false;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticEffectSupported(haptic_, effect.getAsSdlTypePtr());
    }
    return ret;
}

int32_t GfxHaptic::hapticNewEffect(const GfxHapticEffect& effect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticNewEffect(haptic_, effect.getAsSdlTypePtr());
    }
    return ret;
}

int32_t GfxHaptic::hapticUpdateEffect(const int32_t effect, const GfxHapticEffect& data) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect >= 0);
    assert(data);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticUpdateEffect(haptic_, effect, data.getAsSdlTypePtr());
    }
    return ret;
}

int32_t GfxHaptic::hapticRunEffect(const int32_t effect, const uint32_t iterations) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect >= 0);
    assert(iterations > 0);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticRunEffect(haptic_, effect, iterations);
    }
    return ret;
}

int32_t GfxHaptic::hapticStopEffect(const int32_t effect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect >= 0);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticStopEffect(haptic_, effect);
    }
    return ret;
}

void GfxHaptic::hapticDestroyEffect(const int32_t effect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect >= 0);

    if (haptic_ != nullptr)
    {
        SDL_HapticDestroyEffect(haptic_, effect);
    }
}

int32_t GfxHaptic::hapticGetEffectStatus(const int32_t effect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(effect >= 0);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticGetEffectStatus(haptic_, effect);
    }
    return ret;
}

int32_t GfxHaptic::hapticSetGain(const int32_t gain) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticSetGain(haptic_, gain);
    }
    return ret;
}

int32_t GfxHaptic::hapticSetAutocenter(const int32_t autocenter) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((autocenter >= 0) && (autocenter <= 100));

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticSetAutocenter(haptic_, autocenter);
    }
    return ret;
}

int32_t GfxHaptic::hapticPause(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticPause(haptic_);
    }
    return ret;
}

int32_t GfxHaptic::hapticUnpause(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticUnpause(haptic_);
    }
    return ret;
}

int32_t GfxHaptic::hapticStopAll(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticStopAll(haptic_);
    }
    return ret;
}

bool GfxHaptic::hapticRumbleSupported(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticRumbleSupported(haptic_);
    }
    return (ret == SDL_TRUE);
}

int32_t GfxHaptic::hapticRumbleInit(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticRumbleInit(haptic_);
    }
    return ret;
}

int32_t GfxHaptic::hapticRumblePlay(const float strength, const uint32_t length) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((strength >= 0.0) && (strength <= 1.0));
    assert(length > 0);

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticRumblePlay(haptic_, strength, length);
    }
    return ret;
}

int32_t GfxHaptic::hapticRumbleStop(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (haptic_ != nullptr)
    {
        ret = SDL_HapticRumbleStop(haptic_);
    }
    return ret;
}

void GfxHaptic::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    haptic_ = nullptr;
}

GfxHaptic::SdlTypePtr GfxHaptic::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return haptic_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
