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

#include "GfxKeyboardEvent.hpp"

namespace gfx
{

namespace events
{

const char GfxKeyboardEvent::ClassName[] = "GfxKeyboardEvent";

GfxKeyboardEvent::GfxKeyboardEvent() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxKeyboardEvent::GfxKeyboardEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    keyboardEvent_ = event;
}

GfxKeyboardEvent::GfxKeyboardEvent(GfxKeyboardEvent const& other) noexcept : GfxObject(ClassName)
{
    keyboardEvent_ = other.keyboardEvent_;
}

GfxKeyboardEvent::GfxKeyboardEvent(GfxKeyboardEvent&& other) noexcept : GfxObject(ClassName)
{
    keyboardEvent_ = other.keyboardEvent_;
    // Delete other's data
    other.clear();
}

GfxKeyboardEvent& GfxKeyboardEvent::operator=(GfxKeyboardEvent const& other) noexcept
{
    if (this != &other)
    {
        keyboardEvent_ = other.keyboardEvent_;
    }
    return *this;
}

GfxKeyboardEvent& GfxKeyboardEvent::operator=(GfxKeyboardEvent&& other) noexcept
{
    if (this != &other)
    {
        keyboardEvent_ = other.keyboardEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxKeyboardEvent::operator bool() const noexcept
{
    return true;
}

GfxCommonEvent GfxKeyboardEvent::getCommonEvent(void) const noexcept
{
    GfxCommonEvent cEv(keyboardEvent_.type, keyboardEvent_.timestamp);

    return cEv;
}

uint32_t GfxKeyboardEvent::getWindowID(void) const noexcept
{
    return keyboardEvent_.windowID;
}

uint8_t GfxKeyboardEvent::getState(void) const noexcept
{
    return keyboardEvent_.state;
}

bool GfxKeyboardEvent::getRepeat(void) const noexcept
{
    return (keyboardEvent_.repeat != 0);
}

keyboard::GfxKeysym GfxKeyboardEvent::getKeysym(void) const noexcept
{
    return keyboard::GfxKeysym(keyboardEvent_.keysym);
}

void GfxKeyboardEvent::clear(void) noexcept
{
    keyboardEvent_.type = 0;
    keyboardEvent_.timestamp = 0;
    keyboardEvent_.windowID = 0;
    keyboardEvent_.state = 0;
    keyboardEvent_.repeat = 0;
    keyboardEvent_.padding2 = 0;
    keyboardEvent_.padding3 = 0;
    keyboardEvent_.keysym.scancode = sdl2::SDL_SCANCODE_UNKNOWN;
    keyboardEvent_.keysym.sym = 0;
    keyboardEvent_.keysym.mod = 0;
    keyboardEvent_.keysym.unused = 0;
}

GfxKeyboardEvent::SdlType GfxKeyboardEvent::getAsSdlType(void) const noexcept
{
    return keyboardEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
