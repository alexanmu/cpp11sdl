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

#include "GfxFillStyles.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxfillstyles::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxFillStyles::ClassName[] = "GfxFillStyles";

GfxFillStyles::GfxFillStyles() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxFillStyles::GfxFillStyles(const ValueType fill) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    fill_ = static_cast<BgiType>(fill);
}

GfxFillStyles::GfxFillStyles(const BgiType fill) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    fill_ = fill;
}

GfxFillStyles::GfxFillStyles(const GfxFillStyles& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    fill_ = other.fill_;
}

GfxFillStyles::GfxFillStyles(GfxFillStyles&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    fill_ = other.fill_;
    // Delete other's value
    other.clear();
}

GfxFillStyles& GfxFillStyles::operator=(const GfxFillStyles& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        fill_ = other.fill_;
    }
    return *this;
}

GfxFillStyles& GfxFillStyles::operator=(GfxFillStyles&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        fill_ = other.fill_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxFillStyles::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxFillStyles::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxFillStyles::ValueType GfxFillStyles::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(fill_);
}

void GfxFillStyles::setValue(const ValueType fill) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fill_ = static_cast<BgiType>(fill);
}

bool GfxFillStyles::isEmptyFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::EMPTY_FILL);
}

bool GfxFillStyles::isSolidFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::SOLID_FILL);
}

bool GfxFillStyles::isLineFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::LINE_FILL);
}

bool GfxFillStyles::isLightSlashFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::LTSLASH_FILL);
}

bool GfxFillStyles::isSlashFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::SLASH_FILL);
}

bool GfxFillStyles::isBackSlashFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::BKSLASH_FILL);
}

bool GfxFillStyles::isLightBackSlashFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::LTBKSLASH_FILL);
}

bool GfxFillStyles::isHatchFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::HATCH_FILL);
}

bool GfxFillStyles::isXHatchFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::XHATCH_FILL);
}

bool GfxFillStyles::isInterleaveFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::INTERLEAVE_FILL);
}

bool GfxFillStyles::isWideDotFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::WIDE_DOT_FILL);
}

bool GfxFillStyles::isCloseDotFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::CLOSE_DOT_FILL);
}

bool GfxFillStyles::isUserFill(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (fill_ == prv::GfxCanvasBgi::bgiFillStyles::USER_FILL);
}

void GfxFillStyles::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    fill_ = static_cast<BgiType>(ValueType::solidFill);
}

GfxFillStyles::BgiType GfxFillStyles::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fill_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
