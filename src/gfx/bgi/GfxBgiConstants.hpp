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

#ifndef GfxBgiConstants_hpp
#define GfxBgiConstants_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxColor.hpp"
#include "GfxBitmapFont.hpp"

namespace gfx
{

namespace bgi
{

static const int32_t kNumColors = 16;

enum class GfxColorIndex : int32_t
{
    indexBlack = 0,
    indexBlue = 1,
    indexGreen = 2,
    indexCyan = 3,
    indexRed = 4,
    indexMagenta = 5,
    indexBrown = 6,
    indexLightGray = 7,
    indexDarkGray = 8,
    indexLightBlue = 9,
    indexLightGreen = 10,
    indexLightCyan = 11,
    indexLightRed = 12,
    indexLightMagenta = 13,
    indexYellow = 14,
    indexWhite = 15
};

const pixels::GfxColor& kColorBlack(void);
const pixels::GfxColor& kColorBlue(void);
const pixels::GfxColor& kColorGreen(void);
const pixels::GfxColor& kColorCyan(void);
const pixels::GfxColor& kColorRed(void);
const pixels::GfxColor& kColorMagenta(void);
const pixels::GfxColor& kColorBrown(void);
const pixels::GfxColor& kColorLightGray(void);
const pixels::GfxColor& kColorDarkGray(void);
const pixels::GfxColor& kColorLightBlue(void);
const pixels::GfxColor& kColorLightGreen(void);
const pixels::GfxColor& kColorLightCyan(void);
const pixels::GfxColor& kColorLightRed(void);
const pixels::GfxColor& kColorLightMagenta(void);
const pixels::GfxColor& kColorYellow(void);
const pixels::GfxColor& kColorWhite(void);

const pixels::GfxColor& kGetColorByIndex(const GfxColorIndex index);

namespace fnt
{

static const int32_t kNumFonts = 10;

enum class GfxFontIndex : int32_t
{
    indexStandard8x16 = 0,
    indexAntique = 1,
    indexBroadway = 2,
    indexCourrier = 3,
    indexDragon = 4,
    indexMedieval = 5,
    indexRoman = 6,
    indexSansserif = 7,
    indexScript = 8,
    indexWacky = 9
};

const GfxBitmapFont& kFontStandard8x16(void);
const GfxBitmapFont& kFontAntique(void);
const GfxBitmapFont& kFontBroadway(void);
const GfxBitmapFont& kFontCourrier(void);
const GfxBitmapFont& kFontDragon(void);
const GfxBitmapFont& kFontMedieval(void);
const GfxBitmapFont& kFontRoman(void);
const GfxBitmapFont& kFontSansserif(void);
const GfxBitmapFont& kFontScript(void);
const GfxBitmapFont& kFontWacky(void);

const GfxBitmapFont& kGetFontByIndex(const GfxFontIndex index);

}  // namespace fnt

}  // namespace bgi

}  // namespace gfx

#endif
