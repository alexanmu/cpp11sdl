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

#include "GfxGameControllerButton.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgamecontrollerbutton::gamecontroller::gfx");

namespace gfx
{

namespace gamecontroller
{

const char GfxGameControllerButton::ClassName[] = "GfxGameControllerButton";

GfxGameControllerButton::GfxGameControllerButton() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxGameControllerButton::GfxGameControllerButton(const SdlType button) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    button_ = button;
}

GfxGameControllerButton::GfxGameControllerButton(const ValueType button) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    button_ = static_cast<SdlType>(button);
}

GfxGameControllerButton::GfxGameControllerButton(const GfxGameControllerButton& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    button_ = other.button_;
}

GfxGameControllerButton::GfxGameControllerButton(GfxGameControllerButton&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    button_ = other.button_;
    // Delete other's data
    other.clear();
}

GfxGameControllerButton& GfxGameControllerButton::operator=(const GfxGameControllerButton& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        button_ = other.button_;
    }
    return *this;
}

GfxGameControllerButton& GfxGameControllerButton::operator=(GfxGameControllerButton&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        button_ = other.button_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxGameControllerButton::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGameControllerButton::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxGameControllerButton::ValueType GfxGameControllerButton::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(button_);
}

bool GfxGameControllerButton::isButtonInvalid(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_INVALID);
}

bool GfxGameControllerButton::isButtonA(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_A);
}

bool GfxGameControllerButton::isButtonB(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_B);
}

bool GfxGameControllerButton::isButtonX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_X);
}

bool GfxGameControllerButton::isButtonY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_Y);
}

bool GfxGameControllerButton::isButtonBack(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_BACK);
}

bool GfxGameControllerButton::isButtonGuide(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_GUIDE);
}

bool GfxGameControllerButton::isButtonStart(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_START);
}

bool GfxGameControllerButton::isButtonLeftStick(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_LEFTSTICK);
}

bool GfxGameControllerButton::isButtonRightStick(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_RIGHTSTICK);
}

bool GfxGameControllerButton::isButtonLeftShoulder(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
}

bool GfxGameControllerButton::isButtonRightShoulder(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
}

bool GfxGameControllerButton::isButtonDPadUp(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_DPAD_UP);
}

bool GfxGameControllerButton::isButtonDPadDown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_DPAD_DOWN);
}

bool GfxGameControllerButton::isButtonDPadLeft(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_DPAD_LEFT);
}

bool GfxGameControllerButton::isButtonDPadRight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
}

bool GfxGameControllerButton::isButtonMax(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (button_ == SDL_CONTROLLER_BUTTON_MAX);
}

void GfxGameControllerButton::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    button_ = SDL_CONTROLLER_BUTTON_INVALID;
}

GfxGameControllerButton::SdlType GfxGameControllerButton::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return button_;
}

}  // namespace gamecontroller

}  // namespace gfx

/* EOF */
