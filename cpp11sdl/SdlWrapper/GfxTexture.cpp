//
//  GfxTexture.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxTexture.hpp"

#include "GfxRenderer.hpp"

GfxTexture::GfxTexture(void * rend) : GfxRootClass("GfxTexture")
{
    rend_ = rend;
    tex_ = nullptr;
}

GfxTexture::GfxTexture(void * rend,const GfxSurface& surf) : GfxTexture(rend)
{
    GfxRenderer* rendptr;
    
    rendptr = (GfxRenderer*)rend;
    tex_ = SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(),surf.getAsSdlTypePtr());
}

GfxTexture::~GfxTexture()
{
    if (tex_)
        SDL_DestroyTexture(tex_);
}

GfxTexture::GfxTexture(GfxTexture&& tex)
{
    tex_ = tex.tex_;
}

GfxTexture& GfxTexture::operator=(GfxTexture&& tex)
{
    if (this != &tex)
    {
        tex_ = tex.tex_;
        
        tex.tex_ = nullptr;
    }
    return *this;
}

void GfxTexture::destroyTexture(void)
{
    if (tex_)
    {
        SDL_DestroyTexture(tex_);
        tex_ = nullptr;
    }
}

GfxTexture::SdlTypePtr GfxTexture::getAsSdlTypePtr(void) const
{
    return tex_;
}
