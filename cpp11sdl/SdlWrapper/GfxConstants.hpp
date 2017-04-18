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

#ifndef gfxconstants_hpp
#define gfxconstants_hpp

#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"
#include "GfxBitmapFont.hpp"

class GfxConstants final : public GfxRootClass
{
public:
	GfxConstants() = delete;
	GfxConstants(const GfxConstants&) = delete;
	GfxConstants(GfxConstants&&) = delete;

	GfxConstants& operator=(const GfxConstants&) = delete;
	GfxConstants& operator=(GfxConstants&&) = delete;

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

	static GfxColor vga16Black(void);
	static GfxColor vga16Blue(void);
	static GfxColor vga16Green(void);
	static GfxColor vga16Cyan(void);
	static GfxColor vga16Red(void);
	static GfxColor vga16Magenta(void);
	static GfxColor vga16Brown(void);
	static GfxColor vga16LightGray(void);
	static GfxColor vga16DarkGray(void);
	static GfxColor vga16LightBlue(void);
	static GfxColor vga16LightGreen(void);
	static GfxColor vga16LightCyan(void);
	static GfxColor vga16LightRed(void);
	static GfxColor vga16LightMagenta(void);
	static GfxColor vga16Yellow(void);
	static GfxColor vga16White(void);

	static GfxColor vga16GetColorByIndex(const GfxVga16ColorIndex index);
	static GfxColor vga16GetColorByIndex(const uint8_t index);

	static GfxBitmapFont std8x16Font(void);
private:
	static const std::vector<GfxColor> colorsVGA16_;
	static const uint8_t standard8x16FontBitmapData[16 * 256];
};

#endif
