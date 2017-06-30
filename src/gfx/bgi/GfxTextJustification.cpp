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

#include "GfxTextJustification.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtextjustification::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxTextJustification::ClassName[] = "GfxTextJustification";

GfxTextJustification::GfxTextJustification() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    clear();
}

GfxTextJustification::GfxTextJustification(const ValueType just) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    just_ = static_cast<BgiType>(just);
}

GfxTextJustification::GfxTextJustification(const BgiType just) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    just_ = just;
}

GfxTextJustification::GfxTextJustification(GfxTextJustification const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    just_ = other.just_;
}

GfxTextJustification::GfxTextJustification(GfxTextJustification&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    just_ = other.just_;
    // Delete other's value
    other.clear();
}

GfxTextJustification& GfxTextJustification::operator=(GfxTextJustification const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();
    if (this != &other)
    {
        just_ = other.just_;
    }
    return *this;
}

GfxTextJustification& GfxTextJustification::operator=(GfxTextJustification&& other) noexcept
{
    LOG_TRACE_PRIO_LOW();
    if (this != &other)
    {
        just_ = other.just_;
        // Delete other's value
        other.clear();
    }
    return *this;
}


GfxTextJustification::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return true;
}

GfxTextJustification::ValueType GfxTextJustification::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return static_cast<ValueType>(just_);
}

void GfxTextJustification::setValue(const ValueType just) noexcept
{
    LOG_TRACE_PRIO_LOW();
    just_ = static_cast<BgiType>(just);
}

void GfxTextJustification::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();
    just_ = static_cast<BgiType>(ValueType::centerText);
}

GfxTextJustification::BgiType GfxTextJustification::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return just_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
