//
//  GfxColor.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxColor_hpp
#define GfxColor_hpp

#include "GfxSdlHeader.hpp"

class GfxColor final
{
public:
    typedef SDL_Color SdlType;
    typedef SDL_Color* SdlTypePtr;
    
    GfxColor()
    {
        clr_.r = 0;
        clr_.g = 0;
        clr_.b = 0;
        clr_.a = 0;
    }
    GfxColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        clr_.r = r;
        clr_.g = g;
        clr_.b = b;
        clr_.a = a;
    }
    GfxColor(SdlType clr);
    
    /* Copy constructor */
    GfxColor(const GfxColor& other)
    {
        clr_ = other.clr_;
    }

    /* Move constructor */
    GfxColor(GfxColor&& other)
    {
        clr_ = other.clr_;
        /* Delete other's data */
        other.clr_.r = 0;
        other.clr_.g = 0;
        other.clr_.b = 0;
        other.clr_.a = 0;
    }
    
    /* Delete copy and move assign operators */
    GfxColor& operator=(const GfxColor&) = delete;
    GfxColor& operator=(GfxColor&&) = delete;
    
    /* Getters ... */
    uint8_t getRed(void) const { return clr_.r; }
    uint8_t getGreen(void) const { return clr_.g; }
    uint8_t getBlue(void) const { return clr_.b; }
    uint8_t getAlpha(void) const { return clr_.a; }
    
    /* Setters ... */
    void setRed(uint8_t r) { clr_.r = r; }
    void setGreen(uint8_t g) { clr_.g = g; }
    void setBlue(uint8_t b) { clr_.b = b; }
    void setAlpha(uint8_t a) { clr_.a = a; }
    
    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType clr_;
};

#endif /* GfxColor_hpp */