/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#ifndef GfxBits_hpp
#define GfxBits_hpp

#include <string>
#include <cstdint>

#include "GfxObject.hpp"

namespace gfx
{

namespace bits
{

class GfxBits final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxBits() noexcept;

    GfxBits(const GfxBits& other) noexcept;
    GfxBits(GfxBits&& other) noexcept;

    GfxBits& operator=(const GfxBits& other) noexcept;
    GfxBits& operator=(GfxBits&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t mostSignificantBitIndex32(const uint32_t x) const noexcept;
};

}  // namespace bits

}  // namespace gfx

#endif /* GfxBits_hpp */
