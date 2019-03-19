/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#include "GfxBitmapOrder.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxbitmaporder::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxBitmapOrder::ClassName[] = "GfxBitmapOrder";

GfxBitmapOrder::GfxBitmapOrder() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxBitmapOrder::GfxBitmapOrder(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxBitmapOrder::GfxBitmapOrder(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxBitmapOrder::GfxBitmapOrder(const GfxBitmapOrder& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxBitmapOrder::GfxBitmapOrder(GfxBitmapOrder&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxBitmapOrder& GfxBitmapOrder::operator=(const GfxBitmapOrder& other) noexcept
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

GfxBitmapOrder& GfxBitmapOrder::operator=(GfxBitmapOrder&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxBitmapOrder::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxBitmapOrder::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxBitmapOrder::ValueType GfxBitmapOrder::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

bool GfxBitmapOrder::isNone(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_BITMAPORDER_NONE);
}

bool GfxBitmapOrder::is4321(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_BITMAPORDER_4321);
}

bool GfxBitmapOrder::is1234(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (value_ == SDL_BITMAPORDER_1234);
}

void GfxBitmapOrder::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::bitmapOrderNone);
}

GfxBitmapOrder::SdlType GfxBitmapOrder::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
