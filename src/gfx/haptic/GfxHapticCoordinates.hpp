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

#ifndef GfxHapticCoordinates_hpp
#define GfxHapticCoordinates_hpp

#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace haptic
{

class GfxHapticCoordinates : public GfxObject
{
public:
    typedef uint8_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint8_t
    {
        hapticPolar = SDL_HAPTIC_POLAR,
        hapticCartesian = SDL_HAPTIC_CARTESIAN,
        hapticSpherical = SDL_HAPTIC_SPHERICAL
    };

    GfxHapticCoordinates() noexcept;
    explicit GfxHapticCoordinates(const SdlType coord) noexcept;
    explicit GfxHapticCoordinates(const ValueType coord) noexcept;

    GfxHapticCoordinates(GfxHapticCoordinates const& other) noexcept;
    GfxHapticCoordinates(GfxHapticCoordinates&& other) noexcept;

    GfxHapticCoordinates& operator=(GfxHapticCoordinates const& other) noexcept;
    GfxHapticCoordinates& operator=(GfxHapticCoordinates&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isPolar(void) const noexcept;
    bool isCartesian(void) const noexcept;
    bool isSpherical(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType coord_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticCoordinates_hpp */
