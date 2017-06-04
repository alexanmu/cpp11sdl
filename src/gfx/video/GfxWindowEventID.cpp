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
#include <cassert>
#include <string>

#include "GfxWindowEventID.hpp"

namespace gfx
{

namespace video
{

const char GfxWindowEventID::ClassName[] = "GfxWindowEventID";

GfxWindowEventID::GfxWindowEventID() noexcept : GfxRootClass(ClassName)
{
    clear();
}

GfxWindowEventID::GfxWindowEventID(ValueType eventid) noexcept : GfxRootClass(ClassName)
{
    eventid_ = static_cast<SdlType>(eventid);
}

GfxWindowEventID::GfxWindowEventID(SdlType eventid) noexcept : GfxRootClass(ClassName)
{
    assert(eventid >= 0);

    eventid_ = eventid;
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventID const& other) noexcept : GfxRootClass(ClassName)
{
    eventid_ = other.eventid_;
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventID&& other) noexcept : GfxRootClass(ClassName)
{
    eventid_ = other.eventid_;
    // Delete other's data
    other.clear();
}

GfxWindowEventID& GfxWindowEventID::operator=(GfxWindowEventID const& other) noexcept
{
    if (this != &other)
    {
        eventid_ = other.eventid_;
    }
    return *this;
}

GfxWindowEventID& GfxWindowEventID::operator=(GfxWindowEventID&& other) noexcept
{
    if (this != &other)
    {
        eventid_ = other.eventid_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxWindowEventID::isShown(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_SHOWN);
}

bool GfxWindowEventID::isHidden(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_HIDDEN);
}

bool GfxWindowEventID::isExposed(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_EXPOSED);
}

bool GfxWindowEventID::isMoved(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MOVED);
}

bool GfxWindowEventID::isResized(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_RESIZED);
}

bool GfxWindowEventID::isSizeChanged(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_SIZE_CHANGED);
}

bool GfxWindowEventID::isMinimized(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MINIMIZED);
}

bool GfxWindowEventID::isMaximized(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MAXIMIZED);
}

bool GfxWindowEventID::isRestored(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_RESTORED);
}

bool GfxWindowEventID::enter(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_ENTER);
}

bool GfxWindowEventID::leave(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_LEAVE);
}

bool GfxWindowEventID::isFocusGained(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_FOCUS_GAINED);
}

bool GfxWindowEventID::isFocusLost(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_FOCUS_LOST);
}

bool GfxWindowEventID::close(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_CLOSE);
}

bool GfxWindowEventID::takeFocus(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_TAKE_FOCUS);
}

bool GfxWindowEventID::hitTest(void) const noexcept
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_HIT_TEST);
}

void GfxWindowEventID::clear(void) noexcept
{
    eventid_ = static_cast<SdlType>(ValueType::eventNone);
}

GfxWindowEventID::SdlType GfxWindowEventID::getAsSdlType(void) const noexcept
{
    return eventid_;
}

GfxWindowEventID::SdlTypePtr GfxWindowEventID::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&eventid_;
}

}  // namespace video

}  // namespace gfx

/* EOF */
