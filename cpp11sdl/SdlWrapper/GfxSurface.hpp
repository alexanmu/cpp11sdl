//
//  GfxSurface.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxSurface_hpp
#define GfxSurface_hpp

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

#include "GfxPixelFormat.hpp"
#include "GfxRect.hpp"

class GfxSurface final : public GfxRootClass
{
public:
    typedef SDL_Surface SdlType;
    typedef SDL_Surface* SdlTypePtr;

    GfxSurface() = delete;
    GfxSurface(int w,int h);
    GfxSurface(SdlTypePtr surf);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& surf);
    
    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& surf);

    GfxSurface(const std::string& filename);
    GfxSurface(std::string&& filename);

    ~GfxSurface();

    int getWidth(void) const;
    int getHeight(void) const;
    int getDepth(void) const;

    std::unique_ptr<GfxPixelFormat> getFormat(void);

    void fillRect(const GfxRect& rect,const GfxColor& color);
    void fillRect(const GfxColor& color);

    void fillRects(const std::vector<GfxRect>& rects,const GfxColor& color);

    void blitSurface(const GfxSurface& src,const GfxRect& srcr,const GfxRect& dstr);
    void blitSurface(const GfxSurface& src);
    
    void destroySurface(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlTypePtr surf_;
};

#endif /* GfxSurface_hpp */
