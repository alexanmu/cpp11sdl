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

	enum GfxVGA16ColorIndex
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

	static GfxColor clrVGA16Black(void);
	static GfxColor clrVGA16Blue(void);
	static GfxColor clrVGA16Green(void);
	static GfxColor clrVGA16Cyan(void);
	static GfxColor clrVGA16Red(void);
	static GfxColor clrVGA16Magenta(void);
	static GfxColor clrVGA16Brown(void);
	static GfxColor clrVGA16LightGray(void);
	static GfxColor clrVGA16DarkGray(void);
	static GfxColor clrVGA16LightBlue(void);
	static GfxColor clrVGA16LightGreen(void);
	static GfxColor clrVGA16LightCyan(void);
	static GfxColor clrVGA16LightRed(void);
	static GfxColor clrVGA16LightMagenta(void);
	static GfxColor clrVGA16Yellow(void);
	static GfxColor clrVGA16White(void);

	static GfxColor clrVGA16GetByIndex(const GfxVGA16ColorIndex index);
private:
	static std::vector<GfxColor> colorsVGA16_;
	static std::vector<GfxColor> colorsVGA256_;
};

#endif
