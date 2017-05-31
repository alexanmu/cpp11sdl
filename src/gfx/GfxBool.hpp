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

#ifndef GfxBool_hpp
#define GfxBool_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxBool final : public GfxRootClass
{
public:
    typedef sdl2::SDL_bool SdlType;

    static const char ClassName[];

    enum class ValueType : bool
    {
        boolFalse = sdl2::SDL_FALSE,
        boolTrue = sdl2::SDL_TRUE
    };

    GfxBool();

    explicit GfxBool(const ValueType value);
    explicit GfxBool(const SdlType value);
    explicit GfxBool(const bool value);

    GfxBool(const GfxBool& other);
    GfxBool(GfxBool&& other);

    GfxBool& operator=(const GfxBool& other);
    GfxBool& operator=(GfxBool&& other);

    virtual explicit operator bool() const;

    bool getBool(void) const;

    void clear(void);

    SdlType getAsSdlType(void) const;
private:
    SdlType value_;
};

}  // namespace gfx

#endif /* GfxBool_hpp */
