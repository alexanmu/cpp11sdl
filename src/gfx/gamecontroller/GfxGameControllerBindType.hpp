/*
  Giotto
  Copyright (C) 2019 George Oros

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

#ifndef GfxGameControllerBindType_hpp
#define GfxGameControllerBindType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace gamecontroller
{

class GfxGameControllerBindType final : public GfxObject
{
public:
    typedef SDL_GameControllerBindType SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        bindTypeNone = SDL_CONTROLLER_BINDTYPE_NONE,
        bindTypeNormal = SDL_CONTROLLER_BINDTYPE_BUTTON,
        bindTypeAxis = SDL_CONTROLLER_BINDTYPE_AXIS,
        bindTypeHat = SDL_CONTROLLER_BINDTYPE_HAT
    };

    GfxGameControllerBindType() noexcept;

    explicit GfxGameControllerBindType(const SdlType btype) noexcept;
    explicit GfxGameControllerBindType(const ValueType btype) noexcept;

    GfxGameControllerBindType(const GfxGameControllerBindType& other) noexcept;
    GfxGameControllerBindType(GfxGameControllerBindType&& other) noexcept;

    GfxGameControllerBindType& operator=(const GfxGameControllerBindType& other) noexcept;
    GfxGameControllerBindType& operator=(GfxGameControllerBindType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isBindTypeNone(void) const noexcept;
    bool isBindTypeNormal(void) const noexcept;
    bool isBindTypeAxis(void) const noexcept;
    bool isBindTypeHat(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType bType_;
};

}  // namespace gamecontroller

}  // namespace gfx

#endif /* GfxGameControllerBindType_hpp */
