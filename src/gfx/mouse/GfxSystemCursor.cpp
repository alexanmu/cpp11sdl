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

#include "GfxSystemCursor.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxsystemcursor::mouse::gfx");

namespace gfx
{

namespace mouse
{

const char GfxSystemCursor::ClassName[] = "GfxSystemCursor";

GfxSystemCursor::GfxSystemCursor() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxSystemCursor::GfxSystemCursor(const ValueType cursor) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    cursor_ = static_cast<SdlType>(cursor);
}

GfxSystemCursor::GfxSystemCursor(const SdlType cursor) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    cursor_ = cursor;
}

GfxSystemCursor::GfxSystemCursor(GfxSystemCursor const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    cursor_ = other.cursor_;
}

GfxSystemCursor::GfxSystemCursor(GfxSystemCursor&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    cursor_ = other.cursor_;
    // Delete other's data
    other.clear();
}

GfxSystemCursor& GfxSystemCursor::operator=(GfxSystemCursor const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        cursor_ = other.cursor_;
    }
    return *this;
}

GfxSystemCursor& GfxSystemCursor::operator=(GfxSystemCursor&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        cursor_ = other.cursor_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxSystemCursor::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxSystemCursor::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxSystemCursor::ValueType GfxSystemCursor::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(cursor_);
}

void GfxSystemCursor::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorArrow);
}

GfxSystemCursor::SdlType GfxSystemCursor::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return cursor_;
}

}  // namespace mouse

}  // namespace gfx

/* EOF */
