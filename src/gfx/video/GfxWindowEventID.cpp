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

#include "GfxWindowEventID.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxwindoweventid::video::gfx");

namespace gfx
{

namespace video
{

const char GfxWindowEventID::ClassName[] = "GfxWindowEventID";

GfxWindowEventID::GfxWindowEventID() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxWindowEventID::GfxWindowEventID(const ValueType eventid) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    eventid_ = static_cast<SdlType>(eventid);
}

GfxWindowEventID::GfxWindowEventID(const SdlType eventid) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    eventid_ = eventid;
}

GfxWindowEventID::GfxWindowEventID(const uint8_t eventid) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    eventid_ = static_cast<SdlType>(eventid);
}

GfxWindowEventID::GfxWindowEventID(const GfxWindowEventID& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    eventid_ = other.eventid_;
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventID&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    eventid_ = other.eventid_;
    // Delete other's data
    other.clear();
}

GfxWindowEventID& GfxWindowEventID::operator=(const GfxWindowEventID& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        eventid_ = other.eventid_;
    }
    return *this;
}

GfxWindowEventID& GfxWindowEventID::operator=(GfxWindowEventID&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        eventid_ = other.eventid_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxWindowEventID::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxWindowEventID::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxWindowEventID::isShown(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_SHOWN);
}

bool GfxWindowEventID::isHidden(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_HIDDEN);
}

bool GfxWindowEventID::isExposed(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_EXPOSED);
}

bool GfxWindowEventID::isMoved(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_MOVED);
}

bool GfxWindowEventID::isResized(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_RESIZED);
}

bool GfxWindowEventID::isSizeChanged(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_SIZE_CHANGED);
}

bool GfxWindowEventID::isMinimized(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_MINIMIZED);
}

bool GfxWindowEventID::isMaximized(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_MAXIMIZED);
}

bool GfxWindowEventID::isRestored(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_RESTORED);
}

bool GfxWindowEventID::enter(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_ENTER);
}

bool GfxWindowEventID::leave(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_LEAVE);
}

bool GfxWindowEventID::isFocusGained(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_FOCUS_GAINED);
}

bool GfxWindowEventID::isFocusLost(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_FOCUS_LOST);
}

bool GfxWindowEventID::close(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_CLOSE);
}

bool GfxWindowEventID::takeFocus(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_TAKE_FOCUS);
}

bool GfxWindowEventID::hitTest(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (eventid_ == SDL_WINDOWEVENT_HIT_TEST);
}

void GfxWindowEventID::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    eventid_ = static_cast<SdlType>(ValueType::eventNone);
}

GfxWindowEventID::SdlType GfxWindowEventID::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return eventid_;
}

}  // namespace video

}  // namespace gfx

/* EOF */
