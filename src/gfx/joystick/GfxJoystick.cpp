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
#include <string>

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

    joy_ = nullptr;
}

GfxJoystick::GfxJoystick(const int32_t index) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(index >= 0);

    joy_ = nullptr;

    SdlTypePtr tmpjoyptr;

    tmpjoyptr = sdl2::SDL_JoystickOpen(index);
    if (tmpjoyptr == nullptr)
    {
        throw std::runtime_error("Unable to create GfxJoystick object");
    }
    joy_ = tmpjoyptr;
}

GfxJoystick::GfxJoystick(GfxJoystickID const& joyid) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(joyid);

    joy_ = nullptr;

    SdlTypePtr tmpjoyptr;

    tmpjoyptr = sdl2::SDL_JoystickFromInstanceID(joyid.getAsSdlType());
    if (tmpjoyptr == nullptr)
    {
        throw std::runtime_error("Unable to create GfxJoystick object");
    }
    joy_ = tmpjoyptr;
}

GfxJoystick::GfxJoystick(GfxJoystick&& other) noexcept : GfxObject(ClassName)
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
        sdl2::SDL_JoystickClose(joy_);
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

int32_t GfxJoystick::numJoysticks(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_NumJoysticks();
}

std::string GfxJoystick::joystickNameForIndex(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    const char * chptr;

    chptr = sdl2::SDL_JoystickNameForIndex(index);
    if (chptr != NULL)
    {
        return std::string(chptr);
    }
    return std::string();
}

GfxJoystickGUID GfxJoystick::joystickGetDeviceGUID(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickGUID::SdlType guid;

    guid = sdl2::SDL_JoystickGetDeviceGUID(index);
    return GfxJoystickGUID(guid);
}

uint16_t GfxJoystick::joystickGetDeviceVendor(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return sdl2::SDL_JoystickGetDeviceVendor(index);
}

uint16_t GfxJoystick::joystickGetDeviceProduct(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return sdl2::SDL_JoystickGetDeviceProduct(index);
}

uint16_t GfxJoystick::joystickGetDeviceProductVersion(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    return sdl2::SDL_JoystickGetDeviceProductVersion(index);
}

GfxJoystickType GfxJoystick::joystickGetDeviceType(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickType::SdlType jtype;

    jtype = sdl2::SDL_JoystickGetDeviceType(index);
    return GfxJoystickType(jtype);
}

GfxJoystickID GfxJoystick::joystickGetDeviceInstanceID(const int32_t index) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxJoystickID::SdlType id;

    id = sdl2::SDL_JoystickGetDeviceInstanceID(index);
    if (static_cast<int32_t>(id) != -1)
    {
        return GfxJoystickID(id);
    }
    return GfxJoystickID();
}

std::string GfxJoystick::joystickName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * chptr;

    if (joy_ != nullptr)
    {
        chptr = sdl2::SDL_JoystickName(joy_);
        if (chptr != NULL)
        {
            return std::string(chptr);
        }
    }
    return std::string();
}

GfxJoystickGUID GfxJoystick::joystickGetGUID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickGUID::SdlType guid;

    if (joy_ != nullptr)
    {
        guid = sdl2::SDL_JoystickGetGUID(joy_);
        return GfxJoystickGUID(guid);
    }
    return GfxJoystickGUID();
}

uint16_t GfxJoystick::joystickGetVendor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickGetVendor(joy_);
    }
    return 0;
}

uint16_t GfxJoystick::joystickGetProduct(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickGetProduct(joy_);
    }
    return 0;
}

uint16_t GfxJoystick::joystickGetProductVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickGetProductVersion(joy_);
    }
    return 0;
}

GfxJoystickType GfxJoystick::joystickGetType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickType::SdlType type;

    if (joy_ != nullptr)
    {
        type = sdl2::SDL_JoystickGetType(joy_);
        return GfxJoystickType(type);
    }
    return GfxJoystickType();
}

std::string GfxJoystick::joystickGetGUIDString(GfxJoystickGUID const& guid) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(guid);

    char * ptr;
    std::string str;

    ptr = static_cast<char *>(std::malloc(33));
    sdl2::SDL_JoystickGetGUIDString(guid.getAsSdlType(), ptr, 33);
    str = std::string(ptr);
    free(ptr);
    return str;
}

GfxJoystickGUID GfxJoystick::joystickGetGUIDFromString(std::string const guid) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(guid.length() > 0);

    GfxJoystickGUID::SdlType sdlguid;

    sdlguid = sdl2::SDL_JoystickGetGUIDFromString(guid.c_str());
    return GfxJoystickGUID(sdlguid);
}

GfxBool GfxJoystick::joystickGetAttached(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    if (joy_ != nullptr)
    {
        sdlbool = sdl2::SDL_JoystickGetAttached(joy_);
        return GfxBool(sdlbool);
    }
    return GfxBool(false);
}

GfxJoystickID GfxJoystick::joystickInstanceID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickID::SdlType id;

    if (joy_ != nullptr)
    {
        id = sdl2::SDL_JoystickInstanceID(joy_);
    }
    return GfxJoystickID();
}

int32_t GfxJoystick::joystickNumAxes(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickNumAxes(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumBalls(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickNumBalls(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumHats(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickNumHats(joy_);
    }
    return 0;
}

int32_t GfxJoystick::joystickNumButtons(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickNumButtons(joy_);
    }
    return 0;
}

void GfxJoystick::joystickUpdate(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_JoystickUpdate();
}

int32_t GfxJoystick::joystickEventState(const int32_t state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert((state == events::kGfxQuery) || (state == events::kGfxEnable) || (state == events::kGfxIgnore));

    return sdl2::SDL_JoystickEventState(state);
}

int16_t GfxJoystick::joystickGetAxis(const int32_t axis) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis >= 0);

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickGetAxis(joy_, axis);
    }
    return 0;
}

GfxBool GfxJoystick::joystickGetAxisInitialState(const int32_t axis, int16_t * state) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis >= 0);
    assert(state != nullptr);

    GfxBool::SdlType sdlbool;

    *state = 0;
    if (joy_ != nullptr)
    {
        sdlbool = sdl2::SDL_JoystickGetAxisInitialState(joy_, axis, state);
        return GfxBool(sdlbool);
    }
    return GfxBool(false);
}

GfxHatPosition GfxJoystick::joystickGetHat(const int32_t hat) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(hat >= 0);

    GfxHatPosition::SdlType hatpos;

    if (joy_ != nullptr)
    {
        hatpos = sdl2::SDL_JoystickGetHat(joy_, hat);
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
        sdl2::SDL_JoystickGetBall(joy_, ball, dx, dy);
    }
}

uint8_t GfxJoystick::joystickGetButton(const int32_t button) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(button >= 0);

    if (joy_ != nullptr)
    {
        return sdl2::SDL_JoystickGetButton(joy_, button);
    }
    return 0;
}

void GfxJoystick::joystickClose(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (joy_ != nullptr)
    {
        sdl2::SDL_JoystickClose(joy_);
        joy_ = nullptr;
    }
}

GfxJoystickPowerLevel GfxJoystick::joystickCurrentPowerLevel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxJoystickPowerLevel::SdlType plvl;

    if (joy_ != nullptr)
    {
        plvl = sdl2::SDL_JoystickCurrentPowerLevel(joy_);
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
