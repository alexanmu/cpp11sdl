//
//  GfxPoint.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxPoint.hpp"

int GfxPoint::getX(void) const
{
    return pt_.x;
}

int GfxPoint::getY(void) const
{
    return pt_.y;
}

void GfxPoint::setX(const int x)
{
    pt_.x = x;
}

void GfxPoint::setY(const int y)
{
    pt_.y = y;
}

GfxPoint::SdlType GfxPoint::getAsSdlType(void) const
{
    return pt_;
}

GfxPoint::SdlTypePtr GfxPoint::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&pt_;
}
