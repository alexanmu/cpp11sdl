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

#include <cassert>
#include <string>
#include <utility>

#include "GfxHapticCondition.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticcondition::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticCondition::ClassName[] = "GfxHapticCondition";

GfxHapticCondition::GfxHapticCondition() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticCondition::GfxHapticCondition(const SdlType hCond) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hCond_ = hCond;
}

GfxHapticCondition::GfxHapticCondition(const GfxHapticCondition& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hCond_ = other.hCond_;
}

GfxHapticCondition::GfxHapticCondition(GfxHapticCondition&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hCond_ = other.hCond_;
    // Delete other's data
    other.clear();
}

GfxHapticCondition& GfxHapticCondition::operator=(const GfxHapticCondition& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hCond_ = other.hCond_;
    }
    return *this;
}

GfxHapticCondition& GfxHapticCondition::operator=(GfxHapticCondition&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hCond_ = other.hCond_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticCondition::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticCondition::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticCondition::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hCond_.type);
}

const GfxHapticDirection GfxHapticCondition::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticDirection(hCond_.direction);
}

uint32_t GfxHapticCondition::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCond_.length;
}

uint16_t GfxHapticCondition::getDelay(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCond_.delay;
}

uint16_t GfxHapticCondition::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCond_.button;
}

uint16_t GfxHapticCondition::getInterval(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCond_.interval;
}

const GfxHapticCondition::RightSat GfxHapticCondition::getRightSat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return RightSat(const_cast<uint16_t *>(&hCond_.right_sat[0]));
}

const GfxHapticCondition::LeftSat GfxHapticCondition::getLeftSat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return LeftSat(const_cast<uint16_t *>(&hCond_.left_sat[0]));
}

const GfxHapticCondition::RightCoeff GfxHapticCondition::getRightCoeff(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return RightCoeff(const_cast<int16_t *>(&hCond_.right_coeff[0]));
}

const GfxHapticCondition::LeftCoeff GfxHapticCondition::getLeftCoeff(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return LeftCoeff(const_cast<int16_t *>(&hCond_.left_coeff[0]));
}

const GfxHapticCondition::Deadband GfxHapticCondition::getDeadband(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return Deadband(const_cast<uint16_t *>(&hCond_.deadband[0]));
}

const GfxHapticCondition::Center GfxHapticCondition::getCenter(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return Center(const_cast<int16_t *>(&hCond_.center[0]));
}

void GfxHapticCondition::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hCond_.type = SDL_HAPTIC_SPRING;
    hCond_.direction.type = 0;
    hCond_.direction.dir[0] = 0;
    hCond_.direction.dir[1] = 0;
    hCond_.direction.dir[2] = 0;
    hCond_.length = 0;
    hCond_.delay = 0;
    hCond_.button = 0;
    hCond_.interval = 0;
    hCond_.right_sat[0] = 0;
    hCond_.right_sat[1] = 0;
    hCond_.right_sat[2] = 0;
    hCond_.left_sat[0] = 0;
    hCond_.left_sat[1] = 0;
    hCond_.left_sat[2] = 0;
    hCond_.right_coeff[0] = 0;
    hCond_.right_coeff[1] = 0;
    hCond_.right_coeff[2] = 0;
    hCond_.left_coeff[0] = 0;
    hCond_.left_coeff[1] = 0;
    hCond_.left_coeff[2] = 0;
    hCond_.deadband[0] = 0;
    hCond_.deadband[1] = 0;
    hCond_.deadband[2] = 0;
    hCond_.center[0] = 0;
    hCond_.center[1] = 0;
    hCond_.center[2] = 0;
}

GfxHapticCondition::SdlType GfxHapticCondition::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCond_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
