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

#ifndef GfxTouchFingerEvent_hpp
#define GfxTouchFingerEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "IGetCommonEvent.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"
#include "GfxTouchID.hpp"
#include "GfxFingerID.hpp"

namespace gfx
{

namespace events
{

class GfxTouchFingerEvent : public GfxObject, public prv::IGetCommonEvent
{
public:
    typedef sdl2::SDL_TouchFingerEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxTouchFingerEvent() noexcept;
    explicit GfxTouchFingerEvent(const SdlType event) noexcept;

    GfxTouchFingerEvent(GfxTouchFingerEvent const& other) noexcept;
    GfxTouchFingerEvent(GfxTouchFingerEvent&& other) noexcept;

    GfxTouchFingerEvent& operator=(GfxTouchFingerEvent const& other) noexcept;
    GfxTouchFingerEvent& operator=(GfxTouchFingerEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxCommonEvent getCommonEvent(void) const noexcept;
    virtual const touch::GfxTouchID getTouchID(void) const noexcept;

    const touch::GfxFingerID getFingerID(void) const noexcept;
    float getX(void) const noexcept;
    float getY(void) const noexcept;
    float getdX(void) const noexcept;
    float getdY(void) const noexcept;
    float getPressure(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType tfEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxTouchFingerEvent_hpp */
