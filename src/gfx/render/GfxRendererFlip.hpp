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

#ifndef GfxRendererFlip_hpp
#define GfxRendererFlip_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace render
{

class GfxRendererFlip final : public GfxObject
{
public:
    typedef sdl2::SDL_RendererFlip SdlType;
    typedef sdl2::SDL_RendererFlip* SdlTypePtr;

    static const char ClassName[];

    enum class ValueType : int32_t
    {
        flipNone = sdl2::SDL_FLIP_NONE,
        flipHorizontal = sdl2::SDL_FLIP_HORIZONTAL,
        flipVertical = sdl2::SDL_FLIP_VERTICAL
    };

    GfxRendererFlip() noexcept;

    GfxRendererFlip(const bool fliph, const bool flipv) noexcept;
    explicit GfxRendererFlip(const ValueType value) noexcept;

    GfxRendererFlip(GfxRendererFlip const& other) noexcept;
    GfxRendererFlip(GfxRendererFlip&& other) noexcept;

    GfxRendererFlip& operator=(GfxRendererFlip const& other) noexcept;
    GfxRendererFlip& operator=(GfxRendererFlip&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool operator==(GfxRendererFlip const& other) noexcept;

    bool isFlipHorizontal(void) const noexcept;
    bool isFlipVertical(void) const noexcept;

    void setFlipHorizontal(void) noexcept;
    void setFlipVertical(void) noexcept;

    void resetFlipHorizontal(void) noexcept;
    void resetFlipVertical(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType flip_;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxRendererFlip_hpp */
