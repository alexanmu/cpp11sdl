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

namespace supp
{

class GfxFontInfo final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxFontInfo();
    explicit GfxFontInfo(std::string const& fontName);

    GfxFontInfo(GfxFontInfo const& other);
    GfxFontInfo(GfxFontInfo&& other);

    GfxFontInfo& operator=(GfxFontInfo const& other);
    GfxFontInfo& operator=(GfxFontInfo&& other);

    virtual explicit operator bool() const;

    void clear(void);
private:
    std::string fontName_;
    int32_t fontOutline_;
    bool fontBold_;
    bool fontItalic_;
    bool fontUnderline_;
    bool fontStrikethrough_;
    int32_t fontHinting_;
    bool fontKerning_;
};

}  // namespace supp

}  // namespace gfx

#endif /* GfxFontInfo_hpp */
