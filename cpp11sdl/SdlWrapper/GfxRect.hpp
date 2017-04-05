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

class GfxRect final
{
public:
    typedef SDL_Rect GfxRectSdlType;
    
    GfxRect() = delete;
    GfxRect(const int x, const int y, const int w, const int h)
    {
        rect_.x = x;
        rect_.y = y;
        rect_.w = w;
        rect_.h = h;
    }
    GfxRect(GfxRectSdlType rect)
    {
        rect_ = rect;
    }

    int getX(void) const;
    int getY(void) const;
    int getWidth(void) const;
    int getHeight(void) const;
    
    void setX(const int x);
    void setY(const int y);
    void setWidth(const int w);
    void setHeight(const int h);
    
    GfxRectSdlType getAsGfxRectSdlType() const;
    GfxRectSdlType* getAsGfxRectSdlTypePtr();
private:
    SDL_Rect rect_;
};

#endif /* GfxRect_hpp */
