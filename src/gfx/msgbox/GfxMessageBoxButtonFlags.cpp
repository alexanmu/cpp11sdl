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

#include "GfxMessageBoxButtonFlags.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxmessageboxbuttonflags::msgbox::gfx");

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxButtonFlags::ClassName[] = "GfxMessageBoxButtonFlags";

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const ValueType flags) noexcept :
        GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flags_ = static_cast<SdlType>(flags);
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const SdlType flags) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags > 0);
    assert(flags < 3);

    flags_ = flags;
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const GfxMessageBoxButtonFlags& other) noexcept :
        GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags&& other) noexcept :
        GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(const GfxMessageBoxButtonFlags& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flags_ = other.flags_;
    }
    return *this;
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(GfxMessageBoxButtonFlags&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxMessageBoxButtonFlags::operator==(const GfxMessageBoxButtonFlags& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flags_ == other.flags_);
}

GfxMessageBoxButtonFlags::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxMessageBoxButtonFlags::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxMessageBoxButtonFlags::isReturnDefault(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flags_ == SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT);
}

bool GfxMessageBoxButtonFlags::isEscDefault(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (flags_ == SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT);
}

void GfxMessageBoxButtonFlags::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flags_ = static_cast<SdlType>(ValueType::noneDefault);
}

GfxMessageBoxButtonFlags::SdlType GfxMessageBoxButtonFlags::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return flags_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */
