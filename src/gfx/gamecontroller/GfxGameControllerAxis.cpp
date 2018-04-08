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

#include "GfxGameControllerAxis.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgamecontrolleraxis::gamecontroller::gfx");

namespace gfx
{

namespace gamecontroller
{

const char GfxGameControllerAxis::ClassName[] = "GfxGameControllerAxis";

GfxGameControllerAxis::GfxGameControllerAxis() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxGameControllerAxis::GfxGameControllerAxis(const SdlType axis) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    axis_ = axis;
}

GfxGameControllerAxis::GfxGameControllerAxis(const ValueType axis) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    axis_ = static_cast<SdlType>(axis);
}

GfxGameControllerAxis::GfxGameControllerAxis(GfxGameControllerAxis const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    axis_ = other.axis_;
}

GfxGameControllerAxis::GfxGameControllerAxis(GfxGameControllerAxis&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    axis_ = other.axis_;
    // Delete other's data
    other.clear();
}

GfxGameControllerAxis& GfxGameControllerAxis::operator=(GfxGameControllerAxis const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        axis_ = other.axis_;
    }
    return *this;
}

GfxGameControllerAxis& GfxGameControllerAxis::operator=(GfxGameControllerAxis&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        axis_ = other.axis_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxGameControllerAxis::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGameControllerAxis::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxGameControllerAxis::ValueType GfxGameControllerAxis::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(axis_);
}

bool GfxGameControllerAxis::isAxisInvalid(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_INVALID);
}

bool GfxGameControllerAxis::isAxisLeftX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_LEFTX);
}

bool GfxGameControllerAxis::isAxisLeftY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_LEFTY);
}

bool GfxGameControllerAxis::isAxisRightX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_RIGHTX);
}

bool GfxGameControllerAxis::isAxisRightY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_RIGHTY);
}

bool GfxGameControllerAxis::isAxisTriggerLeft(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_TRIGGERLEFT);
}

bool GfxGameControllerAxis::isAxisTriggerRight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
}

bool GfxGameControllerAxis::isAxisMax(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (axis_ == SDL_CONTROLLER_AXIS_MAX);
}

void GfxGameControllerAxis::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    axis_ = SDL_CONTROLLER_AXIS_INVALID;
}

GfxGameControllerAxis::SdlType GfxGameControllerAxis::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return axis_;
}

}  // namespace gamecontroller

}  // namespace gfx

/* EOF */
