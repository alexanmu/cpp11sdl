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

#ifndef GfxFillStyles_hpp
#define GfxFillStyles_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxFillStyles final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiFillStyles BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        emptyFill = prv::GfxCanvasBgi::bgiFillStyles::EMPTY_FILL,
        solidFill = prv::GfxCanvasBgi::bgiFillStyles::SOLID_FILL,
        lineFill = prv::GfxCanvasBgi::bgiFillStyles::LINE_FILL,
        lightSlashFill = prv::GfxCanvasBgi::bgiFillStyles::LTSLASH_FILL,
        slashFill = prv::GfxCanvasBgi::bgiFillStyles::SLASH_FILL,
        backSlashFill = prv::GfxCanvasBgi::bgiFillStyles::BKSLASH_FILL,
        lightBackSlashFill = prv::GfxCanvasBgi::bgiFillStyles::LTBKSLASH_FILL,
        hatchFill = prv::GfxCanvasBgi::bgiFillStyles::HATCH_FILL,
        xHatchFill = prv::GfxCanvasBgi::bgiFillStyles::XHATCH_FILL,
        interleaveFill = prv::GfxCanvasBgi::bgiFillStyles::INTERLEAVE_FILL,
        wideDotFill = prv::GfxCanvasBgi::bgiFillStyles::WIDE_DOT_FILL,
        closeDotFill = prv::GfxCanvasBgi::bgiFillStyles::CLOSE_DOT_FILL,
        userFill = prv::GfxCanvasBgi::bgiFillStyles::USER_FILL
    };

    GfxFillStyles() noexcept;

    explicit GfxFillStyles(const ValueType fill) noexcept;
    explicit GfxFillStyles(const BgiType fill) noexcept;

    GfxFillStyles(const GfxFillStyles& other) noexcept;
    GfxFillStyles(GfxFillStyles&& other) noexcept;

    GfxFillStyles& operator=(const GfxFillStyles& other) noexcept;
    GfxFillStyles& operator=(GfxFillStyles&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType fill) noexcept;

    bool isEmptyFill(void) const noexcept;
    bool isSolidFill(void) const noexcept;
    bool isLineFill(void) const noexcept;
    bool isLightSlashFill(void) const noexcept;
    bool isSlashFill(void) const noexcept;
    bool isBackSlashFill(void) const noexcept;
    bool isLightBackSlashFill(void) const noexcept;
    bool isHatchFill(void) const noexcept;
    bool isXHatchFill(void) const noexcept;
    bool isInterleaveFill(void) const noexcept;
    bool isWideDotFill(void) const noexcept;
    bool isCloseDotFill(void) const noexcept;
    bool isUserFill(void) const noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType fill_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxFillStyles_hpp */
