//
//  GfxBlendMode.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/9/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxBlendMode_hpp
#define GfxBlendMode_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxBlendMode final : public GfxRootClass
{
public:
    typedef SDL_BlendMode SdlType;
    typedef SDL_BlendMode* SdlTypePtr;

    enum class GfxBlendModeValues : int
    {
        blendNone = SDL_BLENDMODE_NONE,
        blendBlend = SDL_BLENDMODE_BLEND,
        blendAdd = SDL_BLENDMODE_ADD,
        blendMod = SDL_BLENDMODE_MOD
    };

    GfxBlendMode();
    GfxBlendMode(GfxBlendModeValues blendmode);
    GfxBlendMode(SdlType blendmode);
    GfxBlendMode(SdlTypePtr blendmode);
    GfxBlendMode(const GfxBlendMode& other);
    GfxBlendMode(GfxBlendMode&& other);
    
    GfxBlendMode& operator=(const GfxBlendMode& other);
    GfxBlendMode& operator=(GfxBlendMode&& other);
        
    GfxBlendModeValues getBlendMode(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    GfxBlendModeValues blendmode_;
};

#endif /* GfxBlendMode_hpp */
