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

    return sdl2::SDL_GetKeyboardFocus();
}

const uint8_t * GfxKeyboard::getKeyboardState(int32_t * numkeys) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(numkeys != nullptr);

    return sdl2::SDL_GetKeyboardState(numkeys);
}

keycode::GfxKeymod GfxKeyboard::getModState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    keycode::GfxKeymod::SdlType km;

    km = sdl2::SDL_GetModState();
    return keycode::GfxKeymod(km);
}

void GfxKeyboard::setModState(keycode::GfxKeymod const& mod) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(mod);

    sdl2::SDL_SetModState(mod.getAsSdlType());
}

keycode::GfxKeycode GfxKeyboard::getKeyFromScancode(scancode::GfxScancode const& scancode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(scancode);

    keycode::GfxKeycode::SdlType kc;

    kc = sdl2::SDL_GetKeyFromScancode(scancode.getAsSdlType());
    return keycode::GfxKeycode(kc);
}

scancode::GfxScancode GfxKeyboard::getScancodeFromKey(keycode::GfxKeycode const& keycode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(keycode);

    scancode::GfxScancode::SdlType sc;

    sc = sdl2::SDL_GetScancodeFromKey(keycode.getAsSdlType());
    return scancode::GfxScancode(sc);
}

const std::string GfxKeyboard::getScancodeName(scancode::GfxScancode const& scancode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(scancode);

    const char * chptr;

    chptr = sdl2::SDL_GetScancodeName(scancode.getAsSdlType());
    if (chptr != nullptr)
    {
        return std::string(chptr);
    }
    return "";
}

scancode::GfxScancode GfxKeyboard::getScancodeFromName(std::string const& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    scancode::GfxScancode::SdlType sc;

    sc = sdl2::SDL_GetScancodeFromName(name.c_str());
    return scancode::GfxScancode(sc);
}

const std::string GfxKeyboard::getKeyName(keycode::GfxKeycode const& keycode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(keycode);

    const char * chptr;

    chptr = sdl2::SDL_GetKeyName(keycode.getAsSdlType());
    if (chptr != nullptr)
    {
        return std::string(chptr);
    }
    return "";
}

keycode::GfxKeycode GfxKeyboard::getKeyFromName(std::string const& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    keycode::GfxKeycode::SdlType kc;

    kc = sdl2::SDL_GetKeyFromName(name.c_str());
    return keycode::GfxKeycode(kc);
}

void GfxKeyboard::startTextInput(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_StartTextInput();
}

GfxBool GfxKeyboard::isTextInputActive(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_IsTextInputActive();
    return GfxBool(sdlbool);
}

void GfxKeyboard::stopTextInput(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    sdl2::SDL_StopTextInput();
}

void GfxKeyboard::setTextInputRect(rect::GfxRect const& rect) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);

    sdl2::SDL_SetTextInputRect(rect.getAsSdlTypePtr());
}

GfxBool GfxKeyboard::hasScreenKeyboardSupport(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_HasScreenKeyboardSupport();
    return GfxBool(sdlbool);
}

GfxBool GfxKeyboard::isScreenKeyboardShown(video::GfxWindow const& window) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(window);

    GfxBool::SdlType sdlbool;

    sdlbool = sdl2::SDL_IsScreenKeyboardShown(window.getAsSdlTypePtr());
    return GfxBool(sdlbool);
}

}  // namespace keyboard

}  // namespace gfx

/* EOF */
