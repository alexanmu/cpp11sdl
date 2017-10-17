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


#ifndef GfxGameControllerButton_hpp
#define GfxGameControllerButton_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace gamecontroller
{

class GfxGameControllerButton final : public GfxObject
{
public:
    typedef sdl2::SDL_GameControllerButton SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        buttonInvalid = sdl2::SDL_CONTROLLER_BUTTON_INVALID,
        buttonA = sdl2::SDL_CONTROLLER_BUTTON_A,
        buttonB = sdl2::SDL_CONTROLLER_BUTTON_B,
        buttonX = sdl2::SDL_CONTROLLER_BUTTON_X,
        buttonY = sdl2::SDL_CONTROLLER_BUTTON_Y,
        buttonBack = sdl2::SDL_CONTROLLER_BUTTON_BACK,
        buttonGuide = sdl2::SDL_CONTROLLER_BUTTON_GUIDE,
        buttonStart = sdl2::SDL_CONTROLLER_BUTTON_START,
        buttonLeftStick = sdl2::SDL_CONTROLLER_BUTTON_LEFTSTICK,
        buttonRightStick = sdl2::SDL_CONTROLLER_BUTTON_RIGHTSTICK,
        buttonLeftShoulder = sdl2::SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
        buttonRightShoulder = sdl2::SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
        buttonDPadUp = sdl2::SDL_CONTROLLER_BUTTON_DPAD_UP,
        buttonDPadDown = sdl2::SDL_CONTROLLER_BUTTON_DPAD_DOWN,
        buttonDPadLeft = sdl2::SDL_CONTROLLER_BUTTON_DPAD_LEFT,
        buttonDPadRight = sdl2::SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
        buttonMax = sdl2::SDL_CONTROLLER_BUTTON_MAX
    };

    GfxGameControllerButton() noexcept;

    explicit GfxGameControllerButton(const SdlType button) noexcept;
    explicit GfxGameControllerButton(const ValueType button) noexcept;

    GfxGameControllerButton(GfxGameControllerButton const& other) noexcept;
    GfxGameControllerButton(GfxGameControllerButton&& other) noexcept;

    GfxGameControllerButton& operator=(GfxGameControllerButton const& other) noexcept;
    GfxGameControllerButton& operator=(GfxGameControllerButton&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isButtonInvalid(void) const noexcept;
    bool isButtonA(void) const noexcept;
    bool isButtonB(void) const noexcept;
    bool isButtonX(void) const noexcept;
    bool isButtonY(void) const noexcept;
    bool isButtonBack(void) const noexcept;
    bool isButtonGuide(void) const noexcept;
    bool isButtonStart(void) const noexcept;
    bool isButtonLeftStick(void) const noexcept;
    bool isButtonRightStick(void) const noexcept;
    bool isButtonLeftShoulder(void) const noexcept;
    bool isButtonRightShoulder(void) const noexcept;
    bool isButtonDPadUp(void) const noexcept;
    bool isButtonDPadDown(void) const noexcept;
    bool isButtonDPadLeft(void) const noexcept;
    bool isButtonDPadRight(void) const noexcept;
    bool isButtonMax(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType button_;
};

}  // namespace gamecontroller

}  // namespace gfx

#endif /* GfxGameControllerButton_hpp */
