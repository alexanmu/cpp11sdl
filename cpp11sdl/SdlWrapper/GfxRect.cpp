//
//  GfxRect.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxRect.hpp"

int GfxRect::getX(void) const
{
    return rect_.x;
}

int GfxRect::getY(void) const
{
    return rect_.y;
}

int GfxRect::getWidth(void) const
{
    return rect_.w;
}

int GfxRect::getHeight(void) const
{
    return rect_.h;
}

void GfxRect::setX(const int x)
{
    rect_.x = x;
}

void GfxRect::setY(const int y)
{
    rect_.y = y;
}

void GfxRect::setWidth(const int w)
{
    rect_.w = w;
}

void GfxRect::setHeight(const int h)
{
    rect_.h = h;
}

GfxRect::SdlType GfxRect::getAsSdlType() const
{
    return rect_;
}

GfxRect::SdlTypePtr GfxRect::getAsSdlTypePtr() const
{
    return (SdlTypePtr)&rect_;
}
