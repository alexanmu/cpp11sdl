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

#include "GfxConstants.hpp"

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

const GfxColor GfxConstants::colorsVGA16_[16] {
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

const GfxBitmapFont GfxConstants::fonts_[10] {
    { &fntStandard8x16Data_[0],8,16 },
    { &fntAntiqueData_[0],8,16 },
    { &fntBroadwayData_[0],8,16 },
    { &fntCourrierData_[0],8,16 },
    { &fntDragonData_[0],8,16 },
    { &fntMedievalData_[0],8,16 },
    { &fntRomanData_[0],8,16 },
    { &fntSansserifData_[0],8,16 },
    { &fntScriptData_[0],8,16 },
    { &fntWackyData_[0],8,16 }
};

const GfxColor& GfxConstants::vgaBlack(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBlack)];
}

const GfxColor& GfxConstants::vgaBlue(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBlue)];
}

const GfxColor& GfxConstants::vgaGreen(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexGreen)];
}

const GfxColor& GfxConstants::vgaCyan(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexCyan)];
}

const GfxColor& GfxConstants::vgaRed(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexRed)];
}

const GfxColor& GfxConstants::vgaMagenta(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexMagenta)];
}

const GfxColor& GfxConstants::vgaBrown(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBrown)];
}

const GfxColor& GfxConstants::vgaLightGray(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightGray)];
}

const GfxColor& GfxConstants::vgaDarkGray(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexDarkGray)];
}

const GfxColor& GfxConstants::vgaLightBlue(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightBlue)];
}

const GfxColor& GfxConstants::vgaLightGreen(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightGreen)];
}

const GfxColor& GfxConstants::vgaLightCyan(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightCyan)];
}

const GfxColor& GfxConstants::vgaLightRed(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightRed)];
}

const GfxColor& GfxConstants::vgaLightMagenta(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightMagenta)];
}

const GfxColor& GfxConstants::vgaYellow(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexYellow)];
}

const GfxColor& GfxConstants::vgaWhite(void)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexWhite)];
}

const GfxColor& GfxConstants::vgaGetColorByIndex(const GfxVga16ColorIndex index)
{
	return GfxConstants::colorsVGA16_[static_cast<int>(index)];
}

const GfxBitmapFont& GfxConstants::fntStandard8x16(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexStandard8x16)];
}

const GfxBitmapFont& GfxConstants::fntAntique(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexAntique)];
}

const GfxBitmapFont& GfxConstants::fntBroadway(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexBroadway)];
}

const GfxBitmapFont& GfxConstants::fntCourrier(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexCourrier)];
}

const GfxBitmapFont& GfxConstants::fntDragon(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::intdexDragon)];
}

const GfxBitmapFont& GfxConstants::fntMedieval(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexMedieval)];
}

const GfxBitmapFont& GfxConstants::fntRoman(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexRoman)];
}

const GfxBitmapFont& GfxConstants::fntSansserif(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexSansserif)];
}

const GfxBitmapFont& GfxConstants::fntScript(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexScript)];
}

const GfxBitmapFont& GfxConstants::fntWacky(void)
{
    return GfxConstants::fonts_[static_cast<int>(GfxFontIndex::indexWacky)];
}

const GfxBitmapFont& GfxConstants::fntGetFontByIndex(const GfxFontIndex index)
{
    return GfxConstants::fonts_[static_cast<int>(index)];
}
