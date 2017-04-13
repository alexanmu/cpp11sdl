//
//  GfxPixelFormat.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxPixelFormat_hpp
#define GfxPixelFormat_hpp

#include <memory>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxPalette.hpp"

class GfxPixelFormat final : public GfxRootClass
{
public:
    typedef SDL_PixelFormat SdlType;
    typedef SDL_PixelFormat* SdlTypePtr;

    GfxPixelFormat();
    GfxPixelFormat(SdlTypePtr pix);

    GfxPixelFormat(const GfxPixelFormat& other);
    GfxPixelFormat(GfxPixelFormat&& other);
    GfxPixelFormat& operator=(const GfxPixelFormat& other);
    GfxPixelFormat& operator=(GfxPixelFormat&& other);

    uint32_t getFormat(void) const;
    uint8_t getBitsPerPixel(void) const;
    std::unique_ptr<GfxPalette> getPalette(void);
    uint8_t getBytesPerPixel(void) const;
    uint32_t getRedMask(void) const;
    uint32_t getGreenMask(void) const;
    uint32_t getBlueMask(void) const;
    uint32_t getAlphaMask(void) const;

    void setFormat(const uint32_t format);
    void setBitsPerPixel(const uint8_t bpp);
    void setPalette(const GfxPalette& pal);
    void setBytesPerPixel(const uint8_t bypp);
    void setRedMask(const uint32_t rmask);
    void setGreenMask(const uint32_t gmask);
    void setBlueMask(const uint32_t bmask);
    void setAlphaMask(const uint32_t amask);

    /* for internal use by SDL */
    uint8_t getRloss(void) const;
    uint8_t getGloss(void) const;
    uint8_t getBloss(void) const;
    uint8_t getAloss(void) const;
    uint8_t getRshift(void) const;
    uint8_t getGshift(void) const;
    uint8_t getBshift(void) const;
    int getRefCount(void) const;
    SdlTypePtr getNext(void) const;
    
    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlTypePtr pix_;
    GfxPalette pal_;
};

#endif /* GfxPixelFormat_hpp */
