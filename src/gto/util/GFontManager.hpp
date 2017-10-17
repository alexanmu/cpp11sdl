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

#ifndef GFontManager_hpp
#define GFontManager_hpp

#include <string>
#include <vector>

#include "GObject.hpp"
#include "GfxTtfFont.hpp"

namespace gto
{

namespace util
{

// Not really a FontManager; just a file list. Maybe later ...
class GFontManager : public gobj::GObject
{
public:
    GFontManager() = delete;

    GFontManager(GFontManager const&) = delete;
    GFontManager(GFontManager&&) = delete;

    GFontManager& operator=(GFontManager const&) = delete;
    GFontManager& operator=(GFontManager&&) = delete;

    explicit GFontManager(std::string const& fontsFolder) noexcept;
    virtual ~GFontManager() noexcept;

    void loadFonts(void) noexcept;
    gfx::ttf::GfxTtfFont * getFont(std::string const& fontName, const int pointSize) const noexcept;
    void freeFont(gfx::ttf::GfxTtfFont * font) const noexcept;
private:
    std::string getFileNameByFontName(std::string const& fontName) const noexcept;

    std::string fontsFolder_;
    std::vector<std::string> fontFiles_;

    static const char kDefaultFontName[];
    static const char kDefaultFontFileExtension[];
};

}  // namespace util

}  // namespace gto

#endif /* GFontManager_hpp */
