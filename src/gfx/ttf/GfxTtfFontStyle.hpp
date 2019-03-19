/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfFontStyle final : public GfxObject
{
public:
    typedef int32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class GfxTtfFontStyleValues : int32_t
    {
        styleNormal = TTF_STYLE_NORMAL,
        styleBold = TTF_STYLE_BOLD,
        styleItalic = TTF_STYLE_ITALIC,
        styleUnderline = TTF_STYLE_UNDERLINE,
        styleStrikethrough = TTF_STYLE_STRIKETHROUGH
    };

    GfxTtfFontStyle() noexcept;
    explicit GfxTtfFontStyle(const bool bold, const bool italic, const bool underline,
                             const bool strikethrough) noexcept;
    explicit GfxTtfFontStyle(const SdlType style) noexcept;

    GfxTtfFontStyle(const GfxTtfFontStyle& other) noexcept;
    GfxTtfFontStyle(GfxTtfFontStyle&& other) noexcept;

    GfxTtfFontStyle& operator=(const GfxTtfFontStyle& other) noexcept;
    GfxTtfFontStyle& operator=(GfxTtfFontStyle&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isNormal(void) const noexcept;
    bool isBold(void) const noexcept;
    bool isItalic(void) const noexcept;
    bool isUnderline(void) const noexcept;
    bool isStrikethrough(void) const noexcept;

    void setNormal(void) noexcept;

    void setBold(void) noexcept;
    void resetBold(void) noexcept;
    void setItalic(void) noexcept;
    void resetItalic(void) noexcept;
    void setUnderline(void) noexcept;
    void resetUnderline(void) noexcept;
    void setStrikethrough(void) noexcept;
    void resetStrikethrough(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType style_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfFontStyle_hpp
