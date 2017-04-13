//
//  GfxFlip.hpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxFlip_hpp
#define GfxFlip_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxFlip final : public GfxRootClass
{
public:
    typedef SDL_RendererFlip SdlType;
    typedef SDL_RendererFlip* SdlTypePtr;

    GfxFlip();
    GfxFlip(const bool fliph,const bool flipv);
    GfxFlip(const GfxFlip& other);
    GfxFlip(GfxFlip&& other);
    GfxFlip& operator=(const GfxFlip& other);
    GfxFlip& operator=(GfxFlip&& other);

    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr() const;
private:
    enum class GfxFlipValues : int
    {
        flipNone = SDL_FLIP_NONE,
        flipHorizontal = SDL_FLIP_HORIZONTAL,
        flipVertical = SDL_FLIP_VERTICAL
    };
    int flip_;
};

#endif /* GfxFlip_hpp */
