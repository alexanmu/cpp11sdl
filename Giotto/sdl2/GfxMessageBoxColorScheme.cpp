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

#include "GfxMessageBoxColorScheme.hpp"

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme() : GfxRootClass("GfxMessageBoxColorScheme")
{
    for (int index = 0; index < 5; index++)
    {
        clrscheme_.colors[index].r = 0x00;
        clrscheme_.colors[index].g = 0x00;
        clrscheme_.colors[index].b = 0x00;
    }
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(GfxMessageBoxColor colors[]) : GfxRootClass("GfxMessageBoxColorScheme")
{
    for (int index = 0; index < 5; index++)
    {
        clrscheme_.colors[index] = colors[index].getAsSdlType();
    }
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(GfxMessageBoxColorScheme const& other)
{
    clrscheme_ = other.clrscheme_;
}

GfxMessageBoxColorScheme::GfxMessageBoxColorScheme(GfxMessageBoxColorScheme&& other)
{
    clrscheme_ = other.clrscheme_;
    // Delete other's data
    for (int index = 0; index < 5; index++)
    {
        clrscheme_.colors[index].r = 0x00;
        clrscheme_.colors[index].g = 0x00;
        clrscheme_.colors[index].b = 0x00;
    }
}

GfxMessageBoxColorScheme& GfxMessageBoxColorScheme::operator=(GfxMessageBoxColorScheme const& other)
{
    if (this != &other)
    {
        clrscheme_ = other.clrscheme_;
    }
    return *this;
}

GfxMessageBoxColorScheme& GfxMessageBoxColorScheme::operator=(GfxMessageBoxColorScheme&& other)
{
    if (this != &other)
    {
        clrscheme_ = other.clrscheme_;
        // Delete other's data
        for (int index = 0; index < 5; index++)
        {
            clrscheme_.colors[index].r = 0x00;
            clrscheme_.colors[index].g = 0x00;
            clrscheme_.colors[index].b = 0x00;
        }
    }
    return *this;
}

GfxMessageBoxColorScheme::SdlType GfxMessageBoxColorScheme::getAsSdlType(void) const
{
    return (SdlType)clrscheme_;
}

GfxMessageBoxColorScheme::SdlTypePtr GfxMessageBoxColorScheme::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&clrscheme_;
}
