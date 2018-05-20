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

#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxKeyboard.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxkeyboard::keyboard::gfx");

namespace gfx
{

namespace keyboard
{

const char GfxKeyboard::ClassName[] = "GfxKeyboard";

GfxKeyboard::GfxKeyboard() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxKeyboard::GfxKeyboard(const GfxKeyboard& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxKeyboard::GfxKeyboard(GfxKeyboard&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxKeyboard& GfxKeyboard::operator=(const GfxKeyboard& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(other);
    }
    return *this;
}

GfxKeyboard& GfxKeyboard::operator=(GfxKeyboard&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxKeyboard::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxKeyboard::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

video::GfxWindow::SdlTypePtr GfxKeyboard::getKeyboardFocus(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return SDL_GetKeyboardFocus();
}

const uint8_t * GfxKeyboard::getKeyboardState(int32_t * numkeys) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(numkeys != nullptr);

    return SDL_GetKeyboardState(numkeys);
}

const keycode::GfxKeymod GfxKeyboard::getModState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    keycode::GfxKeymod::SdlType km;

    km = SDL_GetModState();
    return keycode::GfxKeymod(km);
}

void GfxKeyboard::setModState(const keycode::GfxKeymod& mod) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(mod);

    SDL_SetModState(mod.getAsSdlType());
}

const keycode::GfxKeycode GfxKeyboard::getKeyFromScancode(const scancode::GfxScancode& scancode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(scancode);

    keycode::GfxKeycode::SdlType kc;

    kc = SDL_GetKeyFromScancode(scancode.getAsSdlType());
    return keycode::GfxKeycode(kc);
}

const scancode::GfxScancode GfxKeyboard::getScancodeFromKey(const keycode::GfxKeycode& keycode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(keycode);

    scancode::GfxScancode::SdlType sc;

    sc = SDL_GetScancodeFromKey(keycode.getAsSdlType());
    return scancode::GfxScancode(sc);
}

const std::string GfxKeyboard::getScancodeName(const scancode::GfxScancode& scancode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(scancode);

    const char * chptr;

    chptr = SDL_GetScancodeName(scancode.getAsSdlType());
    if (chptr != nullptr)
    {
        return std::string(chptr);
    }
    return "";
}

const scancode::GfxScancode GfxKeyboard::getScancodeFromName(const std::string& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    scancode::GfxScancode::SdlType sc;

    sc = SDL_GetScancodeFromName(name.c_str());
    return scancode::GfxScancode(sc);
}

const std::string GfxKeyboard::getKeyName(const keycode::GfxKeycode& keycode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(keycode);

    const char * chptr;

    chptr = SDL_GetKeyName(keycode.getAsSdlType());
    if (chptr != nullptr)
    {
        return std::string(chptr);
    }
    return "";
}

const keycode::GfxKeycode GfxKeyboard::getKeyFromName(const std::string& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    keycode::GfxKeycode::SdlType kc;

    kc = SDL_GetKeyFromName(name.c_str());
    return keycode::GfxKeycode(kc);
}

void GfxKeyboard::startTextInput(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_StartTextInput();
}

const GfxBool GfxKeyboard::isTextInputActive(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_IsTextInputActive();
    return GfxBool(sdlbool);
}

void GfxKeyboard::stopTextInput(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    SDL_StopTextInput();
}

void GfxKeyboard::setTextInputRect(const rect::GfxRect& rect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);

    SDL_SetTextInputRect(rect.getAsSdlTypePtr());
}

const GfxBool GfxKeyboard::hasScreenKeyboardSupport(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_HasScreenKeyboardSupport();
    return GfxBool(sdlbool);
}

const GfxBool GfxKeyboard::isScreenKeyboardShown(const video::GfxWindow& window) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(window);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_IsScreenKeyboardShown(window.getAsSdlTypePtr());
    return GfxBool(sdlbool);
}

}  // namespace keyboard

}  // namespace gfx

/* EOF */
