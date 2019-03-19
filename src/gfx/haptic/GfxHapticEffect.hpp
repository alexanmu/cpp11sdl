/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#ifndef GfxHapticEffect_hpp
#define GfxHapticEffect_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxHapticEffectType.hpp"
#include "GfxHapticConstant.hpp"
#include "GfxHapticPeriodic.hpp"
#include "GfxHapticCondition.hpp"
#include "GfxHapticRamp.hpp"
#include "GfxHapticLeftRight.hpp"
#include "GfxHapticCustom.hpp"

namespace gfx
{

namespace haptic
{

class GfxHapticEffect final : public GfxObject
{
public:
    typedef SDL_HapticEffect SdlType;
    typedef SDL_HapticEffect * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHapticEffect() noexcept;

    explicit GfxHapticEffect(const SdlType effect) noexcept;

    GfxHapticEffect(const GfxHapticEffect& other) noexcept;
    GfxHapticEffect(GfxHapticEffect&& other) noexcept;

    GfxHapticEffect& operator=(const GfxHapticEffect& other) noexcept;
    GfxHapticEffect& operator=(GfxHapticEffect&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxHapticEffectType getType(void) const noexcept;

    const GfxHapticConstant getConstant(void) const noexcept;
    const GfxHapticPeriodic getPeriodic(void) const noexcept;
    const GfxHapticCondition getCondition(void) const noexcept;
    const GfxHapticRamp getRamp(void) const noexcept;
    const GfxHapticLeftRight getLeftRight(void) const noexcept;
    const GfxHapticCustom getCustom(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType effect_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticEffect_hpp */
