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

#ifndef GfxEndian_hpp
#define GfxEndian_hpp

#include <cstdlib>

#include "GfxRootClass.hpp"

class GfxEndian final : public GfxRootClass
{
public:
    GfxEndian();

    GfxEndian(GfxEndian const&) = delete;
    GfxEndian(GfxEndian&&) = delete;

    GfxEndian& operator=(GfxEndian const&) = delete;
    GfxEndian& operator=(GfxEndian&&) = delete;

    /* Methods */
    uint16_t swap16(const uint16_t x) const;
    uint32_t swap32(const uint32_t x) const;
    uint64_t swap64(const uint64_t x) const;
    float swapFloat(const float x) const;

    uint16_t swapLE16(const uint16_t x) const;
    uint32_t swapLE32(const uint32_t x) const;
    uint64_t swapLE64(const uint64_t x) const;
    float swapFloatLE(const float x) const;
    uint16_t swapBE16(const uint16_t x) const;
    uint32_t swapBE32(const uint32_t x) const;
    uint64_t swapBE64(const uint64_t x) const;
    float swapFloatBE(const float x) const;
};

#endif /* GfxEndian_hpp */
