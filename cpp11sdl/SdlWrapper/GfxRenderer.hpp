//
//  GfxRenderer.hpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxRenderer_hpp
#define GfxRenderer_hpp

#include "GfxSdlHeader.hpp"

#include "GfxWindow.hpp"
#include "GfxRect.hpp"
#include "GfxPoint.hpp"
#include "GfxFlip.hpp"
#include "GfxTexture.hpp"

class GfxRenderer final
{
public:
    typedef SDL_Renderer GfxRendererSdlType;
    
    GfxRenderer(const GfxWindow& win);
    
    GfxRenderer() = delete;
    GfxRenderer(const GfxRenderer&) = delete;
    GfxRenderer& operator=(const GfxRenderer&) = delete;
    
    GfxRenderer(GfxRenderer&& rend);
    GfxRenderer& operator=(GfxRenderer&& rend);
    
    ~GfxRenderer();
    
    void destroyRenderer(void);
    void renderClear(void);

    void renderCopy(const GfxTexture& tex,GfxRect* const src,GfxRect* const dest);
    void renderCopy(const GfxTexture& tex);
    
    void renderCopyEx(const GfxTexture& tex,GfxRect* const src, GfxRect* const dest,const double angle,const GfxPoint& pt,const GfxFlip& flip);
    void renderCopyEx(const GfxTexture& text,const double angle,const GfxPoint& pt,const GfxFlip& flip);

    void renderPresent(void);

    GfxRendererSdlType* getAsGfxRendererSdlTypePtr() const;
private:
    SDL_Renderer* renderer_;
    GfxWindow const* window_;
};

#endif /* GfxRenderer_hpp */
