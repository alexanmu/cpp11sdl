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

#include "GfxJoystickType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoysticktype::joystick::gfx");

namespace gfx
{

namespace joystick
{

const char GfxJoystickType::ClassName[] = "GfxJoystickType";

GfxJoystickType::GfxJoystickType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoystickType::GfxJoystickType(const SdlType type) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = type;
}

GfxJoystickType::GfxJoystickType(const ValueType type) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = static_cast<SdlType>(type);
}


GfxJoystickType::GfxJoystickType(const GfxJoystickType& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = other.type_;
}

GfxJoystickType::GfxJoystickType(GfxJoystickType&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    type_ = other.type_;
    // Delete other's value
    other.clear();
}

GfxJoystickType& GfxJoystickType::operator=(const GfxJoystickType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        type_ = other.type_;
    }
    return *this;
}

GfxJoystickType& GfxJoystickType::operator=(GfxJoystickType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        type_ = other.type_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxJoystickType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoystickType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxJoystickType::ValueType  GfxJoystickType::getType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(type_);
}

void GfxJoystickType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    type_ = static_cast<SdlType>(ValueType::typeUnknown);
}

GfxJoystickType::SdlType GfxJoystickType::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return type_;
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
