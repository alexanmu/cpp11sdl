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

#ifndef GfxGameController_hpp
#define GfxGameController_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxJoystickGUID.hpp"
#include "GfxBool.hpp"
#include "GfxJoystickID.hpp"
#include "GfxJoystick.hpp"
#include "GfxEventConstants.hpp"
#include "GfxGameControllerAxis.hpp"
#include "GfxGameControllerButtonBind.hpp"
#include "GfxGameControllerButton.hpp"

namespace gfx
{

namespace gamecontroller
{

class GfxGameController final : public GfxObject
{
public:
    typedef SDL_GameController * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxGameController() noexcept;
    explicit GfxGameController(const int32_t index) throw(std::runtime_error);

    GfxGameController(const GfxGameController& other) = delete;
    GfxGameController(GfxGameController&& other) noexcept;

    GfxGameController& operator=(const GfxGameController& other) = delete;
    GfxGameController& operator=(GfxGameController&& other) noexcept;

    virtual ~GfxGameController();

    void gameControllerOpen(const int32_t index) throw(std::runtime_error);
    void gameControllerClose(void) noexcept;

    /* void gameControllerAddMappingsFromRW(); ~GeOr~ ToDo */
    /* void gameControllerAddMappingsFromFile(); ~GeOr~ ToDo */
    int32_t gameControllerAddMapping(const std::string& mappingString) const noexcept;
    int32_t gameControllerNumMappings(void) const noexcept;
    const std::string gameControllerMappingForIndex(const int32_t mappingIndex) const noexcept;
    const std::string gameControllerMappingForGUID(const joystick::GfxJoystickGUID& joyId) const noexcept;
    const std::string gameControllerMapping(void) const noexcept;
    const GfxBool isGameController(const int32_t joystickIndex) const noexcept;
    const std::string gameControllerNameForIndex(const int32_t joystickIndex) const noexcept;
    SdlTypePtr gameControllerFromInstanceID(const joystick::GfxJoystickID& joyId) const noexcept;
    const std::string gameControllerName(void) const noexcept;
    uint16_t gameControllerVendor(void) const noexcept;
    uint16_t gameControllerGetProduct(void) const noexcept;
    uint16_t gameControllerGetProductVersion(void) const noexcept;
    const GfxBool gameControllerGetAttached(void) const noexcept;
    joystick::GfxJoystick::SdlTypePtr gameControllerGetJoystick(void) const noexcept;
    events::GfxEventActionCommand gameControllerEventState(const events::
                GfxEventActionCommand state) const noexcept;
    void gameControllerUpdate(void) const noexcept;
    const GfxGameControllerAxis gameControllerGetAxisFromString(const std::string& pchString) const noexcept;
    const std::string gameControllerGetStringForAxis(const GfxGameControllerAxis& axis) const noexcept;
    const GfxGameControllerButtonBind gameControllerGetBindForAxis(const GfxGameControllerAxis& axis) const noexcept;
    int32_t gameControllerGetAxis(const GfxGameControllerAxis& axis) const noexcept;
    const GfxGameControllerButton gameControllerGetButtonFromString(const std::string& pchString) const noexcept;
    const std::string gameControllerGetStringForButton(const GfxGameControllerButton& button) const noexcept;
    const GfxGameControllerButtonBind gameControllerGetBindForButton(const GfxGameControllerButton& button)
            const noexcept;
    uint8_t gameControllerGetButton(const GfxGameControllerButton& button) const noexcept;

    void clear(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr gCtrl_;
};

}  // namespace gamecontroller

}  // namespace gfx

#endif /* GfxGameController_hpp */
