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
    clr_.a = 0;
}

GfxColor::GfxColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : GfxRootClass("GfxColor")
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

GfxColor::SdlType GfxColor::getAsSdlType() const
{
    return clr_;
}

GfxColor::SdlTypePtr GfxColor::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}
