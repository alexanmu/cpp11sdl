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
    typedef SDL_Surface GfxSurfaceSdlType;

    GfxSurface() = delete;
    GfxSurface(int w,int h,int d,int rmask,int gmask,int bmask,int amask);
    GfxSurface(GfxSurfaceSdlType** surf);

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

    GfxPixelFormat getFormat(void);

    void destroySurface(void);

    GfxSurfaceSdlType* getAsGfxSurfaceSdlTypePtr(void) const;
private:
    SDL_Surface* surf_;
    int w_;
    int h_;
    int d_;
    int rmask_;
    int gmask_;
    int bmask_;
    int amask_;
};

#endif /* GfxSurface_hpp */
