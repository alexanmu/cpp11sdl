//
//  SdlPoint.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "SdlPoint.hpp"

int SdlPoint::getX(void) const
{
    return pt_.x;
}

int SdlPoint::getY(void) const
{
    return pt_.y;
}

void SdlPoint::setX(const int x)
{
    pt_.x = x;
}

void SdlPoint::setY(const int y)
{
    pt_.y = y;
}

SdlPoint::SdlPointSdlType SdlPoint::getAsGfxPointSdlType(void) const
{
    return pt_;
}

SdlPoint::SdlPointSdlType* SdlPoint::getAsGfxPointSdlTypePtr(void) const
{
    return (SdlPointSdlType*)&pt_;
}
