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


#ifndef GfxGameControllerButtonBind_hpp
#define GfxGameControllerButtonBind_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxGameControllerBindType.hpp"

namespace gfx
{

namespace gamecontroller
{

class GfxGameControllerButtonBind final : public GfxObject
{
public:
    typedef SDL_GameControllerButtonBind SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;


    GfxGameControllerButtonBind() noexcept;

    explicit GfxGameControllerButtonBind(const SdlType bbind) noexcept;

    GfxGameControllerButtonBind(const GfxGameControllerButtonBind& other) noexcept;
    GfxGameControllerButtonBind(GfxGameControllerButtonBind&& other) noexcept;

    GfxGameControllerButtonBind& operator=(const GfxGameControllerButtonBind& other) noexcept;
    GfxGameControllerButtonBind& operator=(GfxGameControllerButtonBind&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    GfxGameControllerBindType getBindType(void) const noexcept;
    int32_t getButton(void) const noexcept;
    int32_t getAxis(void) const noexcept;
    int32_t getHat(void) const noexcept;
    int32_t getHatMask(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType buttonBind_;
};

}  // namespace gamecontroller

}  // namespace gfx

#endif /* GfxGameControllerButtonBind_hpp */
