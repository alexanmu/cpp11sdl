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

    enum class ValueType : int32_t
    {
        black = prv::GfxCanvasBgi::bgiColors::BLACK,
        blue = prv::GfxCanvasBgi::bgiColors::BLUE,
        green = prv::GfxCanvasBgi::bgiColors::GREEN,
        cyan = prv::GfxCanvasBgi::bgiColors::CYAN,
        red = prv::GfxCanvasBgi::bgiColors::RED,
        magenta = prv::GfxCanvasBgi::bgiColors::MAGENTA,
        brown = prv::GfxCanvasBgi::bgiColors::BROWN,
        lightGray = prv::GfxCanvasBgi::bgiColors::LIGHTGRAY,
        darkGray = prv::GfxCanvasBgi::bgiColors::DARKGRAY,
        lightBlue = prv::GfxCanvasBgi::bgiColors::LIGHTBLUE,
        lightGreen = prv::GfxCanvasBgi::bgiColors::LIGHTGREEN,
        lightCyan = prv::GfxCanvasBgi::bgiColors::LIGHTCYAN,
        lightRed = prv::GfxCanvasBgi::bgiColors::LIGHTRED,
        lightMagenta = prv::GfxCanvasBgi::bgiColors::LIGHTMAGENTA,
        yellow = prv::GfxCanvasBgi::bgiColors::YELLOW,
        white = prv::GfxCanvasBgi::bgiColors::WHITE,
        customForeground = prv::GfxCanvasBgi::bgiColors::CUSTOM_FG,
        customBackground = prv::GfxCanvasBgi::bgiColors::CUSTOM_BG,
        customFill = prv::GfxCanvasBgi::bgiColors::CUSTOM_FILL
    };

    GfxColors2() noexcept;

    explicit GfxColors2(const ValueType clr, uint32_t argb = 0) noexcept;
    explicit GfxColors2(const BgiType clr, uint32_t argb = 0) noexcept;

    GfxColors2(GfxColors2 const& other) noexcept;
    GfxColors2(GfxColors2&& other) noexcept;

    GfxColors2& operator=(const GfxColors2& other) noexcept;
    GfxColors2& operator=(GfxColors2&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType clr) noexcept;
    uint32_t getARGB(void) const throw(std::runtime_error);
    void setARGB(const uint32_t argb) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType clr_;
    uint32_t argb_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxColors2_hpp */
