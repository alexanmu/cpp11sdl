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

#ifndef GfxCommonEvent_hpp
#define GfxCommonEvent_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxEventConstants.hpp"
#include "GfxEventType.hpp"

namespace gfx
{

namespace events
{

class GfxCommonEvent final : public GfxObject
{
public:
    typedef SDL_CommonEvent SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxCommonEvent() noexcept;
    explicit GfxCommonEvent(const uint32_t type, const uint32_t timestamp) noexcept;
    explicit GfxCommonEvent(const SdlType ev) noexcept;

    GfxCommonEvent(const GfxCommonEvent& other) noexcept;
    GfxCommonEvent(GfxCommonEvent&& other) noexcept;

    GfxCommonEvent& operator=(const GfxCommonEvent& other) noexcept;
    GfxCommonEvent& operator=(GfxCommonEvent&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxEventType getType(void) const noexcept;
    uint32_t getTimeStamp(void) const noexcept;

    void setType(const GfxEventType& evtype) noexcept;
    void setTimeStamp(const uint32_t timestamp) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType commonEvent_;
};

}  // namespace events

}  // namespace gfx

#endif  /* GfxCommonEvent_hpp */
