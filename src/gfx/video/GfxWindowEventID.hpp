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

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace video
{

class GfxWindowEventID final : public GfxRootClass
{
public:
    typedef sdl2::SDL_WindowEventID SdlType;
    typedef sdl2::SDL_WindowEventID* SdlTypePtr;

    static const char ClassName[];

    enum class ValueType : int32_t
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

    GfxWindowEventID() noexcept;

    explicit GfxWindowEventID(const ValueType eventid) noexcept;
    explicit GfxWindowEventID(const SdlType eventid) noexcept;

    GfxWindowEventID(GfxWindowEventID const& other) noexcept;
    GfxWindowEventID(GfxWindowEventID&& other) noexcept;

    GfxWindowEventID& operator=(GfxWindowEventID const& other) noexcept;
    GfxWindowEventID& operator=(GfxWindowEventID&& other) noexcept;

    // Getters
    bool isShown(void) const noexcept;
    bool isHidden(void) const noexcept;
    bool isExposed(void) const noexcept;
    bool isMoved(void) const noexcept;
    bool isResized(void) const noexcept;
    bool isSizeChanged(void) const noexcept;
    bool isMinimized(void) const noexcept;
    bool isMaximized(void) const noexcept;
    bool isRestored(void) const noexcept;
    bool enter(void) const noexcept;
    bool leave(void) const noexcept;
    bool isFocusGained(void) const noexcept;
    bool isFocusLost(void) const noexcept;
    bool close(void) const noexcept;
    bool takeFocus(void) const noexcept;
    bool hitTest(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType eventid_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindowEventID_hpp */
