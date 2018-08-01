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

#ifndef GfxKeyboardEvent_hpp
#define GfxKeyboardEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxEventConstants.hpp"
#include "IGetCommonEvent.hpp"
#include "IGetWindowID.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"
#include "GfxKeysym.hpp"

namespace gfx
{

namespace events
{

class GfxKeyboardEvent final : public GfxObject, public prv::IGetCommonEvent, public prv::IGetWindowID
{
public:
    typedef SDL_KeyboardEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxKeyboardEvent() noexcept;
    explicit GfxKeyboardEvent(const SdlType event) noexcept;

    GfxKeyboardEvent(const GfxKeyboardEvent& other) noexcept;
    GfxKeyboardEvent(GfxKeyboardEvent&& other) noexcept;

    GfxKeyboardEvent& operator=(const GfxKeyboardEvent& other) noexcept;
    GfxKeyboardEvent& operator=(GfxKeyboardEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxCommonEvent getCommonEvent(void) const noexcept;

    virtual uint32_t getWindowID(void) const noexcept;

    uint8_t getState(void) const noexcept;
    bool getRepeat(void) const noexcept;
    const keyboard::GfxKeysym getKeysym(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType keyboardEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxKeyboardEvent_hpp */
