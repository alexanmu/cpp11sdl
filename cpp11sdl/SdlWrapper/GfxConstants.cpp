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

GfxColor GfxConstants::vga16GetColorByIndex(const int index)
{
	return vga16GetColorByIndex(static_cast<GfxVga16ColorIndex>(index));
}
