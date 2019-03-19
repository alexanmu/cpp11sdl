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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxGameController.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgamecontroller::gamecontroller::gfx");

namespace gfx
{

namespace gamecontroller
{

const char GfxGameController::ClassName[] = "GfxGameController";

GfxGameController::GfxGameController() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxGameController::GfxGameController(const int32_t index) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(index >= 0);

    gCtrl_ = nullptr;

    SdlTypePtr tmpgctrlptr;

    tmpgctrlptr = SDL_GameControllerOpen(index);
    if (tmpgctrlptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create GfxJoystick object (" + sdlErr + ")");
    }
    gCtrl_ = tmpgctrlptr;
}

GfxGameController::GfxGameController(GfxGameController&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    gCtrl_ = other.gCtrl_;
    // Delete other's data
    other.clear();
}

GfxGameController& GfxGameController::operator=(GfxGameController&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        gCtrl_ = other.gCtrl_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxGameController::~GfxGameController()
{
    LOG_TRACE_PRIO_MED();

    if (gCtrl_ != nullptr)
    {
        SDL_GameControllerClose(gCtrl_);
        gCtrl_ = nullptr;
    }
}

void GfxGameController::gameControllerOpen(const int32_t index) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(index >= 0);

    gCtrl_ = nullptr;

    SdlTypePtr tmpgctrlptr;

    if (gCtrl_ != nullptr)
    {
        throw std::runtime_error("Game controller already open");
    }
    tmpgctrlptr = SDL_GameControllerOpen(index);
    if (tmpgctrlptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create GfxGameController object (" + sdlErr + ")");
    }
    gCtrl_ = tmpgctrlptr;
}

void GfxGameController::gameControllerClose(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (gCtrl_ != nullptr)
    {
        SDL_GameControllerClose(gCtrl_);
        gCtrl_ = nullptr;
    }
}

int32_t GfxGameController::gameControllerAddMapping(const std::string& mappingString) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(mappingString.length() > 0);

    int32_t ret = -1;

    ret = SDL_GameControllerAddMapping(mappingString.c_str());
    assert((ret == -1) || (ret == 0) || (ret == 1));

    return ret;
}

int32_t GfxGameController::gameControllerNumMappings(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret;

    ret = SDL_GameControllerNumMappings();

    return ret;
}

const std::string GfxGameController::gameControllerMappingForIndex(const int32_t mappingIndex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(mappingIndex >= 0);

    std::string ret = "";
    const char * pch = NULL;

    pch = SDL_GameControllerMappingForIndex(mappingIndex);
    if (pch != NULL)
    {
        ret = pch;
        SDL_free(static_cast<void *>(const_cast<char *>(pch)));
    }
    return ret;
}

const std::string GfxGameController::gameControllerMappingForGUID(const joystick::GfxJoystickGUID& joyId) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(joyId);

    std::string ret = "";
    const char * pch = NULL;

    pch = SDL_GameControllerMappingForGUID(joyId.getAsSdlType());
    if (pch != NULL)
    {
        ret = pch;
        SDL_free(static_cast<void *>(const_cast<char *>(pch)));
    }
    return ret;
}

const std::string GfxGameController::gameControllerMapping(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string ret = "";
    const char * pch = NULL;

    if (gCtrl_ != nullptr)
    {
        pch = SDL_GameControllerMapping(gCtrl_);
        if (pch != NULL)
        {
            ret = pch;
            SDL_free(static_cast<void *>(const_cast<char *>(pch)));
        }
    }
    return ret;
}

const GfxBool GfxGameController::isGameController(const int32_t joystickIndex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(joystickIndex >= 0);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_IsGameController(joystickIndex);
    return GfxBool(sdlbool);
}

const std::string GfxGameController::gameControllerNameForIndex(const int32_t joystickIndex) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(joystickIndex >= 0);

    std::string ret = "";
    const char * pch = NULL;

    pch = SDL_GameControllerNameForIndex(joystickIndex);
    if (pch != NULL)
    {
        ret = pch;
    }
    return ret;
}

GfxGameController::SdlTypePtr GfxGameController::gameControllerFromInstanceID(const joystick::
        GfxJoystickID& joyId) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(joyId);

    GfxGameController::SdlTypePtr ret = nullptr;

    ret = SDL_GameControllerFromInstanceID(joyId.getAsSdlType());
    return ret;
}

const std::string GfxGameController::gameControllerName(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string ret = "";
    const char * pch = NULL;

    if (gCtrl_ != nullptr)
    {
        pch = SDL_GameControllerName(gCtrl_);
        ret = pch;
    }
    return ret;
}

uint16_t GfxGameController::gameControllerVendor(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint16_t vendor = 0;

    if (gCtrl_ != nullptr)
    {
        vendor = SDL_GameControllerGetVendor(gCtrl_);
    }
    return vendor;
}

uint16_t GfxGameController::gameControllerGetProduct(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint16_t product = 0;

    if (gCtrl_ != nullptr)
    {
        product = SDL_GameControllerGetProduct(gCtrl_);
    }
    return product;
}

uint16_t GfxGameController::gameControllerGetProductVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint16_t productVersion = 0;

    if (gCtrl_ != nullptr)
    {
        productVersion = SDL_GameControllerGetProductVersion(gCtrl_);
    }
    return productVersion;
}

const GfxBool GfxGameController::gameControllerGetAttached(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    if (gCtrl_ != nullptr)
    {
        sdlbool = SDL_GameControllerGetAttached(gCtrl_);
        return GfxBool(sdlbool);
    }
    return GfxBool(false);
}

joystick::GfxJoystick::SdlTypePtr GfxGameController::gameControllerGetJoystick(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    joystick::GfxJoystick::SdlTypePtr ret = nullptr;

    if (gCtrl_ != nullptr)
    {
        ret = SDL_GameControllerGetJoystick(gCtrl_);
    }
    return ret;
}

events::GfxEventActionCommand GfxGameController::gameControllerEventState(const events::GfxEventActionCommand state)
            const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = SDL_GameControllerEventState(static_cast<int>(state));
    return static_cast<events::GfxEventActionCommand>(ret);
}

void GfxGameController::gameControllerUpdate(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_GameControllerUpdate();
}

const GfxGameControllerAxis GfxGameController::gameControllerGetAxisFromString(const std::string& pchString)
            const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(pchString.length() > 0);

    GfxGameControllerAxis::SdlType sdlAxis;

    sdlAxis = SDL_GameControllerGetAxisFromString(pchString.c_str());
    return GfxGameControllerAxis(sdlAxis);
}

const std::string GfxGameController::gameControllerGetStringForAxis(const GfxGameControllerAxis& axis) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis);

    std::string ret = SDL_GameControllerGetStringForAxis(axis.getAsSdlType());
    return ret;
}

const GfxGameControllerButtonBind GfxGameController::gameControllerGetBindForAxis(const GfxGameControllerAxis& axis)
            const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis);

    GfxGameControllerButtonBind::SdlType btnBind;

    if (gCtrl_ != nullptr)
    {
        btnBind = SDL_GameControllerGetBindForAxis(gCtrl_, axis.getAsSdlType());
    }
    return GfxGameControllerButtonBind(btnBind);
}

int32_t GfxGameController::gameControllerGetAxis(const GfxGameControllerAxis& axis) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(axis);

    int32_t ret = 0;

    if (gCtrl_ != nullptr)
    {
        ret = SDL_GameControllerGetAxis(gCtrl_, axis.getAsSdlType());
    }
    return ret;
}

const GfxGameControllerButton GfxGameController::gameControllerGetButtonFromString(const std::string& pchString)
            const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(pchString.length() > 0);

    GfxGameControllerButton::SdlType btn;

    btn = SDL_GameControllerGetButtonFromString(pchString.c_str());
    return GfxGameControllerButton(btn);
}

const std::string GfxGameController::gameControllerGetStringForButton(const GfxGameControllerButton& button)
            const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(button);

    std::string ret = SDL_GameControllerGetStringForButton(button.getAsSdlType());
    return ret;
}

const GfxGameControllerButtonBind GfxGameController::gameControllerGetBindForButton(const GfxGameControllerButton&
            button) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(button);

    GfxGameControllerButtonBind::SdlType btnBind;

    if (gCtrl_ != nullptr)
    {
        btnBind = SDL_GameControllerGetBindForButton(gCtrl_, button.getAsSdlType());
    }
    return GfxGameControllerButtonBind(btnBind);
}

uint8_t GfxGameController::gameControllerGetButton(const GfxGameControllerButton& button) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(button);

    uint8_t btn = 255;

    if (gCtrl_ != nullptr)
    {
        btn = SDL_GameControllerGetButton(gCtrl_, button.getAsSdlType());
    }
    return btn;
}

void GfxGameController::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    gCtrl_ = nullptr;
}

GfxGameController::SdlTypePtr GfxGameController::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return gCtrl_;
}

}  // namespace gamecontroller

}  // namespace gfx

/* EOF */
