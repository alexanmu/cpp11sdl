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

#include "GfxHapticCoordinates.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticoordinates:haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticCoordinates::ClassName[] = "GfxHapticCoordinates";

GfxHapticCoordinates::GfxHapticCoordinates() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticCoordinates::GfxHapticCoordinates(const SdlType coord) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    coord_ = coord;
}

GfxHapticCoordinates::GfxHapticCoordinates(const ValueType coord) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    coord_ = static_cast<SdlType>(coord);
}

GfxHapticCoordinates::GfxHapticCoordinates(const GfxHapticCoordinates& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    coord_ = other.coord_;
}

GfxHapticCoordinates::GfxHapticCoordinates(GfxHapticCoordinates&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    coord_ = other.coord_;
    // Delete other's data
    other.clear();
}

GfxHapticCoordinates& GfxHapticCoordinates::operator=(const GfxHapticCoordinates& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        coord_ = other.coord_;
    }
    return *this;
}

GfxHapticCoordinates& GfxHapticCoordinates::operator=(GfxHapticCoordinates&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        coord_ = other.coord_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticCoordinates::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticCoordinates::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxHapticCoordinates::ValueType GfxHapticCoordinates::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(coord_);
}

bool GfxHapticCoordinates::isPolar(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (coord_ == static_cast<SdlType>(ValueType::hapticPolar));
}

bool GfxHapticCoordinates::isCartesian(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (coord_ == static_cast<SdlType>(ValueType::hapticCartesian));
}

bool GfxHapticCoordinates::isSpherical(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (coord_ == static_cast<SdlType>(ValueType::hapticSpherical));
}

void GfxHapticCoordinates::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    coord_ = static_cast<SdlType>(0);
}

GfxHapticCoordinates::SdlType GfxHapticCoordinates::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return coord_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
