//
//  GfxPoint.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#ifndef GfxPoint_hpp
#define GfxPoint_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxPoint final : public GfxRootClass
{
public:
    typedef SDL_Point SdlType;
    typedef SDL_Point* SdlTypePtr;
    
    GfxPoint() : GfxRootClass("GfxPoint")
    {
        pt_.x = -1;
        pt_.y = -1;
    }

    GfxPoint(int x,int y) : GfxRootClass("GfxPoint")
    {
        pt_.x = x;
        pt_.y = y;
    }

    GfxPoint(SdlType pt) : GfxRootClass("GfxPoint")
    {
        pt_ = pt;
    }
    
    GfxPoint(const GfxPoint& other) : GfxRootClass("GfxPoint")
    {
        pt_ = other.pt_;
    }

    GfxPoint(GfxPoint&& other) : GfxRootClass("GfxPoint")
    {
        pt_ = other.pt_;
        /* Delete other's data */
        other.pt_.x = -1;
        other.pt_.y = -1;
    }
    
    /* No assignement operators */
    GfxPoint& operator=(const GfxPoint&) = delete;
    GfxPoint& operator=(GfxPoint&&) = delete;
    
    /* Getters */
    int getX(void) const;
    int getY(void) const;
    
    /* Setters */
    void setX(const int x);
    void setY(const int y);
    
    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType pt_;
};


#endif /* GfxPoint_hpp */
