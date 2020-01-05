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
#include <cstdlib>
#include <string>
#include <utility>

#include "GfxPoint.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpoint::rect::gfx");

namespace gfx
{

namespace rect
{

const char GfxPoint::ClassName[] = "GfxPoint";

GfxPoint::GfxPoint() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxPoint::GfxPoint(const int32_t x, const int32_t y) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(x >= 0);
    assert(y >= 0);

    pt_.x = x;
    pt_.y = y;
}

GfxPoint::GfxPoint(const SdlType pt) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    pt_ = pt;
}

GfxPoint::GfxPoint(const GfxPoint& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    pt_ = other.pt_;
}

GfxPoint::GfxPoint(GfxPoint&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    pt_ = other.pt_;
    /* Delete other's data */
    other.clear();
}

GfxPoint& GfxPoint::operator=(const GfxPoint& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        pt_ = other.pt_;
    }
    return *this;
}

GfxPoint& GfxPoint::operator=(GfxPoint&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        pt_ = other.pt_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxPoint::operator==(const GfxPoint& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ((pt_.x == other.pt_.x) && (pt_.y == other.pt_.y));
}

GfxPoint::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPoint::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxPoint::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pt_.x;
}

int32_t GfxPoint::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pt_.y;
}

void GfxPoint::setX(const int32_t x) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x >= 0);

    pt_.x = x;
}

void GfxPoint::setY(const int32_t y) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(y >= 0);

    pt_.y = y;
}

void GfxPoint::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pt_.x = -1;
    pt_.y = -1;
}

GfxPoint::SdlType GfxPoint::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pt_;
}

GfxPoint::SdlTypePtr GfxPoint::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&pt_;
}

}  // namespace rect

}  // namespace gfx

/* EOF */
