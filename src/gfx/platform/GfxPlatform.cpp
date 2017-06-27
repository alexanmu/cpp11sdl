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

#include "GfxPlatform.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace platform
{

const char GfxPlatform::ClassName[] = "GfxPlatform";

GfxPlatform::GfxPlatform() noexcept : GfxObject(ClassName)
{
    platform_ = "";
}

GfxPlatform::GfxPlatform(GfxPlatform const& other) noexcept : GfxObject(ClassName)
{
    platform_ = other.platform_;
}

GfxPlatform::GfxPlatform(GfxPlatform&& other) noexcept : GfxObject(ClassName)
{
    platform_ = other.platform_;
    // Delete other's data
    other.platform_.clear();
}

GfxPlatform& GfxPlatform::operator=(GfxPlatform const& other) noexcept
{
    if (this != &other)
    {
        platform_ = other.platform_;
    }
    return *this;
}

GfxPlatform& GfxPlatform::operator=(GfxPlatform&& other) noexcept
{
    if (this != &other)
    {
        platform_ = other.platform_;
        // Delete other's data
        other.platform_.clear();
    }
    return *this;
}

GfxPlatform::operator bool() const noexcept
{
    return true;
}

void GfxPlatform::queryPlatform(void) noexcept
{
    platform_ = sdl2::SDL_GetPlatform();
}

std::string const& GfxPlatform::getPlatform(void) const noexcept
{
    return platform_;
}

}  // namespace platform

}  // namespace gfx

/* EOF */
