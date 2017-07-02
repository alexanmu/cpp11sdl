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

#include "GfxBlendMode.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxblendmode::blendmode::gfx");

namespace gfx
{

namespace blendmode
{

const char GfxBlendMode::ClassName[] = "GfxBlendMode";

GfxBlendMode::GfxBlendMode() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxBlendMode::GfxBlendMode(const ValueType blendmode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    blendmode_ = static_cast<SdlType>(blendmode);
}

GfxBlendMode::GfxBlendMode(const SdlType blendmode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(blendmode >= 0);

    blendmode_ = blendmode;
}

GfxBlendMode::GfxBlendMode(GfxBlendMode const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    blendmode_ = other.blendmode_;
}

GfxBlendMode::GfxBlendMode(GfxBlendMode&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    blendmode_ = other.blendmode_;
    // Destroy other's data
    other.clear();
}

GfxBlendMode& GfxBlendMode::operator=(GfxBlendMode const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        blendmode_ = other.blendmode_;
    }
    return *this;
}

GfxBlendMode& GfxBlendMode::operator=(GfxBlendMode&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        blendmode_ = other.blendmode_;
        // Destroy other's data
        other.clear();
    }
    return *this;
}

bool GfxBlendMode::operator==(GfxBlendMode const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendmode_ == other.blendmode_);
}

GfxBlendMode::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxBlendMode::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxBlendMode::ValueType GfxBlendMode::getBlendMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(blendmode_);
}

bool GfxBlendMode::isNone(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendmode_ == sdl2::SDL_BLENDMODE_NONE);
}

bool GfxBlendMode::isBlend(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendmode_ == sdl2::SDL_BLENDMODE_BLEND);
}

bool GfxBlendMode::isAdd(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendmode_ == sdl2::SDL_BLENDMODE_ADD);
}

bool GfxBlendMode::isMod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (blendmode_ == sdl2::SDL_BLENDMODE_MOD);
}

void GfxBlendMode::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    blendmode_ = static_cast<SdlType>(ValueType::blendNone);
}

GfxBlendMode::SdlType GfxBlendMode::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)blendmode_;
}

}  // namespace blendmode

}  // namespace gfx

/* EOF */
