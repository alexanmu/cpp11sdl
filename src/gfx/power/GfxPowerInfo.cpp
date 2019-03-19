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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxPowerInfo.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpowerinfo::power::gfx");

namespace gfx
{

namespace power
{

const char GfxPowerInfo::ClassName[] = "GfxPowerInfo";

GfxPowerInfo::GfxPowerInfo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();

    clear();
}

GfxPowerInfo::GfxPowerInfo(const GfxPowerInfo& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_LOW();

    pstate_ = other.pstate_;
    seconds_ = other.seconds_;
    percentage_ = other.percentage_;
}

GfxPowerInfo::GfxPowerInfo(GfxPowerInfo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_LOW();

    pstate_ = other.pstate_;
    seconds_ = other.seconds_;
    percentage_ = other.percentage_;
    // Delete other's data
    other.clear();
}

GfxPowerInfo& GfxPowerInfo::operator=(const GfxPowerInfo& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        pstate_ = other.pstate_;
        seconds_ = other.seconds_;
        percentage_ = other.percentage_;
    }
    return *this;
}

GfxPowerInfo& GfxPowerInfo::operator=(GfxPowerInfo&& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        pstate_ = other.pstate_;
        seconds_ = other.seconds_;
        percentage_ = other.percentage_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPowerInfo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPowerInfo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxPowerInfo::queryPowerInfo(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxPowerState::SdlType pstate;

    pstate = SDL_GetPowerInfo(&seconds_, &percentage_);
    pstate_ = GfxPowerState(pstate);
}

const GfxPowerState& GfxPowerInfo::getPowerState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pstate_;
}

int32_t GfxPowerInfo::getRemainingSeconds(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return seconds_;
}

int32_t GfxPowerInfo::getRemainingPercentage(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return percentage_;
}

const std::string GfxPowerInfo::getAsString(void) const noexcept
{
    std::string str;

    str = pstate_.getAsString() + "\n";
    str += "Minutes remaining " + std::to_string(seconds_ / 60) + "\n";
    str += "Percentage left " + std::to_string(percentage_) + "%";
    return str;
}

void GfxPowerInfo::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pstate_ = GfxPowerState(GfxPowerState::ValueType::stateUnknown);
    seconds_ = -1;
    percentage_ = -1;
}

}  // namespace power

}  // namespace gfx

/* EOF */
