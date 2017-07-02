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

#ifndef GfxDirection_hpp
#define GfxDirection_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxDirection final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiDirection BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        horizontalDirection = prv::GfxCanvasBgi::bgiDirection::HORIZ_DIR,
        verticalDirection = prv::GfxCanvasBgi::bgiDirection::VERT_DIR
    };

    GfxDirection() noexcept;

    explicit GfxDirection(const ValueType dir) noexcept;
    explicit GfxDirection(const BgiType dir) noexcept;

    GfxDirection(GfxDirection const& other) noexcept;
    GfxDirection(GfxDirection&& other) noexcept;

    GfxDirection& operator=(const GfxDirection& other) noexcept;
    GfxDirection& operator=(GfxDirection&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType dir) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType dir_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxDirection_hpp */
