//
//  GfxCanvasData.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/16/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxCanvasBgiData_h
#define GfxCanvasBgiData_h

#include <cstdint>

class GfxCanvasBgiData final
{
public:
    GfxCanvasBgiData() = delete;
    GfxCanvasBgiData(const GfxCanvasBgiData&) = delete;
    GfxCanvasBgiData(GfxCanvasBgiData&&) = delete;
    
    GfxCanvasBgiData& operator=(const GfxCanvasBgiData&) = delete;
    GfxCanvasBgiData& operator=(GfxCanvasBgiData&&) = delete;

    static constexpr int MAXCOLORS = 15;
    static constexpr int PALETTE_SIZE = 4096;
    static constexpr int GFX_FONTDATAMAX = 8 * 256;
    
    static uint32_t bgi_palette[1 + MAXCOLORS];
    static uint16_t line_patterns[1 + 4/*static_cast<int>(bgiLineStyle::USERBIT_LINE)*/];
    static uint8_t fill_patterns[1 + 12/*static_cast<int>(GfxCanvas::SDL_bgi::bgiFillStyles::USER_FILL)*/][8];
    static unsigned char gfxPrimitivesFontdata[GFX_FONTDATAMAX];
};

#endif /* GfxCanvasBgiData_h */
