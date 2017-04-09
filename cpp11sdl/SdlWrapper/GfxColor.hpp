//
//  GfxColor.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#ifndef GfxColor_hpp
#define GfxColor_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxColor final : public GfxRootClass
{
public:
    typedef SDL_Color SdlType;
    typedef SDL_Color* SdlTypePtr;
    
    GfxColor();
    GfxColor(uint8_t r, uint8_t g, uint8_t b);
    GfxColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    GfxColor(SdlType clr);
    GfxColor(const GfxColor& other);
    GfxColor(GfxColor&& other);
    GfxColor& operator=(const GfxColor& other);
    GfxColor& operator=(GfxColor&& other);
    
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
