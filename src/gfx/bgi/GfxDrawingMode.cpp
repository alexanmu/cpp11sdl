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

#include "GfxDrawingMode.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxdrawingmode::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxDrawingMode::ClassName[] = "GfxDrawingMode";

GfxDrawingMode::GfxDrawingMode() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxDrawingMode::GfxDrawingMode(const ValueType dmode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    dmode_ = static_cast<BgiType>(dmode);
}

GfxDrawingMode::GfxDrawingMode(const BgiType dmode) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    dmode_ = dmode;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    dmode_ = other.dmode_;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    dmode_ = other.dmode_;
    // Delete other's value
    other.clear();
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        dmode_ = other.dmode_;
    }
    return *this;
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        dmode_ = other.dmode_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxDrawingMode::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxDrawingMode::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxDrawingMode::ValueType GfxDrawingMode::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(dmode_);
}

void GfxDrawingMode::setValue(const ValueType dmode) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dmode_ = static_cast<BgiType>(dmode);
}

void GfxDrawingMode::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    dmode_ = static_cast<BgiType>(ValueType::copyPut);
}

GfxDrawingMode::BgiType GfxDrawingMode::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dmode_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
