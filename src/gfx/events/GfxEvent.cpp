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

#include "GfxEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxevent::event::gfx");

namespace gfx
{

namespace events
{

const char GfxEvent::ClassName[] = "GfxEvent";
const char GfxEvent::kInvalidEventTypeMessage[] = "Invalid event type";

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

GfxEvent::GfxEvent(const GfxEvent& other) noexcept : GfxObject(other)
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

GfxEvent& GfxEvent::operator=(const GfxEvent& other) noexcept
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

int32_t GfxEvent::peepEvents(std::vector<SdlType> * events, const int32_t numevents, const GfxEventAction& action,
                             const GfxEventType& minType, const GfxEventType& maxType) const noexcept
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
    if (action.getValue() == GfxEventAction::ValueType::addEvent)
    {
        assert(events->size() > 0);

        for (index = 0; index < numevents; index++)
        {
            eventsPtr[index] = events->at(index);
        }
    }
    ret = SDL_PeepEvents(eventsPtr, numevents, action.getAsSdlType(), minType.getAsSdlType(),
                         maxType.getAsSdlType());
    if ((action.getValue() == GfxEventAction::ValueType::peekEvent) ||
        (action.getValue() == GfxEventAction::ValueType::getEvent))
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

const GfxBool GfxEvent::hasEvent(const GfxEventType& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_HasEvent(type.getAsSdlType());
    return GfxBool(sdlbool);
}

const GfxBool GfxEvent::hasEvents(const GfxEventType& minType, const GfxEventType& maxType) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(minType);
    assert(maxType);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_HasEvents(minType.getAsSdlType(), maxType.getAsSdlType());
    return GfxBool(sdlbool);
}

void GfxEvent::flushEvent(const GfxEventType& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    SDL_FlushEvent(type.getAsSdlType());
}

void GfxEvent::flushEvents(const GfxEventType& minType, const GfxEventType& maxType) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(minType);
    assert(maxType);

    SDL_FlushEvents(minType.getAsSdlType(), maxType.getAsSdlType());
}

int32_t GfxEvent::pollEvent(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 0;

    ret = SDL_PollEvent(&event_);
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

    ret = SDL_WaitEvent(&event_);
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

    ret = SDL_WaitEventTimeout(&event_, timeout);
    if (ret == 1)
    {
        processEvent();
    }
    return ret;
}

int32_t GfxEvent::pushEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 0;

    ret = SDL_PushEvent(const_cast<SdlType *>(&event_));
    return ret;
}

int32_t GfxEvent::pushEvent(const GfxEvent& event) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(event);

    int32_t ret = 0;

    ret = SDL_PushEvent(event.getAsSdlTypePtr());
    return ret;
}

void GfxEvent::setEventFilter(const GfxEventFilter& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (eventFilterFunctionObject_ == nullptr)
    {
        eventFilterFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        SDL_SetEventFilter(eventFilterFunction, userdata);
    }
}

const GfxBool GfxEvent::getEventFilter(GfxEventFilter * filter) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(filter == nullptr);

    SDL_EventFilter sdlEventFilterFunc = nullptr;
    void * userdata = nullptr;

    SDL_GetEventFilter(&sdlEventFilterFunc, &userdata);
    if (userdata != static_cast<void *>(const_cast<GfxEvent *>(this)))
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

void GfxEvent::addEventWatch(const GfxEventFilter& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (eventWatchFunctionObject_ == nullptr)
    {
        eventWatchFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        SDL_AddEventWatch(eventWatchFunction, userdata);
    }
}

void GfxEvent::delEventWatch(const GfxEventFilter& filter) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if ((eventWatchFunctionObject_ != nullptr) &&
        (eventWatchFunctionObject_ == const_cast<GfxEventFilter *>(&filter)))
    {
        SDL_DelEventWatch(eventWatchFunction, userdata);
        eventWatchFunctionObject_ = nullptr;
    }
}

void GfxEvent::filterEvents(const GfxEventFilter& filter) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(filter);

    void * userdata = static_cast<void *>(this);

    if (filterEventsFunctionObject_ == nullptr)
    {
        filterEventsFunctionObject_ = const_cast<GfxEventFilter *>(&filter);
        SDL_FilterEvents(filterEventsFunction, userdata);
        filterEventsFunctionObject_ = nullptr;
    }
    else
    {
        throw std::runtime_error("Invalid object state");
    }
}

uint8_t GfxEvent::eventState(const GfxEventType& type, const GfxEventActionCommand state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    uint8_t ret = 0;

    ret = SDL_EventState(type.getAsSdlType(), static_cast<int32_t>(state));
    return ret;
}

uint8_t GfxEvent::getEventState(const GfxEventType& type) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(type);

    return eventState(type, GfxEventActionCommand::kGfxQuery);
}

uint32_t GfxEvent::registerEvents(const int32_t numevents) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(numevents > 0);

    uint32_t ret = 0;

    ret = SDL_RegisterEvents(numevents);
    return ret;
}

const GfxEventType& GfxEvent::eventType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return eventType_;
}

const GfxCommonEvent GfxEvent::commonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return GfxCommonEvent(event_.common);
}

const GfxQuitEvent& GfxEvent::quitEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isQuit() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return quitEvent_;
}

const GfxWindowEvent& GfxEvent::windowEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isWindowEvent() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return windowEvent_;
}

const GfxSysWmEvent& GfxEvent::sysWmEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isSysWmEvent() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return sysWmEvent_;
}

const GfxKeyboardEvent& GfxEvent::keyboardEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isKeyDown() == false) && (eventType().isKeyUp() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return keyboardEvent_;
}

const GfxTextEditingEvent& GfxEvent::textEditingEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isTextEditing() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return textEditingEvent_;
}

const GfxTextInputEvent& GfxEvent::textInputEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isTextInput() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return textInputEvent_;
}

const GfxMouseMotionEvent& GfxEvent::mouseMotionEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isMouseMotion() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return mouseMotionEvent_;
}

const GfxMouseButtonEvent& GfxEvent::mouseButtonEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isMouseButtonDown() == false) && (eventType().isMouseButtonUp() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return mouseButtonEvent_;
}

const GfxMouseWheelEvent& GfxEvent::mouseWheelEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isMouseWheel() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return mouseWheelEvent_;
}

const GfxJoyAxisEvent& GfxEvent::joyAxisEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isJoyAxisMotion() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return joyAxisEvent_;
}

const GfxJoyBallEvent& GfxEvent::joyBallEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isJoyBallMotion() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return joyBallEvent_;
}

const GfxJoyButtonEvent& GfxEvent::joyButtonEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isJoyButtonDown() == false) && (eventType().isJoyButtonUp() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return joyButtonEvent_;
}

const GfxJoyHatEvent& GfxEvent::joyHatEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isJoyHatMotion() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return joyHatEvent_;
}

const GfxJoyDeviceEvent& GfxEvent::joyDeviceEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isJoyDeviceAdded() == false) && (eventType().isJoyDeviceRemoved() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return joyDeviceEvent_;
}

const GfxControllerAxisEvent& GfxEvent::ctrlAxisMotionEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isControllerAxisMotion() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return ctrlAxisEvent_;
}

const GfxControllerButtonEvent& GfxEvent::ctrlButtonEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isControllerButtonDown() == false) && (eventType().isControllerButtonUp() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return ctrlButtonEvent_;
}

const GfxControllerDeviceEvent& GfxEvent::ctrlDeviceEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isControllerDeviceAdded() == false) && (eventType().isControllerDeviceRemoved() == false) &&
        (eventType().isControllerDeviceRemapped() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return ctrlDeviceEvent_;
}

const GfxTouchFingerEvent& GfxEvent::fingerEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isFingerDown() == false) && (eventType().isFingerUp() == false) &&
        (eventType().isFingerMotion() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return fingerEvent_;
}

const GfxDollarGestureEvent& GfxEvent::dollarEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isDollarGesture() == false) || (eventType().isDollarRecord() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return dollarEvent_;
}

const GfxMultiGestureEvent& GfxEvent::multiGestureEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isMultiGesture() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return multiGestureEvent_;
}

const GfxDropEvent& GfxEvent::dropEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isDropFile() == false) && (eventType().isDropText() == false) &&
        (eventType().isDropBegin() == false) && (eventType().isDropComplete() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return dropEvent_;
}

const GfxAudioDeviceEvent& GfxEvent::audioDeviceEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if ((eventType().isAudioDeviceAdded() == false) || (eventType().isAudioDeviceRemoved() == false))
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return audioDeviceEvent_;
}

const GfxUserEvent& GfxEvent::userEvent(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (eventType().isUserEvent() == false)
    {
        throw std::runtime_error(kInvalidEventTypeMessage);
    };

    return userEvent_;
}

void GfxEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    event_.type = SDL_FIRSTEVENT;
    eventType_.clear();
    eventFilterFunctionObject_ = nullptr;
    eventWatchFunctionObject_ = nullptr;
    filterEventsFunctionObject_ = nullptr;
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
    ctrlAxisEvent_.clear();
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
            ctrlAxisEvent_.setValue(event_.caxis);
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

void GfxEvent::assign(const GfxEvent& other) noexcept
{
    LOG_TRACE_PRIO_LOW();

    event_ = other.event_;
    eventType_ = other.eventType_;
    eventFilterFunctionObject_ = other.eventFilterFunctionObject_;
    eventWatchFunctionObject_ = other.eventWatchFunctionObject_;
    filterEventsFunctionObject_ = other.filterEventsFunctionObject_;
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
    ctrlAxisEvent_ = other.ctrlAxisEvent_;
    ctrlButtonEvent_ = other.ctrlButtonEvent_;
    ctrlDeviceEvent_ = other.ctrlDeviceEvent_;
    fingerEvent_ = other.fingerEvent_;
    dollarEvent_ = other.dollarEvent_;
    multiGestureEvent_ = other.multiGestureEvent_;
    dropEvent_ = other.dropEvent_;
    audioDeviceEvent_ = other.audioDeviceEvent_;
    userEvent_ = other.userEvent_;
}

int32_t GfxEvent::eventFilterFunction(void * userdata, SdlTypePtr event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr->eventFilterFunctionObject_ != nullptr)
    {
        ret = (*(evptr->eventFilterFunctionObject_))(GfxEvent(*event));
    }
    return ret;
}

int32_t GfxEvent::eventWatchFunction(void * userdata, SdlTypePtr event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr->eventWatchFunctionObject_ != nullptr)
    {
        ret = (*(evptr->eventWatchFunctionObject_))(GfxEvent(*event));
    }
    return ret;
}

int32_t GfxEvent::filterEventsFunction(void * userdata, SdlTypePtr event)
{
    assert(userdata != nullptr);
    assert(event != nullptr);

    int32_t ret = 0;
    GfxEvent * evptr = static_cast<GfxEvent *>(userdata);

    if (evptr->filterEventsFunctionObject_ != nullptr)
    {
        ret = (*(evptr->filterEventsFunctionObject_))(GfxEvent(*event));
    }
    return ret;
}

}  // namespace events

}  // namespace gfx

/* EOF */
