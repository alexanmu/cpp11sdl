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

#ifndef GfxTextureModulate_hpp
#define GfxTextureModulate_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxTextureModulate final : public GfxRootClass
{
public:
    typedef sdl2::SDL_TextureModulate SdlType;
    typedef sdl2::SDL_TextureModulate* SdlTypePtr;

    static const char ClassName[];

    enum class GfxTextureModulateValues : int
    {
        modulateNone = sdl2::SDL_TEXTUREMODULATE_NONE,
        modulateColor = sdl2::SDL_TEXTUREMODULATE_COLOR,
        modulateAlpha = sdl2::SDL_TEXTUREMODULATE_ALPHA
    };

    GfxTextureModulate();

    explicit GfxTextureModulate(const GfxTextureModulateValues modulate);
    explicit GfxTextureModulate(const SdlType modulate);
    explicit GfxTextureModulate(const SdlTypePtr modulate);

    GfxTextureModulate(GfxTextureModulate const& other);
    GfxTextureModulate(GfxTextureModulate&& other);

    GfxTextureModulate& operator=(GfxTextureModulate const& other);
    GfxTextureModulate& operator=(GfxTextureModulate&& other);

    bool isNone(void) const;
    bool isColor(void) const;
    bool isAlpha(void) const;

    void setColor(void);
    void resetColor(void);

    void setAlpha(void);
    void resetAlpha(void);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType modulate_;
};

}  // namespace gfx

#endif /* GfxTextureModulate_hpp */
