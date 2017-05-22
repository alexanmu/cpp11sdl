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

#include <cassert>
#include <cstdint>
#include <string>

#include "GfxPixelFormat.hpp"

namespace gfx
{

const char GfxPixelFormat::ClassName[] = "GfxPixelFormat";

GfxPixelFormat::GfxPixelFormat() : GfxRootClass(ClassName)
{
    pix_ = sdl2::SDL_AllocFormat(sdl2::SDL_PIXELFORMAT_ARGB8888);
    if (pix_ == nullptr)
    {
        // Error handling here
    }
};

GfxPixelFormat::GfxPixelFormat(const SdlTypePtr pix) : GfxRootClass(ClassName)
{
    assert(pix != nullptr);

    pix_ = sdl2::SDL_AllocFormat(pix->format);
}

GfxPixelFormat::GfxPixelFormat(const uint32_t format) : GfxRootClass(ClassName)
{
    assert(format > 0);

    pix_ = sdl2::SDL_AllocFormat(format);
    if (pix_ == nullptr)
    {
        // Error handling here
    }
}

GfxPixelFormat::GfxPixelFormat(GfxPixelFormat&& other) : GfxRootClass(ClassName)
{
    pix_ = other.pix_;
    // Delete other's data
    other.clear();
}

GfxPixelFormat& GfxPixelFormat::operator=(GfxPixelFormat&& other)
{
    if (this != &other)
    {
        if (pix_ != nullptr)
        {
            SDL_FreeFormat(pix_);
        }
        pix_ = other.pix_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPixelFormat::~GfxPixelFormat()
{
    if (pix_ != nullptr)
    {
        SDL_FreeFormat(pix_);
    }
}

GfxPixelFormat::operator bool() const
{
    return (pix_ != nullptr);
}

/*** Getters ***/
uint32_t GfxPixelFormat::getFormat(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->format;
    }
    return 0;
}

uint8_t GfxPixelFormat::getBitsPerPixel(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->BitsPerPixel;
    }
    return 0;
}

uint8_t GfxPixelFormat::getBytesPerPixel(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->BytesPerPixel;
    }
    return 0;
}

uint32_t GfxPixelFormat::getRedMask(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Rmask;
    }
    return 0;
}

uint32_t GfxPixelFormat::getGreenMask(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Gmask;
    }
    return 0;
}

uint32_t GfxPixelFormat::getBlueMask(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Bmask;
    }
    return 0;
}

uint32_t GfxPixelFormat::getAlphaMask(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Amask;
    }
    return 0;
}

/* for internal use by SDL */
uint8_t GfxPixelFormat::getRloss(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Rloss;
    }
    return 0;
}

uint8_t GfxPixelFormat::getGloss(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Gloss;
    }
    return 0;
}

uint8_t GfxPixelFormat::getBloss(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Bloss;
    }
    return 0;
}

uint8_t GfxPixelFormat::getAloss(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Aloss;
    }
    return 0;
}

uint8_t GfxPixelFormat::getRshift(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Rshift;
    }
    return 0;
}

uint8_t GfxPixelFormat::getGshift(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Gshift;
    }
    return 0;
}

uint8_t GfxPixelFormat::getBshift(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Bshift;
    }
    return 0;
}

uint8_t GfxPixelFormat::getAshift(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->Ashift;
    }
    return 0;
}

int32_t GfxPixelFormat::getRefCount(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->refcount;
    }
    return -1;
}

GfxPixelFormat::SdlTypePtr GfxPixelFormat::getNext(void) const
{
    if (pix_ != nullptr)
    {
        return pix_->next;
    }
    return nullptr;
}

std::string GfxPixelFormat::getFormatAsString(void) const
{
    std::string str {"$nullptr$"};

    if (pix_ != nullptr)
    {
        str = sdl2::SDL_GetPixelFormatName(pix_->format);
    }
    return str;
}

/*** Setters ***/
void GfxPixelFormat::setFormat(const uint32_t format)
{
    assert(format > 0);

    if (pix_ != nullptr)
    {
        pix_->format = format;
    }
}

void GfxPixelFormat::setBitsPerPixel(const uint8_t bpp)
{
    assert(bpp > 0);

    if (pix_ != nullptr)
    {
        pix_->BitsPerPixel = bpp;
    }
}

void GfxPixelFormat::setBytesPerPixel(const uint8_t bypp)
{
    assert(bypp > 0);

    if (pix_ != nullptr)
    {
        pix_->BytesPerPixel = bypp;
    }
}

void GfxPixelFormat::setRedMask(const uint32_t rmask)
{
    if (pix_ != nullptr)
    {
        pix_->Rmask = rmask;
    }
}

void GfxPixelFormat::setGreenMask(const uint32_t gmask)
{
    if (pix_ != nullptr)
    {
        pix_->Gmask = gmask;
    }
}

void GfxPixelFormat::setBlueMask(const uint32_t bmask)
{
    if (pix_ != nullptr)
    {
        pix_->Bmask = bmask;
    }
}

void GfxPixelFormat::setAlphaMask(const uint32_t amask)
{
    if (pix_ != nullptr)
    {
        pix_->Amask = amask;
    }
}

void GfxPixelFormat::clear(void)
{
    if (pix_ != nullptr)
    {
        SDL_FreeFormat(pix_);
        pix_ = nullptr;
    }
}

/*** SDL ***/
GfxPixelFormat::SdlTypePtr GfxPixelFormat::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)pix_;
}

}  // namespace gfx

/* EOF */
