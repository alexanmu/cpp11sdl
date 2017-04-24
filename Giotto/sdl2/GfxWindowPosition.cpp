//
//  GfxWindowPosition.cpp
//  Giotto
//
//  Created by George Oros on 4/24/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxWindowPosition.hpp"

GfxWindowPosition::GfxWindowPosition() : GfxRootClass("GfxWindowPosition")
{
    pos_ = GfxWindowPositionValues::positionUndefined;
    coord_ = -1;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPositionValues pos,uint32_t coord) : GfxRootClass("GfxWindowPosition")
{
    pos_ = pos;
    coord_ = coord;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition const& other) : GfxRootClass("GfxWindowPosition")
{
    pos_ = other.pos_;
    coord_ = other.coord_;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition&& other) : GfxRootClass("GfxWindowPosition")
{
    pos_ = other.pos_;
    coord_ = other.coord_;
    // Delete other's data
    other.pos_ = GfxWindowPositionValues::positionUndefined;
    other.coord_ = -1;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition const& other)
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
    }
    return *this;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition&& other)
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
        // Delete other's data
        other.pos_ = GfxWindowPositionValues::positionUndefined;
        other.coord_ = -1;
    }
    return *this;
}

void GfxWindowPosition::setPosition(GfxWindowPositionValues pos)
{
    pos_ = pos;
}

GfxWindowPosition::GfxWindowPositionValues GfxWindowPosition::getPosition(void) const
{
    return pos_;
}

void GfxWindowPosition::setCoordinate(uint32_t coord)
{
    coord_ = coord;
}

uint32_t GfxWindowPosition::getCoordinate(void) const
{
    uint32_t ret;
    
    switch (pos_)
    {
        case GfxWindowPositionValues::positionUndefined:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
        case GfxWindowPositionValues::positionCentered:
            ret = SDL_WINDOWPOS_CENTERED;
            break;
        case GfxWindowPositionValues::positionSpecified:
            ret = coord_;
            break;
        default:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
    }
    return ret;
}
