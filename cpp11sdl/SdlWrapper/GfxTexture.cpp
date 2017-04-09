//
//  GfxTexture.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxTexture.hpp"

#include "GfxRenderer.hpp"

GfxTexture::GfxTexture(GfxRootClass * rend) : GfxRootClass("GfxTexture")
{
    rend_ = rend;
    tex_ = nullptr;
}

GfxTexture::GfxTexture(GfxRootClass * rend,const GfxSurface& surf) : GfxTexture(rend)
{
    GfxRenderer* rendptr;
    
    rendptr = (GfxRenderer*)rend;
    tex_ = SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(),surf.getAsSdlTypePtr());
}

GfxTexture::~GfxTexture()
{
    if (tex_ != nullptr)
        SDL_DestroyTexture(tex_);
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
    SDL_SetTextureBlendMode(tex_,blendmode.getAsSdlType());
}

std::unique_ptr<GfxBlendMode> GfxTexture::getBlendMode(void)
{
    SDL_BlendMode bm;
    
    SDL_GetTextureBlendMode(tex_,&bm);
    std::unique_ptr<GfxBlendMode> ptr { new GfxBlendMode(bm) };

    return ptr;
}

GfxTexture::SdlTypePtr GfxTexture::getAsSdlTypePtr(void) const
{
    return tex_;
}
