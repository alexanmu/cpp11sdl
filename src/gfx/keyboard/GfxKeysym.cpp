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

#include <cstdint>

#include "GfxKeysym.hpp"

namespace gfx
{

namespace keyboard
{

const char GfxKeysym::ClassName[] = "GfxKeysym";

GfxKeysym::GfxKeysym() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxKeysym::GfxKeysym(const SdlType sym) noexcept : GfxObject(ClassName)
{
    sym_ = sym;
}

GfxKeysym::GfxKeysym(GfxKeysym const& other) noexcept : GfxObject(ClassName)
{
    sym_ = other.sym_;
}

GfxKeysym::GfxKeysym(GfxKeysym&& other) noexcept : GfxObject(ClassName)
{
    sym_ = other.sym_;
    // Delete other's data
    other.clear();
}

GfxKeysym& GfxKeysym::operator=(GfxKeysym const& other) noexcept
{
    if (this != &other)
    {
        sym_ = other.sym_;
    }
    return *this;
}

GfxKeysym& GfxKeysym::operator=(GfxKeysym&& other) noexcept
{
    if (this != &other)
    {
        sym_ = other.sym_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxKeysym::operator bool() const noexcept
{
    return true;
}

scancode::GfxScancode GfxKeysym::getScanCode(void) const noexcept
{
    return scancode::GfxScancode(sym_.scancode);
}

keycode::GfxKeycode GfxKeysym::getKeyCode(void) const noexcept
{
    return keycode::GfxKeycode(sym_.sym);
}

keycode::GfxKeymod GfxKeysym::getKeyMod(void) const noexcept
{
    return keycode::GfxKeymod(sym_.mod);
}

void GfxKeysym::clear(void) noexcept
{
    sym_.scancode = sdl2::SDL_SCANCODE_UNKNOWN;
    sym_.sym = sdl2::SDLK_UNKNOWN;
    sym_.mod = 0;
    sym_.unused = 0;
}

GfxKeysym::SdlType GfxKeysym::getAsSdlType(void) const noexcept
{
    return sym_;
}

}  // namespace keyboard

}  // namespace gfx

/* EOF */
