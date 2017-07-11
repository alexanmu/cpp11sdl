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
#include <utility>

#include "GfxHintPriority.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhintpriority::hints::gfx");

namespace gfx
{

namespace hints
{

const char GfxHintPriority::ClassName[] = "GfxHintPriority";

GfxHintPriority::GfxHintPriority() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHintPriority::GfxHintPriority(const SdlType hint) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hint_ = hint;
}

GfxHintPriority::GfxHintPriority(const ValueType hint) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hint_ = static_cast<SdlType>(hint);
}

GfxHintPriority::GfxHintPriority(GfxHintPriority const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hint_ = other.hint_;
}

GfxHintPriority::GfxHintPriority(GfxHintPriority&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hint_ = other.hint_;
    // Delete other's data
    other.clear();
}

GfxHintPriority& GfxHintPriority::operator=(GfxHintPriority const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hint_ = other.hint_;
    }
    return *this;
}

GfxHintPriority& GfxHintPriority::operator=(GfxHintPriority&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hint_ = other.hint_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHintPriority::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHintPriority::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxHintPriority::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hint_ = sdl2::SDL_HINT_DEFAULT;
}

GfxHintPriority::SdlType GfxHintPriority::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hint_;
}

}  // namespace hints

}  // namespace gfx

/* EOF */
