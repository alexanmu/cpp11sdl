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

#include "GfxHintPriority.hpp"

namespace gfx
{

namespace hints
{

const char GfxHintPriority::ClassName[] = "GfxHintPriority";

GfxHintPriority::GfxHintPriority() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxHintPriority::GfxHintPriority(const SdlType hint) noexcept : GfxObject(ClassName)
{
    hint_ = hint;
}

GfxHintPriority::GfxHintPriority(const ValueType hint) noexcept : GfxObject(ClassName)
{
    hint_ = static_cast<SdlType>(hint);
}

GfxHintPriority::GfxHintPriority(GfxHintPriority const& other) noexcept : GfxObject(ClassName)
{
    hint_ = other.hint_;
}

GfxHintPriority::GfxHintPriority(GfxHintPriority&& other) noexcept : GfxObject(ClassName)
{
    hint_ = other.hint_;
    // Delete other's data
    other.clear();
}

GfxHintPriority& GfxHintPriority::operator=(GfxHintPriority const& other) noexcept
{
    if (this != &other)
    {
        hint_ = other.hint_;
    }
    return *this;
}

GfxHintPriority& GfxHintPriority::operator=(GfxHintPriority&& other) noexcept
{
    if (this != &other)
    {
        hint_ = other.hint_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxHintPriority::operator bool() const noexcept
{
    return true;
}

void GfxHintPriority::clear(void) noexcept
{
    hint_ = sdl2::SDL_HINT_DEFAULT;
}

GfxHintPriority::SdlType GfxHintPriority::getAsSdlType(void) const noexcept
{
    return hint_;
}

GfxHintPriority::SdlTypePtr GfxHintPriority::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&hint_;
}

}  // namespace hints

}  // namespace gfx

/* EOF */
