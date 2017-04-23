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

#ifndef GfxBgiConstants_hpp
#define GfxBgiConstants_hpp

#include "GfxRootClass.hpp"
#include "GfxColor.hpp"
#include "GfxBitmapFont.hpp"

class GfxBgiConstants final : public GfxRootClass
{
public:
	GfxBgiConstants() = delete;
	GfxBgiConstants(const GfxBgiConstants&) = delete;
	GfxBgiConstants(GfxBgiConstants&&) = delete;

	GfxBgiConstants& operator=(const GfxBgiConstants&) = delete;
	GfxBgiConstants& operator=(GfxBgiConstants&&) = delete;

	static const int vgaNumColors = 16;

    enum class GfxVga16ColorIndex : int
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

	static const int fntNumFonts = 10;

	enum class GfxFontIndex : int
	{
		indexStandard8x16 = 0,
		indexAntique = 1,
		indexBroadway = 2,
		indexCourrier = 3,
		intdexDragon = 4,
		indexMedieval = 5,
		indexRoman = 6,
		indexSansserif = 7,
		indexScript = 8,
		indexWacky = 9
	};

	static const GfxColor& vgaBlack(void);
	static const GfxColor& vgaBlue(void);
	static const GfxColor& vgaGreen(void);
	static const GfxColor& vgaCyan(void);
	static const GfxColor& vgaRed(void);
	static const GfxColor& vgaMagenta(void);
	static const GfxColor& vgaBrown(void);
	static const GfxColor& vgaLightGray(void);
	static const GfxColor& vgaDarkGray(void);
	static const GfxColor& vgaLightBlue(void);
	static const GfxColor& vgaLightGreen(void);
	static const GfxColor& vgaLightCyan(void);
	static const GfxColor& vgaLightRed(void);
	static const GfxColor& vgaLightMagenta(void);
	static const GfxColor& vgaYellow(void);
	static const GfxColor& vgaWhite(void);

	static const GfxColor& vgaGetColorByIndex(const GfxVga16ColorIndex index);

	static const GfxBitmapFont& fntStandard8x16(void);
	static const GfxBitmapFont& fntAntique(void);
	static const GfxBitmapFont& fntBroadway(void);
	static const GfxBitmapFont& fntCourrier(void);
	static const GfxBitmapFont& fntDragon(void);
	static const GfxBitmapFont& fntMedieval(void);
	static const GfxBitmapFont& fntRoman(void);
	static const GfxBitmapFont& fntSansserif(void);
	static const GfxBitmapFont& fntScript(void);
	static const GfxBitmapFont& fntWacky(void);

	static const GfxBitmapFont& fntGetFontByIndex(const GfxFontIndex index);
private:
	static const GfxColor colorsVGA16_[vgaNumColors];
    static const GfxBitmapFont fonts_[fntNumFonts];

	static const uint8_t fntStandard8x16Data_[16 * 256];
	static const uint8_t fntAntiqueData_[16 * 256];
	static const uint8_t fntBroadwayData_[16 * 256];
	static const uint8_t fntCourrierData_[16 * 256];
	static const uint8_t fntDragonData_[16 * 256];
	static const uint8_t fntMedievalData_[16 * 256];
	static const uint8_t fntRomanData_[16 * 256];
	static const uint8_t fntSansserifData_[16 * 256];
	static const uint8_t fntScriptData_[16 * 256];
	static const uint8_t fntWackyData_[16 * 256];
};

#endif
