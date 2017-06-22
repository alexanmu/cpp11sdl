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

#include "GfxKeymod.hpp"

namespace gfx
{

namespace keycode
{

const char GfxKeymod::ClassName[] = "GfxKeymod";

GfxKeymod::GfxKeymod() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxKeymod::GfxKeymod(const uint16_t mod) noexcept : GfxObject(ClassName)
{
    mod_ = static_cast<SdlType>(mod);
}

GfxKeymod::GfxKeymod(const ValueType mod) noexcept : GfxObject(ClassName)
{
    mod_ = static_cast<SdlType>(mod);
}

GfxKeymod::GfxKeymod(const SdlType mod) noexcept : GfxObject(ClassName)
{
    mod_ = mod;
}

GfxKeymod::GfxKeymod(GfxKeymod const& other) noexcept : GfxObject(ClassName)
{
    mod_ = other.mod_;
}

GfxKeymod::GfxKeymod(GfxKeymod&& other) noexcept : GfxObject(ClassName)
{
    mod_ = other.mod_;
    // Delete other's data
    other.clear();
}

GfxKeymod& GfxKeymod::operator=(GfxKeymod const& other) noexcept
{
    if (this != &other)
    {
        mod_ = other.mod_;
    }
    return *this;
}

GfxKeymod& GfxKeymod::operator=(GfxKeymod&& other) noexcept
{
    if (this != &other)
    {
        mod_ = other.mod_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxKeymod::operator bool() const noexcept
{
    return true;
}

bool GfxKeymod::isNone(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodNone);
}

bool GfxKeymod::isLeftShift(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodLShift);
}

bool GfxKeymod::isRightShift(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodRShift);
}

bool GfxKeymod::isLeftControl(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodLCtrl);
}

bool GfxKeymod::isRightControl(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodRCtrl);
}

bool GfxKeymod::isLeftAlt(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodLAlt);
}

bool GfxKeymod::isRightAlt(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodRAlt);
}

bool GfxKeymod::isLeftGui(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodLGui);
}

bool GfxKeymod::isRightGui(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodRGui);
}

bool GfxKeymod::isNumLock(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodRGui);
}

bool GfxKeymod::isCapsLock(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodCaps);
}

bool GfxKeymod::isMode(void) const noexcept
{
    return (static_cast<ValueType>(mod_) == ValueType::kmodMode);
}

bool GfxKeymod::isControl(void) const noexcept
{
    return (static_cast<uint16_t>(mod_) == kmodCtrl);
}

bool GfxKeymod::isShift(void) const noexcept
{
    return (static_cast<uint16_t>(mod_) == kmodShift);
}

bool GfxKeymod::isAlt(void) const noexcept
{
    return (static_cast<uint16_t>(mod_) == kmodAlt);
}

bool GfxKeymod::isGui(void) const noexcept
{
    return (static_cast<uint16_t>(mod_) == kmodGui);
}

void GfxKeymod::clear(void) noexcept
{
    mod_ = static_cast<SdlType>(ValueType::kmodNone);
}

GfxKeymod::SdlType GfxKeymod::getAsSdlType(void) const noexcept
{
    return mod_;
}

}  // namespace keycode

}  // namespace gfx

/* EOF */
