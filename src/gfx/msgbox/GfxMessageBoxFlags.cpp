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

#include <cassert>
#include <string>
#include <utility>

#include "GfxMessageBoxFlags.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxflags::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxFlags::ClassName[] = "GfxMessageBoxFlags";

GfxMessageBoxFlags::GfxMessageBoxFlags() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMessageBoxFlags::GfxMessageBoxFlags(const ValueType flag) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();

    flag_ = static_cast<SdlType>(flag);
}

GfxMessageBoxFlags::GfxMessageBoxFlags(const SdlType flag) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flag > 0);

    flag_ = flag;
}

GfxMessageBoxFlags::GfxMessageBoxFlags(GfxMessageBoxFlags const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    flag_ = other.flag_;
}

GfxMessageBoxFlags::GfxMessageBoxFlags(GfxMessageBoxFlags&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flag_ = other.flag_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxFlags& GfxMessageBoxFlags::operator=(GfxMessageBoxFlags const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flag_ = other.flag_;
    }
    return *this;
}

GfxMessageBoxFlags& GfxMessageBoxFlags::operator=(GfxMessageBoxFlags&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flag_ = other.flag_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxMessageBoxFlags::operator==(GfxMessageBoxFlags const& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flag_ == other.flag_);
}

GfxMessageBoxFlags::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxFlags::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxMessageBoxFlags::ValueType GfxMessageBoxFlags::getFlag(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(flag_);
}

bool GfxMessageBoxFlags::isError(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flag_ == SDL_MESSAGEBOX_ERROR);
}

bool GfxMessageBoxFlags::isWarning(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flag_ == SDL_MESSAGEBOX_WARNING);
}

bool GfxMessageBoxFlags::isInformation(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flag_ == SDL_MESSAGEBOX_INFORMATION);
}

void GfxMessageBoxFlags::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flag_ = static_cast<SdlType>(ValueType::flagError);
}

GfxMessageBoxFlags::SdlType GfxMessageBoxFlags::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlType)flag_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */
