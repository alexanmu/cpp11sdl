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

#include <string.h>
#include <string>
#include <utility>

#include "GfxHapticEffect.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticeffect::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticEffect::ClassName[] = "GfxHapticEffect";

GfxHapticEffect::GfxHapticEffect() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticEffect::GfxHapticEffect(const SdlType effect) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    effect_ = effect;
}

GfxHapticEffect::GfxHapticEffect(const GfxHapticEffect& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    effect_ = other.effect_;
}

GfxHapticEffect::GfxHapticEffect(GfxHapticEffect&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    effect_ = other.effect_;
    // Delete other's value
    other.clear();
}

GfxHapticEffect& GfxHapticEffect::operator=(const GfxHapticEffect& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        effect_ = other.effect_;
    }
    return *this;
}

GfxHapticEffect& GfxHapticEffect::operator=(GfxHapticEffect&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        effect_ = other.effect_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxHapticEffect::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticEffect::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticEffect::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(effect_.type);
}

const GfxHapticConstant GfxHapticEffect::getConstant(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticConstant(effect_.constant);
}

const GfxHapticPeriodic GfxHapticEffect::getPeriodic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticPeriodic(effect_.periodic);
}

const GfxHapticCondition GfxHapticEffect::getCondition(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticCondition(effect_.condition);
}

const GfxHapticRamp GfxHapticEffect::getRamp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticRamp(effect_.ramp);
}

const GfxHapticLeftRight GfxHapticEffect::getLeftRight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticLeftRight(effect_.leftright);
}

const GfxHapticCustom GfxHapticEffect::getCustom(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticCustom(effect_.custom);
}

void GfxHapticEffect::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    effect_.type = 0;
    memset(static_cast<void *>(&effect_.constant), 0, sizeof(effect_.constant));
    memset(static_cast<void *>(&effect_.periodic), 0, sizeof(effect_.periodic));
    memset(static_cast<void *>(&effect_.condition), 0, sizeof(effect_.condition));
    memset(static_cast<void *>(&effect_.ramp), 0, sizeof(effect_.ramp));
    memset(static_cast<void *>(&effect_.leftright), 0, sizeof(effect_.leftright));
    memset(static_cast<void *>(&effect_.custom), 0, sizeof(effect_.custom));
}

GfxHapticEffect::SdlType GfxHapticEffect::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return effect_;
}

GfxHapticEffect::SdlTypePtr GfxHapticEffect::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&effect_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
