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

#include "GfxDisplayMode.hpp"

GfxDisplayMode::GfxDisplayMode() : GfxRootClass("GfxDisplayMode")
{
    dmode_.format = 0;
    dmode_.w = -1;
    dmode_.h = -1;
    dmode_.refresh_rate = -1;
    dmode_.driverdata = NULL;
}

GfxDisplayMode::GfxDisplayMode(uint32_t format,int w,int h,int refresh) : GfxRootClass("GfxDisplayMode")
{
    dmode_.format = format;
    dmode_.w = w;
    dmode_.h = h;
    dmode_.refresh_rate = refresh;
    dmode_.driverdata = NULL;
}

GfxDisplayMode::GfxDisplayMode(GfxDisplayMode&& other) : GfxRootClass("GfxDisplayMode")
{
    dmode_.format = other.dmode_.format;
    dmode_.w = other.dmode_.w;
    dmode_.h = other.dmode_.h;
    dmode_.refresh_rate = other.dmode_.refresh_rate;
    dmode_.driverdata = other.dmode_.driverdata;
    // Delete other's data
    other.dmode_.format = 0;
    other.dmode_.w = -1;
    other.dmode_.h = -1;
    other.dmode_.refresh_rate = -1;
    other.dmode_.driverdata = NULL;
}

GfxDisplayMode& GfxDisplayMode::operator=(GfxDisplayMode&& other)
{
    if (this != &other)
    {
        dmode_.format = other.dmode_.format;
        dmode_.w = other.dmode_.w;
        dmode_.h = other.dmode_.h;
        dmode_.refresh_rate = other.dmode_.refresh_rate;
        dmode_.driverdata = other.dmode_.driverdata;
        // Delete other's data
        other.dmode_.format = 0;
        other.dmode_.w = -1;
        other.dmode_.h = -1;
        other.dmode_.refresh_rate = -1;
        other.dmode_.driverdata = NULL;
    }
    return *this;
}

uint32_t GfxDisplayMode::getFormat(void) const
{
    return dmode_.format;
}

int GfxDisplayMode::getWidth(void) const
{
    return dmode_.w;
}

int GfxDisplayMode::getHeight(void) const
{
    return dmode_.h;
}

int GfxDisplayMode::getRefreshRate(void) const
{
    return dmode_.refresh_rate;
}

GfxDisplayMode::SdlType GfxDisplayMode::getAsSdlType(void) const
{
    return dmode_;
}

GfxDisplayMode::SdlTypePtr GfxDisplayMode::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&dmode_;
}
