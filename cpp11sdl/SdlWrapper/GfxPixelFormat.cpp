//
//  GfxPixelFormat.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxPixelFormat.hpp"

GfxPixelFormat::GfxPixelFormat() : GfxRootClass("GfxPixelFormat")
{
    pix_ = nullptr;
};

GfxPixelFormat::GfxPixelFormat(SdlTypePtr pix) : GfxRootClass("GfxPixelFormat")
{
    pix_ = pix;
}

GfxPixelFormat::GfxPixelFormat(const GfxPixelFormat& other) : GfxRootClass("GfxPixelFormat")
{
    pix_ = other.pix_;
    pal_ = other.pal_;
}

GfxPixelFormat::GfxPixelFormat(GfxPixelFormat&& other) : GfxRootClass("GfxPixelFormat")
{
    pix_ = other.pix_;
    pal_ = other.pal_;
}

GfxPixelFormat& GfxPixelFormat::operator=(const GfxPixelFormat& other)
{
    if (this != &other)
    {
        pix_ = other.pix_;
        pal_ = other.pal_;
    }
    return *this;
}

GfxPixelFormat& GfxPixelFormat::operator=(GfxPixelFormat&& other)
{
    if (this != &other)
    {
        pix_ = other.pix_;
        pal_ = other.pal_;
    }
    return *this;
}

void GfxPixelFormat::setFormat(const uint32_t format)
{
	pix_->format = format;
}

void GfxPixelFormat::setBitsPerPixel(const uint8_t bpp)
{
	pix_->BitsPerPixel = bpp;
}

void GfxPixelFormat::setPalette(const GfxPalette& pal)
{
	pal_ = pal;
}

void GfxPixelFormat::setBytesPerPixel(const uint8_t bypp)
{
	pix_->BytesPerPixel = bypp;
}

void GfxPixelFormat::setRedMask(const uint32_t rmask)
{
	pix_->Rmask = rmask;
}

void GfxPixelFormat::setGreenMask(const uint32_t gmask)
{
	pix_->Gmask = gmask;
}

void GfxPixelFormat::setBlueMask(const uint32_t bmask)
{
	pix_->Bmask = bmask;
}

void GfxPixelFormat::setAlphaMask(const uint32_t amask)
{
	pix_->Amask = amask;
}

uint32_t GfxPixelFormat::getFormat(void) const
{
    return pix_->format;
}

uint8_t GfxPixelFormat::getBitsPerPixel(void) const
{
    return pix_->BitsPerPixel;
}

std::unique_ptr<GfxPalette> GfxPixelFormat::getPalette(void)
{
    std::unique_ptr<GfxPalette> p {new GfxPalette(pal_)};
    
    return p;
}

uint8_t GfxPixelFormat::getBytesPerPixel(void) const
{
    return pix_->BytesPerPixel;
}

uint32_t GfxPixelFormat::getRedMask(void) const
{
    return pix_->Rmask;
}

uint32_t GfxPixelFormat::getGreenMask(void) const
{
    return pix_->Gmask;
}

uint32_t GfxPixelFormat::getBlueMask(void) const
{
    return pix_->Bmask;
}

uint32_t GfxPixelFormat::getAlphaMask(void) const
{
    return pix_->Amask;
}

/* for internal use by SDL */
uint8_t GfxPixelFormat::getRloss(void) const
{
    return pix_->Rloss;
}

uint8_t GfxPixelFormat::getGloss(void) const
{
    return pix_->Gloss;
}

uint8_t GfxPixelFormat::getBloss(void) const
{
    return pix_->Bloss;
}

uint8_t GfxPixelFormat::getAloss(void) const
{
    return pix_->Aloss;
}

uint8_t GfxPixelFormat::getRshift(void) const
{
    return pix_->Rshift;
}

uint8_t GfxPixelFormat::getGshift(void) const
{
    return pix_->Gshift;
}

uint8_t GfxPixelFormat::getBshift(void) const
{
    return pix_->Bshift;
}

int GfxPixelFormat::getRefCount(void) const
{
    return pix_->refcount;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getNext(void) const
{
    return pix_->next;
}

GfxPixelFormat::SdlType GfxPixelFormat::getAsSdlType(void) const
{
    return *pix_;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)pix_;
}
