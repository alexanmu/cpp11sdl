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

#ifndef GfxRendererFlags_hpp
#define GfxRendererFlags_hpp

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

class GfxRendererFlags final : public GfxRootClass
{
public:
    typedef SDL_RendererFlags SdlType;
    typedef SDL_RendererFlags* SdlTypePtr;

    enum class GfxRendererFlagsValues : int
    {
        flagUnknown,
        flagSoftware = SDL_RENDERER_SOFTWARE,
        flagAccelerated = SDL_RENDERER_ACCELERATED,
        flagPresentVSync = SDL_RENDERER_PRESENTVSYNC,
        flagTargetTexture = SDL_RENDERER_TARGETTEXTURE
    };

    GfxRendererFlags();
    explicit GfxRendererFlags(GfxRendererFlagsValues flags);
    explicit GfxRendererFlags(SdlType flags);
    explicit GfxRendererFlags(SdlTypePtr flags);
    GfxRendererFlags(GfxRendererFlags const& other);
    GfxRendererFlags(GfxRendererFlags&& other);

    GfxRendererFlags& operator=(GfxRendererFlags const& other);
    GfxRendererFlags& operator=(GfxRendererFlags&& other);

    bool isUnknown(void) const;
    bool isSoftware(void) const;
    bool isAccelerated(void) const;
    bool getPresentVSync(void) const;
    bool getTargetTexture(void) const;

    void setSoftware(void);
    void resetSoftware(void);

    void setAccelerated(void);
    void resetAccelerated(void);

    void setPresentVSync(void);
    void resetPresentVSync(void);

    void setTargetTexture(void);
    void resetTargetTexture(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flags_;
};

#endif /* GfxRendererFlags_hpp */
