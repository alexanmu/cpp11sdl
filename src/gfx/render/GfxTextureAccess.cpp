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

#include <string>
#include <utility>

#include "GfxTextureAccess.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtextureaccess::render::gfx");

namespace gfx
{

namespace render
{

const char GfxTextureAccess::ClassName[] = "GfxTextureAccess";

GfxTextureAccess::GfxTextureAccess() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxTextureAccess::GfxTextureAccess(const ValueType access) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    access_ = static_cast<SdlType>(access);
}

GfxTextureAccess::GfxTextureAccess(const SdlType access) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    access_ = access;
}

GfxTextureAccess::GfxTextureAccess(const int32_t access) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    access_ = static_cast<SdlType>(access);
}

GfxTextureAccess::GfxTextureAccess(const GfxTextureAccess& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    access_ = other.access_;
}

GfxTextureAccess::GfxTextureAccess(GfxTextureAccess&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    access_ = other.access_;
    // Delete other's data
    other.clear();
}

GfxTextureAccess& GfxTextureAccess::operator=(const GfxTextureAccess& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        access_ = other.access_;
    }
    return *this;
}

GfxTextureAccess& GfxTextureAccess::operator=(GfxTextureAccess&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        access_ = other.access_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxTextureAccess::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTextureAccess::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxTextureAccess::ValueType GfxTextureAccess::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(access_);
}

bool GfxTextureAccess::isStatic(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (access_ == SDL_TEXTUREACCESS_STATIC);
}

bool GfxTextureAccess::isStreaming(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (access_ == SDL_TEXTUREACCESS_STREAMING);
}

bool GfxTextureAccess::isTarget(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (access_ == SDL_TEXTUREACCESS_TARGET);
}

void GfxTextureAccess::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    access_ = static_cast<SdlType>(ValueType::accessStatic);
}

GfxTextureAccess::SdlType GfxTextureAccess::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return access_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
