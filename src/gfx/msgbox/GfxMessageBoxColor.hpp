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

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxColor final : public GfxObject
{
public:
    typedef sdl2::SDL_MessageBoxColor SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxMessageBoxColor() noexcept;

    explicit GfxMessageBoxColor(const uint8_t r, const uint8_t g, const uint8_t b) noexcept;
    explicit GfxMessageBoxColor(const SdlType clr) noexcept;

    GfxMessageBoxColor(GfxMessageBoxColor const& other) noexcept;
    GfxMessageBoxColor(GfxMessageBoxColor&& other) noexcept;

    GfxMessageBoxColor& operator=(GfxMessageBoxColor const& other) noexcept;
    GfxMessageBoxColor& operator=(GfxMessageBoxColor&& other) noexcept;

    bool operator==(GfxMessageBoxColor const& other) noexcept;

    virtual explicit operator bool() const noexcept;

    /* Getters ... */
    uint8_t getRed(void) const noexcept;
    uint8_t getGreen(void) const noexcept;
    uint8_t getBlue(void) const noexcept;

    /* Setters ... */
    void setRed(const uint8_t r) noexcept;
    void setGreen(const uint8_t g) noexcept;
    void setBlue(const uint8_t b) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType clr_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxColor_hpp */
