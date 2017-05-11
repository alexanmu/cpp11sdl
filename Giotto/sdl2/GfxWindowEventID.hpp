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

#ifndef GfxWindowEventID_hpp
#define GfxWindowEventID_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxWindowEventID final : public GfxRootClass
{
public:
    typedef sdl2::SDL_WindowEventID SdlType;
    typedef sdl2::SDL_WindowEventID* SdlTypePtr;

    static const char ClassName[];

    enum class GfxWindowEventIDValues : int
    {
        eventNone = sdl2::SDL_WINDOWEVENT_NONE,
        eventShown = sdl2::SDL_WINDOWEVENT_SHOWN,
        eventHidden = sdl2::SDL_WINDOWEVENT_HIDDEN,
        eventExposed = sdl2::SDL_WINDOWEVENT_EXPOSED,
        eventMoved = sdl2::SDL_WINDOWEVENT_MOVED,
        eventResized = sdl2::SDL_WINDOWEVENT_RESIZED,
        eventSizeChanged = sdl2::SDL_WINDOWEVENT_SIZE_CHANGED,
        eventMinimized = sdl2::SDL_WINDOWEVENT_MINIMIZED,
        eventMaximized = sdl2::SDL_WINDOWEVENT_MAXIMIZED,
        eventRestored = sdl2::SDL_WINDOWEVENT_RESTORED,
        eventEnter = sdl2::SDL_WINDOWEVENT_ENTER,
        eventLeave = sdl2::SDL_WINDOWEVENT_LEAVE,
        eventFocusGained = sdl2::SDL_WINDOWEVENT_FOCUS_GAINED,
        eventFocusLost = sdl2::SDL_WINDOWEVENT_FOCUS_LOST,
        eventClose = sdl2::SDL_WINDOWEVENT_CLOSE,
        eventTakeFocus = sdl2::SDL_WINDOWEVENT_TAKE_FOCUS,
        eventHitTest = sdl2::SDL_WINDOWEVENT_HIT_TEST
    };

    GfxWindowEventID();

    explicit GfxWindowEventID(const GfxWindowEventIDValues eventid);
    explicit GfxWindowEventID(const SdlType eventid);

    GfxWindowEventID(GfxWindowEventID const& other);
    GfxWindowEventID(GfxWindowEventID&& other);

    GfxWindowEventID& operator=(GfxWindowEventID const& other);
    GfxWindowEventID& operator=(GfxWindowEventID&& other);

    // Getters
    bool isShown(void) const;
    bool isHidden(void) const;
    bool isExposed(void) const;
    bool isMoved(void) const;
    bool isResized(void) const;
    bool isSizeChanged(void) const;
    bool isMinimized(void) const;
    bool isMaximized(void) const;
    bool isRestored(void) const;
    bool enter(void) const;
    bool leave(void) const;
    bool isFocusGained(void) const;
    bool isFocusLost(void) const;
    bool close(void) const;
    bool takeFocus(void) const;
    bool hitTest(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType eventid_;
};

}  // namespace gfx

#endif /* GfxWindowEventID_hpp */
