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
#include <cstdlib>
#include <utility>

#include "GfxHitTestResult.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhittestresult::video::gfx");

namespace gfx
{

namespace video
{

const char GfxHitTestResult::ClassName[] = "GfxHitTestResult";

GfxHitTestResult::GfxHitTestResult() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHitTestResult::GfxHitTestResult(const ValueType value) noexcept
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxHitTestResult::GfxHitTestResult(const SdlType value) noexcept
{
    LOG_TRACE_PRIO_MED();
    value_ = value;
}

GfxHitTestResult::GfxHitTestResult(GfxHitTestResult const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxHitTestResult::GfxHitTestResult(GfxHitTestResult&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxHitTestResult& GfxHitTestResult::operator=(GfxHitTestResult const& other) noexcept
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

GfxHitTestResult& GfxHitTestResult::operator=(GfxHitTestResult&& other) noexcept
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

GfxHitTestResult::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHitTestResult::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxHitTestResult::setValue(const ValueType value) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(value);
}

GfxHitTestResult::ValueType GfxHitTestResult::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

void GfxHitTestResult::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::hittestNormal);
}

GfxHitTestResult::SdlType GfxHitTestResult::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace video

}  // namespace gfx

/* EOF */
