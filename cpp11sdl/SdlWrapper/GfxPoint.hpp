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
    
    GfxPoint();
    GfxPoint(int x,int y);
    GfxPoint(SdlType pt);
    GfxPoint(const GfxPoint& other);
    GfxPoint(GfxPoint&& other);
    GfxPoint& operator=(const GfxPoint& other);
    GfxPoint& operator=(GfxPoint&& other);

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
