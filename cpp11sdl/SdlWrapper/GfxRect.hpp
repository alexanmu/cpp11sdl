//
//  GfxRect.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxRect_hpp
#define GfxRect_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxRect final : public GfxRootClass
{
public:
    typedef SDL_Rect SdlType;
    typedef SDL_Rect* SdlTypePtr;
    
    GfxRect();
    GfxRect(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h);
    GfxRect(SdlType rect);
    GfxRect(SdlTypePtr rect);
    GfxRect(const GfxRect& other);
    GfxRect(GfxRect&& other);

    GfxRect& operator=(const GfxRect& other);
    GfxRect& operator=(GfxRect&& other);

    uint16_t getX(void) const;
    uint16_t getY(void) const;
    uint16_t getWidth(void) const;
    uint16_t getHeight(void) const;
    
    void setX(const uint16_t x);
    void setY(const uint16_t y);
    void setWidth(const uint16_t w);
    void setHeight(const uint16_t h);
    
    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr() const;
private:
    SDL_Rect rect_;
};

#endif /* GfxRect_hpp */
