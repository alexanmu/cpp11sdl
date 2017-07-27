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

#ifndef GfxJoyHatEvent_hpp
#define GfxJoyHatEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "IGetCommonEvent.hpp"
#include "IGetJoystickID.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"
#include "GfxHatPosition.hpp"

namespace gfx
{

namespace events
{

class GfxJoyHatEvent : public GfxObject, public prv::IGetCommonEvent, public prv::IGetJoystickID
{
public:
    typedef sdl2::SDL_JoyHatEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxJoyHatEvent() noexcept;
    explicit GfxJoyHatEvent(const SdlType event) noexcept;

    GfxJoyHatEvent(GfxJoyHatEvent const& other) noexcept;
    GfxJoyHatEvent(GfxJoyHatEvent&& other) noexcept;

    GfxJoyHatEvent& operator=(GfxJoyHatEvent const& other) noexcept;
    GfxJoyHatEvent& operator=(GfxJoyHatEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual GfxCommonEvent getCommonEvent(void) const noexcept;

    virtual joystick::GfxJoystickID getJoystickID(void) const noexcept;

    uint8_t getHat(void) const noexcept;
    joystick::GfxHatPosition getPosition(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType jhEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxJoyHatEvent_hpp */
