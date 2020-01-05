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

#include "GfxRendererFlip.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxrendererflip::render::gfx");

namespace gfx
{

namespace render
{

const char GfxRendererFlip::ClassName[] = "GfxRendererFlip";

GfxRendererFlip::GfxRendererFlip() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxRendererFlip::GfxRendererFlip(const bool fliph, const bool flipv) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flip_ = static_cast<SdlType>(ValueType::flipNone);
    if (fliph == true)
    {
        flip_ = static_cast<SdlType>(flip_ | SDL_FLIP_HORIZONTAL);
    }
    if (flipv == true)
    {
        flip_ = static_cast<SdlType>(flip_ | SDL_FLIP_VERTICAL);
    }
}

GfxRendererFlip::GfxRendererFlip(const ValueType flip) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flip_ = static_cast<SdlType>(flip);
}

GfxRendererFlip::GfxRendererFlip(const SdlType flip) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flip_ = flip;
}

GfxRendererFlip::GfxRendererFlip(const GfxRendererFlip& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    flip_ = other.flip_;
}

GfxRendererFlip::GfxRendererFlip(GfxRendererFlip&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flip_ = other.flip_;
    // Delete other's data
    other.clear();
}

GfxRendererFlip& GfxRendererFlip::operator=(const GfxRendererFlip& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flip_ = other.flip_;
    }
    return *this;
}

GfxRendererFlip& GfxRendererFlip::operator=(GfxRendererFlip&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flip_ = other.flip_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxRendererFlip::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxRendererFlip::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxRendererFlip::operator==(const GfxRendererFlip& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flip_ == other.flip_);
}

bool GfxRendererFlip::isFlipHorizontal(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ((flip_ & SDL_FLIP_HORIZONTAL) != 0);
}

bool GfxRendererFlip::isFlipVertical(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ((flip_ & SDL_FLIP_VERTICAL) != 0);
}

void GfxRendererFlip::setFlipHorizontal(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flip_ = static_cast<SdlType>(flip_ | SDL_FLIP_HORIZONTAL);
}

void GfxRendererFlip::setFlipVertical(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flip_ = static_cast<SdlType>(flip_ | SDL_FLIP_VERTICAL);
}

void GfxRendererFlip::resetFlipHorizontal(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flip_ = static_cast<SdlType>(flip_ & ~SDL_FLIP_HORIZONTAL);
}

void GfxRendererFlip::resetFlipVertical(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flip_ = static_cast<SdlType>(flip_ & ~SDL_FLIP_VERTICAL);
}

void GfxRendererFlip::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flip_ = static_cast<SdlType>(ValueType::flipNone);
}

GfxRendererFlip::SdlType GfxRendererFlip::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)flip_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
