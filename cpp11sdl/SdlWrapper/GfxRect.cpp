//
//  GfxRect.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxRect.hpp"

GfxRect::GfxRect() : GfxRootClass("GfxRect")
{
    rect_.x = -1;
    rect_.y = -1;
    rect_.w = -1;
    rect_.h = -1;
}

GfxRect::GfxRect(const int x, const int y, const int w, const int h) : GfxRootClass("GfxRect")
{
    rect_.x = x;
    rect_.y = y;
    rect_.w = w;
    rect_.h = h;
}

GfxRect::GfxRect(SdlType rect) : GfxRootClass("GfxRect")
{
    rect_ = rect;
}

GfxRect::GfxRect(const GfxRect& other) : GfxRootClass("GfxRect")
{
    rect_ = other.rect_;
}

GfxRect::GfxRect(GfxRect&& other) : GfxRootClass("GfxRect")
{
    rect_ = other.rect_;
    other.rect_.x = -1;
    other.rect_.y = -1;
    other.rect_.w = -1;
    other.rect_.h = -1;
}

GfxRect& GfxRect::operator=(const GfxRect& other)
{
    if (this != &other)
    {
        rect_ = other.rect_;
    }
    return *this;
}

GfxRect& GfxRect::operator=(GfxRect&& other)
{
    if (this != &other)
    {
        rect_ = other.rect_;
        other.rect_.x = -1;
        other.rect_.y = -1;
        other.rect_.w = -1;
        other.rect_.h = -1;
    }
    return *this;
}

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
