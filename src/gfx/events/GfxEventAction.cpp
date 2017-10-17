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

#include "GfxEventAction.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gxfeventaction::events::bgi");

namespace gfx
{

namespace events
{

const char GfxEventAction::ClassName[] = "GfxEventAction";

GfxEventAction::GfxEventAction() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxEventAction::GfxEventAction(const ValueType act) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    action_ = static_cast<SdlType>(act);
}

GfxEventAction::GfxEventAction(const SdlType act) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    action_ = act;
}

GfxEventAction::GfxEventAction(GfxEventAction const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    action_ = other.action_;
}

GfxEventAction::GfxEventAction(GfxEventAction&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    action_ = other.action_;
    // Delete other's data
    other.clear();
}

GfxEventAction& GfxEventAction::operator=(GfxEventAction const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        action_ = other.action_;
    }
    return *this;
}

GfxEventAction& GfxEventAction::operator=(GfxEventAction&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        action_ = other.action_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxEventAction::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxEventAction::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxEventAction::ValueType GfxEventAction::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(action_);
}

bool GfxEventAction::isAddEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (action_ == sdl2::SDL_ADDEVENT);
}

bool GfxEventAction::isPeekEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (action_ == sdl2::SDL_PEEKEVENT);
}

bool GfxEventAction::isGetEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (action_ == sdl2::SDL_GETEVENT);
}

void GfxEventAction::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    action_ = static_cast<SdlType>(ValueType::addEvent);
}

GfxEventAction::SdlType GfxEventAction::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return action_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
