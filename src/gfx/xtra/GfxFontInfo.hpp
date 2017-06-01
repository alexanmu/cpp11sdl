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

#ifndef GfxFontInfo_hpp
#define GfxFontInfo_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"

namespace gfx
{

namespace xtra
{

class GfxFontInfo final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxFontInfo();
    explicit GfxFontInfo(std::string const& fontName);
    explicit GfxFontInfo(std::string const& fontName, const uint8_t fontSize);

    GfxFontInfo(GfxFontInfo const& other);
    GfxFontInfo(GfxFontInfo&& other);

    GfxFontInfo& operator=(GfxFontInfo const& other);
    GfxFontInfo& operator=(GfxFontInfo&& other);

    virtual explicit operator bool() const;

    void setFontName(std::string const& fontName);
    void setFontNameDefault(void);
    std::string const& getFontName(void) const;

    void setFontSize(const uint8_t fontSize);
    void setFontSizeDefault(void);
    uint8_t getFontSize(void) const;

    void setFontOutline(const int32_t fontOutline);
    void setFontOutlineDefault(void);
    int32_t getFontOutline(void) const;

    void setFontBold(const bool fontBold);
    void setFontBoldDefault(void);
    bool getFontBold(void) const;

    void setFontItalic(const bool fontItalic);
    void setFontItalicDefault(void);
    bool getFontItalic(void) const;

    void setFontUnderline(const bool fontUnderline);
    void setFontUnderlineDefault(void);
    bool getFontUnderline(void) const;

    void setFontStrikethrough(const bool fontStrikethrough);
    void setFontStrikethroughDefault(void);
    bool getFontStrikethrough(void) const;

    void setFontHinting(const int32_t fontHinting);
    void setFontHintingDefault(void);
    int32_t getFontHinting(void) const;

    void setFontKerning(const bool fontKerning);
    void setFontKerningDefault(void);
    bool getFontKerning(void) const;

    void clear(void);
private:
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
