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

#include "GfxBlendFactor.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxblendfactor::blendmode::gfx");

namespace gfx
{

namespace blendmode
{

const char GfxBlendFactor::ClassName[] = "GfxBlendFactor";

GfxBlendFactor::GfxBlendFactor() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxBlendFactor::GfxBlendFactor(const ValueType blendfactor) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    blendFactor_ = static_cast<SdlType>(blendfactor);
}

GfxBlendFactor::GfxBlendFactor(const SdlType blendfactor) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(blendfactor >= 0);

    blendFactor_ = blendfactor;
}

GfxBlendFactor::GfxBlendFactor(GfxBlendFactor const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    blendFactor_ = other.blendFactor_;
}

GfxBlendFactor::GfxBlendFactor(GfxBlendFactor&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    blendFactor_ = other.blendFactor_;
    // Destroy other's data
    other.clear();
}

GfxBlendFactor& GfxBlendFactor::operator=(GfxBlendFactor const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        blendFactor_ = other.blendFactor_;
    }
    return *this;
}

GfxBlendFactor& GfxBlendFactor::operator=(GfxBlendFactor&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        blendFactor_ = other.blendFactor_;
        // Destroy other's data
        other.clear();
    }
    return *this;
}

bool GfxBlendFactor::operator==(GfxBlendFactor const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == other.blendFactor_);
}

GfxBlendFactor::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxBlendFactor::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxBlendFactor::ValueType GfxBlendFactor::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(blendFactor_);
}

bool GfxBlendFactor::isZero(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ZERO);
}

bool GfxBlendFactor::isOne(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ONE);
}

bool GfxBlendFactor::isSrcColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_SRC_COLOR);
}

bool GfxBlendFactor::isOneMinusSrcColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR);
}

bool GfxBlendFactor::isSrcAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_SRC_ALPHA);
}

bool GfxBlendFactor::isOneMinusSrcAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA);
}

bool GfxBlendFactor::isDstColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_DST_COLOR);
}

bool GfxBlendFactor::isOneMinusDstColor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR);
}

bool GfxBlendFactor::isDstAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_DST_ALPHA);
}

bool GfxBlendFactor::isOneMinusDstAlpha(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendFactor_ == sdl2::SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA);
}

void GfxBlendFactor::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    blendFactor_ = static_cast<SdlType>(ValueType::blendFactorZero);
}

GfxBlendFactor::SdlType GfxBlendFactor::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)blendFactor_;
}

}  // namespace blendmode

}  // namespace gfx

/* EOF */
