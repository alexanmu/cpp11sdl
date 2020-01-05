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

#include "GfxHapticConstant.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticconstant::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticConstant::ClassName[] = "GfxHapticConstant";

GfxHapticConstant::GfxHapticConstant() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticConstant::GfxHapticConstant(const SdlType hConst) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hConst_ = hConst;
}

GfxHapticConstant::GfxHapticConstant(const GfxHapticConstant& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hConst_ = other.hConst_;
}

GfxHapticConstant::GfxHapticConstant(GfxHapticConstant&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hConst_ = other.hConst_;
    // Delete other's data
    other.clear();
}

GfxHapticConstant& GfxHapticConstant::operator=(const GfxHapticConstant& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hConst_ = other.hConst_;
    }
    return *this;
}

GfxHapticConstant& GfxHapticConstant::operator=(GfxHapticConstant&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hConst_ = other.hConst_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticConstant::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticConstant::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticConstant::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hConst_.type);
}

const GfxHapticDirection GfxHapticConstant::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticDirection(hConst_.direction);
}

uint32_t GfxHapticConstant::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.length;
}

uint16_t GfxHapticConstant::getDelay(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.delay;
}

uint16_t GfxHapticConstant::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.button;
}

uint16_t GfxHapticConstant::getInterval(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.interval;
}

int16_t GfxHapticConstant::getLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.level;
}

uint16_t GfxHapticConstant::getAttackLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.attack_length;
}

uint16_t GfxHapticConstant::getAttackLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.attack_level;
}

uint16_t GfxHapticConstant::getFadeLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.fade_length;
}

uint16_t GfxHapticConstant::getFadeLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_.fade_level;
}

void GfxHapticConstant::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hConst_.type = SDL_HAPTIC_CONSTANT;
    hConst_.direction.type = 0;
    hConst_.direction.dir[0] = 0;
    hConst_.direction.dir[1] = 0;
    hConst_.direction.dir[2] = 0;
    hConst_.length = 0;
    hConst_.delay = 0;
    hConst_.button = 0;
    hConst_.interval = 0;
    hConst_.level = 0;
    hConst_.attack_length = 0;
    hConst_.attack_level = 0;
    hConst_.fade_length = 0;
    hConst_.fade_level = 0;
}

GfxHapticConstant::SdlType GfxHapticConstant::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hConst_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
