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

GfxRect::GfxRect(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h) : GfxRootClass(ClassName)
{
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

uint16_t GfxRect::getX(void) const
{
    return rect_.x;
}

uint16_t GfxRect::getY(void) const
{
    return rect_.y;
}

uint16_t GfxRect::getWidth(void) const
{
    return rect_.w;
}

uint16_t GfxRect::getHeight(void) const
{
    return rect_.h;
}

void GfxRect::setX(const uint16_t x)
{
    rect_.x = x;
}

void GfxRect::setY(const uint16_t y)
{
    rect_.y = y;
}

void GfxRect::setWidth(const uint16_t w)
{
    rect_.w = w;
}

void GfxRect::setHeight(const uint16_t h)
{
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
