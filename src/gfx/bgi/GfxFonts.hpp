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

#ifndef GfxFonts_hpp
#define GfxFonts_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxFonts final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiFonts BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        defaultFont = prv::GfxCanvasBgi::bgiFonts::DEFAULT_FONT,
        triplexFont = prv::GfxCanvasBgi::bgiFonts::TRIPLEX_FONT,
        smallFont = prv::GfxCanvasBgi::bgiFonts::SMALL_FONT,
        sanserifFont = prv::GfxCanvasBgi::bgiFonts::SANSSERIF_FONT,
        gothicFont = prv::GfxCanvasBgi::bgiFonts::GOTHIC_FONT,
        bigFont = prv::GfxCanvasBgi::bgiFonts::BIG_FONT,
        scriptFont = prv::GfxCanvasBgi::bgiFonts::SCRIPT_FONT,
        simplexFont = prv::GfxCanvasBgi::bgiFonts::SIMPLEX_FONT,
        triplexScriptFont = prv::GfxCanvasBgi::bgiFonts::TRIPLEX_SCR_FONT,
        complexFont = prv::GfxCanvasBgi::bgiFonts::COMPLEX_FONT,
        europeanFont = prv::GfxCanvasBgi::bgiFonts::EUROPEAN_FONT,
        boldFont = prv::GfxCanvasBgi::bgiFonts::BOLD_FONT
    };

    GfxFonts() noexcept;

    explicit GfxFonts(const ValueType font) noexcept;
    explicit GfxFonts(const BgiType font) noexcept;

    GfxFonts(GfxFonts const& other) noexcept;
    GfxFonts(GfxFonts&& other) noexcept;

    GfxFonts& operator=(const GfxFonts& other) noexcept;
    GfxFonts& operator=(GfxFonts&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType font) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType font_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxFonts_hpp */

