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

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

namespace gfx
{

namespace bgi
{

class GfxBgiConstants final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxBgiConstants() = delete;

    GfxBgiConstants(const GfxBgiConstants&) = delete;
    GfxBgiConstants(GfxBgiConstants&&) = delete;

    GfxBgiConstants& operator=(const GfxBgiConstants&) = delete;
    GfxBgiConstants& operator=(GfxBgiConstants&&) = delete;

    static const int32_t kVgaNumColors = 16;

    enum class GfxVga16ColorIndex : int32_t
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

    static const pixels::GfxColor& vgaBlack(void);
    static const pixels::GfxColor& vgaBlue(void);
    static const pixels::GfxColor& vgaGreen(void);
    static const pixels::GfxColor& vgaCyan(void);
    static const pixels::GfxColor& vgaRed(void);
    static const pixels::GfxColor& vgaMagenta(void);
    static const pixels::GfxColor& vgaBrown(void);
    static const pixels::GfxColor& vgaLightGray(void);
    static const pixels::GfxColor& vgaDarkGray(void);
    static const pixels::GfxColor& vgaLightBlue(void);
    static const pixels::GfxColor& vgaLightGreen(void);
    static const pixels::GfxColor& vgaLightCyan(void);
    static const pixels::GfxColor& vgaLightRed(void);
    static const pixels::GfxColor& vgaLightMagenta(void);
    static const pixels::GfxColor& vgaYellow(void);
    static const pixels::GfxColor& vgaWhite(void);

    static const pixels::GfxColor& vgaGetColorByIndex(const GfxVga16ColorIndex index);
private:
    static const pixels::GfxColor kColorsVGA16_[kVgaNumColors];
};

}  // namespace bgi

}  // namespace gfx

#endif
