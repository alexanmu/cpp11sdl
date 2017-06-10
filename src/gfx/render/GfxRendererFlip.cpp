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

#include <string>

#include "GfxRendererFlip.hpp"

namespace gfx
{

namespace render
{

const char GfxRendererFlip::ClassName[] = "GfxRendererFlip";

GfxRendererFlip::GfxRendererFlip() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxRendererFlip::GfxRendererFlip(const bool fliph, const bool flipv) noexcept : GfxObject(ClassName)
{
    flip_ = static_cast<SdlType>(ValueType::flipNone);
    if (fliph == true)
    {
        flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_HORIZONTAL);
    }
    if (flipv == true)
    {
        flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_VERTICAL);
    }
}

GfxRendererFlip::GfxRendererFlip(GfxRendererFlip const& other) noexcept : GfxObject(ClassName)
{
    flip_ = other.flip_;
}

GfxRendererFlip::GfxRendererFlip(GfxRendererFlip&& other) noexcept : GfxObject(ClassName)
{
    flip_ = other.flip_;
    other.clear();
}

GfxRendererFlip& GfxRendererFlip::operator=(GfxRendererFlip const& other) noexcept
{
    if (this != &other)
    {
        flip_ = other.flip_;
    }
    return *this;
}

GfxRendererFlip& GfxRendererFlip::operator=(GfxRendererFlip&& other) noexcept
{
    if (this != &other)
    {
        flip_ = other.flip_;
        other.clear();
    }
    return *this;
}

GfxRendererFlip::operator bool() const noexcept
{
    return true;
}

bool GfxRendererFlip::operator==(GfxRendererFlip const& other) noexcept
{
    return (flip_ == other.flip_);
}

bool GfxRendererFlip::isFlipHorizontal(void) const noexcept
{
    return ((flip_ & sdl2::SDL_FLIP_HORIZONTAL) != 0);
}

bool GfxRendererFlip::isFlipVertical(void) const noexcept
{
    return ((flip_ & sdl2::SDL_FLIP_VERTICAL) != 0);
}

void GfxRendererFlip::setFlipHorizontal(void) noexcept
{
    flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_HORIZONTAL);
}

void GfxRendererFlip::setFlipVertical(void) noexcept
{
    flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_VERTICAL);
}

void GfxRendererFlip::resetFlipHorizontal(void) noexcept
{
    flip_ = static_cast<SdlType>(flip_ & ~sdl2::SDL_FLIP_HORIZONTAL);
}

void GfxRendererFlip::resetFlipVertical(void) noexcept
{
    flip_ = static_cast<SdlType>(flip_ & ~sdl2::SDL_FLIP_VERTICAL);
}

void GfxRendererFlip::clear(void) noexcept
{
    flip_ = static_cast<SdlType>(ValueType::flipNone);
}

GfxRendererFlip::SdlType GfxRendererFlip::getAsSdlType(void) const noexcept
{
    return (SdlType)flip_;
}

GfxRendererFlip::SdlTypePtr GfxRendererFlip::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&flip_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
