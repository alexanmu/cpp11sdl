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

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
// General event types
#include "GfxEventType.hpp"
#include "GfxEventAction.hpp"
#include "GfxEventFilter.hpp"
#include "GfxCommonEvent.hpp"
// Joystick events
#include "GfxJoyAxisEvent.hpp"
#include "GfxJoyBallEvent.hpp"
#include "GfxJoyButtonEvent.hpp"
#include "GfxJoyDeviceEvent.hpp"
#include "GfxJoyHatEvent.hpp"
// Keyboard events
#include "GfxKeyboardEvent.hpp"
// Mouse events
#include "GfxMouseButtonEvent.hpp"
#include "GfxMouseMotionEvent.hpp"
#include "GfxMouseWheelEvent.hpp"
// Text events
#include "GfxTextEditingEvent.hpp"
#include "GfxTextInputEvent.hpp"
// Window events
#include "GfxWindowEvent.hpp"
// Controller events
#include "GfxControllerAxisEvent.hpp"
#include "GfxControllerButtonEvent.hpp"
#include "GfxControllerDeviceEvent.hpp"
// Quit event
#include "GfxQuitEvent.hpp"
// User event
#include "GfxUserEvent.hpp"

namespace gfx
{

namespace events
{

struct GfxSysWmEvent {typedef sdl2::SDL_SysWMEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxTouchFingerEvent {typedef sdl2::SDL_TouchFingerEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxDollarGestureEvent {typedef sdl2::SDL_DollarGestureEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxMultiGestureEvent {typedef sdl2::SDL_MultiGestureEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxDropEvent {typedef sdl2::SDL_DropEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT
struct GfxAudioDeviceEvent {typedef sdl2::SDL_AudioDeviceEvent SdlType; void setValue(SdlType event) noexcept {event=event;};void clear(void) noexcept {};}; // NOLINT

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
    void setEventFilter(GfxEventFilter const& filter) noexcept;
    GfxBool getEventFilter(GfxEventFilter * filter) const throw(std::runtime_error);
    void addEventWatch(GfxEventFilter const& filter) noexcept;
    void delEventWatch(GfxEventFilter const& filter) noexcept;
    void filterEvents(GfxEventFilter const& filter) throw(std::runtime_error);
    uint8_t eventState(GfxEventType const& type, const GfxEventActionCommand state) const noexcept;
    uint8_t getEventState(GfxEventType const& type) const noexcept;
    uint32_t registerEvents(const int32_t numevents) const noexcept;

    GfxEventType const& eventType(void) const noexcept;
    GfxCommonEvent commonEvent(void) const noexcept;

    GfxQuitEvent const& quitEvent(void) const throw(std::runtime_error);
    GfxWindowEvent const& windowEvent(void) const throw(std::runtime_error);
    GfxSysWmEvent const& sysWmEvent(void) const throw(std::runtime_error);
    GfxKeyboardEvent const& keyboardEvent(void) const throw(std::runtime_error);
    GfxTextEditingEvent const& textEditingEvent(void) const throw(std::runtime_error);
    GfxTextInputEvent const& textInputEvent(void) const throw(std::runtime_error);
    GfxMouseMotionEvent const& mouseMotionEvent(void) const throw(std::runtime_error);
    GfxMouseButtonEvent const& mouseButtonEvent(void) const throw(std::runtime_error);
    GfxMouseWheelEvent const& mouseWheelEvent(void) const throw(std::runtime_error);
    GfxJoyAxisEvent const& joyAxisEvent(void) const throw(std::runtime_error);
    GfxJoyBallEvent const& joyBallEvent(void) const throw(std::runtime_error);
    GfxJoyButtonEvent const& joyButtonEvent(void) const throw(std::runtime_error);
    GfxJoyHatEvent const& joyHatEvent(void) const throw(std::runtime_error);
    GfxJoyDeviceEvent const& joyDeviceEvent(void) const throw(std::runtime_error);
    GfxControllerAxisEvent const& ctrlAxisMotionEvent(void) const throw(std::runtime_error);
    GfxControllerButtonEvent const& ctrlButtonEvent(void) const throw(std::runtime_error);
    GfxControllerDeviceEvent const& ctrlDeviceEvent(void) const throw(std::runtime_error);
    GfxTouchFingerEvent const& fingerEvent(void) const throw(std::runtime_error);
    GfxDollarGestureEvent const& dollarEvent(void) const throw(std::runtime_error);
    GfxMultiGestureEvent const& multiGestureEvent(void) const throw(std::runtime_error);
    GfxDropEvent const& dropEvent(void) const throw(std::runtime_error);
    GfxAudioDeviceEvent const& audioDeviceEvent(void) const throw(std::runtime_error);
    GfxUserEvent const& userEvent(void) const throw(std::runtime_error);

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void processEvent(void) noexcept;
    void assign(GfxEvent const& other) noexcept;

    static int32_t eventFilterFunction(void * userdata, SdlTypePtr event);
    static int32_t eventWatchFunction(void * userdata, SdlTypePtr event);
    static int32_t filterEventsFunction(void * userdata, SdlTypePtr event);

    GfxEventFilter * eventFilterFunctionObject_;
    GfxEventFilter * eventWatchFunctionObject_;
    GfxEventFilter * filterEventsFunctionObject_;

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
    GfxControllerAxisEvent ctrlAxisEvent_;
    GfxControllerButtonEvent ctrlButtonEvent_;
    GfxControllerDeviceEvent ctrlDeviceEvent_;
    GfxTouchFingerEvent fingerEvent_;
    GfxDollarGestureEvent dollarEvent_;
    GfxMultiGestureEvent multiGestureEvent_;
    GfxDropEvent dropEvent_;
    GfxAudioDeviceEvent audioDeviceEvent_;
    GfxUserEvent userEvent_;

    static const char kInvalidEventTypeMessage[];
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxEvent_hpp */
