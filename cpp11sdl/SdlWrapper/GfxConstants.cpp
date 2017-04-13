#include "GfxConstants.hpp"

std::vector<GfxColor> GfxConstants::colorsVGA16_ {
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

std::vector<GfxColor> GfxConstants::colorsVGA256_ {
	{0,0,0}, // Black
	{128,0,0} // Maroon
};

GfxColor GfxConstants::clrVGA16Black(void)
{
    GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexBlack)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Blue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexBlue)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Green(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexGreen)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Cyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexCyan)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Red(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexRed)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Magenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexMagenta)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Brown(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexBrown)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightGray)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16DarkGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexDarkGray)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightBlue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightBlue)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightGreen(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightGreen)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightCyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightCyan)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightRed(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightRed)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightMagenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexLightMagenta)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Yellow(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexYellow)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16White(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(GfxVGA16ColorIndex::indexWhite)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16GetByIndex(const GfxVGA16ColorIndex index)
{
	GfxColor clr {GfxConstants::colorsVGA16_[static_cast<int>(index)]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}
