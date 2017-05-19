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

#ifndef GfxTtfFontStyle_hpp
#define GfxTtfFontStyle_hpp

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontStyle final : public GfxRootClass
{
public:
    typedef int32_t SdlType;
    typedef int32_t* SdlTypePtr;

    static const char ClassName[];

    enum class GfxTtfFontStyleValues : int32_t
    {
        styleNormal = TTF_STYLE_NORMAL,
        styleBold = TTF_STYLE_BOLD,
        styleItalic = TTF_STYLE_ITALIC,
        styleUnderline = TTF_STYLE_UNDERLINE,
        styleStrikethrough = TTF_STYLE_STRIKETHROUGH
    };

    GfxTtfFontStyle();
    explicit GfxTtfFontStyle(bool bold, bool italic, bool underline, bool strikethrough);
    explicit GfxTtfFontStyle(SdlType style);

    GfxTtfFontStyle(GfxTtfFontStyle const& other);
    GfxTtfFontStyle(GfxTtfFontStyle&& other);

    GfxTtfFontStyle& operator=(GfxTtfFontStyle const& other);
    GfxTtfFontStyle& operator=(GfxTtfFontStyle&& other);

    virtual explicit operator bool() const;

    bool isNormal(void) const;
    bool isBold(void) const;
    bool isItalic(void) const;
    bool isUnderline(void) const;
    bool isStrikethrough(void) const;

    void setNormal(void);

    void setBold(void);
    void resetBold(void);
    void setItalic(void);
    void resetItalic(void);
    void setUnderline(void);
    void resetUnderline(void);
    void setStrikethrough(void);
    void resetStrikethrough(void);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType style_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFontStyle_hpp
