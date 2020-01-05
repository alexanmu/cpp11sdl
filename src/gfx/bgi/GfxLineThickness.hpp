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

#ifndef GfxLineThickness_hpp
#define GfxLineThickness_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxLineThickness final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiLineThickness BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        normalWidth = prv::GfxCanvasBgi::bgiLineThickness::NORM_WIDTH,
        thickWidth = prv::GfxCanvasBgi::bgiLineThickness::THICK_WIDTH
    };

    GfxLineThickness() noexcept;

    explicit GfxLineThickness(const ValueType thick) noexcept;
    explicit GfxLineThickness(const BgiType thick) noexcept;

    GfxLineThickness(const GfxLineThickness& other) noexcept;
    GfxLineThickness(GfxLineThickness&& other) noexcept;

    GfxLineThickness& operator=(const GfxLineThickness& other) noexcept;
    GfxLineThickness& operator=(GfxLineThickness&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType thick) noexcept;

    bool isNormalWidth(void) const noexcept;
    bool isThickWidth(void) const noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType thick_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxLineThickness_hpp */
