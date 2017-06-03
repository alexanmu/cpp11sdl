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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>

#include "GfxSurfaceFlags.hpp"

namespace gfx
{

namespace surface
{

const char GfxSurfaceFlags::ClassName[] = "GfxSurfaceFlags";

GfxSurfaceFlags::GfxSurfaceFlags() : GfxRootClass(ClassName)
{
    clear();
}

GfxSurfaceFlags::GfxSurfaceFlags(const ValueType flags) : GfxRootClass(ClassName)
{
    flags_ = static_cast<SdlType>(flags);
}

GfxSurfaceFlags::GfxSurfaceFlags(const SdlType flags) : GfxRootClass(ClassName)
{
    assert(flags > 0);

    flags_ = flags;
}

GfxSurfaceFlags::GfxSurfaceFlags(GfxSurfaceFlags const& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
}

GfxSurfaceFlags::GfxSurfaceFlags(GfxSurfaceFlags&& other) : GfxRootClass(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxSurfaceFlags& GfxSurfaceFlags::operator=(GfxSurfaceFlags const& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxSurfaceFlags& GfxSurfaceFlags::operator=(GfxSurfaceFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxSurfaceFlags::operator bool() const
{
    return true;
}

bool GfxSurfaceFlags::isSwSurface(void) const
{
    uint32_t r = flags_ & SDL_SWSURFACE;

    return (r != 0);
}

bool GfxSurfaceFlags::isPreAlloc(void) const
{
    uint32_t r = flags_ & SDL_PREALLOC;

    return (r != 0);
}

bool GfxSurfaceFlags::isRLEAccel(void) const
{
    uint32_t r = flags_ & SDL_RLEACCEL;

    return (r != 0);
}

bool GfxSurfaceFlags::isDontFree(void) const
{
    uint32_t r = flags_ & SDL_DONTFREE;

    return (r != 0);
}

void GfxSurfaceFlags::setSwSurface(void) throw(std::runtime_error)
{
    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setPreAlloc(void) throw(std::runtime_error)
{
    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setRLEAccel(void) throw(std::runtime_error)
{
    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setDontFree(void) throw(std::runtime_error)
{
    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::clear(void)
{
    flags_ = static_cast<SdlType>(ValueType::flagSwSurface);
}

GfxSurfaceFlags::SdlType GfxSurfaceFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxSurfaceFlags::SdlTypePtr GfxSurfaceFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

}  // namespace surface

}  // namespace gfx

/* EOF */
