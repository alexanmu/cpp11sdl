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

#include <memory>

#include "GfxPixelFormat.hpp"

GfxPixelFormat::GfxPixelFormat() : GfxRootClass("GfxPixelFormat")
{
    pix_ = nullptr;
    pal_ = nullptr;
};

GfxPixelFormat::GfxPixelFormat(SdlTypePtr pix) : GfxRootClass("GfxPixelFormat")
{
    pix_ = pix;
    pal_ = new GfxPalette(pix->palette);
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

/*** Getters ***/
uint32_t GfxPixelFormat::getFormat(void) const
{
    return pix_->format;
}

std::unique_ptr<GfxPalette> GfxPixelFormat::getPalette(void)
{
    std::unique_ptr<GfxPalette> p { new GfxPalette(pix_->palette) };

    return p;
}

uint8_t GfxPixelFormat::getBitsPerPixel(void) const
{
    return pix_->BitsPerPixel;
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

uint8_t GfxPixelFormat::getAshift(void) const
{
    return pix_->Ashift;
}

int GfxPixelFormat::getRefCount(void) const
{
    return pix_->refcount;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getNext(void) const
{
    return pix_->next;
}

/*** Setters ***/
void GfxPixelFormat::setFormat(const uint32_t format)
{
    pix_->format = format;
}

void GfxPixelFormat::setPalette(GfxPalette&& pal)
{
    pal_ = pal;
}

void GfxPixelFormat::setBitsPerPixel(const uint8_t bpp)
{
    pix_->BitsPerPixel = bpp;
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

/*** SDL ***/
GfxPixelFormat::SdlType GfxPixelFormat::getAsSdlType(void) const
{
    return *pix_;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)pix_;
}

/* EOF */
