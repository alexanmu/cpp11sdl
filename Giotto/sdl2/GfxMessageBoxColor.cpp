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

#include "GfxMessageBoxColor.hpp"

GfxMessageBoxColor::GfxMessageBoxColor() : GfxRootClass("GfxMessageBoxColor")
{
    clr_.r = 0;
    clr_.g = 0;
    clr_.b = 0;
}

GfxMessageBoxColor::GfxMessageBoxColor(const uint8_t r, const  uint8_t g, const  uint8_t b) :
        GfxRootClass("GfxMessageBoxColor")
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
}

GfxMessageBoxColor::GfxMessageBoxColor(SdlType clr) : GfxRootClass("GfxMessageBoxColor")
{
    /* Copy structure; hope SDL_MessageBoxColor assignement operator works ... */
    clr_ = clr;
}

/* Copy constructor */
GfxMessageBoxColor::GfxMessageBoxColor(const GfxMessageBoxColor& other) : GfxRootClass("GfxMessageBoxColor")
{
    clr_ = other.clr_;
}

/* Move constructor */
GfxMessageBoxColor::GfxMessageBoxColor(GfxMessageBoxColor&& other) : GfxRootClass("GfxMessageBoxColor")
{
    clr_ = other.clr_;
    /* Delete other's data */
    other.clr_.r = 0;
    other.clr_.g = 0;
    other.clr_.b = 0;
}

/* Delete copy and move assign operators */
GfxMessageBoxColor& GfxMessageBoxColor::operator=(const GfxMessageBoxColor& other)
{
    if (this != &other)
    {
        clr_ = other.clr_;
    }
    return *this;
}

GfxMessageBoxColor& GfxMessageBoxColor::operator=(GfxMessageBoxColor&& other)
{
    if (this != &other)
    {
        clr_ = other.clr_;
        other.clr_.r = 0;
        other.clr_.g = 0;
        other.clr_.b = 0;
    }
    return *this;
}

bool GfxMessageBoxColor::operator==(const GfxMessageBoxColor& other)
{
    return ((clr_.r == other.clr_.r) && (clr_.g == other.clr_.g) && (clr_.b == other.clr_.b));
}

uint8_t GfxMessageBoxColor::getRed(void) const
{
    return clr_.r;
}

uint8_t GfxMessageBoxColor::getGreen(void) const
{
    return clr_.g;
}

uint8_t GfxMessageBoxColor::getBlue(void) const
{
    return clr_.b;
}

uint32_t GfxMessageBoxColor::getColor() const
{
    uint32_t c = 0;

    c |= clr_.r << 16 | clr_.g << 8 | clr_.b;
    return c;
}

void GfxMessageBoxColor::setRed(const uint8_t r)
{
    clr_.r = r;
}

void GfxMessageBoxColor::setGreen(const uint8_t g)
{
    clr_.g = g;
}

void GfxMessageBoxColor::setBlue(const uint8_t b)
{
    clr_.b = b;
}

GfxMessageBoxColor::SdlType GfxMessageBoxColor::getAsSdlType() const
{
    return clr_;
}

GfxMessageBoxColor::SdlTypePtr GfxMessageBoxColor::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}

/* EOF */
