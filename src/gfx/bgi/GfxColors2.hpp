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
#include <string>

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

    static const int32_t kNumColors = 16;

    static const ValueType kColors[kNumColors];

    static constexpr const ValueType& kBlack = kColors[0];
    static constexpr const ValueType& kBlue = kColors[1];
    static constexpr const ValueType& kGreen = kColors[2];
    static constexpr const ValueType& kCyan = kColors[3];
    static constexpr const ValueType& kRed = kColors[4];
    static constexpr const ValueType& kMagenta = kColors[5];
    static constexpr const ValueType& kBrown = kColors[6];
    static constexpr const ValueType& kLightGray = kColors[7];
    static constexpr const ValueType& kDarkGray = kColors[8];
    static constexpr const ValueType& kLightBlue = kColors[9];
    static constexpr const ValueType& kLightGreen = kColors[10];
    static constexpr const ValueType& kLightCyan = kColors[11];
    static constexpr const ValueType& kLightRed = kColors[12];
    static constexpr const ValueType& kLightMagenta = kColors[13];
    static constexpr const ValueType& kYellow = kColors[14];
    static constexpr const ValueType& kWhite = kColors[15];

    GfxColors2() noexcept;

    explicit GfxColors2(const ValueType clr) noexcept;
    explicit GfxColors2(const BgiType clr) noexcept;

    GfxColors2(const GfxColors2& other) noexcept;
    GfxColors2(GfxColors2&& other) noexcept;

    GfxColors2& operator=(const GfxColors2& other) noexcept;
    GfxColors2& operator=(GfxColors2&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

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
