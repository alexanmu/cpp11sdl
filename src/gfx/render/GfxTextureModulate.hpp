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

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace render
{

class GfxTextureModulate final : public GfxObject
{
public:
    typedef SDL_TextureModulate SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        modulateNone = SDL_TEXTUREMODULATE_NONE,
        modulateColor = SDL_TEXTUREMODULATE_COLOR,
        modulateAlpha = SDL_TEXTUREMODULATE_ALPHA
    };

    GfxTextureModulate() noexcept;

    explicit GfxTextureModulate(const ValueType modulate) noexcept;
    explicit GfxTextureModulate(const SdlType modulate) noexcept;
    explicit GfxTextureModulate(const int32_t modulate) noexcept;

    GfxTextureModulate(const GfxTextureModulate& other) noexcept;
    GfxTextureModulate(GfxTextureModulate&& other) noexcept;

    GfxTextureModulate& operator=(const GfxTextureModulate& other) noexcept;
    GfxTextureModulate& operator=(GfxTextureModulate&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isNone(void) const noexcept;
    bool isColor(void) const noexcept;
    bool isAlpha(void) const noexcept;

    void setColor(void) noexcept;
    void resetColor(void) noexcept;

    void setAlpha(void) noexcept;
    void resetAlpha(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType modulate_;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxTextureModulate_hpp */
