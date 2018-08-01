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


#ifndef GfxGameControllerAxis_hpp
#define GfxGameControllerAxis_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace gamecontroller
{

class GfxGameControllerAxis final : public GfxObject
{
public:
    typedef SDL_GameControllerAxis SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        axisInvalid = SDL_CONTROLLER_AXIS_INVALID,
        axisLeftX = SDL_CONTROLLER_AXIS_LEFTX,
        axisLeftY = SDL_CONTROLLER_AXIS_LEFTY,
        axisRightX = SDL_CONTROLLER_AXIS_RIGHTX,
        axisRightY = SDL_CONTROLLER_AXIS_RIGHTY,
        axisTriggerLeft = SDL_CONTROLLER_AXIS_TRIGGERLEFT,
        axisTriggerRight = SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
        axisMax = SDL_CONTROLLER_AXIS_MAX
    };

    GfxGameControllerAxis() noexcept;

    explicit GfxGameControllerAxis(const SdlType axis) noexcept;
    explicit GfxGameControllerAxis(const ValueType axis) noexcept;

    GfxGameControllerAxis(const GfxGameControllerAxis& other) noexcept;
    GfxGameControllerAxis(GfxGameControllerAxis&& other) noexcept;

    GfxGameControllerAxis& operator=(const  GfxGameControllerAxis& other) noexcept;
    GfxGameControllerAxis& operator=(GfxGameControllerAxis&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isAxisInvalid(void) const noexcept;
    bool isAxisLeftX(void) const noexcept;
    bool isAxisLeftY(void) const noexcept;
    bool isAxisRightX(void) const noexcept;
    bool isAxisRightY(void) const noexcept;
    bool isAxisTriggerLeft(void) const noexcept;
    bool isAxisTriggerRight(void) const noexcept;
    bool isAxisMax(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType axis_;
};

}  // namespace gamecontroller

}  // namespace gfx

#endif /* GfxGameControllerAxis_hpp */
