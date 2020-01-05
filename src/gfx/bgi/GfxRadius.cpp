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

#include <cassert>
#include <string>
#include <utility>

#include "GfxRadius.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxradius::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxRadius::ClassName[] = "GfxRadius";

GfxRadius::GfxRadius() noexcept : GfxObject(ClassName), value_(0)
{
    LOG_TRACE_PRIO_MED();
}

GfxRadius::GfxRadius(const BgiType value) noexcept : GfxObject(ClassName), value_(value)
{
    LOG_TRACE_PRIO_MED();

    assert(value > 0);
}

GfxRadius::GfxRadius(const GfxRadius& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxRadius::GfxRadius(GfxRadius&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's value
    other.clear();
}

GfxRadius& GfxRadius::operator=(const GfxRadius& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        value_ = other.value_;
    }
    return *this;
}

GfxRadius& GfxRadius::operator=(GfxRadius&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        value_ = other.value_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

bool GfxRadius::operator==(const GfxRadius& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == other.value_);
}

bool GfxRadius::operator>(const GfxRadius& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ > other.value_);
}

bool GfxRadius::operator<(const GfxRadius& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ < other.value_);
}

GfxRadius::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxRadius::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxRadius::BgiType GfxRadius::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

void GfxRadius::setValue(const BgiType value) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(value > 0);

    value_ = value;
}

void GfxRadius::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = 0;
}

GfxRadius::BgiType GfxRadius::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
