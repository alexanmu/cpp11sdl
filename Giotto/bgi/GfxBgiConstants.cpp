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

#include <cstdint>
#include <string>

#include "GfxColor.hpp"
#include "GfxBgiConstants.hpp"

namespace gfx
{
namespace bgi
{

const char GfxBgiConstants::ClassName[] = "GfxBgiConstants";

const GfxColor GfxBgiConstants::colorsVGA16_[16] {
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

const GfxColor& GfxBgiConstants::vgaBlack(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexBlack)];
}

const GfxColor& GfxBgiConstants::vgaBlue(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexBlue)];
}

const GfxColor& GfxBgiConstants::vgaGreen(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexGreen)];
}

const GfxColor& GfxBgiConstants::vgaCyan(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexCyan)];
}

const GfxColor& GfxBgiConstants::vgaRed(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexRed)];
}

const GfxColor& GfxBgiConstants::vgaMagenta(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexMagenta)];
}

const GfxColor& GfxBgiConstants::vgaBrown(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexBrown)];
}

const GfxColor& GfxBgiConstants::vgaLightGray(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightGray)];
}

const GfxColor& GfxBgiConstants::vgaDarkGray(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexDarkGray)];
}

const GfxColor& GfxBgiConstants::vgaLightBlue(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightBlue)];
}

const GfxColor& GfxBgiConstants::vgaLightGreen(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightGreen)];
}

const GfxColor& GfxBgiConstants::vgaLightCyan(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightCyan)];
}

const GfxColor& GfxBgiConstants::vgaLightRed(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightRed)];
}

const GfxColor& GfxBgiConstants::vgaLightMagenta(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexLightMagenta)];
}

const GfxColor& GfxBgiConstants::vgaYellow(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexYellow)];
}

const GfxColor& GfxBgiConstants::vgaWhite(void)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(GfxVga16ColorIndex::indexWhite)];
}

const GfxColor& GfxBgiConstants::vgaGetColorByIndex(const GfxVga16ColorIndex index)
{
    return GfxBgiConstants::colorsVGA16_[static_cast<int32_t>(index)];
}

}  // namespace bgi
}  // namespace gfx

/* EOF */
