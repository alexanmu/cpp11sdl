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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxJoystickID.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoystickid::joystick::gfx");

namespace gfx
{

namespace joystick
{

const char GfxJoystickID::ClassName[] = "GfxJoystickID";

GfxJoystickID::GfxJoystickID() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoystickID::GfxJoystickID(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    id_ = value;
}

GfxJoystickID::GfxJoystickID(const GfxJoystickID& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    id_ = other.id_;
}

GfxJoystickID::GfxJoystickID(GfxJoystickID&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    id_ = other.id_;
    // Delete other's value
    other.clear();
}

GfxJoystickID& GfxJoystickID::operator=(const GfxJoystickID& other) noexcept
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

GfxJoystickID& GfxJoystickID::operator=(GfxJoystickID&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        id_ = other.id_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxJoystickID::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoystickID::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t  GfxJoystickID::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return id_;
}

void GfxJoystickID::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    id_ = -1;
}

GfxJoystickID::SdlType GfxJoystickID::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return id_;
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
