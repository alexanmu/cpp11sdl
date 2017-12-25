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

#ifndef GfxHapticLeftRight_hpp
#define GfxHapticLeftRight_hpp

#include <string>
#include <cstdint>

#include "GfxObject.hpp"
#include "GFxSdlHeader.hpp"
#include "GfxHapticEffectType.hpp"

namespace gfx
{

namespace haptic
{

class GfxHapticLeftRight final : public GfxObject
{
public:
    typedef sdl2::SDL_HapticLeftRight SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHapticLeftRight() noexcept;
    explicit GfxHapticLeftRight(const SdlType hLR) noexcept;

    GfxHapticLeftRight(GfxHapticLeftRight const& other) noexcept;
    GfxHapticLeftRight(GfxHapticLeftRight&& other) noexcept;

    GfxHapticLeftRight& operator=(GfxHapticLeftRight const& other) noexcept;
    GfxHapticLeftRight& operator=(GfxHapticLeftRight&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxHapticEffectType getType(void) const noexcept;
    uint32_t getLength(void) const noexcept;
    uint16_t getLargeMagnitude(void) const noexcept;
    uint16_t getSmallMagnitude(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType hLR_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticLeftRight_hpp */
