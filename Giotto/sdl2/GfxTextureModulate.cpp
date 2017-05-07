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

#include <string>

#include "GfxTextureModulate.hpp"

namespace gfx
{

const std::string GfxTextureModulate::ClassName = "GfxTextureModulate";

GfxTextureModulate::GfxTextureModulate() : GfxRootClass(ClassName)
{
    modulate_ = static_cast<SdlType>(GfxTextureModulateValues::modulateNone);
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulateValues flags) : GfxRootClass(ClassName)
{
    modulate_ = static_cast<SdlType>(flags);
}

GfxTextureModulate::GfxTextureModulate(SdlType flags) : GfxRootClass(ClassName)
{
    modulate_ = flags;
}

GfxTextureModulate::GfxTextureModulate(SdlTypePtr flags) : GfxRootClass(ClassName)
{
    modulate_ = *flags;
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulate const& other) : GfxRootClass(ClassName)
{
    modulate_ = other.modulate_;
}

GfxTextureModulate::GfxTextureModulate(GfxTextureModulate&& other) : GfxRootClass(ClassName)
{
    modulate_ = other.modulate_;
    // Delete other's data
    other.modulate_ = static_cast<SdlType>(GfxTextureModulateValues::modulateNone);
}

GfxTextureModulate& GfxTextureModulate::operator=(GfxTextureModulate const& other)
{
    if (this != &other)
    {
        modulate_ = other.modulate_;
    }
    return *this;
}

GfxTextureModulate& GfxTextureModulate::operator=(GfxTextureModulate&& other)
{
    if (this != &other)
    {
        modulate_ = other.modulate_;
        // Delete other's data
        other.modulate_ = static_cast<SdlType>(GfxTextureModulateValues::modulateNone);
    }
    return *this;
}

bool GfxTextureModulate::isNone(void) const
{
    return (modulate_ == static_cast<SdlType>(GfxTextureModulateValues::modulateNone));
}

bool GfxTextureModulate::isColor(void) const
{
    uint32_t r = modulate_ & sdl2::SDL_TEXTUREMODULATE_COLOR;

    return (r != 0);
}

bool GfxTextureModulate::isAlpha(void) const
{
    uint32_t r = modulate_ & sdl2::SDL_TEXTUREMODULATE_ALPHA;

    return (r != 0);
}

void GfxTextureModulate::setColor(void)
{
    modulate_ = static_cast<SdlType>(modulate_ | sdl2::SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::resetColor(void)
{
    modulate_ = static_cast<SdlType>(modulate_ & ~sdl2::SDL_TEXTUREMODULATE_COLOR);
}

void GfxTextureModulate::setAlpha(void)
{
    modulate_ = static_cast<SdlType>(modulate_ | sdl2::SDL_TEXTUREMODULATE_ALPHA);
}

void GfxTextureModulate::resetAlpha(void)
{
    modulate_ = static_cast<SdlType>(modulate_ & ~sdl2::SDL_TEXTUREMODULATE_ALPHA);
}

GfxTextureModulate::SdlType GfxTextureModulate::getAsSdlType(void) const
{
    return modulate_;
}

GfxTextureModulate::SdlTypePtr GfxTextureModulate::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&modulate_;
}

}  // namespace

/* EOF */
