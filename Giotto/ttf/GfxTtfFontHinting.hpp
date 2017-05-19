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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontHinting final : public GfxRootClass
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

    GfxTtfFontHinting();
    explicit GfxTtfFontHinting(GfxTtfFontHintingValues const& hinting);
    explicit GfxTtfFontHinting(SdlType hinting);

    GfxTtfFontHinting(GfxTtfFontHinting const& other);
    GfxTtfFontHinting(GfxTtfFontHinting&& other);

    GfxTtfFontHinting& operator=(GfxTtfFontHinting const& other);
    GfxTtfFontHinting& operator=(GfxTtfFontHinting&& other);

    virtual explicit operator bool() const;

    bool isNormal(void) const;
    bool isLight(void) const;
    bool isMono(void) const;
    bool isNone(void) const;

    void setNormal(void);
    void setLight(void);
    void setMono(void);
    void setNone(void);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType hinting_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFontHinting_hpp
