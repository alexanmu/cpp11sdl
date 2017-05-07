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

#ifndef gfxbitmapfont_hpp
#define gfxbitmapfont_hpp

#include <string>
#include <cstdint>

#include "GfxRootClass.hpp"

namespace bgi
{

class GfxBitmapFont final : public GfxRootClass
{
public:
    static const std::string ClassName;

    GfxBitmapFont();

    GfxBitmapFont(const uint8_t* fontData, const uint8_t fontWidth, const uint8_t fontHeight);

    GfxBitmapFont(const GfxBitmapFont& other);
    GfxBitmapFont(GfxBitmapFont&& other);

    virtual ~GfxBitmapFont();

    GfxBitmapFont& operator=(const GfxBitmapFont& other);
    GfxBitmapFont& operator=(GfxBitmapFont&& other);

    uint8_t* getFontData(void) const;
    uint16_t getFontDataSize(void) const;
    uint8_t getFontWidth(void) const;
    uint8_t getFontHeight(void) const;
private:
    uint8_t* fontData_;
    uint16_t fontDataSize_;
    uint8_t fontWidth_;
    uint8_t fontHeight_;
};

}  // namespace bgi

#endif  // gfxbitmapfont_hpp
