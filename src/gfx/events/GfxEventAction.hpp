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

#ifndef GfxEventAction_hpp
#define GfxEventAction_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace events
{

class GfxEventAction final : public GfxObject
{
public:
    typedef SDL_eventaction SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        addEvent = SDL_ADDEVENT,
        peekEvent = SDL_PEEKEVENT,
        getEvent = SDL_GETEVENT
    };

    GfxEventAction() noexcept;
    explicit GfxEventAction(const ValueType act) noexcept;
    explicit GfxEventAction(const SdlType act) noexcept;

    GfxEventAction(const GfxEventAction& other) noexcept;
    GfxEventAction(GfxEventAction&& other) noexcept;

    GfxEventAction& operator=(const GfxEventAction& other) noexcept;
    GfxEventAction& operator=(GfxEventAction&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isAddEvent(void) const noexcept;
    bool isPeekEvent(void) const noexcept;
    bool isGetEvent(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType action_;
};

}  // namespace events

}  // namespace gfx

#endif /* GfxEventAction_hpp */
