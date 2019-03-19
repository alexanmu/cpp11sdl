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

#include "GfxHapticCustom.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticcustom::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticCustom::ClassName[] = "GfxHapticCustom";

GfxHapticCustom::GfxHapticCustom() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticCustom::GfxHapticCustom(const SdlType hCust) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hCust_ = hCust;
}

GfxHapticCustom::GfxHapticCustom(const GfxHapticCustom& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hCust_ = other.hCust_;
}

GfxHapticCustom::GfxHapticCustom(GfxHapticCustom&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hCust_ = other.hCust_;
    // Delete other's data
    other.clear();
}

GfxHapticCustom& GfxHapticCustom::operator=(const GfxHapticCustom& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hCust_ = other.hCust_;
    }
    return *this;
}

GfxHapticCustom& GfxHapticCustom::operator=(GfxHapticCustom&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hCust_ = other.hCust_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticCustom::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticCustom::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticCustom::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hCust_.type);
}

const GfxHapticDirection GfxHapticCustom::getDirection(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticDirection(hCust_.direction);
}

uint32_t GfxHapticCustom::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.length;
}

uint16_t GfxHapticCustom::getDelay(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.delay;
}

uint16_t GfxHapticCustom::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.button;
}

uint16_t GfxHapticCustom::getInterval(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.interval;
}

uint8_t GfxHapticCustom::getChannels(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.channels;
}

uint16_t GfxHapticCustom::getPeriod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.period;
}

uint16_t GfxHapticCustom::getSamples(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.samples;
}

uint16_t * GfxHapticCustom::getData(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.data;
}

uint16_t GfxHapticCustom::getAttackLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.attack_length;
}

uint16_t GfxHapticCustom::getAttackLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.attack_level;
}

uint16_t GfxHapticCustom::getFadeLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.fade_length;
}

uint16_t GfxHapticCustom::getFadeLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_.fade_level;
}

void GfxHapticCustom::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hCust_.type = SDL_HAPTIC_CUSTOM;
    hCust_.direction.type = 0;
    hCust_.direction.dir[0] = 0;
    hCust_.direction.dir[1] = 0;
    hCust_.direction.dir[2] = 0;
    hCust_.length = 0;
    hCust_.delay = 0;
    hCust_.button = 0;
    hCust_.interval = 0;
    hCust_.channels = 0;
    hCust_.period = 0;
    hCust_.samples = 0;
    hCust_.data = NULL;
    hCust_.attack_length = 0;
    hCust_.attack_level = 0;
    hCust_.fade_length = 0;
    hCust_.fade_level = 0;
}

GfxHapticCustom::SdlType GfxHapticCustom::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hCust_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
