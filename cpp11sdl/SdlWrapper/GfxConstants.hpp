#ifndef gfxconstants_hpp
#define gfxconstants_hpp

#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

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
	static GfxColor vga16GetColorByIndex(const int index);
private:
	static std::vector<GfxColor> colorsVGA16_;
	static std::vector<GfxColor> colorsVGA256_;
};

#endif
