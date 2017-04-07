//
//  GfxPixelFormat.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxPixelFormat.hpp"

GfxPixelFormat::GfxPixelFormat()
{
    pix_.format = -1;
    pix_.BitsPerPixel = -1;
    pix_.palette = nullptr;
    pix_.BytesPerPixel = -1;
    pix_.Rmask = -1;
    pix_.Bmask = -1;
    pix_.Amask = -1;
    pix_.Rloss = -1;
    pix_.Gloss = -1;
    pix_.Bloss = -1;
    pix_.Aloss = -1;
    pix_.Rshift = -1;
    pix_.Gshift = -1;
    pix_.Bshift = -1;
    pix_.Ashift = -1;
    pix_.refcount = -1;
    pix_.next = nullptr;
};

GfxPixelFormat::GfxPixelFormat(SdlType pix)
{
    pix_ = pix;
}

void GfxPixelFormat::setFormat(const uint32_t format)
{
	pix_.format = format;
}

void GfxPixelFormat::setBitsPerPixel(const uint8_t bpp)
{
	pix_.BitsPerPixel = bpp;
}

void GfxPixelFormat::setPalette(const GfxPalette& pal)
{
	pal_ = pal;
}

void GfxPixelFormat::setBytesPerPixel(const uint8_t bypp)
{
	pix_.BytesPerPixel = bypp;
}

void GfxPixelFormat::setRedMask(const uint32_t rmask)
{
	pix_.Rmask = rmask;
}

void GfxPixelFormat::setGreenMask(const uint32_t gmask)
{
	pix_.Gmask = gmask;
}

void GfxPixelFormat::setBlueMask(const uint32_t bmask)
{
	pix_.Bmask = bmask;
}

void GfxPixelFormat::setAlphaMask(const uint32_t amask)
{
	pix_.Amask = amask;
}

GfxPixelFormat::SdlType GfxPixelFormat::getAsSdlType(void)
{
    return pix_;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void)
{
    return &pix_;
}
