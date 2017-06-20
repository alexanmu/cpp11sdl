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

#ifndef GfxRadius_hpp
#define GfxRadius_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace bgi
{

class GfxRadius final : public GfxObject
{
public:
    typedef int32_t ValueType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxRadius() noexcept;

    explicit GfxRadius(const ValueType value) noexcept;

    GfxRadius(GfxRadius const& other) noexcept;
    GfxRadius(GfxRadius&& other) noexcept;

    GfxRadius& operator=(const GfxRadius& other) noexcept;
    GfxRadius& operator=(GfxRadius&& other) noexcept;

    bool operator==(GfxRadius const& other) const noexcept;
    bool operator>(GfxRadius const& other) const noexcept;
    bool operator<(GfxRadius const& other) const noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue() const noexcept;
    void setValue(const ValueType value) noexcept;
private:
    ValueType value_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxRadius_hpp */
