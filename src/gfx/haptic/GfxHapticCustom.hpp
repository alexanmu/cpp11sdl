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

#ifndef GfxHapticCustom_hpp
#define GfxHapticCustom_hpp

#include <string>
#include <algorithm>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxHapticDirection.hpp"
#include "GfxHapticEffectType.hpp"

namespace gfx
{

namespace haptic
{

class GfxHapticCustom final : public GfxObject
{
public:
    typedef SDL_HapticCustom SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHapticCustom() noexcept;
    explicit GfxHapticCustom(const SdlType hCust) noexcept;

    GfxHapticCustom(const GfxHapticCustom& other) noexcept;
    GfxHapticCustom(GfxHapticCustom&& other) noexcept;

    GfxHapticCustom& operator=(const GfxHapticCustom& other) noexcept;
    GfxHapticCustom& operator=(GfxHapticCustom&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxHapticEffectType getType(void) const noexcept;
    const GfxHapticDirection getDirection(void) const noexcept;
    uint32_t getLength(void) const noexcept;
    uint16_t getDelay(void) const noexcept;
    uint16_t getButton(void) const noexcept;
    uint16_t getInterval(void) const noexcept;

    uint8_t getChannels(void) const noexcept;
    uint16_t getPeriod(void) const noexcept;
    uint16_t getSamples(void) const noexcept;
    uint16_t * getData(void) const noexcept;
    uint16_t getAttackLength(void) const noexcept;
    uint16_t getAttackLevel(void) const noexcept;
    uint16_t getFadeLength(void) const noexcept;
    uint16_t getFadeLevel(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType hCust_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticCustom_hpp */
