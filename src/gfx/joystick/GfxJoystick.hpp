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

#ifndef GfxJoystick_hpp
#define GfxJoystick_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxJoystickGUID.hpp"
#include "GfxJoystickType.hpp"
#include "GfxJoystickID.hpp"
#include "GfxBool.hpp"
#include "GfxHatPosition.hpp"
#include "GfxJoystickPowerLevel.hpp"
#include "GfxEventConstants.hpp"

namespace gfx
{

namespace joystick
{

class GfxJoystick final : public GfxObject
{
public:
    typedef SDL_Joystick * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    static const int32_t kJoystickAxisMin = -32768;
    static const int32_t kJoystickAxisMax = 32768;

    GfxJoystick() noexcept;

    explicit GfxJoystick(const int32_t index) throw(std::runtime_error);
    explicit GfxJoystick(GfxJoystickID const& joyid) throw(std::runtime_error);

    GfxJoystick(const GfxJoystick& other) = delete;
    GfxJoystick(GfxJoystick&& other) noexcept;

    GfxJoystick& operator=(const GfxJoystick& other) = delete;
    GfxJoystick& operator=(GfxJoystick&& other) noexcept;

    virtual ~GfxJoystick();

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void joystickOpen(const int32_t index) throw(std::runtime_error);

    void lockJoysticks(void) const noexcept;
    void unlockJoysticks(void) const noexcept;
    int32_t numJoysticks(void) const noexcept;
    const std::string joystickNameForIndex(const int32_t index) const noexcept;
    const GfxJoystickGUID joystickGetDeviceGUID(const int32_t index) const noexcept;
    uint16_t joystickGetDeviceVendor(const int32_t index) const noexcept;
    uint16_t joystickGetDeviceProduct(const int32_t index) const noexcept;
    uint16_t joystickGetDeviceProductVersion(const int32_t index) const noexcept;
    const GfxJoystickType joystickGetDeviceType(const int32_t index) const noexcept;
    const GfxJoystickID joystickGetDeviceInstanceID(const int32_t index) const noexcept;
    const std::string joystickName(void) const noexcept;
    const GfxJoystickGUID joystickGetGUID(void) const noexcept;
    uint16_t joystickGetVendor(void) const noexcept;
    uint16_t joystickGetProduct(void) const noexcept;
    uint16_t joystickGetProductVersion(void) const noexcept;
    const GfxJoystickType joystickGetType(void) const noexcept;
    const std::string joystickGetGUIDString(const GfxJoystickGUID& guid) const noexcept;
    const GfxJoystickGUID joystickGetGUIDFromString(const std::string& guid) const noexcept;
    const GfxBool joystickGetAttached(void) const noexcept;
    const GfxJoystickID joystickInstanceID(void) const noexcept;
    int32_t joystickNumAxes(void) const noexcept;
    int32_t joystickNumBalls(void) const noexcept;
    int32_t joystickNumHats(void) const noexcept;
    int32_t joystickNumButtons(void) const noexcept;
    void joystickUpdate(void) const noexcept;
    events::GfxEventActionCommand joystickEventState(const events::GfxEventActionCommand state) const noexcept;
    int16_t joystickGetAxis(const int32_t axis) const noexcept;
    const GfxBool joystickGetAxisInitialState(const int32_t axis, int16_t * state) const noexcept;
    const GfxHatPosition joystickGetHat(const int32_t hat) const noexcept;
    void joystickGetBall(const int32_t ball, int32_t * dx, int32_t * dy) const noexcept;
    uint8_t joystickGetButton(const int32_t button) const noexcept;
    void joystickClose(void) noexcept;
    const GfxJoystickPowerLevel joystickCurrentPowerLevel(void) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr joy_;
};

}  // namespace joystick

}  // namespace gfx

#endif /* GfxJoystick_hpp */
