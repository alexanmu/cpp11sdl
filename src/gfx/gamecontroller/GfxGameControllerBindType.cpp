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

#include <string>
#include <utility>

#include "GfxGameControllerBindType.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgamecontrollerbindtype::gamecontroller::gfx");

namespace gfx
{

namespace gamecontroller
{

const char GfxGameControllerBindType::ClassName[] = "GfxGameControllerBindType";

GfxGameControllerBindType::GfxGameControllerBindType() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxGameControllerBindType::GfxGameControllerBindType(const SdlType btype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    bType_ = btype;
}

GfxGameControllerBindType::GfxGameControllerBindType(const ValueType btype) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    bType_ = static_cast<SdlType>(btype);
}

GfxGameControllerBindType::GfxGameControllerBindType(const GfxGameControllerBindType& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    bType_ = other.bType_;
}

GfxGameControllerBindType::GfxGameControllerBindType(GfxGameControllerBindType&& other) noexcept :
        GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    bType_ = other.bType_;
    // Delete other's data
    other.clear();
}

GfxGameControllerBindType& GfxGameControllerBindType::operator=(const GfxGameControllerBindType& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        bType_ = other.bType_;
    }
    return *this;
}

GfxGameControllerBindType& GfxGameControllerBindType::operator=(GfxGameControllerBindType&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        bType_ = other.bType_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxGameControllerBindType::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGameControllerBindType::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxGameControllerBindType::ValueType GfxGameControllerBindType::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(bType_);
}

bool GfxGameControllerBindType::isBindTypeNone(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (bType_ == SDL_CONTROLLER_BINDTYPE_NONE);
}

bool GfxGameControllerBindType::isBindTypeNormal(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (bType_ == SDL_CONTROLLER_BINDTYPE_BUTTON);
}

bool GfxGameControllerBindType::isBindTypeAxis(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (bType_ == SDL_CONTROLLER_BINDTYPE_AXIS);
}

bool GfxGameControllerBindType::isBindTypeHat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (bType_ == SDL_CONTROLLER_BINDTYPE_HAT);
}

void GfxGameControllerBindType::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    bType_ = SDL_CONTROLLER_BINDTYPE_NONE;
}

GfxGameControllerBindType::SdlType GfxGameControllerBindType::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return bType_;
}

}  // namespace gamecontroller

}  // namespace gfx

/* EOF */
