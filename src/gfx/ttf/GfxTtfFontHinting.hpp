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

#ifndef GfxTtfFontHinting_hpp
#define GfxTtfFontHinting_hpp

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontHinting final : public GfxObject
{
public:
    typedef int32_t SdlType;
    typedef int32_t* SdlTypePtr;

    static const char ClassName[];

    enum class GfxTtfFontHintingValues : int32_t
    {
        hintingNormal = TTF_HINTING_NORMAL,
        hintingLight = TTF_HINTING_LIGHT,
        hintingMono = TTF_HINTING_MONO,
        hintingNone = TTF_HINTING_NONE
    };

    GfxTtfFontHinting() noexcept;
    explicit GfxTtfFontHinting(GfxTtfFontHintingValues const& hinting) noexcept;
    explicit GfxTtfFontHinting(SdlType hinting) noexcept;

    GfxTtfFontHinting(GfxTtfFontHinting const& other) noexcept;
    GfxTtfFontHinting(GfxTtfFontHinting&& other) noexcept;

    GfxTtfFontHinting& operator=(GfxTtfFontHinting const& other) noexcept;
    GfxTtfFontHinting& operator=(GfxTtfFontHinting&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isNormal(void) const noexcept;
    bool isLight(void) const noexcept;
    bool isMono(void) const noexcept;
    bool isNone(void) const noexcept;

    void setNormal(void) noexcept;
    void setLight(void) noexcept;
    void setMono(void) noexcept;
    void setNone(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType hinting_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFontHinting_hpp
