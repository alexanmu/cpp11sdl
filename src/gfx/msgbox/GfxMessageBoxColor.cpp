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

#include "GfxMessageBoxColor.hpp"

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxColor::ClassName[] = "GfxMessageBoxColor";

GfxMessageBoxColor::GfxMessageBoxColor() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxMessageBoxColor::GfxMessageBoxColor(const uint8_t r, const  uint8_t g, const  uint8_t b) noexcept :
        GfxObject(ClassName)
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
}

GfxMessageBoxColor::GfxMessageBoxColor(const SdlType clr) noexcept : GfxObject(ClassName)
{
    /* Copy structure; hope SDL_MessageBoxColor assignement operator works ... */
    clr_ = clr;
}

/* Copy constructor */
GfxMessageBoxColor::GfxMessageBoxColor(GfxMessageBoxColor const& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
}

/* Move constructor */
GfxMessageBoxColor::GfxMessageBoxColor(GfxMessageBoxColor&& other) noexcept : GfxObject(ClassName)
{
    clr_ = other.clr_;
    /* Delete other's data */
    other.clear();
}

/* Delete copy and move assign operators */
GfxMessageBoxColor& GfxMessageBoxColor::operator=(GfxMessageBoxColor const& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
    }
    return *this;
}

GfxMessageBoxColor& GfxMessageBoxColor::operator=(GfxMessageBoxColor&& other) noexcept
{
    if (this != &other)
    {
        clr_ = other.clr_;
        other.clear();
    }
    return *this;
}

bool GfxMessageBoxColor::operator==(GfxMessageBoxColor const& other) noexcept
{
    return ((clr_.r == other.clr_.r) && (clr_.g == other.clr_.g) && (clr_.b == other.clr_.b));
}

GfxMessageBoxColor::operator bool() const noexcept
{
    return true;
}

uint8_t GfxMessageBoxColor::getRed(void) const noexcept
{
    return clr_.r;
}

uint8_t GfxMessageBoxColor::getGreen(void) const noexcept
{
    return clr_.g;
}

uint8_t GfxMessageBoxColor::getBlue(void) const noexcept
{
    return clr_.b;
}

void GfxMessageBoxColor::setRed(const uint8_t r) noexcept
{
    clr_.r = r;
}

void GfxMessageBoxColor::setGreen(const uint8_t g) noexcept
{
    clr_.g = g;
}

void GfxMessageBoxColor::setBlue(const uint8_t b) noexcept
{
    clr_.b = b;
}

void GfxMessageBoxColor::clear(void) noexcept
{
    clr_.r = 0;
    clr_.g = 0;
    clr_.b = 0;
}

GfxMessageBoxColor::SdlType GfxMessageBoxColor::getAsSdlType() const noexcept
{
    return clr_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */
