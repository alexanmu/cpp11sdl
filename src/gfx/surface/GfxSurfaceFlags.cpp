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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxSurfaceFlags.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxsurfaceflags::surface::gfx");

namespace gfx
{

namespace surface
{

const char GfxSurfaceFlags::ClassName[] = "GfxSurfaceFlags";

GfxSurfaceFlags::GfxSurfaceFlags() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxSurfaceFlags::GfxSurfaceFlags(const ValueType flags) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flags_ = static_cast<SdlType>(flags);
}

GfxSurfaceFlags::GfxSurfaceFlags(const SdlType flags) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(flags > 0);

    flags_ = flags;
}

GfxSurfaceFlags::GfxSurfaceFlags(const GfxSurfaceFlags& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
}

GfxSurfaceFlags::GfxSurfaceFlags(GfxSurfaceFlags&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxSurfaceFlags& GfxSurfaceFlags::operator=(const GfxSurfaceFlags& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        flags_ = other.flags_;
    }
    return *this;
}

GfxSurfaceFlags& GfxSurfaceFlags::operator=(GfxSurfaceFlags&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxSurfaceFlags::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxSurfaceFlags::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

bool GfxSurfaceFlags::isSwSurface(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = flags_ & SDL_SWSURFACE;

    return (r != 0);
}

bool GfxSurfaceFlags::isPreAlloc(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = flags_ & SDL_PREALLOC;

    return (r != 0);
}

bool GfxSurfaceFlags::isRLEAccel(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = flags_ & SDL_RLEACCEL;

    return (r != 0);
}

bool GfxSurfaceFlags::isDontFree(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t r = flags_ & SDL_DONTFREE;

    return (r != 0);
}

void GfxSurfaceFlags::setSwSurface(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::resetSwSurface(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setPreAlloc(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::resetPreAlloc(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setRLEAccel(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::resetRLEAccel(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::setDontFree(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::resetDontFree(void) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    throw std::runtime_error("Not supported");
}

void GfxSurfaceFlags::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    flags_ = static_cast<SdlType>(ValueType::flagSwSurface);
}

GfxSurfaceFlags::SdlType GfxSurfaceFlags::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return flags_;
}

}  // namespace surface

}  // namespace gfx

/* EOF */
