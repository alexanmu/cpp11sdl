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
    GfxColor(const uint8_t r,const uint8_t g,const uint8_t b);
    GfxColor(const uint8_t r,const uint8_t g,const uint8_t b,const uint8_t a);
    GfxColor(const SdlType clr);
    GfxColor(const GfxColor& other);
    GfxColor(GfxColor&& other);
    GfxColor& operator=(const GfxColor& other);
    GfxColor& operator=(GfxColor&& other);
    
    /* Getters ... */
    uint8_t getRed(void) const;
    uint8_t getGreen(void) const;
    uint8_t getBlue(void) const;
    uint8_t getAlpha(void) const;
    
    /* Setters ... */
    void setRed(const uint8_t r);
    void setGreen(const uint8_t g);
    void setBlue(const uint8_t b);
    void setAlpha(const uint8_t a);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType clr_;
};

#endif /* GfxColor_hpp */
