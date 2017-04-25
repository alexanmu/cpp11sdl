/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/

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
    explicit GfxPixelFormat(SdlTypePtr pix);

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
