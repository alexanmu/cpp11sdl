//
//  SdlPoint.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef SdlPoint_hpp
#define SdlPoint_hpp

#include "SDL2/SDL.h"

class SdlPoint final
{
public:
    typedef SDL_Point SdlPointSdlType;
    
    /* Delete default constructor */
    SdlPoint() = delete;
    SdlPoint(int x,int y)
    {
        pt_.x = x;
        pt_.y = y;
    }
    SdlPoint(SdlPointSdlType pt)
    {
        pt_ = pt;
    }
    
    /* No copy/move constructors */
    SdlPoint(const SdlPoint&) = delete;
    SdlPoint(SdlPoint&&) = delete;
    
    /* No assignement operators */
    SdlPoint& operator=(const SdlPoint&) = delete;
    SdlPoint& operator=(SdlPoint&&) = delete;
    
    /* Getters */
    int getX(void) const;
    int getY(void) const;
    
    /* Setters */
    void setX(const int x);
    void setY(const int y);
    
    SdlPointSdlType getAsGfxPointSdlType(void) const;
    SdlPointSdlType* getAsGfxPointSdlTypePtr(void) const;
private:
    SDL_Point pt_;
};


#endif /* SdlPoint_hpp */
