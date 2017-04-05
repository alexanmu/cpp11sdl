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

class GfxPixelFormat final
{
public:
    typedef SDL_PixelFormat GfxPixelFormatSdlType;

    GfxPixelFormat() = delete;
    GfxPixelFormat(GfxPixelFormatSdlType pix);

    uint32_t getFormat(void) const { return pix_.format; }
    uint8_t getBitsPerPixel(void) const { return pix_.BitsPerPixel; }
    SDL_Palette* getPalette(void) { return pix_.palette; }
    uint8_t getBytesPerPixel(void) const { return pix_.BytesPerPixel; }
    uint32_t getRedMask(void) const { return pix_.Rmask; }
    uint32_t getGreenMask(void) const { return pix_.Gmask; }
    uint32_t getBlueMask(void) const { return pix_.Bmask; }
    uint32_t getAlphaMask(void) const { return pix_.Amask; }
    /* for internal use by SDL */
    uint8_t getRloss(void) const { return pix_.Rloss; }
    uint8_t getGloss(void) const { return pix_.Gloss; }
    uint8_t getBloss(void) const { return pix_.Bloss; }
    uint8_t getAloss(void) const { return pix_.Aloss; }
    uint8_t getRshift(void) const { return pix_.Rshift; }
    uint8_t getGshift(void) const { return pix_.Gshift; }
    uint8_t getBshift(void) const { return pix_.Bshift; }
    int getRefCount(void) const { return pix_.refcount; }
    GfxPixelFormatSdlType* getNext(void) const { return pix_.next; }
    
    GfxPixelFormatSdlType getAsGfxPixelFormatSdlType(void);
    GfxPixelFormatSdlType* getAsGfxPixelFormatSdlTypePtr(void);
private:
    GfxPixelFormatSdlType pix_;
};

#endif /* GfxPixelFormat_hpp */
