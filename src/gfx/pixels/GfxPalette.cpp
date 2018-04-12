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

GfxPalette::GfxPalette() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    pal_ = nullptr;
};

GfxPalette::GfxPalette(const uint16_t nColors) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(nColors > 0);

    SdlTypePtr palptr;

    palptr = SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create palette (" + sdlErr + ")");
    }
    for (uint32_t i = 0; i < nColors; i++)
    {
        SDL_SetPaletteColors(palptr, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                              kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
    pal_ = palptr;
}

GfxPalette::GfxPalette(const SdlTypePtr pal) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(pal != nullptr);

    pal_ = pal;
}

GfxPalette::GfxPalette(std::vector<GfxColor> const& colors) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(colors.size() > 0);

    uint32_t colorIndex;
    uint16_t nColors;
    SdlTypePtr palptr;

    nColors = colors.size();
    palptr = SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create palette (" + sdlErr + ")");
    }
    colorIndex = 0;
    for (GfxColor clr : colors)
    {
        assert(clr);

        SDL_SetPaletteColors(palptr, clr.getAsSdlTypePtr(), colorIndex, 1);
        colorIndex += 1;
    }
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
            SDL_FreePalette(pal_);
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
        SDL_FreePalette(pal_);
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

void GfxPalette::createPalette(const uint16_t nColors) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(nColors > 0);

    SdlTypePtr palptr;

    if (pal_ != nullptr)
    {
        throw std::runtime_error("Palette already created");
    }
    palptr = SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create palette (" + sdlErr + ")");
    }
    for (uint32_t i = 0; i < nColors; i++)
    {
        SDL_SetPaletteColors(palptr, GfxColor(kDefaultPaletteColorRed, kDefaultPaletteColorGreen, \
                                                    kDefaultPaletteColorBlue).getAsSdlTypePtr(), i, 1);
    }
    pal_ = palptr;
}

void GfxPalette::createPalette(const SdlTypePtr pal) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(pal != nullptr);

    if (pal_ != nullptr)
    {
        throw std::runtime_error("Palette already created");
    }
    pal_ = pal;
}

void GfxPalette::createPalette(std::vector<GfxColor> const& colors) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(colors.size() > 0);

    uint32_t colorIndex;
    uint16_t nColors;
    SdlTypePtr palptr;

    if (pal_ != nullptr)
    {
        throw std::runtime_error("Palette already created");
    }
    nColors = colors.size();
    palptr = SDL_AllocPalette(nColors);
    if (palptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create palette (" + sdlErr + ")");
    }
    colorIndex = 0;
    for (GfxColor clr : colors)
    {
        assert(clr);

        SDL_SetPaletteColors(palptr, clr.getAsSdlTypePtr(), colorIndex, 1);
        colorIndex += 1;
    }
    pal_ = palptr;
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

        errorCode = SDL_SetPaletteColors(pal_, clr.getAsSdlTypePtr(), currentColorIndex, 1);
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

void GfxPalette::setPaletteColor(GfxColor const& clr, const uint16_t index) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(clr);

    int32_t ret = 1;

    if (pal_ != nullptr)
    {
        if (index < pal_->ncolors)
        {
            ret = SDL_SetPaletteColors(pal_, clr.getAsSdlTypePtr(), index, 1);
            assert(ret == 0);
        }
    }
}

GfxColor GfxPalette::getPaletteColor(const uint16_t index) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (pal_ != nullptr)
    {
        if (index < pal_->ncolors)
        {
            return GfxColor(pal_->colors[index]);
        }
    }
    return GfxColor();
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
