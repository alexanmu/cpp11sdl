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

#ifndef GfxEventType_hpp
#define GfxEventType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxEventConstants.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace events
{

class GfxEventType final : public GfxObject
{
public:
    typedef SDL_EventType SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint16_t
    {
        evFirstEvent = SDL_FIRSTEVENT,
        evQuit = SDL_QUIT,
        evAppTerminating = SDL_APP_TERMINATING,
        evLowMemory = SDL_APP_LOWMEMORY,
        evAppWillEnterBackground = SDL_APP_WILLENTERBACKGROUND,
        evAppDidEnterBackground = SDL_APP_DIDENTERBACKGROUND,
        evAppWillEnterForeground = SDL_APP_WILLENTERFOREGROUND,
        evAppDidEnterForeground = SDL_APP_DIDENTERFOREGROUND,
        evWindowEvent = SDL_WINDOWEVENT,
        evSysWMEvent = SDL_SYSWMEVENT,
        evKeyDown = SDL_KEYDOWN,
        evKeyUp = SDL_KEYUP,
        evTextEditing = SDL_TEXTEDITING,
        evTextInput = SDL_TEXTINPUT,
        evKeyMapChanged = SDL_KEYMAPCHANGED,
        evMouseMotion = SDL_MOUSEMOTION,
        evMouseButtonDown = SDL_MOUSEBUTTONDOWN,
        evMouseButtonUp = SDL_MOUSEBUTTONUP,
        evMouseWheel = SDL_MOUSEWHEEL,
        evJoyAxisMotion = SDL_JOYAXISMOTION,
        evJoyBallMotion = SDL_JOYBALLMOTION,
        evJoyHatMotion = SDL_JOYHATMOTION,
        evJoyButtonDown = SDL_JOYBUTTONDOWN,
        evJoyButtonUp = SDL_JOYBUTTONUP,
        evJoyDeviceAdded = SDL_JOYDEVICEADDED,
        evJoyDeviceRemoved = SDL_JOYDEVICEREMOVED,
        evControllerAxisMotion = SDL_CONTROLLERAXISMOTION,
        evControllerButtonDown = SDL_CONTROLLERBUTTONDOWN,
        evControllerButtonUp = SDL_CONTROLLERBUTTONUP,
        evControllerDeviceAdded = SDL_CONTROLLERDEVICEADDED,
        evControllerDeviceRemoved = SDL_CONTROLLERDEVICEREMOVED,
        evControllerDeviceRemapped = SDL_CONTROLLERDEVICEREMAPPED,
        evFingerDown = SDL_FINGERDOWN,
        evFingerUp = SDL_FINGERUP,
        evFingerMotion = SDL_FINGERMOTION,
        evDollarGesture = SDL_DOLLARGESTURE,
        evDollarRecord = SDL_DOLLARRECORD,
        evMultiGesture = SDL_MULTIGESTURE,
        evClipboardUpdate = SDL_CLIPBOARDUPDATE,
        evDropFile = SDL_DROPFILE,
        evDropText = SDL_DROPTEXT,
        evDropBegin = SDL_DROPBEGIN,
        evDropComplete = SDL_DROPCOMPLETE,
        evAudioDeviceAdded = SDL_AUDIODEVICEADDED,
        evAudioDeviceRemoved = SDL_AUDIODEVICEREMOVED,
        evRenderTargetsReset = SDL_RENDER_TARGETS_RESET,
        evRenderDeviceReset = SDL_RENDER_DEVICE_RESET,
        evUserEvent = SDL_USEREVENT,
        evLastEvent = SDL_LASTEVENT
    };

    GfxEventType() noexcept;

    explicit GfxEventType(const ValueType evtype) noexcept;
    explicit GfxEventType(const SdlType evtype) noexcept;
    explicit GfxEventType(const uint32_t evtype) noexcept;

    GfxEventType(const GfxEventType& other) noexcept;
    GfxEventType(GfxEventType&& other) noexcept;

    GfxEventType& operator=(const GfxEventType& other) noexcept;
    GfxEventType& operator=(GfxEventType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getEventType(void) const noexcept;
    uint32_t getEventTypeValue(void) const noexcept;
    void setEventType(const ValueType ev) noexcept;
    void setEventType(const SdlType ev) noexcept;
    void setEventType(const uint32_t ev) noexcept;

    inline bool isQuit(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evQuit); }  // NOLINT
    inline bool isAppTerminating(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAppTerminating); }  // NOLINT
    inline bool isLowMemory(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evLowMemory); }  // NOLINT
    inline bool isAppWillEnterBackground(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAppWillEnterBackground); }  // NOLINT
    inline bool isAppDidEnterBackground(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAppDidEnterBackground); }  // NOLINT
    inline bool isAppWillEnterForeground(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAppWillEnterForeground); }  // NOLINT
    inline bool isAppDidEnterForeground(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAppDidEnterForeground); }  // NOLINT
    inline bool isWindowEvent(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evWindowEvent); }  // NOLINT
    inline bool isSysWmEvent(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evSysWMEvent); }  // NOLINT
    inline bool isKeyDown(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evKeyDown); }  // NOLINT
    inline bool isKeyUp(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evKeyUp); }  // NOLINT
    inline bool isTextEditing(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evTextEditing); }  // NOLINT
    inline bool isTextInput(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evTextInput); }  // NOLINT
    inline bool isKeyMapChanged(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evKeyMapChanged); }  // NOLINT
    inline bool isMouseMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evMouseMotion); }  // NOLINT
    inline bool isMouseButtonDown(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evMouseButtonDown); }  // NOLINT
    inline bool isMouseButtonUp(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evMouseButtonUp); }  // NOLINT
    inline bool isMouseWheel(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evMouseWheel); }  // NOLINT
    inline bool isJoyAxisMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyAxisMotion); }  // NOLINT
    inline bool isJoyBallMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyBallMotion); }  // NOLINT
    inline bool isJoyHatMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyHatMotion); }  // NOLINT
    inline bool isJoyButtonDown(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyButtonDown); }  // NOLINT
    inline bool isJoyButtonUp(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyButtonUp); }  // NOLINT
    inline bool isJoyDeviceAdded(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyDeviceAdded); }  // NOLINT
    inline bool isJoyDeviceRemoved(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evJoyDeviceRemoved); }  // NOLINT
    inline bool isControllerAxisMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerAxisMotion); }  // NOLINT
    inline bool isControllerButtonDown(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerButtonDown); }  // NOLINT
    inline bool isControllerButtonUp(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerButtonUp); }  // NOLINT
    inline bool isControllerDeviceAdded(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerDeviceAdded); }  // NOLINT
    inline bool isControllerDeviceRemoved(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerDeviceRemoved); }  // NOLINT
    inline bool isControllerDeviceRemapped(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evControllerDeviceRemapped); }  // NOLINT
    inline bool isFingerDown(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evFingerDown); }  // NOLINT
    inline bool isFingerUp(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evFingerUp); }  // NOLINT
    inline bool isFingerMotion(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evFingerMotion); }  // NOLINT
    inline bool isDollarGesture(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDollarGesture); }  // NOLINT
    inline bool isDollarRecord(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDollarRecord); }  // NOLINT
    inline bool isMultiGesture(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evMultiGesture); }  // NOLINT
    inline bool isClipboardUpdate(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evClipboardUpdate); }  // NOLINT
    inline bool isDropFile(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDropFile); }  // NOLINT
    inline bool isDropText(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDropText); }  // NOLINT
    inline bool isDropBegin(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDropBegin); }  // NOLINT
    inline bool isDropComplete(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evDropComplete); }  // NOLINT
    inline bool isAudioDeviceAdded(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAudioDeviceAdded); }  // NOLINT
    inline bool isAudioDeviceRemoved(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evAudioDeviceRemoved); }  // NOLINT
    inline bool isRenderTargetsReset(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evRenderTargetsReset); }  // NOLINT
    inline bool isRenderDeviceReset(void) const noexcept { return (static_cast<ValueType>(evType_) == ValueType::evRenderDeviceReset); }  // NOLINT

    bool isUserEvent(void) const noexcept;
    bool isFirstOrLastEvent(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType evType_;
};

}  // namespace events

}  // namespace gfx

#endif /* GfxEventType_hpp */
