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

#include "GfxTexture.hpp"
#include "GfxRenderer.hpp"

GfxTexture::GfxTexture(GfxRootClass * rend, const GfxTextureAccess& acc, const int32_t w, const int32_t h) : GfxRootClass("GfxTexture")
{
    GfxRenderer* rendptr;

    rend_ = rend;
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    tex_ = SDL_CreateTexture(rendptr->getAsSdlTypePtr(),
                             SDL_PIXELFORMAT_ARGB8888,
                             acc.getAsSdlType(),
                             w,h);
}

GfxTexture::GfxTexture(GfxRootClass * rend, const GfxSurface& surf) : GfxRootClass("GfxTexture")
{
    GfxRenderer* rendptr;

    rend_ = rend;
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    tex_ = SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(), surf.getAsSdlTypePtr());
}

GfxTexture::~GfxTexture()
{
    if (tex_ != nullptr)
    {
        SDL_DestroyTexture(tex_);
    }
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
            SDL_DestroyTexture(tex_);
        }
        tex_ = tex.tex_;
        // Destroy other's data
        tex.tex_ = nullptr;
    }
    return *this;
}

void GfxTexture::destroyTexture(void)
{
    if (tex_ != nullptr)
    {
        SDL_DestroyTexture(tex_);
        tex_ = nullptr;
    }
}

void GfxTexture::setBlendMode(const GfxBlendMode& blendmode)
{
    if (tex_ == nullptr)
    {
        return;
    }
    SDL_SetTextureBlendMode(tex_, blendmode.getAsSdlType());
}

void GfxTexture::setBlendMode(const GfxBlendMode::GfxBlendModeValues blendmode)
{
    if (tex_ == nullptr)
    {
        return;
    }
    SDL_SetTextureBlendMode(tex_, static_cast<GfxBlendMode::SdlType>(blendmode));
}

GfxBlendMode GfxTexture::getBlendMode(void)
{
    GfxBlendMode::SdlType bm;

    if (tex_ == nullptr)
    {
        return GfxBlendMode();
    }
    SDL_GetTextureBlendMode(tex_, &bm);

    return GfxBlendMode(bm);
}

GfxTexture::SdlTypePtr GfxTexture::getAsSdlTypePtr(void) const
{
    return tex_;
}

/* EOF */
