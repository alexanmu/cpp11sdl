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

#include "GfxHatPosition.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhatposition::joystick::gfx");

namespace gfx
{

namespace joystick
{

const char GfxHatPosition::ClassName[] = "GfxHatPosition";

GfxHatPosition::GfxHatPosition() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxHatPosition::GfxHatPosition(const ValueType position) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hatPosition_ = static_cast<SdlType>(position);
}

GfxHatPosition::GfxHatPosition(const SdlType position) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    hatPosition_ = position;
}

GfxHatPosition::GfxHatPosition(const GfxHatPosition& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    hatPosition_ = other.hatPosition_;
}

GfxHatPosition::GfxHatPosition(GfxHatPosition&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    hatPosition_ = other.hatPosition_;
    // Delete other's value
    other.clear();
}

GfxHatPosition& GfxHatPosition::operator=(const GfxHatPosition& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        hatPosition_ = other.hatPosition_;
    }
    return *this;
}

GfxHatPosition& GfxHatPosition::operator=(GfxHatPosition&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        hatPosition_ = other.hatPosition_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxHatPosition::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHatPosition::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxHatPosition::ValueType GfxHatPosition::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(hatPosition_);
}

bool GfxHatPosition::isCentered(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_CENTERED);
}

bool GfxHatPosition::isUp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_UP);
}

bool GfxHatPosition::isRight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_RIGHT);
}

bool GfxHatPosition::isDown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_DOWN);
}

bool GfxHatPosition::isLeft(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_LEFT);
}

bool GfxHatPosition::isRightUp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_RIGHTUP);
}

bool GfxHatPosition::isRightDown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_RIGHTDOWN);
}

bool GfxHatPosition::isLeftUp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_LEFTUP);
}

bool GfxHatPosition::isLeftDown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (hatPosition_ == SDL_HAT_LEFTDOWN);
}

void GfxHatPosition::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    hatPosition_ = static_cast<SdlType>(ValueType::hatCentered);
}

GfxHatPosition::SdlType GfxHatPosition::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hatPosition_;
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
