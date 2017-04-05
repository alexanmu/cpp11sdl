//
//  GfxTexture.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxTexture.hpp"

#include "GfxRenderer.hpp"

GfxTexture::GfxTexture(void * rend,std::string name)
{
    rend_ = rend;
    tex_ = nullptr;
    name_ = name;
}

GfxTexture::GfxTexture(void * rend,std::string name,const GfxSurface& surf) : GfxTexture(rend,name)
{
    GfxRenderer* rendptr;
    
    rendptr = (GfxRenderer*)rend;
    tex_ = SDL_CreateTextureFromSurface(rendptr->getAsGfxRendererSdlTypePtr(),surf.getAsGfxSurfaceSdlTypePtr());
}

GfxTexture::~GfxTexture()
{
    if (tex_)
        SDL_DestroyTexture(tex_);
}

GfxTexture::GfxTexture(GfxTexture&& tex)
{
    tex_ = tex.tex_;
    name_ = tex.name_;
}

GfxTexture& GfxTexture::operator=(GfxTexture&& tex)
{
    if (this != &tex)
    {
        tex_ = tex.tex_;
        name_ = tex.name_;
        
        tex.tex_ = nullptr;
        tex.name_ = "";
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

std::string GfxTexture::getName(void) const
{
    return name_;
}

GfxTexture::GfxTextureSdlType* GfxTexture::getAsGfxTextureSdlTypePtr(void) const
{
    return tex_;
}
