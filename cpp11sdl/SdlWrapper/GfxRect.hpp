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
    typedef SDL_Rect SdlType;
    typedef SDL_Rect* SdlTypePtr;
    
    GfxRect()
    {
        rect_.x = -1;
        rect_.y = -1;
        rect_.w = -1;
        rect_.h = -1;
    }
    GfxRect(const int x, const int y, const int w, const int h)
    {
        rect_.x = x;
        rect_.y = y;
        rect_.w = w;
        rect_.h = h;
    }
    GfxRect(SdlType rect)
    {
        rect_ = rect;
    }

    GfxRect(const GfxRect& other)
    {
        rect_ = other.rect_;
    }

    GfxRect(GfxRect&& other)
    {
        rect_ = other.rect_;
        other.rect_.x = -1;
        other.rect_.y = -1;
        other.rect_.w = -1;
        other.rect_.h = -1;
    }

    GfxRect& operator=(const GfxRect& other)
    {
        if (this != &other)
        {
            rect_ = other.rect_;
        }
        return *this;
    }

    GfxRect& operator=(GfxRect&& other)
    {
        if (this != &other)
        {
            rect_ = other.rect_;
            other.rect_.x = -1;
            other.rect_.y = -1;
            other.rect_.w = -1;
            other.rect_.h = -1;
        }
        return *this;
    }

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
