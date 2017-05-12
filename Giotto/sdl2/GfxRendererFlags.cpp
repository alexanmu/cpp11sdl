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

#include "GfxRendererFlags.hpp"

namespace gfx
{

const char GfxRendererFlags::ClassName[] = "GfxRendererFlags";

GfxRendererFlags::GfxRendererFlags() : GfxRootClass(ClassName)
{
    clear();
}

GfxRendererFlags::GfxRendererFlags(GfxRendererFlagsValues flags) : GfxRootClass(ClassName)
{
    flags_ = static_cast<SdlType>(flags);
}

GfxRendererFlags::GfxRendererFlags(SdlType flags) : GfxRootClass(ClassName)
{
    flags_ = flags;
}

GfxRendererFlags::GfxRendererFlags(GfxRendererFlags const& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
}

GfxRendererFlags::GfxRendererFlags(GfxRendererFlags&& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxRendererFlags& GfxRendererFlags::operator=(GfxRendererFlags const& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxRendererFlags& GfxRendererFlags::operator=(GfxRendererFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxRendererFlags::isUnknown(void) const
{
    return (flags_ == static_cast<SdlType>(GfxRendererFlagsValues::flagUnknown));
}

bool GfxRendererFlags::isSoftware(void) const
{
    uint32_t r = flags_ & sdl2::SDL_RENDERER_SOFTWARE;

    return (r != 0);
}

bool GfxRendererFlags::isAccelerated(void) const
{
    uint32_t r = flags_ & sdl2::SDL_RENDERER_ACCELERATED;

    return (r != 0);
}

bool GfxRendererFlags::getPresentVSync(void) const
{
    uint32_t r = flags_ & sdl2::SDL_RENDERER_PRESENTVSYNC;

    return (r != 0);
}

bool GfxRendererFlags::getTargetTexture(void) const
{
    uint32_t r = flags_ & sdl2::SDL_RENDERER_TARGETTEXTURE;

    return (r != 0);
}

void GfxRendererFlags::setSoftware(void)
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_SOFTWARE);
}

void GfxRendererFlags::resetSoftware(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_SOFTWARE);
}

void GfxRendererFlags::setAccelerated(void)
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_ACCELERATED);
}

void GfxRendererFlags::resetAccelerated(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_ACCELERATED);
}

void GfxRendererFlags::setPresentVSync(void)
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_PRESENTVSYNC);
}

void GfxRendererFlags::resetPresentVSync(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_PRESENTVSYNC);
}

void GfxRendererFlags::setTargetTexture(void)
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_TARGETTEXTURE);
}

void GfxRendererFlags::resetTargetTexture(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_TARGETTEXTURE);
}

void GfxRendererFlags::clear(void)
{
    flags_ = static_cast<SdlType>(GfxRendererFlagsValues::flagUnknown);
}

GfxRendererFlags::SdlType GfxRendererFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxRendererFlags::SdlTypePtr GfxRendererFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

}  // namespace gfx

/* EOF */
