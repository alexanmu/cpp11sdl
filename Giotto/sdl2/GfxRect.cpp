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

#include "GfxRect.hpp"

namespace gfx
{

const char GfxRect::ClassName[] = "GfxRect";

GfxRect::GfxRect() : GfxRootClass(ClassName)
{
    rect_.x = -1;
    rect_.y = -1;
    rect_.w = -1;
    rect_.h = -1;
}

GfxRect::GfxRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h) : GfxRootClass(ClassName)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(w >= 0);
    assert(h >= 0);

    rect_.x = x;
    rect_.y = y;
    rect_.w = w;
    rect_.h = h;
}

GfxRect::GfxRect(SdlType rect) : GfxRootClass(ClassName)
{
    rect_ = rect;
}

GfxRect::GfxRect(const GfxRect& other) : GfxRootClass(ClassName)
{
    rect_ = other.rect_;
}

GfxRect::GfxRect(GfxRect&& other) : GfxRootClass(ClassName)
{
    rect_ = other.rect_;
    other.clear();
}

GfxRect& GfxRect::operator=(const GfxRect& other)
{
    if (this != &other)
    {
        rect_ = other.rect_;
    }
    return *this;
}

GfxRect& GfxRect::operator=(GfxRect&& other)
{
    if (this != &other)
    {
        rect_ = other.rect_;
        other.clear();
    }
    return *this;
}

bool GfxRect::operator==(const GfxRect& other)
{
    return ((rect_.x == other.rect_.x) && (rect_.y == other.rect_.y) &&
            (rect_.w == other.rect_.w) && (rect_.h == other.rect_.h));
}

GfxRect::operator bool() const
{
    return true;
}

int32_t GfxRect::getX(void) const
{
    return rect_.x;
}

int32_t GfxRect::getY(void) const
{
    return rect_.y;
}

int32_t GfxRect::getWidth(void) const
{
    return rect_.w;
}

int32_t GfxRect::getHeight(void) const
{
    return rect_.h;
}

void GfxRect::setX(const int32_t x)
{
    assert(x >= 0);

    rect_.x = x;
}

void GfxRect::setY(const int32_t y)
{
    assert(y >= 0);

    rect_.y = y;
}

void GfxRect::setWidth(const int32_t w)
{
    assert(w >= 0);

    rect_.w = w;
}

void GfxRect::setHeight(const int32_t h)
{
    assert(h >= 0);

    rect_.h = h;
}

void GfxRect::set(SdlType r)
{
    rect_ = r;
};

void GfxRect::clear(void)
{
    rect_.x = -1;
    rect_.y = -1;
    rect_.w = -1;
    rect_.h = -1;
}

GfxRect::SdlType GfxRect::getAsSdlType() const
{
    return rect_;
}

GfxRect::SdlTypePtr GfxRect::getAsSdlTypePtr() const
{
    return (SdlTypePtr)&rect_;
}

}  // namespace gfx

/* EOF */
