/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#include <string>
#include <utility>

#include "GfxKeyboardEvent.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxkeyboardevent::events::gfx");

namespace gfx
{

namespace events
{

const char GfxKeyboardEvent::ClassName[] = "GfxKeyboardEvent";

GfxKeyboardEvent::GfxKeyboardEvent() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxKeyboardEvent::GfxKeyboardEvent(const SdlType event) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    keyboardEvent_ = event;
}

GfxKeyboardEvent::GfxKeyboardEvent(const GfxKeyboardEvent& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    keyboardEvent_ = other.keyboardEvent_;
}

GfxKeyboardEvent::GfxKeyboardEvent(GfxKeyboardEvent&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    keyboardEvent_ = other.keyboardEvent_;
    // Delete other's data
    other.clear();
}

GfxKeyboardEvent& GfxKeyboardEvent::operator=(const GfxKeyboardEvent& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        keyboardEvent_ = other.keyboardEvent_;
    }
    return *this;
}

GfxKeyboardEvent& GfxKeyboardEvent::operator=(GfxKeyboardEvent&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        keyboardEvent_ = other.keyboardEvent_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxKeyboardEvent::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxKeyboardEvent::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxCommonEvent GfxKeyboardEvent::getCommonEvent(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxCommonEvent cEv(keyboardEvent_.type, keyboardEvent_.timestamp);

    return cEv;
}

uint32_t GfxKeyboardEvent::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return keyboardEvent_.windowID;
}

uint8_t GfxKeyboardEvent::getState(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return keyboardEvent_.state;
}

bool GfxKeyboardEvent::getRepeat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (keyboardEvent_.repeat != 0);
}

const keyboard::GfxKeysym GfxKeyboardEvent::getKeysym(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return keyboard::GfxKeysym(keyboardEvent_.keysym);
}

void GfxKeyboardEvent::setValue(const SdlType event) noexcept
{
    LOG_TRACE_PRIO_LOW();

    keyboardEvent_ = event;
}

void GfxKeyboardEvent::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    keyboardEvent_.type = 0;
    keyboardEvent_.timestamp = 0;
    keyboardEvent_.windowID = 0;
    keyboardEvent_.state = 0;
    keyboardEvent_.repeat = 0;
    keyboardEvent_.padding2 = 0;
    keyboardEvent_.padding3 = 0;
    keyboardEvent_.keysym.scancode = SDL_SCANCODE_UNKNOWN;
    keyboardEvent_.keysym.sym = 0;
    keyboardEvent_.keysym.mod = 0;
    keyboardEvent_.keysym.unused = 0;
}

GfxKeyboardEvent::SdlType GfxKeyboardEvent::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return keyboardEvent_;
}

}  // namespace events

}  // namespace gfx

/* EOF */
