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

#include "PaletteGFX.hpp"

/***************************************************** Palette (GFX) *****************************************************/
#include <iostream>
#include <cstdint>
#include <sstream>
#include <iomanip>

#include "GfxPalette.hpp"
#include "GfxPixelFormat.hpp"

// http://stackoverflow.com/questions/5100718/integer-to-hex-string-in-c
template <typename T>
static std::string IntToHexStr(T value)
{
    std::stringstream stream;

    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) <<\
            std::hex << static_cast<int>(value);
    return stream.str();
}

static void printSdlPalette(void * palptr, const bool printclrs)
{
    gfx::sdl2::SDL_Palette *pal;
    gfx::sdl2::SDL_Color* clr;

    pal = reinterpret_cast<gfx::sdl2::SDL_Palette *>(palptr);
    std::cout << "pal->ncolors=" << pal->ncolors << '\n';
    clr = pal->colors;
    if (clr == nullptr)
    {
        std::cout << "pal->colors=nullptr" << '\n';
    }
    else
    {
        if (printclrs == true)
        {
            for (int i = 0; i < pal->ncolors; i++)
            {
                std::cout << "r=" << static_cast<int>(clr->r) <<\
                        " g=" << static_cast<int>(clr->g) <<\
                        " b=" << static_cast<int>(clr->b) <<\
                        " a=" << static_cast<int>(clr->a) << '\n';
                clr += 1;
            }
        }
        else
        {
            std::cout << "pal->colors=" << IntToHexStr<uint64_t>(reinterpret_cast<uint64_t>(pal->colors)) << '\n';
        }
    }
    std::cout << "pal->version=" << pal->version << '\n';
    std::cout << "pal->refcount=" << pal->refcount << '\n';
    std::cout << std::endl;
}

void _doPaletteGfx(void)
{
    std::cout << "doPaletteGfx()" << std::endl;

    gfx::pixels::GfxPalette g1;
    gfx::pixels::GfxPalette g2(16);
    gfx::sdl2::SDL_Palette* pal = gfx::sdl2::SDL_AllocPalette(256);
    gfx::pixels::GfxPalette g3(pal);
    gfx::sdl2::SDL_FreePalette(pal);
    std::vector<gfx::pixels::GfxColor> vec { { 0xFF, 0xFE, 0xFD }, { 0xFC, 0xFB, 0xFA }, { 0xF9, 0xF8, 0xF7 }, { 0xF6, 0xF5, 0xF4} };
    gfx::pixels::GfxPalette g4(vec);
    
    printSdlPalette(g1.getAsSdlTypePtr(), false);
    printSdlPalette(g2.getAsSdlTypePtr(), false);
    printSdlPalette(g3.getAsSdlTypePtr(), true);
    printSdlPalette(g4.getAsSdlTypePtr(), false);
    
    gfx::pixels::GfxPixelFormat pf1;
    gfx::sdl2::SDL_PixelFormat* pix = gfx::sdl2::SDL_AllocFormat(gfx::sdl2::SDL_PIXELFORMAT_INDEX8);
    gfx::pixels::GfxPixelFormat pf2(pix->format);
    SDL_FreeFormat(pix);
    gfx::pixels::GfxPixelFormat pf3(static_cast<gfx::pixels::GfxPixelFormatEnum>(gfx::sdl2::SDL_PIXELFORMAT_RGB24));
    
    std::cout << "pf1.getFormatAsString()=" << pf1.getPixelFormatName() << '\n';
    std::cout << "pf2.getFormatAsString()=" << pf2.getPixelFormatName() << '\n';
    std::cout << "pf3.getFormatAsString()=" << pf3.getPixelFormatName() << '\n';
    std::cout << "SDL_GetPixelFormatName(...)=" << gfx::sdl2::SDL_GetPixelFormatName(gfx::sdl2::SDL_PIXELFORMAT_INDEX8) << '\n';
}
