//
//  GfxColor.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#include "GfxColor.hpp"

GfxColor::GfxColor() : GfxRootClass("GfxColor")
{
    clr_.r = 0;
    clr_.g = 0;
    clr_.b = 0;
    clr_.a = 0xFF;
}

GfxColor::GfxColor(const uint8_t r,const  uint8_t g,const  uint8_t b) : GfxRootClass("GfxColor")
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = 0xFF;
}

GfxColor::GfxColor(const uint8_t r,const  uint8_t g,const  uint8_t b,const  uint8_t a) : GfxRootClass("GfxColor")
{
    clr_.r = r;
    clr_.g = g;
    clr_.b = b;
    clr_.a = a;
}

GfxColor::GfxColor(SdlType clr) : GfxRootClass("GfxColor")
{
    /* Copy structure; hope SDL_Color assignement operator works ... */
    clr_ = clr;
}

/* Copy constructor */
GfxColor::GfxColor(const GfxColor& other) : GfxRootClass("GfxColor")
{
    clr_ = other.clr_;
}

/* Move constructor */
GfxColor::GfxColor(GfxColor&& other) : GfxRootClass("GfxColor")
{
    clr_ = other.clr_;
    /* Delete other's data */
    other.clr_.r = 0;
    other.clr_.g = 0;
    other.clr_.b = 0;
    other.clr_.a = 0;
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
        other.clr_.r = 0;
        other.clr_.g = 0;
        other.clr_.b = 0;
        other.clr_.a = 0;
    }
    return *this;
}

bool GfxColor::operator==(const GfxColor& other)
{
    return ((clr_.r == other.clr_.r) && (clr_.g == other.clr_.g) && (clr_.b == other.clr_.b) && (clr_.a == other.clr_.a));
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

GfxColor::SdlType GfxColor::getAsSdlType() const
{
    return clr_;
}

GfxColor::SdlTypePtr GfxColor::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}
