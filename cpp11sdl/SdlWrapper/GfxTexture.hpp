//
//  GfxTexture.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxTexture_hpp
#define GfxTexture_hpp

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"

class GfxTexture final
{
public:
    typedef SDL_Texture GfxTextureSdlType;
    
    GfxTexture() = delete;
    GfxTexture(void * rend,std::string name);
    GfxTexture(void * rend,std::string name,const GfxSurface& surf);

    ~GfxTexture();
    
    GfxTexture(const GfxTexture&) = delete;
    GfxTexture(GfxTexture&& tex);
    
    GfxTexture& operator=(const GfxTexture&) = delete;
    GfxTexture& operator=(GfxTexture&& tex);
    
    void destroyTexture(void);

    std::string getName(void) const;
    GfxTextureSdlType* getAsGfxTextureSdlTypePtr(void) const;
private:
    void * rend_;
    SDL_Texture* tex_;
    std::string name_;
};

#endif /* GfxTexture_hpp */
