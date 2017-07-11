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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>
#include <utility>

#include "GfxPalette.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpalette::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxPalette::ClassName[] = "GfxPalette";

GfxPalette::GfxPalette() throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    SdlTypePtr palptr;

    palptr = sdl2::SDL_AllocPalette(kDefaultPaletteSize);
    if (palptr == nullptr)
    {
        throw std::runtime_error("Unable to create palette");
    }
    pal_ = palptr;
    for (uint32_t i = 0; i < kDefaultPaletteSize; i++)
    {
        SDL_SetPaletteColors(pal_, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                            kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
};

GfxPalette::GfxPalette(std::vector<GfxColor> const& colors) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(colors.size() > 0);

    uint32_t colorIndex;
    uint16_t nColors;
    SdlTypePtr palptr;

    nColors = colors.size();
    palptr = sdl2::SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        throw std::runtime_error("Unable to create palette");
    }
    pal_ = palptr;
    colorIndex = 0;
    for (GfxColor clr : colors)
    {
        assert(clr);

        SDL_SetPaletteColors(pal_, clr.getAsSdlTypePtr(), colorIndex, 1);
        colorIndex += 1;
    }
}

GfxPalette::GfxPalette(const uint16_t nColors) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(nColors > 0);

    SdlTypePtr palptr;

    palptr = sdl2::SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        throw std::runtime_error("Unable to create palette");
    }
    pal_ = palptr;
    for (uint32_t i = 0; i < nColors; i++)
    {
        SDL_SetPaletteColors(pal_, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                            kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
}

GfxPalette::GfxPalette(const SdlTypePtr pal) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(pal != nullptr);
    assert(pal->colors != nullptr);
    assert(pal->ncolors > 0);

    SdlTypePtr palptr;

    palptr = sdl2::SDL_AllocPalette(pal->ncolors);
    if (palptr == nullptr)
    {
        throw std::runtime_error("Unable to create palette");
    }
    SDL_SetPaletteColors(palptr, pal->colors, 0 , pal->ncolors);
    pal_ = palptr;
}

GfxPalette::GfxPalette(GfxPalette&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_LOW();

    pal_ = other.pal_;
    // Delete other's data
    other.pal_ = nullptr;
}

GfxPalette& GfxPalette::operator=(GfxPalette&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
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

GfxPalette::~GfxPalette() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (pal_ != nullptr)
    {
        sdl2::SDL_FreePalette(pal_);
    }
    pal_ = nullptr;
}

GfxPalette::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (pal_ != nullptr);
}

std::string GfxPalette::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxPalette::freePalette(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (pal_ != nullptr)
    {
        SDL_FreePalette(pal_);
    }
}

void GfxPalette::setPaletteColors(std::vector<GfxColor> const& colors, const uint16_t firstColor) noexcept
{
    LOG_TRACE_PRIO_LOW();

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

std::vector<GfxColor> GfxPalette::getPaletteColors(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pal_ != nullptr)
    {
        std::vector<GfxColor> clrs(pal_->ncolors);

        for (int32_t i = 0; i < pal_->ncolors; i++)
        {
            GfxColor c(pal_->colors[i]);
            clrs.push_back(c);
        }
        return clrs;
    }
    return std::vector<GfxColor>();
}

uint16_t GfxPalette::getNumColors(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pal_ != nullptr)
    {
        return pal_->ncolors;
    }
    return 0;
}

uint32_t GfxPalette::getVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pal_ != nullptr)
    {
        return pal_->version;
    }
    return 0;
}

int32_t GfxPalette::getRefCount(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pal_ != nullptr)
    {
        return pal_->refcount;
    }
    return 0;
}

GfxPalette::SdlTypePtr GfxPalette::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)pal_;
}

// Private methods
void GfxPalette::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pal_ = nullptr;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
