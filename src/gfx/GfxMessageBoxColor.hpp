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

#ifndef GfxMessageBoxColor_hpp
#define GfxMessageBoxColor_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxMessageBoxColor final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxColor SdlType;
    typedef sdl2::SDL_MessageBoxColor* SdlTypePtr;

    static const char ClassName[];

    GfxMessageBoxColor();

    explicit GfxMessageBoxColor(const uint8_t r, const uint8_t g, const uint8_t b);
    explicit GfxMessageBoxColor(const SdlType clr);

    GfxMessageBoxColor(const GfxMessageBoxColor& other);
    GfxMessageBoxColor(GfxMessageBoxColor&& other);

    GfxMessageBoxColor& operator=(const GfxMessageBoxColor& other);
    GfxMessageBoxColor& operator=(GfxMessageBoxColor&& other);

    bool operator==(const GfxMessageBoxColor& other);

    virtual explicit operator bool() const;

    /* Getters ... */
    uint8_t getRed(void) const;
    uint8_t getGreen(void) const;
    uint8_t getBlue(void) const;

    uint32_t getColor(void) const;

    /* Setters ... */
    void setRed(const uint8_t r);
    void setGreen(const uint8_t g);
    void setBlue(const uint8_t b);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType clr_;
};

}  // namespace gfx

#endif /* GfxMessageBoxColor_hpp */