//
//  GfxTexture.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxTexture_hpp
#define GfxTexture_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxSurface.hpp"
#include "GfxBlendMode.hpp"

class GfxTexture final : public GfxRootClass
{
public:
    typedef SDL_Texture SdlType;
    typedef SDL_Texture* SdlTypePtr;
    
    GfxTexture() = delete;

    GfxTexture(GfxRootClass * rend);
    GfxTexture(GfxRootClass * rend,const GfxSurface& surf);

    ~GfxTexture();
    
    GfxTexture(const GfxTexture&) = delete;
    GfxTexture(GfxTexture&& tex);
    
    GfxTexture& operator=(const GfxTexture&) = delete;
    GfxTexture& operator=(GfxTexture&& tex);
    
    void destroyTexture(void);

    void setBlendMode(const GfxBlendMode& blendmode);
    std::unique_ptr<GfxBlendMode> getBlendMode(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    GfxRootClass * rend_;
    SDL_Texture* tex_;
};

#endif /* GfxTexture_hpp */
