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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

namespace gfx
{

class GfxRendererFlip final : public GfxRootClass
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

    GfxRendererFlip();

    GfxRendererFlip(const bool fliph, const bool flipv);
    explicit GfxRendererFlip(const ValueType values);

    GfxRendererFlip(const GfxRendererFlip& other);
    GfxRendererFlip(GfxRendererFlip&& other);

    GfxRendererFlip& operator=(const GfxRendererFlip& other);
    GfxRendererFlip& operator=(GfxRendererFlip&& other);

    bool operator==(const GfxRendererFlip& other);

    bool isFlipHorizontal(void) const;
    bool isFlipVertical(void) const;

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flip_;
};

}  // namespace gfx

#endif /* GfxRendererFlip_hpp */
