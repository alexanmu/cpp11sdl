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

class GfxBool final : public GfxRootClass
{
public:
    typedef SDL_bool SdlType;
    typedef SDL_bool* SdlTypePtr;

    static const std::string ClassName;

    GfxBool();

    explicit GfxBool(const bool value);
    explicit GfxBool(const SdlType value);

    GfxBool(const GfxBool& other);
    GfxBool(GfxBool&& other);

    GfxBool& operator=(const GfxBool& other);
    GfxBool& operator=(GfxBool&& other);
    
    bool getBool(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType value_;
};
    
#endif /* GfxBool_hpp */
