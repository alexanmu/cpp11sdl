/*
 Giotto
 Copyright (C) 2019 George Oros
 
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
#include <string>
#include <utility>

#include "GfxJoystick.hpp"
#include "GfxBasicLogger.hpp"
#include "GfxEventConstants.hpp"

LOG_TRACE_MODULE_NAME("gfxjoystick::joystick::gfx");

namespace gfx
{

namespace joystick
{

const char GfxJoystick::ClassName[] = "GfxJoystick";

GfxJoystick::GfxJoystick() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxJoystick::GfxJoystick(const int32_t index) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(index >= 0);

    joy_ = nullptr;

    SdlTypePtr tmpjoyptr;

    tmpjoyptr = SDL_JoystickOpen(index);
    if (tmpjoyptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create GfxJoystick object (" + sdlErr + ")");
    }
    joy_ = tmpjoyptr;
}

GfxJoystick::GfxJoystick(const GfxJoystickID& joyid) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(joyid);

    joy_ = nullptr;

    SdlTypePtr tmpjoyptr;

    tmpjoyptr = SDL_JoystickFromInstanceID(joyid.getAsSdlType());
    if (tmpjoyptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create GfxJoystick object (" + sdlErr + ")");
    }
    joy_ = tmpjoyptr;
}

GfxJoystick::GfxJoystick(GfxJoystick&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    joy_ = other.joy_;
    // Delete other's data
    other.clear();
}

GfxJoystick& GfxJoystick::operator=(GfxJoystick&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        joy_ = other.joy_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxJoystick::~GfxJoystick()
{
    LOG_TRACE_PRIO_MED();

    if (joy_ != nullptr)
    {
        SDL_JoystickClose(joy_);
        joy_ = nullptr;
    }
}

GfxJoystick::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (joy_ != nullptr);
}

std::string GfxJoystick::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxJoystick::joystickOpen(const int32_t index) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(index >= 0);

    joy_ = nullptr;

    SdlTypePtr tmpjoyptr;

    if (joy_ != nullptr)
    {
        throw std::runtime_error("Joystick already open");
    }
    tmpjoyptr = SDL_JoystickOpen(index);
    if (tmpjoyptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create GfxJoystick object (" + sdlErr + ")");
    }
    joy_ = tmpjoyptr;
}

void GfxJoystick::lockJoysticks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_LockJoysticks();
}

void GfxJoystick::unlockJoysticks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_UnlockJoysticks();
}

int32_t GfxJoystick::numJoysticks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return SDL_NumJoysticks();
}

const std::string GfxJoystick::joystickNameForIndex(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    const char * chptr;

    chptr = SDL_JoystickNameForIndex(index);
    if (chptr != NULL)
    {
        return std::string(chptr);
    }
    return std::string();
}

const GfxJoystickGUID GfxJoystick::joystickGetDeviceGUID(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickGUID::SdlType guid;

    guid = SDL_JoystickGetDeviceGUID(index);
    return GfxJoystickGUID(guid);
}

uint16_t GfxJoystick::joystickGetDeviceVendor(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return SDL_JoystickGetDeviceVendor(index);
}

uint16_t GfxJoystick::joystickGetDeviceProduct(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return SDL_JoystickGetDeviceProduct(index);
}

uint16_t GfxJoystick::joystickGetDeviceProductVersion(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return SDL_JoystickGetDeviceProductVersion(index);
}

const GfxJoystickType GfxJoystick::joystickGetDeviceType(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickType::SdlType jtype;

    jtype = SDL_JoystickGetDeviceType(index);
    return GfxJoystickType(jtype);
}

const GfxJoystickID GfxJoystick::joystickGetDeviceInstanceID(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickID::SdlType id;

    id = SDL_JoystickGetDeviceInstanceID(index);
    if (static_cast<int32_t>(id) != -1)
    {
        return GfxJoystickID(id);
    }
    return GfxJoystickID();
}

const std::string GfxJoystick::joystickName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * chptr;

    if (joy_ != nullptr)
    {
        chptr = SDL_JoystickName(joy_);
        if (chptr != NULL)
        {
            return std::string(chptr);
        }
    }
    return std::string();
}

const GfxJoystickGUID GfxJoystick::joystickGetGUID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickGUID::SdlType guid;

    if (joy_ != nullptr)
    {
        guid = SDL_JoystickGetGUID(joy_);
        return GfxJoystickGUID(guid);
    }
    return GfxJoystickGUID();
}

uint16_t GfxJoystick::joystickGetVendor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickGetVendor(joy_);
    }
    return 0;
}

uint16_t GfxJoystick::joystickGetProduct(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickGetProduct(joy_);
    }
    return 0;
}

uint16_t GfxJoystick::joystickGetProductVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickGetProductVersion(joy_);
    }
    return 0;
}

const GfxJoystickType GfxJoystick::joystickGetType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickType::SdlType type;

    if (joy_ != nullptr)
    {
        type = SDL_JoystickGetType(joy_);
        return GfxJoystickType(type);
    }
    return GfxJoystickType();
}

const std::string GfxJoystick::joystickGetGUIDString(const GfxJoystickGUID& guid) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(guid);

    char * ptr;
    std::string str;

    ptr = static_cast<char *>(std::malloc(33));
    SDL_JoystickGetGUIDString(guid.getAsSdlType(), ptr, 33);
    str = std::string(ptr);
    free(ptr);
    return str;
}

const GfxJoystickGUID GfxJoystick::joystickGetGUIDFromString(const std::string& guid) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(guid.length() > 0);

    GfxJoystickGUID::SdlType sdlguid;

    sdlguid = SDL_JoystickGetGUIDFromString(guid.c_str());
    return GfxJoystickGUID(sdlguid);
}

const GfxBool GfxJoystick::joystickGetAttached(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    if (joy_ != nullptr)
    {
        sdlbool = SDL_JoystickGetAttached(joy_);
        return GfxBool(sdlbool);
    }
    return GfxBool(false);
}

const GfxJoystickID GfxJoystick::joystickInstanceID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickID::SdlType id;

    if (joy_ != nullptr)
    {
        id = SDL_JoystickInstanceID(joy_);
        return GfxJoystickID(id);
    }
    return GfxJoystickID();
}

int32_t GfxJoystick::joystickNumAxes(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickNumAxes(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumBalls(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickNumBalls(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumHats(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickNumHats(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumButtons(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return SDL_JoystickNumButtons(joy_);
    }
    return 0;
}

void GfxJoystick::joystickUpdate(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_JoystickUpdate();
}

events::GfxEventActionCommand GfxJoystick::joystickEventState(const events::GfxEventActionCommand state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((static_cast<events::GfxEventActionCommand>(state) == events::GfxEventActionCommand::kGfxQuery) ||
           (static_cast<events::GfxEventActionCommand>(state) == events::GfxEventActionCommand::kGfxEnable) ||
           (static_cast<events::GfxEventActionCommand>(state) == events::GfxEventActionCommand::kGfxIgnore));

    return static_cast<events::GfxEventActionCommand>(SDL_JoystickEventState(static_cast<int32_t>(state)));
}

int16_t GfxJoystick::joystickGetAxis(const int32_t axis) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis >= 0);

    if (joy_ != nullptr)
    {
        return SDL_JoystickGetAxis(joy_, axis);
    }
    return 0;
}

const GfxBool GfxJoystick::joystickGetAxisInitialState(const int32_t axis, int16_t * state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis >= 0);
    assert(state != nullptr);

    GfxBool::SdlType sdlbool;

    *state = 0;
    if (joy_ != nullptr)
    {
        sdlbool = SDL_JoystickGetAxisInitialState(joy_, axis, state);
        return GfxBool(sdlbool);
    }
    return GfxBool(false);
}

const GfxHatPosition GfxJoystick::joystickGetHat(const int32_t hat) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(hat >= 0);

    GfxHatPosition::SdlType hatpos;

    if (joy_ != nullptr)
    {
        hatpos = SDL_JoystickGetHat(joy_, hat);
        return GfxHatPosition(hatpos);
    }
    return GfxHatPosition();
}

void GfxJoystick::joystickGetBall(const int32_t ball, int32_t * dx, int32_t * dy) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(ball >= 0);
    assert(dx != nullptr);
    assert(dy != nullptr);

    *dx = 0;
    *dy = 0;
    if (joy_ != nullptr)
    {
        SDL_JoystickGetBall(joy_, ball, dx, dy);
    }
}

uint8_t GfxJoystick::joystickGetButton(const int32_t button) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(button >= 0);

    if (joy_ != nullptr)
    {
        return SDL_JoystickGetButton(joy_, button);
    }
    return 0;
}

void GfxJoystick::joystickClose(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        SDL_JoystickClose(joy_);
        joy_ = nullptr;
    }
}

const GfxJoystickPowerLevel GfxJoystick::joystickCurrentPowerLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickPowerLevel::SdlType plvl;

    if (joy_ != nullptr)
    {
        plvl = SDL_JoystickCurrentPowerLevel(joy_);
        return GfxJoystickPowerLevel(plvl);
    }
    return GfxJoystickPowerLevel();
}

void GfxJoystick::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    joy_ = nullptr;
}

GfxJoystick::SdlTypePtr GfxJoystick::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return joy_;
}

}  // namespace joystick

}  // namespace gfx

/* EOF */
