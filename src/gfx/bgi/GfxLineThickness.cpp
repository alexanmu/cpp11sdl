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

#include "GfxLineThickness.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlinethickness::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxLineThickness::ClassName[] = "GfxLineThickness";

GfxLineThickness::GfxLineThickness() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLineThickness::GfxLineThickness(const ValueType thick) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    thick_ = static_cast<BgiType>(thick);
}

GfxLineThickness::GfxLineThickness(const BgiType thick) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    thick_ = thick;
}

GfxLineThickness::GfxLineThickness(GfxLineThickness const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    thick_ = other.thick_;
}

GfxLineThickness::GfxLineThickness(GfxLineThickness&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    thick_ = other.thick_;
    // Delete other's value
    other.clear();
}

GfxLineThickness& GfxLineThickness::operator=(GfxLineThickness const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        thick_ = other.thick_;
    }
    return *this;
}

GfxLineThickness& GfxLineThickness::operator=(GfxLineThickness&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        thick_ = other.thick_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxLineThickness::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLineThickness::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxLineThickness::ValueType GfxLineThickness::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(thick_);
}

void GfxLineThickness::setValue(const ValueType thick) noexcept
{
    LOG_TRACE_PRIO_LOW();

    thick_ = static_cast<BgiType>(thick);
}

bool GfxLineThickness::isNormalWidth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (thick_ == prv::GfxCanvasBgi::bgiLineThickness::NORM_WIDTH);
}

bool GfxLineThickness::isThickWidth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (thick_ == prv::GfxCanvasBgi::bgiLineThickness::THICK_WIDTH);
}

void GfxLineThickness::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    thick_ = static_cast<BgiType>(ValueType::normalWidth);
}

GfxLineThickness::BgiType GfxLineThickness::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return thick_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
