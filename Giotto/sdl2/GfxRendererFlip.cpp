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

const std::string GfxRendererFlip::ClassName = "GfxRendererFlip";

GfxRendererFlip::GfxRendererFlip() : GfxRootClass(ClassName)
{
    flip_ = static_cast<SdlType>(GfxRendererFlipValues::flipNone);
}

GfxRendererFlip::GfxRendererFlip(const bool fliph, const bool flipv) : GfxRootClass(ClassName)
{
    flip_ = static_cast<SdlType>(GfxRendererFlipValues::flipNone);
    if (fliph == true)
    {
        flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_HORIZONTAL);
    }
    if (flipv == true)
    {
        flip_ = static_cast<SdlType>(flip_ | sdl2::SDL_FLIP_VERTICAL);
    }
}

GfxRendererFlip::GfxRendererFlip(const GfxRendererFlip& other) : GfxRootClass(ClassName)
{
    flip_ = other.flip_;
}

GfxRendererFlip::GfxRendererFlip(GfxRendererFlip&& other) : GfxRootClass(ClassName)
{
    flip_ = other.flip_;
    other.flip_ = static_cast<SdlType>(GfxRendererFlipValues::flipNone);
}

GfxRendererFlip& GfxRendererFlip::operator=(const GfxRendererFlip& other)
{
    if (this != &other)
    {
        flip_ = other.flip_;
    }
    return *this;
}

GfxRendererFlip& GfxRendererFlip::operator=(GfxRendererFlip&& other)
{
    if (this != &other)
    {
        flip_ = other.flip_;
        other.flip_ = static_cast<SdlType>(GfxRendererFlipValues::flipNone);
    }
    return *this;
}

bool GfxRendererFlip::operator==(const GfxRendererFlip& other)
{
    return (flip_ == other.flip_);
}

bool GfxRendererFlip::isFlipHorizontal(void) const
{
    return ((flip_ & sdl2::SDL_FLIP_HORIZONTAL) != 0);
}

bool GfxRendererFlip::isFlipVertical(void) const
{
    return ((flip_ & sdl2::SDL_FLIP_VERTICAL) != 0);
}

GfxRendererFlip::SdlType GfxRendererFlip::getAsSdlType(void) const
{
    return (SdlType)flip_;
}

GfxRendererFlip::SdlTypePtr GfxRendererFlip::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flip_;
}

}  // namespace gfx

/* EOF */
