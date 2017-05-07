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

#ifndef GfxBits_hpp
#define GfxBits_hpp

#include <string>

#include "GfxRootClass.hpp"

namespace gfx
{

class GfxBits final : public GfxRootClass
{
public:
    static const std::string ClassName;

    GfxBits();

    GfxBits(GfxBits const&) = delete;
    GfxBits(GfxBits&&) = delete;

    GfxBits& operator=(GfxBits const&) = delete;
    GfxBits& operator=(GfxBits&&) = delete;

    int mostSignificantBitIndex32(const uint32_t x) const;
};

}  // namespace gfx

#endif /* GfxBits_hpp */
