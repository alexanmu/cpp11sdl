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

#ifndef GfxRadius_hpp
#define GfxRadius_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"

namespace gfx
{
namespace bgi
{

class GfxRadius final : public GfxRootClass
{
public:
    typedef int32_t GfxValueType;

    static const char ClassName[];

    GfxRadius();

    explicit GfxRadius(const GfxValueType value);

    GfxRadius(const GfxRadius& other);
    GfxRadius(GfxRadius&& other);

    GfxRadius& operator=(const GfxRadius& other);
    GfxRadius& operator=(GfxRadius&& other);

    bool operator==(const GfxRadius& other);
    bool operator>(const GfxRadius& other);
    bool operator<(const GfxRadius& other);

    virtual explicit operator bool() const;

    GfxValueType getValue() const;
    void setValue(const GfxValueType& value);
private:
    GfxValueType value_;
};

}  // namespace bgi
}  // namespace gfx

#endif /* GfxRadius_hpp */
