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

#ifndef GfxJoystickGUID_hpp
#define GfxJoystickGUID_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxjoystickguid::joystick::gfx");

namespace gfx
{

namespace joystick
{

class GfxJoystickGUID final : public GfxObject
{
public:
    typedef sdl2::SDL_JoystickGUID SdlType;
    typedef sdl2::SDL_JoystickGUID * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxJoystickGUID() noexcept;

    explicit GfxJoystickGUID(const uint8_t value[]) noexcept;
    explicit GfxJoystickGUID(const SdlType value) noexcept;

    GfxJoystickGUID(const GfxJoystickGUID& other) noexcept;
    GfxJoystickGUID(GfxJoystickGUID&& other) noexcept;

    GfxJoystickGUID& operator=(const GfxJoystickGUID& other) noexcept;
    GfxJoystickGUID& operator=(GfxJoystickGUID&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    uint8_t * getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void copyValues(uint8_t * values) noexcept;

    SdlType guid_;

    static const int32_t kGuidNumberOfBytes = 16;
};

}  // namespace joystick

}  // namespace gfx

#endif /* GfxJoystickGUID_hpp */
