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

#include <cstring>
#include <vector>
#include <string>
#include <utility>

#include "GfxPaletteType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME(":gfxpalettetype::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxPaletteType::ClassName[] = "GfxPaletteType";

GfxPaletteType::GfxPaletteType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxPaletteType::GfxPaletteType(const BgiType pal) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    pal_ = pal;
}

GfxPaletteType::GfxPaletteType(GfxPaletteType const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    pal_ = other.pal_;
}

GfxPaletteType::GfxPaletteType(GfxPaletteType&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    pal_ = other.pal_;
    // Delete other's value
    other.clear();
}

GfxPaletteType& GfxPaletteType::operator=(GfxPaletteType const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        pal_ = other.pal_;
    }
    return *this;
}

GfxPaletteType& GfxPaletteType::operator=(GfxPaletteType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        pal_ = other.pal_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxPaletteType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPaletteType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

uint8_t GfxPaletteType::getSize(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pal_.size;
}

std::vector<int8_t> GfxPaletteType::getColors(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    std::vector<int8_t> ret;

    ret.reserve(pal_.size);
    for (decltype(pal_.size) i = 0; i < pal_.size; i++)
    {
        ret.push_back(pal_.colors[i]);
    }
    return ret;
}

void GfxPaletteType::setValue(const BgiType value) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pal_ = value;
}

void GfxPaletteType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    pal_.size = 0;
    std::memset(&pal_.colors, 0, prv::GfxCanvasBgi::kMaxColors + 1);
}

GfxPaletteType::BgiType GfxPaletteType::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return pal_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
