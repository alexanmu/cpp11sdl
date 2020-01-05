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

#ifndef GfxAngle_hpp
#define GfxAngle_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace bgi
{

class GfxAngle final : public GfxObject
{
public:
    typedef int32_t BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxAngle() noexcept;

    explicit GfxAngle(const BgiType value) noexcept;

    GfxAngle(const GfxAngle& other) noexcept;
    GfxAngle(GfxAngle&& other) noexcept;

    GfxAngle& operator=(const GfxAngle& other) noexcept;
    GfxAngle& operator=(GfxAngle&& other) noexcept;

    bool operator==(const GfxAngle& other) const noexcept;
    bool operator>(const GfxAngle& other) const noexcept;
    bool operator<(const GfxAngle& other) const noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    BgiType getValue(void) const noexcept;
    void setValue(const BgiType angle) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType value_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxAngle_hpp */
