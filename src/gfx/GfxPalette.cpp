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
#include <cstdint>
#include <string>
#include <memory>

#include "GfxPalette.hpp"

namespace gfx
{

const char GfxPalette::ClassName[] = "GfxPalette";

GfxPalette::GfxPalette() : GfxRootClass(ClassName)
{
    pal_ = sdl2::SDL_AllocPalette(kDefaultPaletteSize);
    for (uint32_t i = 0; i < kDefaultPaletteSize; i++)
    {
        SDL_SetPaletteColors(pal_, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                            kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
};

GfxPalette::GfxPalette(const GfxColorVector& colors) : GfxRootClass(ClassName)
{
    uint32_t colorIndex;
    uint16_t nColors;

    nColors = colors.size();
    pal_ = sdl2::SDL_AllocPalette(nColors);
    colorIndex = 0;
    for (GfxColor clr : colors)
    {
        assert(clr);

        SDL_SetPaletteColors(pal_, clr.getAsSdlTypePtr(), colorIndex, 1);
        colorIndex += 1;
    }
}

GfxPalette::GfxPalette(const uint16_t nColors) : GfxRootClass(ClassName)
{
    assert(nColors > 0);

    pal_ = sdl2::SDL_AllocPalette(nColors);

    for (uint32_t i = 0; i < nColors; i++)
    {
        SDL_SetPaletteColors(pal_, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                            kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
}

GfxPalette::GfxPalette(GfxPalette&& other) : GfxRootClass(ClassName)
{
    pal_ = other.pal_;
    // Delete other's data
    other.pal_ = nullptr;
}

GfxPalette::GfxPalette(const SdlTypePtr pal)
{
    assert(pal != nullptr);

    pal_ = sdl2::SDL_AllocPalette(pal->ncolors);
    SDL_SetPaletteColors(pal_, pal->colors, 0 , pal->ncolors);
}

GfxPalette::~GfxPalette()
{
    if (pal_ != nullptr)
    {
        SDL_FreePalette(pal_);
    }
}

GfxPalette& GfxPalette::operator=(GfxPalette&& other)
{
    if (this != &other)
    {
        if (pal_ != nullptr)
        {
            sdl2::SDL_FreePalette(pal_);
        }
        pal_ = other.pal_;
        // Delete other's data
        other.pal_ = nullptr;
    }
    return *this;
}

GfxPalette::operator bool() const
{
    return (pal_ != nullptr);
}

void GfxPalette::setPaletteColors(const GfxColorVector& colors, const uint16_t firstColor)
{
    int32_t errorCode = 0;
    int32_t currentColorIndex = firstColor;

    if (pal_ == nullptr)
    {
        return;
    }
    for (GfxColor clr : colors)
    {
        assert(clr);

        errorCode = sdl2::SDL_SetPaletteColors(pal_, clr.getAsSdlTypePtr(), currentColorIndex, 1);
        currentColorIndex += 1;
        if (errorCode != 0)
        {
            break;
        }
    }
}

GfxPalette::GfxColorVector GfxPalette::getPaletteColors(void) const
{
    if (pal_ != nullptr)
    {
        GfxColorVector clrs(pal_->ncolors);

        for (int32_t i = 0; i < pal_->ncolors; i++)
        {
            GfxColor c(pal_->colors[i]);
            clrs.push_back(c);
        }
        return clrs;
    }
    return GfxColorVector();
}

uint16_t GfxPalette::getNumColors(void) const
{
    if (pal_ != nullptr)
    {
        return pal_->ncolors;
    }
    return 0;
}

uint32_t GfxPalette::getVersion(void) const
{
    if (pal_ != nullptr)
    {
        return pal_->version;
    }
    return 0;
}

int GfxPalette::getRefCount(void) const
{
    if (pal_ != nullptr)
    {
        return pal_->refcount;
    }
    return 0;
}

void GfxPalette::clear(void)
{
    if (pal_ != nullptr)
    {
        sdl2::SDL_FreePalette(pal_);
        pal_ = nullptr;
    }
}

GfxPalette::SdlTypePtr GfxPalette::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)pal_;
}

}  // namespace gfx

/* EOF */
