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
#include <cstdlib>
#include <string>

#include "GfxPoint.hpp"

namespace gfx
{

const char GfxPoint::ClassName[] = "GfxPoint";

GfxPoint::GfxPoint() : GfxRootClass(ClassName)
{
    clear();
}

GfxPoint::GfxPoint(const int32_t x, const int32_t y) : GfxRootClass(ClassName)
{
    assert(x >= 0);
    assert(y >= 0);

    pt_.x = x;
    pt_.y = y;
}

GfxPoint::GfxPoint(const SdlType pt) : GfxRootClass(ClassName)
{
    pt_ = pt;
}

GfxPoint::GfxPoint(const GfxPoint& other) : GfxRootClass(ClassName)
{
    pt_ = other.pt_;
}

GfxPoint::GfxPoint(GfxPoint&& other) : GfxRootClass(ClassName)
{
    pt_ = other.pt_;
    /* Delete other's data */
    other.clear();
}

/* No assignement operators */
GfxPoint& GfxPoint::operator=(const GfxPoint& other)
{
    if (this != &other)
    {
        pt_ = other.pt_;
    }
    return *this;
}

GfxPoint& GfxPoint::operator=(GfxPoint&& other)
{
    if (this != &other)
    {
        pt_ = other.pt_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxPoint::operator==(const GfxPoint& other)
{
    return ((pt_.x == other.pt_.x) && (pt_.y == other.pt_.y));
}

GfxPoint::operator bool() const
{
    return true;
}

int32_t GfxPoint::getX(void) const
{
    return pt_.x;
}

int32_t GfxPoint::getY(void) const
{
    return pt_.y;
}

void GfxPoint::setX(const int32_t x)
{
    assert(x >= 0);

    pt_.x = x;
}

void GfxPoint::setY(const int32_t y)
{
    assert(y >= 0);

    pt_.y = y;
}

void GfxPoint::clear(void)
{
    pt_.x = -1;
    pt_.y = -1;
}

GfxPoint::SdlType GfxPoint::getAsSdlType(void) const
{
    return pt_;
}

GfxPoint::SdlTypePtr GfxPoint::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&pt_;
}

}  // namespace gfx

/* EOF */
