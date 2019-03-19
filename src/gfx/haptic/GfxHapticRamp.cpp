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

#include <cassert>
#include <string>
#include <utility>

#include "GfxHapticRamp.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticramp::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticRamp::ClassName[] = "GfxHapticRamp";

GfxHapticRamp::GfxHapticRamp() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticRamp::GfxHapticRamp(const SdlType hRamp) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hRamp_ = hRamp;
}

GfxHapticRamp::GfxHapticRamp(const GfxHapticRamp& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hRamp_ = other.hRamp_;
}

GfxHapticRamp::GfxHapticRamp(GfxHapticRamp&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hRamp_ = other.hRamp_;
    // Delete other's data
    other.clear();
}

GfxHapticRamp& GfxHapticRamp::operator=(const GfxHapticRamp& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hRamp_ = other.hRamp_;
    }
    return *this;
}

GfxHapticRamp& GfxHapticRamp::operator=(GfxHapticRamp&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hRamp_ = other.hRamp_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticRamp::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticRamp::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticRamp::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hRamp_.type);
}

const GfxHapticDirection GfxHapticRamp::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticDirection(hRamp_.direction);
}

uint32_t GfxHapticRamp::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.length;
}

uint16_t GfxHapticRamp::getDelay(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.delay;
}

uint16_t GfxHapticRamp::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.button;
}

uint16_t GfxHapticRamp::getInterval(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

return hRamp_.interval;
}

int16_t GfxHapticRamp::getStart(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.start;
}

int16_t GfxHapticRamp::getEnd(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.end;
}

uint16_t GfxHapticRamp::getAttackLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.attack_length;
}

uint16_t GfxHapticRamp::getAttackLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.attack_level;
}

uint16_t GfxHapticRamp::getFadeLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.fade_length;
}

uint16_t GfxHapticRamp::getFadeLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_.fade_level;
}

void GfxHapticRamp::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hRamp_.type = SDL_HAPTIC_RAMP;
    hRamp_.direction.type = 0;
    hRamp_.direction.dir[0] = 0;
    hRamp_.direction.dir[1] = 0;
    hRamp_.direction.dir[2] = 0;
    hRamp_.length = 0;
    hRamp_.delay = 0;
    hRamp_.button = 0;
    hRamp_.interval = 0;
    hRamp_.start = 0;
    hRamp_.end = 0;
    hRamp_.attack_length = 0;
    hRamp_.attack_level = 0;
    hRamp_.fade_length = 0;
    hRamp_.fade_level = 0;
}

GfxHapticRamp::SdlType GfxHapticRamp::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hRamp_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
