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

#ifndef GfxSysWmEvent_hpp
#define GfxSysWmEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "IGetCommonEvent.hpp"
#include "GfxEventType.hpp"
#include "GfxCommonEvent.hpp"

namespace gfx
{

namespace events
{

class GfxSysWmEvent final : public GfxObject, public prv::IGetCommonEvent
{
public:
    typedef SDL_SysWMEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxSysWmEvent() noexcept;
    explicit GfxSysWmEvent(const SdlType event) noexcept;

    GfxSysWmEvent(const GfxSysWmEvent& other) noexcept;
    GfxSysWmEvent(GfxSysWmEvent&& other) noexcept;

    GfxSysWmEvent& operator=(const GfxSysWmEvent& other) noexcept;
    GfxSysWmEvent& operator=(GfxSysWmEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxCommonEvent getCommonEvent(void) const noexcept;

    void setValue(const SdlType event) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType wmEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxSysWmEvent_hpp */
