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

#include "GfxJoystickGUID.hpp"

namespace gfx
{

namespace joystick
{

const char GfxJoystickGUID::ClassName[] = "GfxJoystickGUID";

GfxJoystickGUID::GfxJoystickGUID() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoystickGUID::GfxJoystickGUID(const uint8_t value[]) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    copyValues(const_cast<uint8_t *>(&value[0]));
}

GfxJoystickGUID::GfxJoystickGUID(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    guid_ = value;
}


GfxJoystickGUID::GfxJoystickGUID(const GfxJoystickGUID& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    guid_ = other.guid_;
}

GfxJoystickGUID::GfxJoystickGUID(GfxJoystickGUID&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    guid_ = other.guid_;
    // Delete other's value
    other.clear();
}

GfxJoystickGUID& GfxJoystickGUID::operator=(const GfxJoystickGUID& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        guid_ = other.guid_;
    }
    return *this;
}

GfxJoystickGUID& GfxJoystickGUID::operator=(GfxJoystickGUID&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        guid_ = other.guid_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxJoystickGUID::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxJoystickGUID::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

uint8_t *  GfxJoystickGUID::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint8_t * ptr;

    ptr = static_cast<uint8_t *>(std::malloc(kGuidNumberOfBytes));
    for (int32_t index = 0; index < kGuidNumberOfBytes; index++)
    {
        *(ptr + index) = guid_.data[index];
    }
    return ptr;
}

void GfxJoystickGUID::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    for (int32_t index = 0; index < kGuidNumberOfBytes; index++)
    {
        guid_.data[index] = 0;
    }
}

GfxJoystickGUID::SdlType GfxJoystickGUID::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return guid_;
}

GfxJoystickGUID::SdlTypePtr GfxJoystickGUID::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&guid_;
}

// Private methods
void GfxJoystickGUID::copyValues(uint8_t * values) noexcept
{
    LOG_TRACE_PRIO_LOW();

    for (int32_t index = 0; index < kGuidNumberOfBytes; index++)
    {
        guid_.data[index] = *values;
        values += 1;
    }
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
