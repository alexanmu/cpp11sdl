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

#include <cassert>
#include <string>
#include <utility>

#include "GfxLogPriority.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlogpriority::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLogPriority::ClassName[] = "GfxLogPriority";

GfxLogPriority::GfxLogPriority() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLogPriority::GfxLogPriority(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxLogPriority::GfxLogPriority(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxLogPriority::GfxLogPriority(const int32_t value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(value <= static_cast<int32_t>(ValueType::logPriorityNumLogPriorities));

    value_ = static_cast<SdlType>(value);
}

GfxLogPriority::GfxLogPriority(GfxLogPriority const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxLogPriority::GfxLogPriority(GfxLogPriority&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxLogPriority& GfxLogPriority::operator=(GfxLogPriority const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        value_ = other.value_;
    }
    return *this;
}

GfxLogPriority& GfxLogPriority::operator=(GfxLogPriority&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxLogPriority::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLogPriority::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxLogPriority::ValueType GfxLogPriority::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

bool GfxLogPriority::isVerbose(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_VERBOSE);
}

bool GfxLogPriority::isDebug(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_DEBUG);
}

bool GfxLogPriority::isInfo(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_INFO);
}

bool GfxLogPriority::isWarn(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_WARN);
}

bool GfxLogPriority::isError(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_ERROR);
}

bool GfxLogPriority::isCritical(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_LOG_PRIORITY_CRITICAL);
}

bool GfxLogPriority::isNumLogPriorities(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_NUM_LOG_PRIORITIES);
}

void GfxLogPriority::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::logPriorityNumLogPriorities);
}

GfxLogPriority::SdlType GfxLogPriority::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace log

}  // namespace gfx

/* EOF */
