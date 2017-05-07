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

#ifndef GfxVersion_hpp
#define GfxVersion_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxVersion final : public GfxRootClass
{
public:
    typedef sdl2::SDL_version SdlType;
    typedef sdl2::SDL_version* SdlTypePtr;

    static const std::string ClassName;

    GfxVersion();

    GfxVersion(const uint8_t major, const uint8_t minor, const uint8_t patch);
    explicit GfxVersion(const SdlType ver);

    GfxVersion(GfxVersion const& other);
    GfxVersion(GfxVersion&& other);

    GfxVersion& operator=(GfxVersion const& other);
    GfxVersion& operator=(GfxVersion&& other);

    uint8_t getMajor(void) const;
    uint8_t getMinor(void) const;
    uint8_t getPatch(void) const;

    void set(const SdlType ver);

    std::string getAsString(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType ver_;
};

}  // namespace gfx

#endif /* GfxVersion_hpp */
