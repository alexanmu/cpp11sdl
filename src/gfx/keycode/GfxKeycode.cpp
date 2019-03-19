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

#include "GfxKeycode.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxkeycode::keycode::gfx");

namespace gfx
{

namespace keycode
{

const char GfxKeycode::ClassName[] = "GfxKeycode";

GfxKeycode::GfxKeycode() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxKeycode::GfxKeycode(const int32_t code) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    code_ = static_cast<SdlType>(code);
}

GfxKeycode::GfxKeycode(const ValueType code) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    code_ = static_cast<SdlType>(code);
}

GfxKeycode::GfxKeycode(const GfxKeycode& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    code_ = other.code_;
}

GfxKeycode::GfxKeycode(GfxKeycode&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    code_ = other.code_;
    // Delete other's data
    other.clear();
}

GfxKeycode& GfxKeycode::operator=(const GfxKeycode& other) noexcept
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

GfxKeycode& GfxKeycode::operator=(GfxKeycode&& other) noexcept
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

GfxKeycode::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxKeycode::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxKeycode::ValueType GfxKeycode::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(code_);
}

GfxKeycode::ValueType GfxKeycode::scancodeToKeycode(const scancode::GfxScancode& scancode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(SDL_SCANCODE_TO_KEYCODE(scancode.getAsSdlType()));
}

void GfxKeycode::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    code_ = static_cast<SdlType>(ValueType::kUnknown);
}

GfxKeycode::SdlType GfxKeycode::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return code_;
}

}  // namespace keycode

}  // namespace gfx

/* EOF */
