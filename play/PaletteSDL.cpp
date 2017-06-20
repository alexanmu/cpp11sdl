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

#include "PaletteSDL.hpp"

/***************************************************** Palette (SDL) *****************************************************/
#include <iomanip>
#include <sstream>
#include <iostream>

#include "GfxSdlHeader.hpp"

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

static void printSdlPixFormat(void * pixfmtptr)
{
    gfx::sdl2::SDL_PixelFormat* pix;

    if (pixfmtptr == nullptr)
    {
        std::cout << "pixfmtptr=nullptr" << '\n';
        return;
    }
    pix = reinterpret_cast<gfx::sdl2::SDL_PixelFormat *>(pixfmtptr);
    std::cout << "pix->format=" << IntToHexStr<uint32_t>(pix->format) << '\n';
    if (pix->palette == nullptr)
    {
        std::cout << "pix->palette=nullptr" << '\n';
    }
    else
    {
        printSdlPalette(pix->palette, true);
    }
    std::cout << "pix->BitsPerPixel=" << static_cast<int>(pix->BitsPerPixel) << '\n';
    std::cout << "pix->BytesPerPixel=" << static_cast<int>(pix->BytesPerPixel) << '\n';
    std::cout << "pix->Rmask=" << IntToHexStr<uint32_t>(pix->Rmask) << '\n';
    std::cout << "pix->Gmask=" << IntToHexStr<uint32_t>(pix->Gmask) << '\n';
    std::cout << "pix->Bmask=" << IntToHexStr<uint32_t>(pix->Bmask)<< '\n';
    std::cout << "pix->Amask=" << IntToHexStr<uint32_t>(pix->Amask) << '\n';
    std::cout << "pix->Rloss=" << IntToHexStr<uint8_t>(pix->Rloss) << '\n';
    std::cout << "pix->Gloss=" << IntToHexStr<uint8_t>(pix->Gloss) << '\n';
    std::cout << "pix->Bloss=" << IntToHexStr<uint8_t>(pix->Bloss)<< '\n';
    std::cout << "pix->Aloss=" << IntToHexStr<uint8_t>(pix->Aloss) << '\n';
    std::cout << "pix->Rshift=" << IntToHexStr<uint8_t>(pix->Rshift) << '\n';
    std::cout << "pix->Gshift=" << IntToHexStr<uint8_t>(pix->Gshift) << '\n';
    std::cout << "pix->Bshift=" << IntToHexStr<uint8_t>(pix->Bshift)<< '\n';
    std::cout << "pix->Ashift=" << IntToHexStr<uint8_t>(pix->Ashift) << '\n';
    std::cout << "pix->refcount=" << IntToHexStr<int>(pix->refcount) << '\n';
    std::cout << "pix->next=" << IntToHexStr<uint64_t>((uint64_t)pix->next) << '\n';
    std::cout << std::endl;
}

void _doPaletteSdl(void)
{
    std::cout << "TestPalette" << '\n';
    gfx::sdl2::SDL_Palette* pal;

    /* Part 1 */
    pal = gfx::sdl2::SDL_AllocPalette(2);
    printSdlPalette(pal, false);
    for (int i = 0; i < pal->ncolors; i++)
    {
        gfx::sdl2::SDL_Color c;
        c.r = i + 1;
        c.g = i + 1;
        c.b = i + 1;
        c.a = 255 - i - 1;
        SDL_SetPaletteColors(pal, &c, i, 1);
    }
    printSdlPalette(pal, false);
    /* Part 2 */
    gfx::sdl2::SDL_PixelFormat* pix;

    pix = SDL_AllocFormat(gfx::sdl2::SDL_PIXELFORMAT_RGB332);
    if (SDL_SetPixelFormatPalette(pix, pal) != 0)
    {
        std::cout << gfx::sdl2::SDL_GetError() << '\n';
    }
    printSdlPixFormat(pix);

    std::cout << "SDL_GetPixelFormatName(...)=" << gfx::sdl2::SDL_GetPixelFormatName(pix->format) << '\n';
    /* Free stuff */
    SDL_FreePalette(pal);
    SDL_FreeFormat(pix);
    std::cout << "Done!" << std::endl;
}
