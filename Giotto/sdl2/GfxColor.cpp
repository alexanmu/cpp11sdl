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

#include "GfxColor.hpp"

namespace gfx
{

const char GfxColor::ClassName[] = "GfxColor";

GfxColor::GfxColor() : GfxRootClass(ClassName)
{
    clear();
}

GfxColor::GfxColor(const uint8_t r, const  uint8_t g, const  uint8_t b) : GfxRootClass(ClassName)
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = 0xFF;
}

GfxColor::GfxColor(const uint8_t r, const  uint8_t g, const  uint8_t b, const  uint8_t a) : GfxRootClass(ClassName)
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = a;
}

GfxColor::GfxColor(SdlType clr) : GfxRootClass(ClassName)
{
    /* Copy structure; hope SDL_Color assignement operator works ... */
    clr_ = clr;
}

/* Copy constructor */
GfxColor::GfxColor(const GfxColor& other) : GfxRootClass(ClassName)
{
    clr_ = other.clr_;
}

/* Move constructor */
GfxColor::GfxColor(GfxColor&& other) : GfxRootClass(ClassName)
{
    clr_ = other.clr_;
    /* Delete other's data */
    other.clear();
}

/* Delete copy and move assign operators */
GfxColor& GfxColor::operator=(const GfxColor& other)
{
    if (this != &other)
    {
        clr_ = other.clr_;
    }
    return *this;
}

GfxColor& GfxColor::operator=(GfxColor&& other)
{
    if (this != &other)
    {
        clr_ = other.clr_;
        other.clear();
    }
    return *this;
}

bool GfxColor::operator==(const GfxColor& other)
{
    return ((clr_.r == other.clr_.r) && (clr_.g == other.clr_.g) &&
            (clr_.b == other.clr_.b) && (clr_.a == other.clr_.a));
}

uint8_t GfxColor::getRed(void) const
{
    return clr_.r;
}

uint8_t GfxColor::getGreen(void) const
{
    return clr_.g;
}

uint8_t GfxColor::getBlue(void) const
{
    return clr_.b;
}

uint8_t GfxColor::getAlpha(void) const
{
    return clr_.a;
}

uint32_t GfxColor::getColor() const
{
    uint32_t c = clr_.a << 24 | clr_.r << 16 | clr_.g << 8 | clr_.b;
    return c;
}

void GfxColor::setRed(const uint8_t r)
{
    clr_.r = r;
}

void GfxColor::setGreen(const uint8_t g)
{
    clr_.g = g;
}

void GfxColor::setBlue(const uint8_t b)
{
    clr_.b = b;
}

void GfxColor::setAlpha(const uint8_t a)
{
    clr_.a = a;
}

void GfxColor::clear(void)
{
    clr_.r = 0;
    clr_.g = 0;
    clr_.b = 0;
    clr_.a = 0xFF;
}

GfxColor::SdlType GfxColor::getAsSdlType() const
{
    return clr_;
}

GfxColor::SdlTypePtr GfxColor::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}

}  // namespace gfx

/* EOF */
