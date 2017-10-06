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

#include "GfxGameControllerButtonBind.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgamecontrollerbuttonbind::gamecontroller::gfx");

namespace gfx
{

namespace gamecontroller
{

const char GfxGameControllerButtonBind::ClassName[] = "GfxGameControllerButtonBind";

GfxGameControllerButtonBind::GfxGameControllerButtonBind() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxGameControllerButtonBind::GfxGameControllerButtonBind(const SdlType bbind) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    buttonBind_ = bbind;
}

GfxGameControllerButtonBind::GfxGameControllerButtonBind(GfxGameControllerButtonBind const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    buttonBind_ = other.buttonBind_;
}

GfxGameControllerButtonBind::GfxGameControllerButtonBind(GfxGameControllerButtonBind&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    buttonBind_ = other.buttonBind_;
    // Delete other's data
    other.clear();
}

GfxGameControllerButtonBind& GfxGameControllerButtonBind::operator=(GfxGameControllerButtonBind const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        buttonBind_ = other.buttonBind_;
    }
    return *this;
}

GfxGameControllerButtonBind& GfxGameControllerButtonBind::operator=(GfxGameControllerButtonBind&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        buttonBind_ = other.buttonBind_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxGameControllerButtonBind::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGameControllerButtonBind::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxGameControllerBindType GfxGameControllerButtonBind::getBindType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxGameControllerBindType(buttonBind_.bindType);
}

int32_t GfxGameControllerButtonBind::getButton(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return buttonBind_.value.button;
}

int32_t GfxGameControllerButtonBind::getAxis(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return buttonBind_.value.axis;
}

int32_t GfxGameControllerButtonBind::getHat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return buttonBind_.value.hat.hat;
}

int32_t GfxGameControllerButtonBind::getHatMask(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return buttonBind_.value.hat.hat_mask;
}

void GfxGameControllerButtonBind::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    buttonBind_.bindType = sdl2::SDL_CONTROLLER_BINDTYPE_NONE;
    buttonBind_.value.axis = 0;
    buttonBind_.value.button = 0;
}

GfxGameControllerButtonBind::SdlType GfxGameControllerButtonBind::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return buttonBind_;
}

}  // namespace gamecontroller

}  // namespace gfx

/* EOF */
