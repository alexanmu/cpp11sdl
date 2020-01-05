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

#include <cstdint>
#include <string>

#include "GfxBgiConstants.hpp"
#include "GfxColor.hpp"
#include "GfxBitmapFont.hpp"

#include "fntStandard8x16.hpp"
#include "fntAntique.hpp"
#include "fntBroadway.hpp"
#include "fntCourrier.hpp"
#include "fntDragon.hpp"
#include "fntMedieval.hpp"
#include "fntRoman.hpp"
#include "fntSansserif.hpp"
#include "fntScript.hpp"
#include "fntWacky.hpp"

namespace gfx
{

namespace bgi
{

const pixels::GfxColor kColorsVGA16_[kNumColors] {
    {0x00 << 2, 0x00 << 2, 0x00 << 2, 0xFF},
    {0x00 << 2, 0x00 << 2, 0x28 << 2, 0xFF},
    {0x00 << 2, 0x28 << 2, 0x00 << 2, 0xFF},
    {0x00 << 2, 0x28 << 2, 0x28 << 2, 0xFF},
    {0x28 << 2, 0x07 << 2, 0x07 << 2, 0xFF},
    {0x28 << 2, 0x00 << 2, 0x28 << 2, 0xFF},
    {0x28 << 2, 0x1E << 2, 0x00 << 2, 0xFF},
    {0x2C << 2, 0x2C << 2, 0x2C << 2, 0xFF},
    {0x1A << 2, 0x1A << 2, 0x1A << 2, 0xFF},
    {0x00 << 2, 0x00 << 2, 0x3F << 2, 0xFF},
    {0x09 << 2, 0x3F << 2, 0x09 << 2, 0xFF},
    {0x00 << 2, 0x3F << 2, 0x3F << 2, 0xFF},
    {0x3F << 2, 0x0A << 2, 0x0A << 2, 0xFF},
    {0x2C << 2, 0x00 << 2, 0x3F << 2, 0xFF},
    {0x3F << 2, 0x3F << 2, 0x12 << 2, 0xFF},
    {0x3F << 2, 0x3F << 2, 0x3F << 2, 0xFF}
};

const pixels::GfxColor& kColorBlack(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexBlack)];
}

const pixels::GfxColor& kColorBlue(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexBlue)];
}

const pixels::GfxColor& kColorGreen(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexGreen)];
}

const pixels::GfxColor& kColorCyan(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexCyan)];
}

const pixels::GfxColor& kColorRed(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexRed)];
}

const pixels::GfxColor& kColorMagenta(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexMagenta)];
}

const pixels::GfxColor& kColorBrown(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexBrown)];
}

const pixels::GfxColor& kColorLightGray(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightGray)];
}

const pixels::GfxColor& kColorDarkGray(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexDarkGray)];
}

const pixels::GfxColor& kColorLightBlue(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightBlue)];
}

const pixels::GfxColor& kColorLightGreen(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightGreen)];
}

const pixels::GfxColor& kColorLightCyan(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightCyan)];
}

const pixels::GfxColor& kColorLightRed(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightRed)];
}

const pixels::GfxColor& kColorLightMagenta(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexLightMagenta)];
}

const pixels::GfxColor& kColorYellow(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexYellow)];
}

const pixels::GfxColor& kColorWhite(void)
{
    return kColorsVGA16_[static_cast<int32_t>(GfxColorIndex::indexWhite)];
}

const pixels::GfxColor& kGetColorByIndex(const GfxColorIndex index)
{
    return kColorsVGA16_[static_cast<int32_t>(index)];
}

namespace fnt
{

static const GfxBitmapFont fonts_[kNumFonts] {
    { &prv::fntStandard8x16Data_[0], 8, 16 },
    { &prv::fntAntiqueData_[0], 8, 16 },
    { &prv::fntBroadwayData_[0], 8, 16 },
    { &prv::fntCourrierData_[0], 8, 16 },
    { &prv::fntDragonData_[0], 8, 16 },
    { &prv::fntMedievalData_[0], 8, 16 },
    { &prv::fntRomanData_[0], 8, 16 },
    { &prv::fntSansserifData_[0], 8, 16 },
    { &prv::fntScriptData_[0], 8, 16 },
    { &prv::fntWackyData_[0], 8, 16 }
};

const GfxBitmapFont& kFontStandard8x16(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexStandard8x16)];
}

const GfxBitmapFont& kFontAntique(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexAntique)];
}

const GfxBitmapFont& kFontBroadway(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexBroadway)];
}

const GfxBitmapFont& kFontCourrier(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexCourrier)];
}

const GfxBitmapFont& kFontDragon(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexDragon)];
}

const GfxBitmapFont& kFontMedieval(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexMedieval)];
}

const GfxBitmapFont& kFontRoman(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexRoman)];
}

const GfxBitmapFont& kFontSansserif(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexSansserif)];
}

const GfxBitmapFont& kFontScript(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexScript)];
}

const GfxBitmapFont& kFontWacky(void)
{
    return fonts_[static_cast<int>(GfxFontIndex::indexWacky)];
}

const GfxBitmapFont& kGetFontByIndex(const GfxFontIndex index)
{
    return fonts_[static_cast<int>(index)];
}

}  // namespace fnt

}  // namespace bgi

}  // namespace gfx

/* EOF */
