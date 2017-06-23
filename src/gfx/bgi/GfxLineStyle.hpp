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

#ifndef GfxLineStyle_hpp
#define GfxLineStyle_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxLineStyle final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiLineStyle BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        solidLine = prv::GfxCanvasBgi::bgiLineStyle::SOLID_LINE,
        dottedLine = prv::GfxCanvasBgi::bgiLineStyle::DOTTED_LINE,
        centerLine = prv::GfxCanvasBgi::bgiLineStyle::CENTER_LINE,
        dashedLine = prv::GfxCanvasBgi::bgiLineStyle::DASHED_LINE,
        userbitLine = prv::GfxCanvasBgi::bgiLineStyle::USERBIT_LINE
    };

    GfxLineStyle() noexcept;

    explicit GfxLineStyle(const ValueType line) noexcept;
    explicit GfxLineStyle(const BgiType line) noexcept;

    GfxLineStyle(GfxLineStyle const& other) noexcept;
    GfxLineStyle(GfxLineStyle&& other) noexcept;

    GfxLineStyle& operator=(const GfxLineStyle& other) noexcept;
    GfxLineStyle& operator=(GfxLineStyle&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType line) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType line_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxLineStyle_hpp */
