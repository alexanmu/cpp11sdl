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

#include <cassert>
#include <string>
#include <utility>

#include "GfxTouchID.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtouchid::touch::gfx");

namespace gfx
{

namespace touch
{

const char GfxTouchID::ClassName[] = "GfxTouchID";

GfxTouchID::GfxTouchID() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTouchID::GfxTouchID(const SdlType id) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(id >= 0);

    id_ = id;
}

GfxTouchID::GfxTouchID(const GfxTouchID& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    id_ = other.id_;
}

GfxTouchID::GfxTouchID(GfxTouchID&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    id_ = other.id_;
    // Delete other's data
    other.clear();
}

GfxTouchID& GfxTouchID::operator=(const GfxTouchID& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        id_ = other.id_;
    }
    return *this;
}

GfxTouchID& GfxTouchID::operator=(GfxTouchID&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        id_ = other.id_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTouchID::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTouchID::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxTouchID::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    id_ = static_cast<SdlType>(-1);
}

GfxTouchID::SdlType GfxTouchID::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return id_;
}

}  // namespace touch

}  // namespace gfx

/* EOF */
