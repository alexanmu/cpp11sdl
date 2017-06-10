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
#include <string>

#include "GfxTextureModulate.hpp"

namespace gfx
{

namespace render
{

const char GfxTextureModulate::ClassName[] = "GfxTextureModulate";

GfxTextureModulate::GfxTextureModulate() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxTextureModulate::GfxTextureModulate(const ValueType flags) noexcept : GfxObject(ClassName)
{
    modulate_ = static_cast<SdlType>(flags);
}

GfxTextureModulate::GfxTextureModulate(const SdlType flags) noexcept : GfxObject(ClassName)
{
    assert(flags >= 0);

    modulate_ = flags;
}

GfxTextureModulate::GfxTextureModulate(const SdlTypePtr flags) noexcept : GfxObject(ClassName)
{
    assert(flags != nullptr);

    modulate_ = *flags;
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulate const& other) noexcept : GfxObject(ClassName)
{
    modulate_ = other.modulate_;
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulate&& other) noexcept : GfxObject(ClassName)
{
    modulate_ = other.modulate_;
    // Delete other's data
    other.clear();
}

GfxTextureModulate& GfxTextureModulate::operator=(GfxTextureModulate const& other) noexcept
{
    if (this != &other)
    {
        modulate_ = other.modulate_;
    }
    return *this;
}

GfxTextureModulate& GfxTextureModulate::operator=(GfxTextureModulate&& other) noexcept
{
    if (this != &other)
    {
        modulate_ = other.modulate_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextureModulate::operator bool() const noexcept
{
    return true;
}

bool GfxTextureModulate::isNone(void) const noexcept
{
    return (modulate_ == static_cast<SdlType>(ValueType::modulateNone));
}

bool GfxTextureModulate::isColor(void) const noexcept
{
    int32_t r = modulate_ & sdl2::SDL_TEXTUREMODULATE_COLOR;

    return (r != 0);
}

bool GfxTextureModulate::isAlpha(void) const noexcept
{
    int32_t r = modulate_ & sdl2::SDL_TEXTUREMODULATE_ALPHA;

    return (r != 0);
}

void GfxTextureModulate::setColor(void) noexcept
{
    modulate_ = static_cast<SdlType>(modulate_ | sdl2::SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::resetColor(void) noexcept
{
    modulate_ = static_cast<SdlType>(modulate_ & ~sdl2::SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::setAlpha(void) noexcept
{
    modulate_ = static_cast<SdlType>(modulate_ | sdl2::SDL_TEXTUREMODULATE_ALPHA);
}

void GfxTextureModulate::resetAlpha(void) noexcept
{
    modulate_ = static_cast<SdlType>(modulate_ & ~sdl2::SDL_TEXTUREMODULATE_ALPHA);
}

void GfxTextureModulate::clear(void) noexcept
{
    modulate_ = static_cast<SdlType>(ValueType::modulateNone);
}

GfxTextureModulate::SdlType GfxTextureModulate::getAsSdlType(void) const noexcept
{
    return modulate_;
}

GfxTextureModulate::SdlTypePtr GfxTextureModulate::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&modulate_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
