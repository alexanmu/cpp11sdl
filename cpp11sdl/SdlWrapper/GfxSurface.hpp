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
#include "GfxColor.hpp"

class GfxCanvas;

class GfxSurface final : public GfxRootClass
{
public:
    typedef SDL_Surface SdlType;
    typedef SDL_Surface* SdlTypePtr;

    GfxSurface() = delete;
    GfxSurface(const uint16_t w,const uint16_t h);
    GfxSurface(const SdlTypePtr surf);

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
    
    void putPixel(const uint16_t x,const uint16_t y,const GfxColor& clr);
    std::unique_ptr<GfxColor> getPixel(const uint16_t x, const uint16_t y);

    void destroySurface(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    friend class GfxCanvas;
    
    void putPixelPrv(const uint16_t x,const uint16_t y,const GfxColor& clr);
    std::unique_ptr<GfxColor> getPixelPrv(const uint16_t x, const uint16_t y);
    SdlTypePtr surf_;
};

#endif /* GfxSurface_hpp */
