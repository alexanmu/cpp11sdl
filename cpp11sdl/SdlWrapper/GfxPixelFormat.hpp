//
//  GfxPixelFormat.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxPixelFormat_hpp
#define GfxPixelFormat_hpp

#include "GfxSdlHeader.hpp"
#include "GfxPalette.hpp"

class GfxPixelFormat final
{
public:
    typedef SDL_PixelFormat SdlType;
    typedef SDL_PixelFormat* SdlTypePtr;

    GfxPixelFormat();
    GfxPixelFormat(SdlTypePtr pix);

    GfxPixelFormat(const GfxPixelFormat& other)
    {
        pix_ = other.pix_;
        pal_ = other.pal_;
    }
    GfxPixelFormat(GfxPixelFormat&& other)
    {
        pix_ = other.pix_;
        pal_ = other.pal_;
    }

    GfxPixelFormat& operator=(const GfxPixelFormat& other)
    {
        if (this != &other)
        {
            pix_ = other.pix_;
            pal_ = other.pal_;
        }
        return *this;
    }

    GfxPixelFormat& operator=(GfxPixelFormat&& other)
    {
        if (this != &other)
        {
            pix_ = other.pix_;
            pal_ = other.pal_;
        }
        return *this;
    }

    uint32_t getFormat(void) const { return pix_->format; }
    uint8_t getBitsPerPixel(void) const { return pix_->BitsPerPixel; }
    GfxPalette* getPalette(void) { return new GfxPalette(pal_); }
    uint8_t getBytesPerPixel(void) const { return pix_->BytesPerPixel; }
    uint32_t getRedMask(void) const { return pix_->Rmask; }
    uint32_t getGreenMask(void) const { return pix_->Gmask; }
    uint32_t getBlueMask(void) const { return pix_->Bmask; }
    uint32_t getAlphaMask(void) const { return pix_->Amask; }

    void setFormat(const uint32_t format);
    void setBitsPerPixel(const uint8_t bpp);
    void setPalette(const GfxPalette& pal);
    void setBytesPerPixel(const uint8_t bypp);
    void setRedMask(const uint32_t rmask);
    void setGreenMask(const uint32_t gmask);
    void setBlueMask(const uint32_t bmask);
    void setAlphaMask(const uint32_t amask);

    /* for internal use by SDL */
    uint8_t getRloss(void) const { return pix_->Rloss; }
    uint8_t getGloss(void) const { return pix_->Gloss; }
    uint8_t getBloss(void) const { return pix_->Bloss; }
    uint8_t getAloss(void) const { return pix_->Aloss; }
    uint8_t getRshift(void) const { return pix_->Rshift; }
    uint8_t getGshift(void) const { return pix_->Gshift; }
    uint8_t getBshift(void) const { return pix_->Bshift; }
    int getRefCount(void) const { return pix_->refcount; }
    SdlTypePtr getNext(void) const { return pix_->next; }
    
    SdlType getAsSdlType(void);
    SdlTypePtr getAsSdlTypePtr(void);
private:
    SdlTypePtr pix_;
    GfxPalette pal_;
};

#endif /* GfxPixelFormat_hpp */
