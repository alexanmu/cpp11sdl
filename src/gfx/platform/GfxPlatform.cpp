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
#include <utility>

#include "GfxPlatform.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxplatform::platform::gfx");

namespace gfx
{

namespace platform
{

const char GfxPlatform::ClassName[] = "GfxPlatform";

GfxPlatform::GfxPlatform() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    platform_ = "";
}

GfxPlatform::GfxPlatform(GfxPlatform const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    platform_ = other.platform_;
}

GfxPlatform::GfxPlatform(GfxPlatform&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    platform_ = other.platform_;
    // Delete other's data
    other.platform_.clear();
}

GfxPlatform& GfxPlatform::operator=(GfxPlatform const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        platform_ = other.platform_;
    }
    return *this;
}

GfxPlatform& GfxPlatform::operator=(GfxPlatform&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        platform_ = other.platform_;
        // Delete other's data
        other.platform_.clear();
    }
    return *this;
}

GfxPlatform::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPlatform::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxPlatform::queryPlatform(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    platform_ = SDL_GetPlatform();
}

std::string const& GfxPlatform::getPlatform(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return platform_;
}

}  // namespace platform

}  // namespace gfx

/* EOF */
