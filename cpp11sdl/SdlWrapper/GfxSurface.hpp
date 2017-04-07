//
//  GfxSurface.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxSurface_hpp
#define GfxSurface_hpp

#include "GfxSdlHeader.hpp"
#include "GfxPixelFormat.hpp"

class GfxSurface final
{
public:
    typedef SDL_Surface SdlType;
    typedef SDL_Surface* SdlTypePtr;

    GfxSurface() = delete;
    GfxSurface(int w,int h,int rmask,int gmask,int bmask,int amask);
    GfxSurface(SdlTypePtr surf);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& surf);
    
    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& surf);
    
    ~GfxSurface();

    int getWidth(void) const;
    int getHeight(void) const;
    int getDepth(void) const;

    int getRedMask(void) const;
    int getGreenMask(void) const;
    int getBlueMask(void) const;
    int getAlphaMask(void) const;

    GfxPixelFormat* getFormat(void);

    void destroySurface(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlTypePtr surf_;
};

#endif /* GfxSurface_hpp */
