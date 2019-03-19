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

#include "GfxScancode.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxscancode::scancode::gfx");

namespace gfx
{

namespace scancode
{

const char GfxScancode::ClassName[] = "GfxScancode";

GfxScancode::GfxScancode() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxScancode::GfxScancode(const std::underlying_type<ValueType>::type code) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    code_ = static_cast<SdlType>(code);
}

GfxScancode::GfxScancode(const ValueType code) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    code_ = static_cast<SdlType>(code);
}

GfxScancode::GfxScancode(const GfxScancode& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    code_ = other.code_;
}

GfxScancode::GfxScancode(GfxScancode&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    code_ = other.code_;
    // Delete other's data
    other.clear();
}

GfxScancode& GfxScancode::operator=(const GfxScancode& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        code_ = other.code_;
    }
    return *this;
}

GfxScancode& GfxScancode::operator=(GfxScancode&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        code_ = other.code_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxScancode::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxScancode::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxScancode::ValueType GfxScancode::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(code_);
}

void GfxScancode::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    code_ = static_cast<SdlType>(ValueType::kScanCodeUnknown);
}

GfxScancode::SdlType GfxScancode::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return code_;
}

}  // namespace scancode

}  // namespace gfx

/* EOF */
