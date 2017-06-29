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

#include "GfxAngle.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

const char GfxAngle::ClassName[] = "GfxAngle";

GfxAngle::GfxAngle() noexcept : GfxObject(ClassName), value_(0)
{
    TRACE_P0();
}

GfxAngle::GfxAngle(const ValueType value) noexcept : GfxObject(ClassName), value_(value)
{
    TRACE_P0();
    value_ = value_ % 360;
}

GfxAngle::GfxAngle(GfxAngle const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    value_ = other.value_;
}

GfxAngle::GfxAngle(GfxAngle&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    value_ = other.value_;
    // Delete other's value
    other.value_ = 0;
}

GfxAngle& GfxAngle::operator=(GfxAngle const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxAngle& GfxAngle::operator=(GfxAngle&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's value
        other.value_ = 0;
    }
    return *this;
}

bool GfxAngle::operator==(GfxAngle const& other) const noexcept
{
    TRACE_P0();
    return (value_ == other.value_);
}

bool GfxAngle::operator>(GfxAngle const& other) const noexcept
{
    TRACE_P0();
    return (value_ > other.value_);
}

bool GfxAngle::operator<(GfxAngle const& other) const noexcept
{
    TRACE_P0();
    return (value_ < other.value_);
}

GfxAngle::operator bool() const noexcept
{
    TRACE_P0();
    return true;
}

GfxAngle::ValueType GfxAngle::getValue(void) const noexcept
{
    TRACE_P0();
    return value_;
}

void GfxAngle::setValue(const ValueType value) noexcept
{
    TRACE_P0();
    value_ = value;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
