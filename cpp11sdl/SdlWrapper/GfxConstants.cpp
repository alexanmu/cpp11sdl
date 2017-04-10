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
	GfxColor clr {GfxConstants::colorsVGA16_[indexBlack]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Blue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexBlue]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Green(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexGreen]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Cyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexCyan]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Red(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexRed]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Magenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexMagenta]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Brown(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexBrown]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightGray]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16DarkGray(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexDarkGray]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightBlue(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightBlue]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightGreen(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightGreen]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightCyan(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightCyan]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightRed(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightRed]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16LightMagenta(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexLightMagenta]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16Yellow(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexYellow]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}

GfxColor GfxConstants::clrVGA16White(void)
{
	GfxColor clr {GfxConstants::colorsVGA16_[indexWhite]};

	clr.setRed(clr.getRed() << 2);
	clr.setGreen(clr.getGreen() << 2);
	clr.setBlue(clr.getBlue() << 2);
	clr.setAlpha(0xFF);

	return clr;
}
