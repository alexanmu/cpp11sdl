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

  Portions of this code are based on SDL_bgi. See http://libxgi.sourceforge.net/
*/

#ifndef GfxCanvasBgiData_h
#define GfxCanvasBgiData_h

#include <cstdint>

#include "GfxRootClass.hpp"

class GfxCanvasBgiData final : public GfxRootClass
{
public:
    GfxCanvasBgiData() = delete;

    GfxCanvasBgiData(const GfxCanvasBgiData&) = delete;
    GfxCanvasBgiData(GfxCanvasBgiData&&) = delete;

    GfxCanvasBgiData& operator=(const GfxCanvasBgiData&) = delete;
    GfxCanvasBgiData& operator=(GfxCanvasBgiData&&) = delete;

    static constexpr int kMaxColors = 15;
    static constexpr int kGfxFontDataMax = 8 * 256;

    static const uint32_t bgi_palette[1 + kMaxColors];
    static /*const*/ uint16_t line_patterns[1 + 4/*static_cast<int>(GfxCanvasBgi::bgiLineStyle::USERBIT_LINE)*/];
    static /*const*/ uint8_t fill_patterns[1 + 12/*static_cast<int>(GfxCanvasBgi::bgiFillStyles::USER_FILL)*/][8];
    static const uint8_t gfxPrimitivesFontdata[kGfxFontDataMax];
};

#endif /* GfxCanvasBgiData_h */
