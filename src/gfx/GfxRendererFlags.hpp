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

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxRendererFlags final : public GfxObject
{
public:
    typedef sdl2::SDL_RendererFlags SdlType;
    typedef sdl2::SDL_RendererFlags* SdlTypePtr;

    static const char ClassName[];

    enum class ValueType : int32_t
    {
        flagUnknown,
        flagSoftware = sdl2::SDL_RENDERER_SOFTWARE,
        flagAccelerated = sdl2::SDL_RENDERER_ACCELERATED,
        flagPresentVSync = sdl2::SDL_RENDERER_PRESENTVSYNC,
        flagTargetTexture = sdl2::SDL_RENDERER_TARGETTEXTURE
    };

    GfxRendererFlags() noexcept;

    explicit GfxRendererFlags(const ValueType flags) noexcept;
    explicit GfxRendererFlags(const SdlType flags) noexcept;

    GfxRendererFlags(GfxRendererFlags const& other) noexcept;
    GfxRendererFlags(GfxRendererFlags&& other) noexcept;

    GfxRendererFlags& operator=(GfxRendererFlags const& other) noexcept;
    GfxRendererFlags& operator=(GfxRendererFlags&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isUnknown(void) const noexcept;
    bool isSoftware(void) const noexcept;
    bool isAccelerated(void) const noexcept;
    bool getPresentVSync(void) const noexcept;
    bool getTargetTexture(void) const noexcept;

    void setSoftware(void) noexcept;
    void resetSoftware(void) noexcept;

    void setAccelerated(void) noexcept;
    void resetAccelerated(void) noexcept;

    void setPresentVSync(void) noexcept;
    void resetPresentVSync(void) noexcept;

    void setTargetTexture(void) noexcept;
    void resetTargetTexture(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType flags_;
};

}  // namespace gfx

#endif /* GfxRendererFlags_hpp */
