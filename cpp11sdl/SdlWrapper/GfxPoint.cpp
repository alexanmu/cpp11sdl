//
//  GfxPoint.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#include "GfxPoint.hpp"

GfxPoint::GfxPoint() : GfxRootClass("GfxPoint")
{
    pt_.x = -1;
    pt_.y = -1;
}

GfxPoint::GfxPoint(int x,int y) : GfxRootClass("GfxPoint")
{
    pt_.x = x;
    pt_.y = y;
}

GfxPoint::GfxPoint(SdlType pt) : GfxRootClass("GfxPoint")
{
    pt_ = pt;
}

GfxPoint::GfxPoint(SdlTypePtr pt) : GfxRootClass("GfxPoint")
{
    pt_ = *pt;
}

GfxPoint::GfxPoint(const GfxPoint& other) : GfxRootClass("GfxPoint")
{
    pt_ = other.pt_;
}

GfxPoint::GfxPoint(GfxPoint&& other) : GfxRootClass("GfxPoint")
{
    pt_ = other.pt_;
    /* Delete other's data */
    other.pt_.x = -1;
    other.pt_.y = -1;
}

/* No assignement operators */
GfxPoint& GfxPoint::operator=(const GfxPoint& other)
{
    if (this != &other)
    {
        pt_ = other.pt_;
    }
    return *this;
}

GfxPoint& GfxPoint::operator=(GfxPoint&& other)
{
    if (this != &other)
    {
        pt_ = other.pt_;
        // Delete other's data
        other.pt_.x = -1;
        other.pt_.y = -1;
    }
    return *this;
}

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
