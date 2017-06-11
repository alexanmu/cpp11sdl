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

#include "GfxRendererFlags.hpp"

namespace gfx
{

namespace render
{

const char GfxRendererFlags::ClassName[] = "GfxRendererFlags";

GfxRendererFlags::GfxRendererFlags() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxRendererFlags::GfxRendererFlags(const ValueType flags) noexcept : GfxObject(ClassName)
{
    flags_ = static_cast<SdlType>(flags);
}

GfxRendererFlags::GfxRendererFlags(const SdlType flags) noexcept : GfxObject(ClassName)
{
    assert(flags > 0);

    flags_ = flags;
}

GfxRendererFlags::GfxRendererFlags(GfxRendererFlags const& other) noexcept : GfxObject(ClassName)
{
    flags_ = other.flags_;
}

GfxRendererFlags::GfxRendererFlags(GfxRendererFlags&& other) noexcept : GfxObject(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxRendererFlags& GfxRendererFlags::operator=(GfxRendererFlags const& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxRendererFlags& GfxRendererFlags::operator=(GfxRendererFlags&& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxRendererFlags::operator bool() const noexcept
{
    return true;
}

bool GfxRendererFlags::isUnknown(void) const noexcept
{
    return (flags_ == static_cast<SdlType>(ValueType::flagUnknown));
}

bool GfxRendererFlags::isSoftware(void) const noexcept
{
    int32_t r = flags_ & sdl2::SDL_RENDERER_SOFTWARE;

    return (r != 0);
}

bool GfxRendererFlags::isAccelerated(void) const noexcept
{
    int32_t r = flags_ & sdl2::SDL_RENDERER_ACCELERATED;

    return (r != 0);
}

bool GfxRendererFlags::getPresentVSync(void) const noexcept
{
    int32_t r = flags_ & sdl2::SDL_RENDERER_PRESENTVSYNC;

    return (r != 0);
}

bool GfxRendererFlags::getTargetTexture(void) const noexcept
{
    int32_t r = flags_ & sdl2::SDL_RENDERER_TARGETTEXTURE;

    return (r != 0);
}

void GfxRendererFlags::setSoftware(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_SOFTWARE);
}

void GfxRendererFlags::resetSoftware(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_SOFTWARE);
}

void GfxRendererFlags::setAccelerated(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_ACCELERATED);
}

void GfxRendererFlags::resetAccelerated(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_ACCELERATED);
}

void GfxRendererFlags::setPresentVSync(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_PRESENTVSYNC);
}

void GfxRendererFlags::resetPresentVSync(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_PRESENTVSYNC);
}

void GfxRendererFlags::setTargetTexture(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ | sdl2::SDL_RENDERER_TARGETTEXTURE);
}

void GfxRendererFlags::resetTargetTexture(void) noexcept
{
    flags_ = static_cast<SdlType>(flags_ & ~sdl2::SDL_RENDERER_TARGETTEXTURE);
}

void GfxRendererFlags::clear(void) noexcept
{
    flags_ = static_cast<SdlType>(ValueType::flagUnknown);
}

GfxRendererFlags::SdlType GfxRendererFlags::getAsSdlType(void) const noexcept
{
    return flags_;
}

GfxRendererFlags::SdlTypePtr GfxRendererFlags::getAsSdlTypePtr(void) const noexcept
{
    return (SdlTypePtr)&flags_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
