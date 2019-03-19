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

#ifndef GfxHapticCondition_hpp
#define GfxHapticCondition_hpp

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

class GfxHapticCondition final : public GfxObject
{
public:
    typedef SDL_HapticCondition SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHapticCondition() noexcept;
    explicit GfxHapticCondition(const SdlType hCond) noexcept;

    GfxHapticCondition(const GfxHapticCondition& other) noexcept;
    GfxHapticCondition(GfxHapticCondition&& other) noexcept;

    GfxHapticCondition& operator=(const GfxHapticCondition& other) noexcept;
    GfxHapticCondition& operator=(GfxHapticCondition&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxHapticEffectType getType(void) const noexcept;
    const GfxHapticDirection getDirection(void) const noexcept;
    uint32_t getLength(void) const noexcept;
    uint16_t getDelay(void) const noexcept;
    uint16_t getButton(void) const noexcept;
    uint16_t getInterval(void) const noexcept;

    struct RightSat
    {
        uint16_t data_[3];

        explicit RightSat(uint16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    struct LeftSat
    {
        uint16_t data_[3];

        explicit LeftSat(uint16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    struct RightCoeff
    {
        int16_t data_[3];

        explicit RightCoeff(int16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    struct LeftCoeff
    {
        int16_t data_[3];

        explicit LeftCoeff(int16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    struct Deadband
    {
        uint16_t data_[3];

        explicit Deadband(uint16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    struct Center
    {
        int16_t data_[3];

        explicit Center(int16_t data[])
        {
            std::copy(&data_[0], &data_[2], &data[0]);
        }
    };

    const RightSat getRightSat(void) const noexcept;
    const LeftSat getLeftSat(void) const noexcept;
    const RightCoeff getRightCoeff(void) const noexcept;
    const LeftCoeff getLeftCoeff(void) const noexcept;
    const Deadband getDeadband(void) const noexcept;
    const Center getCenter(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType hCond_;
};

}  // namespace haptic

}  // namespace gfx

#endif /* GfxHapticCondition_hpp */
