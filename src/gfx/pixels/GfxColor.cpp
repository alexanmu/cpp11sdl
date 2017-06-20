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

#include <cstdint>
#include <string>

#include "GfxColor.hpp"

namespace gfx
{

namespace pixels
{

const char GfxColor::ClassName[] = "GfxColor";

GfxColor::GfxColor() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxColor::GfxColor(const uint8_t r, const  uint8_t g, const  uint8_t b) noexcept : GfxObject(ClassName)
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = 0xFFu;
}

GfxColor::GfxColor(const uint8_t r, const  uint8_t g, const  uint8_t b, const  uint8_t a) noexcept :
            GfxObject(ClassName)
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = a;
}

GfxColor::GfxColor(const SdlType clr) noexcept : GfxObject(ClassName)
{
    /* Copy structure; hope SDL_Color assignement operator works ... */
    clr_ = clr;
}

GfxColor::GfxColor(const uint32_t clr) noexcept : GfxObject(ClassName)
{
    clr_.r = (clr & 0x000000FF);
    clr_.g = (clr & 0x0000FF00) >> 8;
    clr_.b = (clr & 0x00FF0000) >> 16;
    clr_.a = (clr & 0xFF000000) >> 24;
}

/* Copy constructor */
GfxColor::GfxColor(GfxColor const& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
}

/* Move constructor */
GfxColor::GfxColor(GfxColor&& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
    /* Delete other's data */
    other.clear();
}

/* Delete copy and move assign operators */
GfxColor& GfxColor::operator=(GfxColor const& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
    }
    return *this;
}

GfxColor& GfxColor::operator=(GfxColor&& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
        other.clear();
    }
    return *this;
}

bool GfxColor::operator==(GfxColor const& other) const noexcept
{
    return ((clr_.r == other.clr_.r) && (clr_.g == other.clr_.g) &&
            (clr_.b == other.clr_.b) && (clr_.a == other.clr_.a));
}

GfxColor::operator bool() const noexcept
{
    return true;
}

uint8_t GfxColor::getRed(void) const noexcept
{
    return clr_.r;
}

uint8_t GfxColor::getGreen(void) const noexcept
{
    return clr_.g;
}

uint8_t GfxColor::getBlue(void) const noexcept
{
    return clr_.b;
}

uint8_t GfxColor::getAlpha(void) const noexcept
{
    return clr_.a;
}

uint32_t GfxColor::getColor() const noexcept
{
    uint32_t c = clr_.a << 24 | clr_.r << 16 | clr_.g << 8 | clr_.b;
    return c;
}

void GfxColor::setRed(const uint8_t r) noexcept
{
    clr_.r = r;
}

void GfxColor::setGreen(const uint8_t g) noexcept
{
    clr_.g = g;
}

void GfxColor::setBlue(const uint8_t b) noexcept
{
    clr_.b = b;
}

void GfxColor::setAlpha(const uint8_t a) noexcept
{
    clr_.a = a;
}

void GfxColor::clear(void) noexcept
{
    clr_.r = 0;
    clr_.g = 0;
    clr_.b = 0;
    clr_.a = 0xFFu;
}

GfxColor::SdlType GfxColor::getAsSdlType() const noexcept
{
    return clr_;
}

GfxColor::SdlTypePtr GfxColor::getAsSdlTypePtr(void) const noexcept
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
