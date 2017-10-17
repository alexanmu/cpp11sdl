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

#ifndef GfxDropEvent_hpp
#define GfxDropEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "IGetCommonEvent.hpp"
#include "IGetWindowID.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"

namespace gfx
{

namespace events
{

class GfxDropEvent : public GfxObject, public prv::IGetCommonEvent, public prv::IGetWindowID
{
public:
    typedef sdl2::SDL_DropEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxDropEvent() noexcept;
    explicit GfxDropEvent(const SdlType event) noexcept;

    GfxDropEvent(GfxDropEvent const& other) noexcept;
    GfxDropEvent(GfxDropEvent&& other) noexcept;

    GfxDropEvent& operator=(GfxDropEvent const& other) noexcept;
    GfxDropEvent& operator=(GfxDropEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxCommonEvent getCommonEvent(void) const noexcept;
    virtual uint32_t getWindowID(void) const noexcept;

    const std::string getFile(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType dEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxDropEvent_hpp */
