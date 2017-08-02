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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include <limits>

#include "GfxEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxevent::event::gfx");

namespace gfx
{

namespace events
{

const char GfxEvent::ClassName[] = "GfxEvent";

GfxEvent::GfxEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxEvent::GfxEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
    event_ = event;
    processEvent();
}

GfxEvent::GfxEvent(GfxEvent const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    clear();
    assign(other);
    processEvent();
}

GfxEvent::GfxEvent(GfxEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    clear();
    assign(other);
    processEvent();
    // Delete other's data
    other.clear();
}

GfxEvent& GfxEvent::operator=(GfxEvent const& other) noexcept
{
    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        assign(other);
        processEvent();
    }
    return *this;
}

GfxEvent& GfxEvent::operator=(GfxEvent&& other) noexcept
{
    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        assign(other);
        processEvent();
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxEvent::peepEvents(std::vector<SdlType> * events, const int32_t numevents, GfxEventAction const& action,
                             GfxEventType const& minType, GfxEventType const& maxType) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(events != nullptr);
    assert(numevents > 0);
    assert(action);
    assert(minType);
    assert(maxType);

    int32_t ret;
    SdlTypePtr eventsPtr;
    int32_t index;

    eventsPtr = new SdlType[numevents];  // NOLINT
    if (action.getAction() == GfxEventAction::ValueType::addEvent)
    {
        assert(events->size() > 0);

        for (index = 0; index < numevents; index++)
        {
            eventsPtr[index] = events->at(index);
        }
    }
    ret = sdl2::SDL_PeepEvents(eventsPtr, numevents, action.getAsSdlType(), minType.getAsSdlType(),
                               maxType.getAsSdlType());
    if ((action.getAction() == GfxEventAction::ValueType::peekEvent) ||
        (action.getAction() == GfxEventAction::ValueType::getEvent))
    {
        events->clear();
        events->reserve(numevents);
        for (index = 0; index < numevents; index++)
        {
            events->push_back(eventsPtr[index]);
        }
    }
    delete[] eventsPtr;

    return ret;
}

GfxBool GfxEvent::hasEvent(GfxEventType const& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_HasEvent(type.getAsSdlType());
    return GfxBool(sdlbool);
}

GfxBool GfxEvent::hasEvents(GfxEventType const& minType, GfxEventType const& maxType) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(minType);
    assert(maxType);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_HasEvents(minType.getAsSdlType(), maxType.getAsSdlType());
    return GfxBool(sdlbool);
}

void GfxEvent::flushEvent(GfxEventType const& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    sdl2::SDL_FlushEvent(type.getAsSdlType());
}

void GfxEvent::flushEvents(GfxEventType const& minType, GfxEventType const& maxType) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(minType);
    assert(maxType);

    sdl2::SDL_FlushEvents(minType.getAsSdlType(), maxType.getAsSdlType());
}

int32_t GfxEvent::pollEvent(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 0;

    ret = sdl2::SDL_PollEvent(&event_);
    if (ret == 1)
    {
        processEvent();
    }
    return ret;
}

int32_t GfxEvent::waitEvent(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 0;

    ret = sdl2::SDL_WaitEvent(&event_);
    if (ret == 1)
    {
        processEvent();
    }
    return ret;
}

int32_t GfxEvent::waitEventTimeout(const int32_t timeout) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(timeout > 0);

    int32_t ret = 0;

    ret = sdl2::SDL_WaitEventTimeout(&event_, timeout);
    if (ret == 1)
    {
        processEvent();
    }
    return ret;
}

int32_t GfxEvent::pushEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret;

    ret = sdl2::SDL_PushEvent(const_cast<SdlType *>(&event_));
    return ret;
}

int32_t GfxEvent::pushEvent(GfxEvent const& event) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(event);

    int32_t ret;

    ret = sdl2::SDL_PushEvent(event.getAsSdlTypePtr());
    return ret;
}

void GfxEvent::setEventFilter(GfxEventFilter const& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (eventFilterFunctionObject_ == nullptr)
    {
        eventFilterFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        sdl2::SDL_SetEventFilter(eventFilterFunction, userdata);
    }
}

GfxBool GfxEvent::getEventFilter(GfxEventFilter * filter) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(filter == nullptr);

    sdl2::SDL_EventFilter sdlEventFilterFunc = nullptr;
    void * userdata = nullptr;

    sdl2::SDL_GetEventFilter(&sdlEventFilterFunc, &userdata);
    if (userdata != static_cast<void *>(this))
    {
        throw std::runtime_error("this pointer error");
    }
    if ((sdlEventFilterFunc != nullptr) &&
        (*sdlEventFilterFunc == eventFilterFunction))
    {
        filter = eventFilterFunctionObject_;
        return GfxBool(true);
    }
    return GfxBool(false);
}

void GfxEvent::addEventWatch(GfxEventFilter const& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (eventWatchFunctionObject_ == nullptr)
    {
        eventWatchFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        sdl2::SDL_AddEventWatch(eventWatchFunction, userdata);
    }
}

void GfxEvent::delEventWatch(GfxEventFilter const& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if ((eventWatchFunctionObject_ != nullptr) &&
        (eventWatchFunctionObject_ == const_cast<GfxEventFilter *>(&filter)))
    {
        sdl2::SDL_DelEventWatch(eventWatchFunction, userdata);
        eventWatchFunctionObject_ = nullptr;
    }
}

void GfxEvent::filterEvents(GfxEventFilter const& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (filterEventsFunctionObject_ == nullptr)
    {
        filterEventsFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        sdl2::SDL_FilterEvents(filterEventsFunction, userdata);
        filterEventsFunctionObject_ = nullptr;
    }
}

uint8_t GfxEvent::eventState(GfxEventType const& type, const GfxEventActionCommand state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    uint8_t ret;

    ret = sdl2::SDL_EventState(type.getAsSdlType(), static_cast<int32_t>(state));
    return ret;
}

uint8_t GfxEvent::getEventState(GfxEventType const& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    return eventState(type, GfxEventActionCommand::kGfxQuery);
}

uint32_t GfxEvent::registerEvents(const int32_t numevents) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(numevents > 0);

    uint32_t ret = std::numeric_limits<uint32_t>::max() - 1;

    ret = sdl2::SDL_RegisterEvents(numevents);
    return ret;
}

GfxEventType const& GfxEvent::eventType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return eventType_;
}

GfxCommonEvent GfxEvent::commonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxCommonEvent(event_.common);
}

GfxQuitEvent const& GfxEvent::quitEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return quitEvent_;
}

GfxWindowEvent const& GfxEvent::windowEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return windowEvent_;
}

GfxSysWmEvent const& GfxEvent::sysWmEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sysWmEvent_;
}

GfxKeyboardEvent const& GfxEvent::keyboardEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return keyboardEvent_;
}

GfxTextEditingEvent const& GfxEvent::textEditingEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textEditingEvent_;
}

GfxTextInputEvent const& GfxEvent::textInputEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return textInputEvent_;
}

GfxMouseMotionEvent const& GfxEvent::mouseMotionEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mouseMotionEvent_;
}

GfxMouseButtonEvent const& GfxEvent::mouseButtonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mouseButtonEvent_;
}

GfxMouseWheelEvent const& GfxEvent::mouseWheelEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return mouseWheelEvent_;
}

GfxJoyAxisEvent const& GfxEvent::joyAxisEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joyAxisEvent_;
}

GfxJoyBallEvent const& GfxEvent::joyBallEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joyBallEvent_;
}

GfxJoyButtonEvent const& GfxEvent::joyButtonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joyButtonEvent_;
}

GfxJoyHatEvent const& GfxEvent::joyHatEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joyHatEvent_;
}

GfxJoyDeviceEvent const& GfxEvent::joyDeviceEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joyDeviceEvent_;
}

GfxControllerAxisMotionEvent const& GfxEvent::ctrlAxisMotionEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ctrlAxisMotionEvent_;
}

GfxControllerButtonEvent const& GfxEvent::ctrlButtonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ctrlButtonEvent_;
}

GfxControllerDeviceEvent const& GfxEvent::ctrlDeviceEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ctrlDeviceEvent_;
}

GfxTouchFingerEvent const& GfxEvent::fingerEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return fingerEvent_;
}

GfxDollarGestureEvent const& GfxEvent::dollarEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dollarEvent_;
}

GfxMultiGestureEvent const& GfxEvent::multiGestureEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return multiGestureEvent_;
}

GfxDropEvent const& GfxEvent::dropEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return dropEvent_;
}

GfxAudioDeviceEvent const& GfxEvent::audioDeviceEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return audioDeviceEvent_;
}

GfxUserEvent const& GfxEvent::userEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return userEvent_;
}

void GfxEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    event_.type = sdl2::SDL_FIRSTEVENT;
    eventFilterFunctionObject_ = nullptr;
    eventWatchFunctionObject_ = nullptr;
    filterEventsFunctionObject_ = nullptr;
    eventType_.clear();
    quitEvent_.clear();
    windowEvent_.clear();
    sysWmEvent_.clear();
    keyboardEvent_.clear();
    textEditingEvent_.clear();
    textInputEvent_.clear();
    mouseButtonEvent_.clear();
    mouseMotionEvent_.clear();
    mouseWheelEvent_.clear();
    joyAxisEvent_.clear();
    joyBallEvent_.clear();
    joyButtonEvent_.clear();
    joyDeviceEvent_.clear();
    joyHatEvent_.clear();
    ctrlAxisMotionEvent_.clear();
    ctrlButtonEvent_.clear();
    ctrlDeviceEvent_.clear();
    fingerEvent_.clear();
    dollarEvent_.clear();
    multiGestureEvent_.clear();
    dropEvent_.clear();
    audioDeviceEvent_.clear();
    userEvent_.clear();
}

GfxEvent::SdlTypePtr GfxEvent::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&event_;
}

// Private methods
void GfxEvent::processEvent(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    eventType_.setEventType(event_.type);

    switch (eventType_.getEventType())
    {
        case GfxEventType::ValueType::evQuit:
            quitEvent_.setValue(event_.quit);
            break;
        case GfxEventType::ValueType::evAppTerminating:
            /* fallthrough */
        case GfxEventType::ValueType::evLowMemory:
            /* fallthrough */
        case GfxEventType::ValueType::evAppWillEnterBackground:
            /* fallthrough */
        case GfxEventType::ValueType::evAppDidEnterBackground:
            /* fallthrough */
        case GfxEventType::ValueType::evAppWillEnterForeground:
            /* fallthrough */
        case GfxEventType::ValueType::evAppDidEnterForeground:
            /* Naked event, nothing to do */
            break;
        case GfxEventType::ValueType::evWindowEvent:
            windowEvent_.setValue(event_.window);
            break;
        case GfxEventType::ValueType::evSysWMEvent:
            sysWmEvent_.setValue(event_.syswm);
            break;
        case GfxEventType::ValueType::evKeyDown:
            /* fallthrought */
        case GfxEventType::ValueType::evKeyUp:
            keyboardEvent_.setValue(event_.key);
            break;
        case GfxEventType::ValueType::evTextEditing:
            textEditingEvent_.setValue(event_.edit);
            break;
        case GfxEventType::ValueType::evTextInput:
            textInputEvent_.setValue(event_.text);
            break;
        case GfxEventType::ValueType::evKeyMapChanged:
            /* Naked event, nothing to do */
            break;
        case GfxEventType::ValueType::evMouseMotion:
            mouseMotionEvent_.setValue(event_.motion);
            break;
        case GfxEventType::ValueType::evMouseButtonDown:
            /* fallthrough */
        case GfxEventType::ValueType::evMouseButtonUp:
            mouseButtonEvent_.setValue(event_.button);
            break;
        case GfxEventType::ValueType::evMouseWheel:
            mouseWheelEvent_.setValue(event_.wheel);
            break;
        case GfxEventType::ValueType::evJoyAxisMotion:
            joyAxisEvent_.setValue(event_.jaxis);
            break;
        case GfxEventType::ValueType::evJoyBallMotion:
            joyBallEvent_.setValue(event_.jball);
            break;
        case GfxEventType::ValueType::evJoyHatMotion:
            joyHatEvent_.setValue(event_.jhat);
            break;
        case GfxEventType::ValueType::evJoyButtonDown:
            /* fallthrough */
        case GfxEventType::ValueType::evJoyButtonUp:
            joyButtonEvent_.setValue(event_.jbutton);
            break;
        case GfxEventType::ValueType::evJoyDeviceAdded:
            /* fallthrough */
        case GfxEventType::ValueType::evJoyDeviceRemoved:
            joyDeviceEvent_.setValue(event_.jdevice);
            break;
        case GfxEventType::ValueType::evControllerAxisMotion:
            ctrlAxisMotionEvent_.setValue(event_.caxis);
            break;
        case GfxEventType::ValueType::evControllerButtonDown:
            /* fallthrough */
        case GfxEventType::ValueType::evControllerButtonUp:
            ctrlButtonEvent_.setValue(event_.cbutton);
            break;
        case GfxEventType::ValueType::evControllerDeviceAdded:
            /* fallthrough */
        case GfxEventType::ValueType::evControllerDeviceRemoved:
            /* fallthrough */
        case GfxEventType::ValueType::evControllerDeviceRemapped:
            ctrlDeviceEvent_.setValue(event_.cdevice);
            break;
        case GfxEventType::ValueType::evFingerDown:
            /* fallthrough */
        case GfxEventType::ValueType::evFingerUp:
            /* fallthrough */
        case GfxEventType::ValueType::evFingerMotion:
            fingerEvent_.setValue(event_.tfinger);
            break;
        case GfxEventType::ValueType::evDollarGesture:
            /* fallthrough */
        case GfxEventType::ValueType::evDollarRecord:
            dollarEvent_.setValue(event_.dgesture);
            break;
        case GfxEventType::ValueType::evMultiGesture:
            multiGestureEvent_.setValue(event_.mgesture);
            break;
        case GfxEventType::ValueType::evClipboardUpdate:
            /* Naked event, nothing to do */
            break;
        case GfxEventType::ValueType::evDropFile:
            /* fallthrough */
        case GfxEventType::ValueType::evDropText:
            /* fallthrough */
        case GfxEventType::ValueType::evDropBegin:
            /* fallthrough */
        case GfxEventType::ValueType::evDropComplete:
            dropEvent_.setValue(event_.drop);
            break;
        case GfxEventType::ValueType::evAudioDeviceAdded:
            /* fallthrough */
        case GfxEventType::ValueType::evAudioDeviceRemoved:
            audioDeviceEvent_.setValue(event_.adevice);
            break;
        case GfxEventType::ValueType::evRenderTargetsReset:
            /* Naked event, nothing to do */
            break;
        case GfxEventType::ValueType::evRenderDeviceReset:
            /* Naked event, nothing to do */
            break;
        default:
            if (
                (static_cast<uint32_t>(eventType_.getEventType()) >=
                    static_cast<uint32_t>(GfxEventType::ValueType::evUserEvent)) &&
                (static_cast<uint32_t>(eventType_.getEventType()) <
                    static_cast<uint32_t>(GfxEventType::ValueType::evLastEvent))
               )
            {
                userEvent_.setValue(event_.user);
            }
            break;
    }
}

void GfxEvent::assign(GfxEvent const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    event_ = other.event_;
    eventFilterFunctionObject_ = other.eventFilterFunctionObject_;
    eventWatchFunctionObject_ = other.eventWatchFunctionObject_;
    filterEventsFunctionObject_ = other.filterEventsFunctionObject_;
    eventType_ = other.eventType_;
    quitEvent_ = other.quitEvent_;
    windowEvent_ = other.windowEvent_;
    sysWmEvent_ = other.sysWmEvent_;
    keyboardEvent_ = other.keyboardEvent_;
    textEditingEvent_ = other.textEditingEvent_;
    textInputEvent_ = other.textInputEvent_;
    mouseButtonEvent_ = other.mouseButtonEvent_;
    mouseMotionEvent_ = other.mouseMotionEvent_;
    mouseWheelEvent_ = other.mouseWheelEvent_;
    joyAxisEvent_ = other.joyAxisEvent_;
    joyBallEvent_ = other.joyBallEvent_;
    joyButtonEvent_ = other.joyButtonEvent_;
    joyDeviceEvent_ = other.joyDeviceEvent_;
    joyHatEvent_ = other.joyHatEvent_;
    ctrlAxisMotionEvent_ = other.ctrlAxisMotionEvent_;
    ctrlButtonEvent_ = other.ctrlButtonEvent_;
    ctrlDeviceEvent_ = other.ctrlDeviceEvent_;
    fingerEvent_ = other.fingerEvent_;
    dollarEvent_ = other.dollarEvent_;
    multiGestureEvent_ = other.multiGestureEvent_;
    dropEvent_ = other.dropEvent_;
    audioDeviceEvent_ = other.audioDeviceEvent_;
    userEvent_ = other.userEvent_;
}

int32_t GfxEvent::eventFilterFunction(void * userdata, sdl2::SDL_Event * event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr != nullptr)
    {
        if (evptr->eventFilterFunctionObject_ != nullptr)
        {
            ret = (*(evptr->eventFilterFunctionObject_))(GfxEvent(*event));
        }
    }
    return ret;
}

int32_t GfxEvent::eventWatchFunction(void * userdata, sdl2::SDL_Event * event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr != nullptr)
    {
        if (evptr->eventFilterFunctionObject_ != nullptr)
        {
            ret = (*(evptr->eventWatchFunctionObject_))(GfxEvent(*event));
        }
    }
    return ret;
}

int32_t GfxEvent::filterEventsFunction(void * userdata, sdl2::SDL_Event * event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr != nullptr)
    {
        if (evptr->filterEventsFunctionObject_ != nullptr)
        {
            ret = (*(evptr->filterEventsFunctionObject_))(GfxEvent(*event));
        }
    }
    return ret;
}

}  // namespace events

}  // namespace gfx

/* EOF */
