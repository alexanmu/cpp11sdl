/*
  CPP11SDL
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

const std::vector<GfxColor> GfxConstants::colorsVGA16_ {
    {0x00,0x00,0x00},
    {0x00,0x00,0x28},
    {0x00,0x28,0x00},
    {0x00,0x28,0x28},
    {0x28,0x07,0x07},
    {0x28,0x00,0x28},
    {0x28,0x1E,0x00},
    {0x2C,0x2C,0x2C},
    {0x1A,0x1A,0x1A},
    {0x00,0x00,0x3F},
    {0x09,0x3F,0x09},
    {0x00,0x3F,0x3F},
    {0x3F,0x0A,0x0A},
    {0x2C,0x00,0x3F},
    {0x3F,0x3F,0x12},
    {0x3F,0x3F,0x3F}
};

GfxColor GfxConstants::vga16Black(void)
{
    GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBlack)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Blue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBlue)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Green(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexGreen)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Cyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexCyan)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Red(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexRed)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Magenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexMagenta)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Brown(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexBrown)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightGray)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16DarkGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexDarkGray)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightBlue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightBlue)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightGreen(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightGreen)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightCyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightCyan)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightRed(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightRed)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16LightMagenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexLightMagenta)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16Yellow(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexYellow)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16White(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVga16ColorIndex::indexWhite)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::vga16GetColorByIndex(const GfxVga16ColorIndex index)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(index)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxBitmapFont GfxConstants::fntStandard8x16(void)
{
    return GfxBitmapFont(&fntStandard8x16Data[0],8,16);
}

GfxBitmapFont GfxConstants::fntAntique(void)
{
    return GfxBitmapFont(&fntAntiqueData[0],8,16);
}

GfxBitmapFont GfxConstants::fntBroadway(void)
{
    return GfxBitmapFont(&fntBroadwayData[0],8,16);
}

GfxBitmapFont GfxConstants::fntCourrier(void)
{
    return GfxBitmapFont(&fntCourrierData[0],8,16);
}

GfxBitmapFont GfxConstants::fntDragon(void)
{
    return GfxBitmapFont(&fntDragonData[0],8,16);
}

GfxBitmapFont GfxConstants::fntMedieval(void)
{
    return GfxBitmapFont(&fntMedievalData[0],8,16);
}

GfxBitmapFont GfxConstants::fntRoman(void)
{
    return GfxBitmapFont(&fntRomanData[0],8,16);
}

GfxBitmapFont GfxConstants::fntSansserif(void)
{
    return GfxBitmapFont(&fntSansserifData[0],8,16);
}

GfxBitmapFont GfxConstants::fntScript(void)
{
    return GfxBitmapFont(&fntScriptData[0],8,16);
}

GfxBitmapFont GfxConstants::fntWacky(void)
{
    return GfxBitmapFont(&fntWackyData[0],8,16);
}

GfxBitmapFont GfxConstants::fntGetFontByIndex(const GfxFontIndex index)
{
    switch (index)
    {
        case GfxConstants::GfxFontIndex::indexStandard8x16:
            return fntStandard8x16();
            break;
        case GfxConstants::GfxFontIndex::indexAntique:
            return fntAntique();
            break; 
        case GfxConstants::GfxFontIndex::indexBroadway:
            return fntBroadway();
            break;
        case GfxConstants::GfxFontIndex::indexCourrier:
            return fntCourrier();
            break;
        case GfxConstants::GfxFontIndex::intdexDragon:
            return fntDragon();
            break;
        case GfxConstants::GfxFontIndex::indexMedieval:
            return fntMedieval();
            break;
        case GfxConstants::GfxFontIndex::indexRoman:
            return fntRoman();
            break;
        case GfxConstants::GfxFontIndex::indexSansserif:
            return fntSansserif();
            break;
        case GfxConstants::GfxFontIndex::indexScript:
            return fntScript();
            break;
        case GfxConstants::GfxFontIndex::indexWacky:
            return fntWacky();
            break;
    }
    /* Should never reach this point; avoid wrong gcc warning */
    return fntStandard8x16();
}