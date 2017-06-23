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

#ifndef GfxTextJustification_hpp
#define GfxTextJustification_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxTextJustification final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiTextJustification BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        leftText = prv::GfxCanvasBgi::bgiTextJustification::LEFT_TEXT,
        centerText = prv::GfxCanvasBgi::bgiTextJustification::CENTER_TEXT,
        rightText = prv::GfxCanvasBgi::bgiTextJustification::RIGHT_TEXT,
        bottomText = prv::GfxCanvasBgi::bgiTextJustification::BOTTOM_TEXT,
        topText = prv::GfxCanvasBgi::bgiTextJustification::TOP_TEXT
    };

    GfxTextJustification() noexcept;

    explicit GfxTextJustification(const ValueType just) noexcept;
    explicit GfxTextJustification(const BgiType just) noexcept;

    GfxTextJustification(GfxTextJustification const& other) noexcept;
    GfxTextJustification(GfxTextJustification&& other) noexcept;

    GfxTextJustification& operator=(const GfxTextJustification& other) noexcept;
    GfxTextJustification& operator=(GfxTextJustification&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType just) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType just_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxTextJustification_hpp */
