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

#ifndef GfxBlendMode_hpp
#define GfxBlendMode_hpp

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

namespace gfx
{

class GfxBlendMode final : public GfxRootClass
{
public:
    typedef sdl2::SDL_BlendMode SdlType;
    typedef sdl2::SDL_BlendMode* SdlTypePtr;

    static const std::string ClassName;

    enum class GfxBlendModeValues : int
    {
        blendNone = sdl2::SDL_BLENDMODE_NONE,
        blendBlend = sdl2::SDL_BLENDMODE_BLEND,
        blendAdd = sdl2::SDL_BLENDMODE_ADD,
        blendMod = sdl2::SDL_BLENDMODE_MOD
    };

    GfxBlendMode();

    explicit GfxBlendMode(const GfxBlendModeValues blendmode);
    explicit GfxBlendMode(const SdlType blendmode);

    GfxBlendMode(const GfxBlendMode& other);
    GfxBlendMode(GfxBlendMode&& other);

    GfxBlendMode& operator=(const GfxBlendMode& other);
    GfxBlendMode& operator=(GfxBlendMode&& other);

    bool operator==(const GfxBlendMode& other);

    GfxBlendModeValues getBlendMode(void) const;

    bool isBlend(void) const;
    bool isAdd(void) const;
    bool isMod(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType blendmode_;
};

}  // namespace gfx

#endif /* GfxBlendMode_hpp */
