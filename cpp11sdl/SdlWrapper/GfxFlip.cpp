//
//  GfxFlip.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxFlip.hpp"

GfxFlip::GfxFlip() : GfxRootClass("GfxFlip")
{
    flip_ = static_cast<int>(GfxFlipValues::flipNone);
}

GfxFlip::GfxFlip(const bool fliph,const bool flipv) : GfxRootClass("GfxFlip")
{
    flip_ = static_cast<int>(GfxFlipValues::flipNone);
    if (fliph)
        flip_ |= static_cast<int>(GfxFlipValues::flipHorizontal);
    if (flipv)
        flip_ |= static_cast<int>(GfxFlipValues::flipVertical);
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

GfxFlip::SdlType GfxFlip::getAsSdlType(void) const
{
    return (SdlType)flip_;
}

GfxFlip::SdlTypePtr GfxFlip::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flip_;
}
