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

#include "GfxArcCoordsType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxarccoordstype::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxArcCoordsType::ClassName[] = "GfxArcCoordsType";

GfxArcCoordsType::GfxArcCoordsType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxArcCoordsType::GfxArcCoordsType(const BgiType arccoords) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    arccoords_ = arccoords;
}

GfxArcCoordsType::GfxArcCoordsType(GfxArcCoordsType const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    arccoords_ = other.arccoords_;
}

GfxArcCoordsType::GfxArcCoordsType(GfxArcCoordsType&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    arccoords_ = other.arccoords_;
    // Delete other's value
    other.clear();
}

GfxArcCoordsType& GfxArcCoordsType::operator=(GfxArcCoordsType const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        arccoords_ = other.arccoords_;
    }
    return *this;
}

GfxArcCoordsType& GfxArcCoordsType::operator=(GfxArcCoordsType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        arccoords_ = other.arccoords_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxArcCoordsType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxArcCoordsType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxArcCoordsType::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.x;
}

int32_t GfxArcCoordsType::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.y;
}

int32_t GfxArcCoordsType::getXStart(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.xstart;
}

int32_t GfxArcCoordsType::getYStart(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.ystart;
}

int32_t GfxArcCoordsType::getXEnd(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.xend;
}

int32_t GfxArcCoordsType::getYEnd(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_.yend;
}

void GfxArcCoordsType::setValue(const BgiType arccoords) noexcept
{
    LOG_TRACE_PRIO_LOW();

    arccoords_ = arccoords;
}

void GfxArcCoordsType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    arccoords_.x = -1;
    arccoords_.y = -1;
    arccoords_.xstart = -1;
    arccoords_.ystart = -1;
    arccoords_.xend = -1;
    arccoords_.yend = -1;
}

GfxArcCoordsType::BgiType GfxArcCoordsType::getAsBgiType() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return arccoords_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
