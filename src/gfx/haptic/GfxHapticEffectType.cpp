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

#include <string>
#include <utility>

#include "GfxHapticEffectType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticeffecttype::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticEffectType::ClassName[] = "GfxHapticEffectType";

GfxHapticEffectType::GfxHapticEffectType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticEffectType::GfxHapticEffectType(const ValueType etype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    eType_ = static_cast<SdlType>(etype);
}

GfxHapticEffectType::GfxHapticEffectType(const SdlType etype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    eType_ = etype;
}

GfxHapticEffectType::GfxHapticEffectType(const GfxHapticEffectType& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    eType_ = other.eType_;
}

GfxHapticEffectType::GfxHapticEffectType(GfxHapticEffectType&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    eType_ = other.eType_;
    // Delete other's value
    other.clear();
}

GfxHapticEffectType& GfxHapticEffectType::operator=(const GfxHapticEffectType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        eType_ = other.eType_;
    }
    return *this;
}

GfxHapticEffectType& GfxHapticEffectType::operator=(GfxHapticEffectType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        eType_ = other.eType_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxHapticEffectType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticEffectType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxHapticEffectType::ValueType GfxHapticEffectType::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(eType_);
}

bool GfxHapticEffectType::isConstant(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticConstant));
}

bool GfxHapticEffectType::isSine(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticSine));
}

bool GfxHapticEffectType::isLeftRight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticLeftRight));
}

bool GfxHapticEffectType::isSquare(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

#warning SDL2 2.1 Will fix this!
    return false;
}

bool GfxHapticEffectType::isTriangle(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticTriangle));
}

bool GfxHapticEffectType::isSawToothUp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticSawToothUp));
}

bool GfxHapticEffectType::isSawToothDown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticSawToothDown));
}

bool GfxHapticEffectType::isRamp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticRamp));
}

bool GfxHapticEffectType::isSpring(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticSpring));
}

bool GfxHapticEffectType::isDamper(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticDamper));
}

bool GfxHapticEffectType::isInertia(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticInertia));
}

bool GfxHapticEffectType::isFriction(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticFriction));
}

bool GfxHapticEffectType::isCustom(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticCustom));
}

bool GfxHapticEffectType::isGain(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticGain));
}

bool GfxHapticEffectType::isAutoCenter(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticAutoCenter));
}

bool GfxHapticEffectType::isStatus(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticStatus));
}

bool GfxHapticEffectType::isPause(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eType_ == static_cast<SdlType>(ValueType::hapticPause));
}

void GfxHapticEffectType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    eType_ = static_cast<SdlType>(ValueType::hapticConstant);
}

GfxHapticEffectType::SdlType GfxHapticEffectType::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return eType_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
