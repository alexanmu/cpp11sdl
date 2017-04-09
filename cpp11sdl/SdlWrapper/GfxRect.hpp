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
    GfxRect(const int x, const int y, const int w, const int h);
    GfxRect(SdlType rect);
    GfxRect(const GfxRect& other);
    GfxRect(GfxRect&& other);

    GfxRect& operator=(const GfxRect& other);
    GfxRect& operator=(GfxRect&& other);

    int getX(void) const;
    int getY(void) const;
    int getWidth(void) const;
    int getHeight(void) const;
    
    void setX(const int x);
    void setY(const int y);
    void setWidth(const int w);
    void setHeight(const int h);
    
    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr() const;
private:
    SDL_Rect rect_;
};

#endif /* GfxRect_hpp */
