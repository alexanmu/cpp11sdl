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

#include <cstdint>
#include <string>
#include <utility>

#include "GfxKeysym.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxkeysym::keyboard::gfx");

namespace gfx
{

namespace keyboard
{

const char GfxKeysym::ClassName[] = "GfxKeysym";

GfxKeysym::GfxKeysym() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxKeysym::GfxKeysym(const SdlType sym) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    sym_ = sym;
}

GfxKeysym::GfxKeysym(const GfxKeysym& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    sym_ = other.sym_;
}

GfxKeysym::GfxKeysym(GfxKeysym&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    sym_ = other.sym_;
    // Delete other's data
    other.clear();
}

GfxKeysym& GfxKeysym::operator=(const GfxKeysym& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        sym_ = other.sym_;
    }
    return *this;
}

GfxKeysym& GfxKeysym::operator=(GfxKeysym&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        sym_ = other.sym_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxKeysym::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxKeysym::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const scancode::GfxScancode GfxKeysym::getScanCode(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return scancode::GfxScancode(sym_.scancode);
}

const keycode::GfxKeycode GfxKeysym::getKeyCode(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return keycode::GfxKeycode(sym_.sym);
}

const keycode::GfxKeymod GfxKeysym::getKeyMod(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return keycode::GfxKeymod(sym_.mod);
}

void GfxKeysym::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    sym_.scancode = SDL_SCANCODE_UNKNOWN;
    sym_.sym = SDLK_UNKNOWN;
    sym_.mod = 0;
    sym_.unused = 0;
}

GfxKeysym::SdlType GfxKeysym::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sym_;
}

}  // namespace keyboard

}  // namespace gfx

/* EOF */
