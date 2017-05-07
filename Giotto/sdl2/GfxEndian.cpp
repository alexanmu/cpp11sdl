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

#include <string>
#include <cstdlib>

#include "GfxEndian.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

const std::string GfxEndian::ClassName = "GfxEndian";

GfxEndian::GfxEndian() : GfxRootClass(ClassName)
{
    // Nothing to do
}

uint16_t GfxEndian::swap16(const uint16_t x) const
{
    return sdl2::SDL_Swap16(x);
}

uint32_t GfxEndian::swap32(const uint32_t x) const
{
    return sdl2::SDL_Swap32(x);
}

uint64_t GfxEndian::swap64(const uint64_t x) const
{
    return sdl2::SDL_Swap64(x);
}

float GfxEndian::swapFloat(const float x) const
{
    return sdl2::SDL_SwapFloat(x);
}

uint16_t GfxEndian::swapLE16(const uint16_t x) const
{
    return SDL_SwapLE16(x);
}

uint32_t GfxEndian::swapLE32(const uint32_t x) const
{
    return SDL_SwapLE32(x);
}

uint64_t GfxEndian::swapLE64(const uint64_t x) const
{
    return SDL_SwapLE64(x);
}

float GfxEndian::swapFloatLE(const float x) const
{
    return SDL_SwapFloatLE(x);
}

uint16_t GfxEndian::swapBE16(const uint16_t x) const
{
    return sdl2::SDL_SwapBE16(x);
}

uint32_t GfxEndian::swapBE32(const uint32_t x) const
{
    return sdl2::SDL_SwapBE32(x);
}

uint64_t GfxEndian::swapBE64(const uint64_t x) const
{
    return sdl2::SDL_SwapBE64(x);
}

float GfxEndian::swapFloatBE(const float x) const
{
    return sdl2::SDL_SwapFloatBE(x);
}

}  // namespace gfx

/* EOF */
