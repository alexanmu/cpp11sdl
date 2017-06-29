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

#include "GfxDrawingMode.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

const char GfxDrawingMode::ClassName[] = "GfxDrawingMode";

GfxDrawingMode::GfxDrawingMode() noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    clear();
}

GfxDrawingMode::GfxDrawingMode(const ValueType dmode) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    dmode_ = static_cast<BgiType>(dmode);
}

GfxDrawingMode::GfxDrawingMode(const BgiType dmode) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    dmode_ = dmode;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    dmode_ = other.dmode_;
}

GfxDrawingMode::GfxDrawingMode(GfxDrawingMode&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    dmode_ = other.dmode_;
    // Delete other's value
    other.clear();
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        dmode_ = other.dmode_;
    }
    return *this;
}

GfxDrawingMode& GfxDrawingMode::operator=(GfxDrawingMode&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        dmode_ = other.dmode_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxDrawingMode::operator bool() const noexcept
{
    TRACE_P0();
    return true;
}

GfxDrawingMode::ValueType GfxDrawingMode::getValue(void) const noexcept
{
    TRACE_P0();
    return static_cast<ValueType>(dmode_);
}

void GfxDrawingMode::setValue(const ValueType dmode) noexcept
{
    TRACE_P0();
    dmode_ = static_cast<BgiType>(dmode);
}

void GfxDrawingMode::clear(void) noexcept
{
    TRACE_P0();
    dmode_ = static_cast<BgiType>(ValueType::copyPut);
}

GfxDrawingMode::BgiType GfxDrawingMode::getAsBgiType(void) const noexcept
{
    TRACE_P0();
    return dmode_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
