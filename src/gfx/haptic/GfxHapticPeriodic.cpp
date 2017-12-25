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

#include <cassert>
#include <string>
#include <utility>

#include "GfxHapticPeriodic.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticperiodic::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticPeriodic::ClassName[] = "GfxHapticPeriodic";

GfxHapticPeriodic::GfxHapticPeriodic() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticPeriodic::GfxHapticPeriodic(const SdlType hPer) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hPer_ = hPer;
}

GfxHapticPeriodic::GfxHapticPeriodic(GfxHapticPeriodic const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hPer_ = other.hPer_;
}

GfxHapticPeriodic::GfxHapticPeriodic(GfxHapticPeriodic&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hPer_ = other.hPer_;
    // Delete other's data
    other.clear();
}

GfxHapticPeriodic& GfxHapticPeriodic::operator=(GfxHapticPeriodic const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hPer_ = other.hPer_;
    }
    return *this;
}

GfxHapticPeriodic& GfxHapticPeriodic::operator=(GfxHapticPeriodic&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hPer_ = other.hPer_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticPeriodic::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticPeriodic::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticPeriodic::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hPer_.type);
}

const GfxHapticDirection GfxHapticPeriodic::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticDirection(hPer_.direction);
}

uint32_t GfxHapticPeriodic::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.length;
}

uint16_t GfxHapticPeriodic::getDelay(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.delay;
}

uint16_t GfxHapticPeriodic::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.button;
}

uint16_t GfxHapticPeriodic::getInterval(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.interval;
}

uint16_t GfxHapticPeriodic::getPeriod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.period;
}

int16_t GfxHapticPeriodic::getMagnitude(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.magnitude;
}

int16_t GfxHapticPeriodic::getOffset(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.offset;
}

uint16_t GfxHapticPeriodic::getPhase(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.phase;
}

uint16_t GfxHapticPeriodic::getAttackLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.attack_length;
}

uint16_t GfxHapticPeriodic::getAttackLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.attack_level;
}

uint16_t GfxHapticPeriodic::getFadeLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.fade_length;
}

uint16_t GfxHapticPeriodic::getFadeLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_.fade_level;
}

void GfxHapticPeriodic::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hPer_.type = SDL_HAPTIC_SINE;
    hPer_.direction.type = 0;
    hPer_.direction.dir[0] = 0;
    hPer_.direction.dir[1] = 0;
    hPer_.direction.dir[2] = 0;
    hPer_.length = 0;
    hPer_.delay = 0;
    hPer_.button = 0;
    hPer_.interval = 0;
    hPer_.period = 0;
    hPer_.magnitude = 0;
    hPer_.offset = 0;
    hPer_.phase = 0;
    hPer_.attack_length = 0;
    hPer_.attack_level = 0;
    hPer_.fade_length = 0;
    hPer_.fade_level = 0;
}

GfxHapticPeriodic::SdlType GfxHapticPeriodic::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hPer_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
