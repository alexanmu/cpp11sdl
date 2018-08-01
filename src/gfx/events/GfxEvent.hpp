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
// Audio device event
#include "GfxAudioDeviceEvent.hpp"
// User event
#include "GfxUserEvent.hpp"
// Drag-drop event
#include "GfxDropEvent.hpp"
// Sys-WM event
#include "GfxSysWmEvent.hpp"
// Multi-touch events
#include "GfxTouchFingerEvent.hpp"
#include "GfxDollarGestureEvent.hpp"
#include "GfxMultiGestureEvent.hpp"

namespace gfx
{

namespace events
{

class GfxEvent final : public GfxObject
{
public:
    typedef SDL_Event SdlType;
    typedef SDL_Event * SdlTypePtr;

    static const char ClassName[];
    static const bool CallsSdl = true;
    static const bool SdlResource = false;

    GfxEvent() noexcept;
    explicit GfxEvent(const SdlType event) noexcept;
    GfxEvent(const GfxEvent& other) noexcept;
    GfxEvent(GfxEvent&& other) noexcept;

    GfxEvent& operator=(const GfxEvent& other) noexcept;
    GfxEvent& operator=(GfxEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t peepEvents(std::vector<SdlType> * events, const int32_t numevents, const GfxEventAction& action,
                       const GfxEventType& minType, const GfxEventType& maxType) const noexcept;
    const GfxBool hasEvent(const GfxEventType& type) const noexcept;
    const GfxBool hasEvents(const GfxEventType& minType, const GfxEventType& maxType) const noexcept;
    void flushEvent(const GfxEventType& type) const noexcept;
    void flushEvents(const GfxEventType& minType, const GfxEventType& maxType) const noexcept;
    int32_t pollEvent(void) noexcept;
    int32_t waitEvent(void) noexcept;
    int32_t waitEventTimeout(const int32_t timeout) noexcept;
    int32_t pushEvent(void) const noexcept;
    int32_t pushEvent(const GfxEvent& event) const noexcept;
    void setEventFilter(const GfxEventFilter& filter) noexcept;
    const GfxBool getEventFilter(GfxEventFilter * filter) const throw(std::runtime_error);
    void addEventWatch(const GfxEventFilter& filter) noexcept;
    void delEventWatch(const GfxEventFilter& filter) noexcept;
    void filterEvents(const GfxEventFilter& filter) throw(std::runtime_error);
    uint8_t eventState(const GfxEventType& type, const GfxEventActionCommand state) const noexcept;
    uint8_t getEventState(const GfxEventType& type) const noexcept;
    uint32_t registerEvents(const int32_t numevents) const noexcept;

    const GfxEventType& eventType(void) const noexcept;
    const GfxCommonEvent commonEvent(void) const noexcept;

    const GfxQuitEvent& quitEvent(void) const throw(std::runtime_error);
    const GfxWindowEvent& windowEvent(void) const throw(std::runtime_error);
    const GfxSysWmEvent& sysWmEvent(void) const throw(std::runtime_error);
    const GfxKeyboardEvent& keyboardEvent(void) const throw(std::runtime_error);
    const GfxTextEditingEvent& textEditingEvent(void) const throw(std::runtime_error);
    const GfxTextInputEvent& textInputEvent(void) const throw(std::runtime_error);
    const GfxMouseMotionEvent& mouseMotionEvent(void) const throw(std::runtime_error);
    const GfxMouseButtonEvent& mouseButtonEvent(void) const throw(std::runtime_error);
    const GfxMouseWheelEvent& mouseWheelEvent(void) const throw(std::runtime_error);
    const GfxJoyAxisEvent& joyAxisEvent(void) const throw(std::runtime_error);
    const GfxJoyBallEvent& joyBallEvent(void) const throw(std::runtime_error);
    const GfxJoyButtonEvent& joyButtonEvent(void) const throw(std::runtime_error);
    const GfxJoyHatEvent& joyHatEvent(void) const throw(std::runtime_error);
    const GfxJoyDeviceEvent& joyDeviceEvent(void) const throw(std::runtime_error);
    const GfxControllerAxisEvent& ctrlAxisMotionEvent(void) const throw(std::runtime_error);
    const GfxControllerButtonEvent& ctrlButtonEvent(void) const throw(std::runtime_error);
    const GfxControllerDeviceEvent& ctrlDeviceEvent(void) const throw(std::runtime_error);
    const GfxTouchFingerEvent& fingerEvent(void) const throw(std::runtime_error);
    const GfxDollarGestureEvent& dollarEvent(void) const throw(std::runtime_error);
    const GfxMultiGestureEvent& multiGestureEvent(void) const throw(std::runtime_error);
    const GfxDropEvent& dropEvent(void) const throw(std::runtime_error);
    const GfxAudioDeviceEvent& audioDeviceEvent(void) const throw(std::runtime_error);
    const GfxUserEvent& userEvent(void) const throw(std::runtime_error);

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void processEvent(void) noexcept;
    void assign(const GfxEvent& other) noexcept;

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
