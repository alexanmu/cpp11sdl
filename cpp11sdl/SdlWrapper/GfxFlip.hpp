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

    GfxFlip() = delete;
    GfxFlip(bool fliph,bool flipv) : GfxRootClass("GfxFlip")
    {
        flip_ = static_cast<int>(GfxFlipValues::flipNone);
        if (fliph)
            flip_ |= static_cast<int>(GfxFlipValues::flipHorizontal);
        if (flipv)
            flip_ |= static_cast<int>(GfxFlipValues::flipVertical);
    }

    GfxFlip(const GfxFlip&) = delete;
    GfxFlip(GfxFlip&&) = delete;
    
    GfxFlip& operator=(const GfxFlip&) = delete;
    GfxFlip& operator=(GfxFlip&&) = delete;

    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr();
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
