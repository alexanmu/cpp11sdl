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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

class GfxWindowEventID final : public GfxRootClass
{
public:
    typedef SDL_WindowEventID SdlType;
    typedef SDL_WindowEventID* SdlTypePtr;

    enum class GfxWindowEventIDValues : int
    {
        eventNone = SDL_WINDOWEVENT_NONE,
        eventShown = SDL_WINDOWEVENT_SHOWN,
        eventHidden = SDL_WINDOWEVENT_HIDDEN,
        eventExposed = SDL_WINDOWEVENT_EXPOSED,
        eventMoved = SDL_WINDOWEVENT_MOVED,
        eventResized = SDL_WINDOWEVENT_RESIZED,
        eventSizeChanged = SDL_WINDOWEVENT_SIZE_CHANGED,
        eventMinimized = SDL_WINDOWEVENT_MINIMIZED,
        eventMaximized = SDL_WINDOWEVENT_MAXIMIZED,
        eventRestored = SDL_WINDOWEVENT_RESTORED,
        eventEnter = SDL_WINDOWEVENT_ENTER,
        eventLeave = SDL_WINDOWEVENT_LEAVE,
        eventFocusGained = SDL_WINDOWEVENT_FOCUS_GAINED,
        eventFocusLost = SDL_WINDOWEVENT_FOCUS_LOST,
        eventClose = SDL_WINDOWEVENT_CLOSE,
        eventTakeFocus = SDL_WINDOWEVENT_TAKE_FOCUS,
        eventHitTest = SDL_WINDOWEVENT_HIT_TEST
    };

    GfxWindowEventID();
    GfxWindowEventID(GfxWindowEventIDValues eventid);
    GfxWindowEventID(SdlType eventid);
    GfxWindowEventID(SdlTypePtr eventid);
    GfxWindowEventID(GfxWindowEventID const& other);
    GfxWindowEventID(GfxWindowEventID&& other);
    
    GfxWindowEventID& operator=(GfxWindowEventID const& other);
    GfxWindowEventID& operator=(GfxWindowEventID&& other);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType eventid_;
};

#endif /* GfxWindowEventID_hpp */
