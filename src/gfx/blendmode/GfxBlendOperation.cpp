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

#include "GfxBlendOperation.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxblendoperation::blendmode::gfx");

namespace gfx
{

namespace blendmode
{

const char GfxBlendOperation::ClassName[] = "GfxBlendOperation";

GfxBlendOperation::GfxBlendOperation() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxBlendOperation::GfxBlendOperation(const ValueType blendop) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    blendOperation_ = static_cast<SdlType>(blendop);
}

GfxBlendOperation::GfxBlendOperation(const SdlType blendop) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(blendop >= 0);

    blendOperation_ = blendop;
}

GfxBlendOperation::GfxBlendOperation(GfxBlendOperation const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    blendOperation_ = other.blendOperation_;
}

GfxBlendOperation::GfxBlendOperation(GfxBlendOperation&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    blendOperation_ = other.blendOperation_;
    // Destroy other's data
    other.clear();
}

GfxBlendOperation& GfxBlendOperation::operator=(GfxBlendOperation const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        blendOperation_ = other.blendOperation_;
    }
    return *this;
}

GfxBlendOperation& GfxBlendOperation::operator=(GfxBlendOperation&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        blendOperation_ = other.blendOperation_;
        // Destroy other's data
        other.clear();
    }
    return *this;
}

bool GfxBlendOperation::operator==(GfxBlendOperation const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == other.blendOperation_);
}

GfxBlendOperation::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxBlendOperation::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxBlendOperation::ValueType GfxBlendOperation::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(blendOperation_);
}

bool GfxBlendOperation::isAdd(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == sdl2::SDL_BLENDOPERATION_ADD);
}

bool GfxBlendOperation::isSubstract(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == sdl2::SDL_BLENDOPERATION_SUBTRACT);
}

bool GfxBlendOperation::isRevSubstract(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == sdl2::SDL_BLENDOPERATION_REV_SUBTRACT);
}

bool GfxBlendOperation::isMinimum(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == sdl2::SDL_BLENDOPERATION_MINIMUM);
}

bool GfxBlendOperation::isMaximum(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendOperation_ == sdl2::SDL_BLENDOPERATION_MAXIMUM);
}

void GfxBlendOperation::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    blendOperation_ = static_cast<SdlType>(ValueType::blendOperationAdd);
}

GfxBlendOperation::SdlType GfxBlendOperation::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)blendOperation_;
}

}  // namespace blendmode

}  // namespace gfx

/* EOF */
