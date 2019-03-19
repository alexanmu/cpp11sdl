/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include <string>
#include <cstdint>

#include "GfxObject.hpp"

namespace gfx
{

namespace endian
{

class GfxEndian final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxEndian() noexcept;

    GfxEndian(const GfxEndian& other) noexcept;
    GfxEndian(GfxEndian&& other) noexcept;

    GfxEndian& operator=(const GfxEndian& other) noexcept;
    GfxEndian& operator=(GfxEndian&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    /* Methods */
    uint16_t swap16(const uint16_t x) const noexcept;
    uint32_t swap32(const uint32_t x) const noexcept;
    uint64_t swap64(const uint64_t x) const noexcept;
    float swapFloat(const float x) const noexcept;

    uint16_t swapLE16(const uint16_t x) const noexcept;
    uint32_t swapLE32(const uint32_t x) const noexcept;
    uint64_t swapLE64(const uint64_t x) const noexcept;
    float swapFloatLE(const float x) const noexcept;
    uint16_t swapBE16(const uint16_t x) const noexcept;
    uint32_t swapBE32(const uint32_t x) const noexcept;
    uint64_t swapBE64(const uint64_t x) const noexcept;
    float swapFloatBE(const float x) const noexcept;
};

}  // namespace endian

}  // namespace gfx

#endif /* GfxEndian_hpp */
