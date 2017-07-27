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

#ifndef GfxEvent_hpp
#define GfxEvent_hpp

#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"

#include "GfxEventType.hpp"
#include "GfxEventAction.hpp"
#include "GfxEventFilter.hpp"

#include "GfxJoyAxisEvent.hpp"
#include "GfxJoyBallEvent.hpp"
#include "GfxJoyButtonEvent.hpp"
#include "GfxJoyDeviceEvent.hpp"
#include "GfxJoyHatEvent.hpp"

#include "GfxKeyboardEvent.hpp"

#include "GfxMouseButtonEvent.hpp"
#include "GfxMouseMotionEvent.hpp"
#include "GfxMouseWheelEvent.hpp"

#include "GfxTextEditingEvent.hpp"
#include "GfxTextInputEvent.hpp"

#include "GfxWindowEvent.hpp"

namespace gfx
{

namespace events
{

struct GfxQuitEvent {typedef sdl2::SDL_QuitEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxSysWmEvent {typedef sdl2::SDL_SysWMEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxControllerAxisMotionEvent {typedef sdl2::SDL_ControllerAxisEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxControllerButtonEvent {typedef sdl2::SDL_ControllerButtonEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxControllerDeviceEvent {typedef sdl2::SDL_ControllerDeviceEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxTouchFingerEvent {typedef sdl2::SDL_TouchFingerEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxDollarGestureEvent {typedef sdl2::SDL_DollarGestureEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxMultiGestureEvent {typedef sdl2::SDL_MultiGestureEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxDropEvent {typedef sdl2::SDL_DropEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxAudioDeviceEvent {typedef sdl2::SDL_AudioDeviceEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxUserEvent {typedef sdl2::SDL_UserEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT

class GfxEvent final : public GfxObject
{
public:
    typedef sdl2::SDL_Event SdlType;
    typedef sdl2::SDL_Event * SdlTypePtr;

    static const char ClassName[];
    static const bool CallsSdl = true;
    static const bool SdlResource = false;

    GfxEvent() noexcept;
    explicit GfxEvent(const SdlType event) noexcept;
    GfxEvent(GfxEvent const& other) noexcept;
    GfxEvent(GfxEvent&& other) noexcept;

    GfxEvent& operator=(GfxEvent const& other) noexcept;
    GfxEvent& operator=(GfxEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t peepEvents(std::vector<SdlType> * events, const int32_t numevents, GfxEventAction const& action,
                       GfxEventType const& minType, GfxEventType const& maxType) const noexcept;
    GfxBool hasEvent(GfxEventType const& type) const noexcept;
    GfxBool hasEvents(GfxEventType const& minType, GfxEventType const& maxType) const noexcept;
    void flushEvent(GfxEventType const& type) const noexcept;
    void flushEvents(GfxEventType const& minType, GfxEventType const& maxType) const noexcept;
    int32_t pollEvent(void) noexcept;
    int32_t waitEvent(void) noexcept;
    int32_t waitEventTimeout(const int32_t timeout) noexcept;
    int32_t pushEvent(void) const noexcept;
    int32_t pushEvent(GfxEvent const& event) const noexcept;
    /* ... */
    void setEventFilter(GfxEventFilter const& filter, void * userdata) noexcept;
    GfxBool getEventFilter(GfxEventFilter * filter, void ** userdata) noexcept;
    void addEventWatch(GfxEventFilter const& filter, void * userdata) noexcept;
    void delEventWatch(GfxEventFilter const& filter, void * userdata) noexcept;
    void filterEvents(GfxEventFilter const& filter, void * userdata) noexcept;
    /* ... */
    uint8_t eventState(GfxEventType const& type, const GfxEventActionCommand state) const noexcept;
    uint8_t getEventState(GfxEventType const& type) const noexcept;
    uint32_t registerEvents(const int32_t numevents) const noexcept;

    GfxEventType const& eventType(void) const noexcept;

    GfxQuitEvent const& quitEvent(void) const noexcept;
    GfxWindowEvent const& windowEvent(void) const noexcept;
    GfxSysWmEvent const& sysWmEvent(void) const noexcept;
    GfxKeyboardEvent const& keyboardEvent(void) const noexcept;
    GfxTextEditingEvent const& textEditingEvent(void) const noexcept;
    GfxTextInputEvent const& textInputEvent(void) const noexcept;
    GfxMouseMotionEvent const& mouseMotionEvent(void) const noexcept;
    GfxMouseButtonEvent const& mouseButtonEvent(void) const noexcept;
    GfxMouseWheelEvent const& mouseWheelEvent(void) const noexcept;
    GfxJoyAxisEvent const& joyAxisEvent(void) const noexcept;
    GfxJoyBallEvent const& joyBallEvent(void) const noexcept;
    GfxJoyButtonEvent const& joyButtonEvent(void) const noexcept;
    GfxJoyHatEvent const& joyHatEvent(void) const noexcept;
    GfxJoyDeviceEvent const& joyDeviceEvent(void) const noexcept;
    GfxControllerAxisMotionEvent const& ctrlAxisMotionEvent(void) const noexcept;
    GfxControllerButtonEvent const& ctrlButtonEvent(void) const noexcept;
    GfxControllerDeviceEvent const& ctrlDeviceEvent(void) const noexcept;
    GfxTouchFingerEvent const& fingerEvent(void) const noexcept;
    GfxDollarGestureEvent const& dollarEvent(void) const noexcept;
    GfxMultiGestureEvent const& multiGestureEvent(void) const noexcept;
    GfxDropEvent const& dropEvent(void) const noexcept;
    GfxAudioDeviceEvent const& audioDeviceEvent(void) const noexcept;
    GfxUserEvent const& userEvent(void) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void processEvent(void) noexcept;
    void assign(GfxEvent const& other) noexcept;

    SdlType event_;

    GfxEventType eventType_;

    GfxQuitEvent quitEvent_;
    GfxWindowEvent windowEvent_;
    GfxSysWmEvent sysWmEvent_;
    GfxKeyboardEvent keyboardEvent_;
    GfxTextEditingEvent textEditingEvent_;
    GfxTextInputEvent textInputEvent_;
    GfxMouseButtonEvent mouseButtonEvent_;
    GfxMouseMotionEvent mouseMotionEvent_;
    GfxMouseWheelEvent mouseWheelEvent_;
    GfxJoyAxisEvent joyAxisEvent_;
    GfxJoyBallEvent joyBallEvent_;
    GfxJoyButtonEvent joyButtonEvent_;
    GfxJoyDeviceEvent joyDeviceEvent_;
    GfxJoyHatEvent joyHatEvent_;
    GfxControllerAxisMotionEvent ctrlAxisMotionEvent_;
    GfxControllerButtonEvent ctrlButtonEvent_;
    GfxControllerDeviceEvent ctrlDeviceEvent_;
    GfxTouchFingerEvent fingerEvent_;
    GfxDollarGestureEvent dollarEvent_;
    GfxMultiGestureEvent multiGestureEvent_;
    GfxDropEvent dropEvent_;
    GfxAudioDeviceEvent audioDeviceEvent_;
    GfxUserEvent userEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxEvent_hpp */
