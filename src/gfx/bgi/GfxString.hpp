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

#ifndef GfxString_hpp
#define GfxString_hpp

#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace bgi
{

class GfxString final : public GfxObject
{
public:
    typedef std::string ValueType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxString() noexcept;

    explicit GfxString(ValueType const& value) noexcept;

    GfxString(GfxString const& other) noexcept;
    GfxString(GfxString&& other) noexcept;

    GfxString& operator=(GfxString const& other) noexcept;
    GfxString& operator=(GfxString&& other) noexcept;

    bool operator==(GfxString const& other) const noexcept;
    bool operator>(GfxString const& other) const noexcept;
    bool operator<(GfxString const& other) const noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getValue() const noexcept;
    void setValue(ValueType const& value) noexcept;
private:
    ValueType value_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxString_hpp */
