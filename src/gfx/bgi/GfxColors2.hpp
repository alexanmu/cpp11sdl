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

#ifndef GfxColors2_hpp
#define GfxColors2_hpp

#include <stdexcept>
#include <cstdint>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxBgiConstants.hpp"

namespace gfx
{

namespace bgi
{

class GfxColors2 final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiColors BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    typedef uint32_t ValueType;

    static const uint32_t black = 0xff000000;
    static const uint32_t blue = 0xff0000ff;
    static const uint32_t green = 0xff00ff00;
    static const uint32_t cyan = 0xff00ffff;
    static const uint32_t red = 0xffff0000;
    static const uint32_t magenta = 0xffff00ff;
    static const uint32_t brown = 0xffa52a2a;
    static const uint32_t lightGray = 0xffd3d3d3;
    static const uint32_t darkGray = 0xffa9a9a9;
    static const uint32_t lightBlue = 0xffadd8e6;
    static const uint32_t lightGreen = 0xff90ee90;
    static const uint32_t lightCyan = 0xffe0ffff;
    static const uint32_t lightRed = 0xfff08080;
    static const uint32_t lightMagenta = 0xffdb7093;
    static const uint32_t yellow = 0xffffff00;
    static const uint32_t white = 0xffffffff;

    static const int32_t numColors = 16;

    GfxColors2() noexcept;

    explicit GfxColors2(const ValueType clr) noexcept;
    explicit GfxColors2(const BgiType clr) noexcept;

    GfxColors2(GfxColors2 const& other) noexcept;
    GfxColors2(GfxColors2&& other) noexcept;

    GfxColors2& operator=(const GfxColors2& other) noexcept;
    GfxColors2& operator=(GfxColors2&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType clr) noexcept;

    bool isCustomColor(void) const noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    bool isBgiColor(void) const noexcept;
    BgiType getBgiColor(void) const noexcept;

    ValueType clr_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxColors2_hpp */
