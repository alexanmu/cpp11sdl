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

#include <string>
#include <utility>

#include "GfxMouseWheelDirection.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmousewheeldirection::mouse::gfx");

namespace gfx
{

namespace mouse
{

const char GfxMouseWheelDirection::ClassName[] = "GfxMouseWheelDirection";

GfxMouseWheelDirection::GfxMouseWheelDirection() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMouseWheelDirection::GfxMouseWheelDirection(const ValueType wheel) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    wheel_ = static_cast<SdlType>(wheel);
}

GfxMouseWheelDirection::GfxMouseWheelDirection(const SdlType wheel) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    wheel_ = wheel;
}

GfxMouseWheelDirection::GfxMouseWheelDirection(const uint32_t wheel) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    wheel_ = static_cast<SdlType>(wheel);
}

GfxMouseWheelDirection::GfxMouseWheelDirection(const GfxMouseWheelDirection& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    wheel_ = other.wheel_;
}

GfxMouseWheelDirection::GfxMouseWheelDirection(GfxMouseWheelDirection&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    wheel_ = other.wheel_;
    // Delete other's data
    other.clear();
}

GfxMouseWheelDirection& GfxMouseWheelDirection::operator=(const GfxMouseWheelDirection& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        wheel_ = other.wheel_;
    }
    return *this;
}

GfxMouseWheelDirection& GfxMouseWheelDirection::operator=(GfxMouseWheelDirection&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        wheel_ = other.wheel_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxMouseWheelDirection::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMouseWheelDirection::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxMouseWheelDirection::setDirectionNormal(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    wheel_ = static_cast<SdlType>(ValueType::mouseWheelNormal);
}

void GfxMouseWheelDirection::setDirectionFlipped(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    wheel_ = static_cast<SdlType>(ValueType::mouseWheelFlipped);
}

bool GfxMouseWheelDirection::isDirectionNormal(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (wheel_ == static_cast<SdlType>(ValueType::mouseWheelNormal));
}

bool GfxMouseWheelDirection::isDirectionFlipped(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (wheel_ == static_cast<SdlType>(ValueType::mouseWheelFlipped));
}

GfxMouseWheelDirection::ValueType GfxMouseWheelDirection::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(wheel_);
}

void GfxMouseWheelDirection::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    wheel_ = static_cast<SdlType>(ValueType::mouseWheelNormal);
}

GfxMouseWheelDirection::SdlType GfxMouseWheelDirection::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return wheel_;
}

}  // namespace mouse

}  // namespace gfx

/* EOF */
