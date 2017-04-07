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
    pix_ = nullptr;
};

GfxPixelFormat::GfxPixelFormat(SdlTypePtr pix)
{
    pix_ = pix;
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

GfxPixelFormat::SdlType GfxPixelFormat::getAsSdlType(void)
{
    return *pix_;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void)
{
    return pix_;
}
