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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxYuvConversionMode.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxyuvconversionmode::surface::gfx");

namespace gfx
{

namespace surface
{

const char GfxYuvConversionMode::ClassName[] = "GfxYuvConversionMode";

GfxYuvConversionMode::GfxYuvConversionMode() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxYuvConversionMode::GfxYuvConversionMode(const ValueType convMode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    convMode_ = static_cast<SdlType>(convMode);
}

GfxYuvConversionMode::GfxYuvConversionMode(const SdlType convMode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(convMode > 0);

    convMode_ = convMode;
}

GfxYuvConversionMode::GfxYuvConversionMode(GfxYuvConversionMode const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    convMode_ = other.convMode_;
}

GfxYuvConversionMode::GfxYuvConversionMode(GfxYuvConversionMode&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    convMode_ = other.convMode_;
    // Delete other's data
    other.clear();
}

GfxYuvConversionMode& GfxYuvConversionMode::operator=(GfxYuvConversionMode const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        convMode_ = other.convMode_;
    }
    return *this;
}

GfxYuvConversionMode& GfxYuvConversionMode::operator=(GfxYuvConversionMode&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        convMode_ = other.convMode_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxYuvConversionMode::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxYuvConversionMode::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxYuvConversionMode::isConversionJPEG(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (convMode_ == sdl2::SDL_YUV_CONVERSION_JPEG);
}

bool GfxYuvConversionMode::isConversionBT601(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (convMode_ == sdl2::SDL_YUV_CONVERSION_BT601);
}

bool GfxYuvConversionMode::isConversionBT709(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (convMode_ == sdl2::SDL_YUV_CONVERSION_BT709);
}

bool GfxYuvConversionMode::isConversionAutomatic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (convMode_ == sdl2::SDL_YUV_CONVERSION_AUTOMATIC);
}

void GfxYuvConversionMode::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    convMode_ = sdl2::SDL_YUV_CONVERSION_AUTOMATIC;
}

GfxYuvConversionMode::SdlType GfxYuvConversionMode::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return convMode_;
}

}  // namespace surface

}  // namespace gfx

/* EOF */
