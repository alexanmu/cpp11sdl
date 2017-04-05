//
//  SdlColor.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef SdlColor_hpp
#define SdlColor_hpp

#include "SDL2/SDL.h"

class SdlColor final
{
public:
    typedef SDL_Color SdlColorSdlType;
    
    /* Default constructor not allowed */
    SdlColor() = delete;
    SdlColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        clr_.r = r;
        clr_.g = g;
        clr_.b = b;
        clr_.a = a;
    }
    SdlColor(SdlColorSdlType clr);
    
    /* Delete copy and move constructors */
    SdlColor(const SdlColor&) = delete;
    SdlColor(SdlColor&&) = delete;
    
    /* Delete copy and move assign operators */
    SdlColor& operator=(const SdlColor&) = delete;
    SdlColor& operator=(SdlColor&&) = delete;
    
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
    
    SdlColorSdlType getAsGfxColorSdlType(void) const;
    SdlColorSdlType* getAsGfxColorSdlTypePtr(void);
private:
    SdlColorSdlType clr_;
};

#endif /* SdlColor_hpp */
