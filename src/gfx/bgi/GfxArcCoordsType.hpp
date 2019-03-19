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

#ifndef GfxArcCoordsType_hpp
#define GfxArcCoordsType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxArcCoordsType final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::arccoordstype BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxArcCoordsType() noexcept;

    explicit GfxArcCoordsType(const BgiType arccoords) noexcept;

    GfxArcCoordsType(const GfxArcCoordsType& other) noexcept;
    GfxArcCoordsType(GfxArcCoordsType&& other) noexcept;

    GfxArcCoordsType& operator=(const GfxArcCoordsType& other) noexcept;
    GfxArcCoordsType& operator=(GfxArcCoordsType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t getX(void) const noexcept;
    int32_t getY(void) const noexcept;
    int32_t getXStart(void) const noexcept;
    int32_t getYStart(void) const noexcept;
    int32_t getXEnd(void) const noexcept;
    int32_t getYEnd(void) const noexcept;
    void setValue(const BgiType arccoords) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType arccoords_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxArcCoordsType_hpp */
