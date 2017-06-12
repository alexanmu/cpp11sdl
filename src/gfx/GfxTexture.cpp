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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>

#include "GfxTexture.hpp"
#include "GfxRenderer.hpp"

namespace gfx
{

namespace render
{

const char GfxTexture::ClassName[] = "GfxTexture";

GfxTexture::GfxTexture(GfxObject * rend, pixels::GfxPixelFormatEnum const& format, GfxTextureAccess const& acc,
            const int32_t w, const int32_t h) throw(std::runtime_error) : GfxObject(ClassName)
{
    assert(rend != nullptr);
    assert(format);
    assert(acc);
    assert(w >= 0);
    assert(h >= 0);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    rend_ = rend;
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = sdl2::SDL_CreateTexture(rendptr->getAsSdlTypePtr(),
                                     format.getAsSdlType(),
                                     acc.getAsSdlType(),
                                     w, h);
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
}

GfxTexture::GfxTexture(GfxObject * rend, surface::GfxSurface const& surf) throw(std::runtime_error)
            : GfxObject(ClassName)
{
    assert(rend != nullptr);
    assert(surf);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    rend_ = rend;
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = sdl2::SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(), surf.getAsSdlTypePtr());
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
}

GfxTexture::~GfxTexture() noexcept
{
    if (tex_ != nullptr)
    {
        sdl2::SDL_DestroyTexture(tex_);
    }
    tex_ = nullptr;
}

GfxTexture::GfxTexture(GfxTexture&& tex)
{
    tex_ = tex.tex_;
    // Destroy other's data
    tex.tex_ = nullptr;
}

GfxTexture& GfxTexture::operator=(GfxTexture&& tex)
{
    if (this != &tex)
    {
        if (tex_ != nullptr)
        {
            sdl2::SDL_DestroyTexture(tex_);
        }
        tex_ = tex.tex_;
        // Destroy other's data
        tex.tex_ = nullptr;
    }
    return *this;
}

GfxTexture::operator bool() const noexcept
{
    return (tex_ != nullptr);
}

void GfxTexture::queryTexture(pixels::GfxPixelFormatEnum * format, GfxTextureAccess * acc, int * w,
                                int * h) const noexcept
{
    assert(format != nullptr);
    assert(acc != nullptr);
    assert(w != nullptr);
    assert(h != nullptr);

    pixels::GfxPixelFormatEnum::SdlType sdlfmt;
    int32_t u32sdlacc;

    if (tex_ != nullptr)
    {
        sdl2::SDL_QueryTexture(tex_, &sdlfmt, &u32sdlacc, w, h);
        format = new pixels::GfxPixelFormatEnum(sdlfmt);
        acc = new GfxTextureAccess(u32sdlacc);
    }
}

void GfxTexture::destroyTexture(void) noexcept
{
    if (tex_ != nullptr)
    {
        sdl2::SDL_DestroyTexture(tex_);
        tex_ = nullptr;
    }
}

void GfxTexture::setBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept
{
    assert(blendmode);

    if (tex_ == nullptr)
    {
        return;
    }
    sdl2::SDL_SetTextureBlendMode(tex_, blendmode.getAsSdlType());
}

void GfxTexture::setBlendMode(const blendmode::GfxBlendMode::ValueType blendmode) const noexcept
{
    if (tex_ == nullptr)
    {
        return;
    }
    sdl2::SDL_SetTextureBlendMode(tex_, static_cast<blendmode::GfxBlendMode::SdlType>(blendmode));
}

blendmode::GfxBlendMode GfxTexture::getBlendMode(void) const noexcept
{
    blendmode::GfxBlendMode::SdlType bm;

    if (tex_ == nullptr)
    {
        return blendmode::GfxBlendMode();
    }
    sdl2::SDL_GetTextureBlendMode(tex_, &bm);

    return blendmode::GfxBlendMode(bm);
}

GfxTexture::SdlTypePtr GfxTexture::getAsSdlTypePtr(void) const noexcept
{
    return tex_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
