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

#include "GfxLineStyle.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlinestyle::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxLineStyle::ClassName[] = "GfxLineStyle";

GfxLineStyle::GfxLineStyle() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLineStyle::GfxLineStyle(const ValueType line) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    line_ = static_cast<BgiType>(line);
}

GfxLineStyle::GfxLineStyle(const BgiType line) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    line_ = line;
}

GfxLineStyle::GfxLineStyle(GfxLineStyle const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    line_ = other.line_;
}

GfxLineStyle::GfxLineStyle(GfxLineStyle&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    line_ = other.line_;
    // Delete other's value
    other.clear();
}

GfxLineStyle& GfxLineStyle::operator=(GfxLineStyle const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        line_ = other.line_;
    }
    return *this;
}

GfxLineStyle& GfxLineStyle::operator=(GfxLineStyle&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        line_ = other.line_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxLineStyle::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLineStyle::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxLineStyle::ValueType GfxLineStyle::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(line_);
}

void GfxLineStyle::setValue(const ValueType line) noexcept
{
    LOG_TRACE_PRIO_LOW();

    line_ = static_cast<BgiType>(line);
}

void GfxLineStyle::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    line_ = static_cast<BgiType>(ValueType::solidLine);
}

GfxLineStyle::BgiType GfxLineStyle::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return line_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
