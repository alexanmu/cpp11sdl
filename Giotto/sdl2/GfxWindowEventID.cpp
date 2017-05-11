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

#include "GfxWindowEventID.hpp"

namespace gfx
{

const char GfxWindowEventID::ClassName[] = "GfxWindowEventID";

GfxWindowEventID::GfxWindowEventID() : GfxRootClass(ClassName)
{
    eventid_ = static_cast<SdlType>(GfxWindowEventIDValues::eventNone);
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventIDValues eventid) : GfxRootClass(ClassName)
{
    eventid_ = static_cast<SdlType>(eventid);
}

GfxWindowEventID::GfxWindowEventID(SdlType eventid) : GfxRootClass(ClassName)
{
    eventid_ = eventid;
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventID const& other) : GfxRootClass(ClassName)
{
    eventid_ = other.eventid_;
}

GfxWindowEventID::GfxWindowEventID(GfxWindowEventID&& other) : GfxRootClass(ClassName)
{
    eventid_ = other.eventid_;
    // Delete other's data
    other.eventid_ = static_cast<SdlType>(GfxWindowEventIDValues::eventNone);
}

GfxWindowEventID& GfxWindowEventID::operator=(GfxWindowEventID const& other)
{
    if (this != &other)
    {
        eventid_ = other.eventid_;
    }
    return *this;
}

GfxWindowEventID& GfxWindowEventID::operator=(GfxWindowEventID&& other)
{
    if (this != &other)
    {
        eventid_ = other.eventid_;
        // Delete other's data
        other.eventid_ = static_cast<SdlType>(GfxWindowEventIDValues::eventNone);
    }
    return *this;
}

bool GfxWindowEventID::isShown(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_SHOWN);
}

bool GfxWindowEventID::isHidden(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_HIDDEN);
}

bool GfxWindowEventID::isExposed(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_EXPOSED);
}

bool GfxWindowEventID::isMoved(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MOVED);
}

bool GfxWindowEventID::isResized(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_RESIZED);
}

bool GfxWindowEventID::isSizeChanged(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_SIZE_CHANGED);
}

bool GfxWindowEventID::isMinimized(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MINIMIZED);
}

bool GfxWindowEventID::isMaximized(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_MAXIMIZED);
}

bool GfxWindowEventID::isRestored(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_RESTORED);
}

bool GfxWindowEventID::enter(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_ENTER);
}

bool GfxWindowEventID::leave(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_LEAVE);
}

bool GfxWindowEventID::isFocusGained(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_FOCUS_GAINED);
}

bool GfxWindowEventID::isFocusLost(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_FOCUS_LOST);
}

bool GfxWindowEventID::close(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_CLOSE);
}

bool GfxWindowEventID::takeFocus(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_TAKE_FOCUS);
}

bool GfxWindowEventID::hitTest(void) const
{
    return (eventid_ == sdl2::SDL_WINDOWEVENT_HIT_TEST);
}


GfxWindowEventID::SdlType GfxWindowEventID::getAsSdlType(void) const
{
    return eventid_;
}

GfxWindowEventID::SdlTypePtr GfxWindowEventID::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&eventid_;
}

}  // namespace gfx

/* EOF */
