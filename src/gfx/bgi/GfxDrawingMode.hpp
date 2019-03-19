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

#ifndef GfxDrawingMode_hpp
#define GfxDrawingMode_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"

namespace gfx
{

namespace bgi
{

class GfxDrawingMode final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::bgiDrawingMode BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        copyPut = prv::GfxCanvasBgi::bgiDrawingMode::COPY_PUT,
        xorPut = prv::GfxCanvasBgi::bgiDrawingMode::XOR_PUT,
        orPut = prv::GfxCanvasBgi::bgiDrawingMode::OR_PUT,
        andPut = prv::GfxCanvasBgi::bgiDrawingMode::AND_PUT,
        notPut = prv::GfxCanvasBgi::bgiDrawingMode::NOT_PUT
    };

    GfxDrawingMode() noexcept;

    explicit GfxDrawingMode(const ValueType dmode) noexcept;
    explicit GfxDrawingMode(const BgiType dmode) noexcept;

    GfxDrawingMode(const GfxDrawingMode& other) noexcept;
    GfxDrawingMode(GfxDrawingMode&& other) noexcept;

    GfxDrawingMode& operator=(const GfxDrawingMode& other) noexcept;
    GfxDrawingMode& operator=(GfxDrawingMode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    void setValue(const ValueType dmode) noexcept;

    bool isCopyPut(void) const noexcept;
    bool isXorPut(void) const noexcept;
    bool isOrPut(void) const noexcept;
    bool isAndPut(void) const noexcept;
    bool isNotPut(void) const noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType dmode_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxDrawingMode_hpp */
