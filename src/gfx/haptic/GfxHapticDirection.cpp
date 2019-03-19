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

#include "GfxHapticDirection.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticdirection::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticDirection::ClassName[] = "GfxHapticDirection";

GfxHapticDirection::GfxHapticDirection() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticDirection::GfxHapticDirection(const SdlType dir) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    direction_ = dir;
}

GfxHapticDirection::GfxHapticDirection(const GfxHapticCoordinates& type, const int32_t dir1, const int32_t dir2,
        const int32_t dir3) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(type);

    direction_.type = type.getAsSdlType();
    direction_.dir[0] = dir1;
    direction_.dir[1] = dir2;
    direction_.dir[2] = dir3;
}

GfxHapticDirection::GfxHapticDirection(const GfxHapticDirection& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    direction_ = other.direction_;
}

GfxHapticDirection::GfxHapticDirection(GfxHapticDirection&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    direction_ = other.direction_;
    // Delete other's data
    other.clear();
}

GfxHapticDirection& GfxHapticDirection::operator=(const GfxHapticDirection& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        direction_ = other.direction_;
    }
    return *this;
}

GfxHapticDirection& GfxHapticDirection::operator=(GfxHapticDirection&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        direction_ = other.direction_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticDirection::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticDirection::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

uint8_t GfxHapticDirection::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return direction_.type;
}

int32_t GfxHapticDirection::getDirection1(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return direction_.dir[0];
}

int32_t GfxHapticDirection::getDirection2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return direction_.dir[1];
}

int32_t GfxHapticDirection::getDirection3(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return direction_.dir[2];
}

void GfxHapticDirection::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    direction_.type = 0;
    direction_.dir[0] = 0;
    direction_.dir[1] = 0;
    direction_.dir[2] = 0;
}

GfxHapticDirection::SdlType GfxHapticDirection::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return direction_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
