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

#include "GfxFlip.hpp"

GfxFlip::GfxFlip() : GfxRootClass("GfxFlip")
{
    flip_ = static_cast<int>(GfxFlipValues::flipNone);
}

GfxFlip::GfxFlip(const bool fliph,const bool flipv) : GfxRootClass("GfxFlip")
{
    flip_ = static_cast<int>(GfxFlipValues::flipNone);
    if (fliph == true)
    {
        flip_ |= static_cast<int>(GfxFlipValues::flipHorizontal);
    }
    if (flipv == true)
    {
        flip_ |= static_cast<int>(GfxFlipValues::flipVertical);
    }
}

GfxFlip::GfxFlip(const GfxFlip& other)
{
    flip_ = other.flip_;
}

GfxFlip::GfxFlip(GfxFlip&& other)
{
    flip_ = other.flip_;
    other.flip_ = static_cast<int>(GfxFlipValues::flipNone);
}

GfxFlip& GfxFlip::operator=(const GfxFlip& other)
{
    if (this != &other)
    {
        flip_ = other.flip_;
    }
    return *this;
}

GfxFlip& GfxFlip::operator=(GfxFlip&& other)
{
    if (this != &other)
    {
        flip_ = other.flip_;
        other.flip_ = static_cast<int>(GfxFlipValues::flipNone);
    }
    return *this;
}

bool GfxFlip::operator==(const GfxFlip& other)
{
    return (flip_ == other.flip_);
}

GfxFlip::SdlType GfxFlip::getAsSdlType(void) const
{
    return (SdlType)flip_;
}

GfxFlip::SdlTypePtr GfxFlip::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flip_;
}
