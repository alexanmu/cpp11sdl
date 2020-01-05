/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#ifndef GfxFontInfo_hpp
#define GfxFontInfo_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace xtra
{

class GfxFontInfo final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxFontInfo() noexcept;
    explicit GfxFontInfo(const std::string& fontName) noexcept;
    explicit GfxFontInfo(const std::string& fontName, const uint8_t fontSize) noexcept;

    GfxFontInfo(const GfxFontInfo& other) noexcept;
    GfxFontInfo(GfxFontInfo&& other) noexcept;

    GfxFontInfo& operator=(const GfxFontInfo& other) noexcept;
    GfxFontInfo& operator=(GfxFontInfo&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setFontName(const std::string& fontName) noexcept;
    void setFontNameDefault(void) noexcept;
    const std::string& getFontName(void) const noexcept;

    void setFontSize(const uint8_t fontSize) noexcept;
    void setFontSizeDefault(void) noexcept;
    uint8_t getFontSize(void) const noexcept;

    void setFontOutline(const int32_t fontOutline) noexcept;
    void setFontOutlineDefault(void) noexcept;
    int32_t getFontOutline(void) const noexcept;

    void setFontBold(const bool fontBold) noexcept;
    void setFontBoldDefault(void) noexcept;
    bool getFontBold(void) const noexcept;

    void setFontItalic(const bool fontItalic) noexcept;
    void setFontItalicDefault(void) noexcept;
    bool getFontItalic(void) const noexcept;

    void setFontUnderline(const bool fontUnderline) noexcept;
    void setFontUnderlineDefault(void) noexcept;
    bool getFontUnderline(void) const noexcept;

    void setFontStrikethrough(const bool fontStrikethrough) noexcept;
    void setFontStrikethroughDefault(void) noexcept;
    bool getFontStrikethrough(void) const noexcept;

    void setFontHinting(const int32_t fontHinting) noexcept;
    void setFontHintingDefault(void) noexcept;
    int32_t getFontHinting(void) const noexcept;

    void setFontKerning(const bool fontKerning) noexcept;
    void setFontKerningDefault(void) noexcept;
    bool getFontKerning(void) const noexcept;

    void setDefault(void) noexcept;

    void clear(void) noexcept;

    static const char kDefaultFontName[];
    static const uint8_t kDefaultFontSize;
    static const int32_t kDefaultFontOutline;
    static const bool kDefaultFontBold;
    static const bool kDefaultFontItalic;
    static const bool kDefaultFontUnderline;
    static const bool kDefaultFontStrikethrough;
    static const int32_t kDefaultFontHinting;
    static const bool kDefaultFontKerning;

    static const uint8_t kMinFontSize;
private:
    std::string fontName_;
    uint8_t fontSize_;
    int32_t fontOutline_;
    bool fontBold_;
    bool fontItalic_;
    bool fontUnderline_;
    bool fontStrikethrough_;
    int32_t fontHinting_;
    bool fontKerning_;
};

}  // namespace xtra

}  // namespace gfx

#endif /* GfxFontInfo_hpp */
