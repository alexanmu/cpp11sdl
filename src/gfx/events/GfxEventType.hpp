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

#ifndef GfxEventType_hpp
#define GfxEventType_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace events
{

class GfxEventType final : public GfxObject
{
public:
    typedef sdl2::SDL_EventType SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint16_t
    {
        etFirstEvent = sdl2::SDL_FIRSTEVENT,
        etAppTerminating = sdl2::SDL_APP_TERMINATING,
        etLowMemory = sdl2::SDL_APP_LOWMEMORY,
        etAppWillEnterBackground = sdl2::SDL_APP_WILLENTERBACKGROUND,
        etAppDidEnterBackground = sdl2::SDL_APP_DIDENTERBACKGROUND,
        etAppWillEnterForeground = sdl2::SDL_APP_WILLENTERBACKGROUND,
        etAppDidEnterForeground = sdl2::SDL_APP_DIDENTERFOREGROUND,
        etWindowEvent = sdl2::SDL_WINDOWEVENT,
        etSysWMEvent = sdl2::SDL_SYSWMEVENT,
        etKeyDown = sdl2::SDL_KEYDOWN,
        etKeyUp = sdl2::SDL_KEYUP,
        etTextEditing = sdl2::SDL_TEXTEDITING,
        etTextInput = sdl2::SDL_TEXTINPUT,
        etKeyMapChanged = sdl2::SDL_KEYMAPCHANGED,
        etMouseMotion = sdl2::SDL_MOUSEMOTION,
        etMouseButtonDown = sdl2::SDL_MOUSEBUTTONDOWN,
        etMouseButtonUp = sdl2::SDL_MOUSEBUTTONUP,
        etMouseWheel = sdl2::SDL_MOUSEWHEEL,
        etJoyAxisMotion = sdl2::SDL_JOYAXISMOTION,
        etJoyBallMotion = sdl2::SDL_JOYBALLMOTION,
        etJoyHatMotion = sdl2::SDL_JOYHATMOTION,
        etJoyButtonDown = sdl2::SDL_JOYBUTTONDOWN,
        etJoyButtonUp = sdl2::SDL_JOYBUTTONUP,
        etJoyDeviceAdded = sdl2::SDL_JOYDEVICEADDED,
        etJoyDeviceRemoved = sdl2::SDL_JOYDEVICEREMOVED,
        etControllerAxisMotion = sdl2::SDL_CONTROLLERAXISMOTION,
        etControllerButtonDown = sdl2::SDL_CONTROLLERBUTTONDOWN,
        etControllerButtonUp = sdl2::SDL_CONTROLLERBUTTONUP,
        etControllerDeviceAdded = sdl2::SDL_CONTROLLERDEVICEADDED,
        etControllerDeviceRemoved = sdl2::SDL_CONTROLLERDEVICEREMOVED,
        etControllerDeviceRemapped = sdl2::SDL_CONTROLLERDEVICEREMAPPED,
        etFingerDown = sdl2::SDL_FINGERDOWN,
        etFinderUp = sdl2::SDL_FINGERUP,
        etFingerMotion = sdl2::SDL_FINGERMOTION,
        etDollarGesture = sdl2::SDL_DOLLARGESTURE,
        etDollarRecord = sdl2::SDL_DOLLARRECORD,
        etMultiGesture = sdl2::SDL_MULTIGESTURE,
        etClipboardUpdate = sdl2::SDL_CLIPBOARDUPDATE,
        etDropFile = sdl2::SDL_DROPFILE,
        etDropText = sdl2::SDL_DROPTEXT,
        etDropBegin = sdl2::SDL_DROPBEGIN,
        etDropComplete = sdl2::SDL_DROPCOMPLETE,
        etAudioDeviceAdded = sdl2::SDL_AUDIODEVICEADDED,
        etAudioDeviceRemoved = sdl2::SDL_AUDIODEVICEREMOVED,
        etRenderTargetsReset = sdl2::SDL_RENDER_TARGETS_RESET,
        etRenderDeviceReset = sdl2::SDL_RENDER_DEVICE_RESET,
        etUserEvent = sdl2::SDL_USEREVENT,
        etLastEvent = sdl2::SDL_LASTEVENT
    };

    GfxEventType() noexcept;

    explicit GfxEventType(const ValueType evtype) noexcept;
    explicit GfxEventType(const SdlType evtype) noexcept;

    GfxEventType(const GfxEventType& other) noexcept;
    GfxEventType(GfxEventType&& other) noexcept;

    GfxEventType& operator=(const GfxEventType& other) noexcept;
    GfxEventType& operator=(GfxEventType&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    ValueType getEventType(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType evType_;
};

}  // namespace events

}  // namespace gfx

#endif /* GfxEventType_hpp */
