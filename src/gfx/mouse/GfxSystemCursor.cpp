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

GfxSystemCursor::GfxSystemCursor(const GfxSystemCursor& other) noexcept : GfxObject(other)
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

GfxSystemCursor& GfxSystemCursor::operator=(const GfxSystemCursor& other) noexcept
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

void GfxSystemCursor::setCursorArrow(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorArrow);
}

void GfxSystemCursor::setCursorIBeam(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorIBeam);
}

void GfxSystemCursor::setCursorWait(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorWait);
}

void GfxSystemCursor::setCursorCrosshair(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorCrosshair);
}

void GfxSystemCursor::setCursorWaitArrow(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorWaitArrow);
}

void GfxSystemCursor::setCursorSizeNorthWestSouthEast(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorSizeNorthWestSouthEast);
}

void GfxSystemCursor::setCursorSizeNortheEastSouthWest(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorSizeNorthEastSouthWest);
}

void GfxSystemCursor::setCursorSizeWestEast(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorSizeWestEast);
}

void GfxSystemCursor::setCursorSizeNorthSouth(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorSizeNorthSouth);
}

void GfxSystemCursor::setCursorSizeAll(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorSizeAll);
}

void GfxSystemCursor::setCursorNo(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorNo);
}


void GfxSystemCursor::setCursorHand(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cursor_ = static_cast<SdlType>(ValueType::sysCursorHand);
}

bool GfxSystemCursor::isCursorArrow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorArrow));
}

bool GfxSystemCursor::isCursorIBeam(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorIBeam));
}

bool GfxSystemCursor::isCursorWait(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorWait));
}

bool GfxSystemCursor::isCursorCrosshair(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorCrosshair));
}

bool GfxSystemCursor::isCursorWaitArrow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorWaitArrow));
}

bool GfxSystemCursor::isCursorSizeNorthWestSouthEast(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorSizeNorthWestSouthEast));
}

bool GfxSystemCursor::isCursorSizeNortheEastSouthWest(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorSizeNorthEastSouthWest));
}

bool GfxSystemCursor::isCursorSizeWestEast(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorSizeWestEast));
}

bool GfxSystemCursor::isCursorSizeNorthSouth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorSizeNorthSouth));
}

bool GfxSystemCursor::isCursorSizeAll(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorSizeAll));
}

bool GfxSystemCursor::isCursorNo(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorNo));
}


bool GfxSystemCursor::isCursorHand(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (cursor_ == static_cast<SdlType>(ValueType::sysCursorHand));
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
