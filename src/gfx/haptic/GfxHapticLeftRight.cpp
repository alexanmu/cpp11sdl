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

#include <string>
#include <cstdint>
#include <utility>

#include "GfxHapticLeftRight.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhapticleftright::haptic::gfx");

namespace gfx
{

namespace haptic
{

const char GfxHapticLeftRight::ClassName[] = "GfxHapticLeftRight";

GfxHapticLeftRight::GfxHapticLeftRight() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHapticLeftRight::GfxHapticLeftRight(const SdlType hLR) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hLR_ = hLR;
}

GfxHapticLeftRight::GfxHapticLeftRight(GfxHapticLeftRight const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hLR_ = other.hLR_;
}

GfxHapticLeftRight::GfxHapticLeftRight(GfxHapticLeftRight&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hLR_ = other.hLR_;
    // Delete other's data
    other.clear();
}

GfxHapticLeftRight& GfxHapticLeftRight::operator=(GfxHapticLeftRight const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hLR_ = other.hLR_;
    }
    return *this;
}

GfxHapticLeftRight& GfxHapticLeftRight::operator=(GfxHapticLeftRight&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hLR_ = other.hLR_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHapticLeftRight::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHapticLeftRight::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxHapticEffectType GfxHapticLeftRight::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxHapticEffectType(hLR_.type);
}

uint32_t GfxHapticLeftRight::getLength(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hLR_.length;
}

uint16_t GfxHapticLeftRight::getLargeMagnitude(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hLR_.large_magnitude;
}

uint16_t GfxHapticLeftRight::getSmallMagnitude(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hLR_.small_magnitude;
}

void GfxHapticLeftRight::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hLR_.type = SDL_HAPTIC_LEFTRIGHT;
    hLR_.length = 0;
    hLR_.large_magnitude = 0;
    hLR_.small_magnitude = 0;
}

GfxHapticLeftRight::SdlType GfxHapticLeftRight::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hLR_;
}

}  // namespace haptic

}  // namespace gfx

/* EOF */
