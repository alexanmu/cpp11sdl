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

#include "GfxButton.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxbutton::mouse::gfx");

namespace gfx
{

namespace mouse
{

const char GfxButton::ClassName[] = "GfxButton";

GfxButton::GfxButton() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxButton::GfxButton(const ValueType button) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    button_ = static_cast<SdlType>(button);
}

GfxButton::GfxButton(const SdlType button) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    button_ = button;
}

GfxButton::GfxButton(const GfxButton& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    button_ = other.button_;
}

GfxButton::GfxButton(GfxButton&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    button_ = other.button_;
    // Delete other's data
    other.clear();
}

GfxButton& GfxButton::operator=(const GfxButton& other) noexcept
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

GfxButton& GfxButton::operator=(GfxButton&& other) noexcept
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

GfxButton::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxButton::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxButton::isLeftButton(void) const noexcept
{
    return (button_ == static_cast<SdlType>(ValueType::buttonLeft));
}

bool GfxButton::isMiddleButton(void) const noexcept
{
    return (button_ == static_cast<SdlType>(ValueType::buttonMiddle));
}

bool GfxButton::isRightButton(void) const noexcept
{
    return (button_ == static_cast<SdlType>(ValueType::buttonRight));
}

bool GfxButton::isX1Button(void) const noexcept
{
    return (button_ == static_cast<SdlType>(ValueType::buttonX1));
}

bool GfxButton::isX2Button(void) const noexcept
{
    return (button_ == static_cast<SdlType>(ValueType::buttonX2));
}

GfxButton::ValueType GfxButton::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(button_);
}

void GfxButton::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    button_ = static_cast<SdlType>(-1);
}

GfxButton::SdlType GfxButton::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return button_;
}

}  // namespace mouse

}  // namespace gfx

/* EOF */
