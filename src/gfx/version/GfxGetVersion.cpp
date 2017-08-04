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
#include <utility>

#include "GfxGetVersion.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgetversion::version::gfx");

namespace gfx
{

namespace version
{

const char GfxGetVersion::ClassName[] = "GfxGetVersion";

GfxGetVersion::GfxGetVersion() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();
}

GfxGetVersion::GfxGetVersion(GfxGetVersion const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();
}

GfxGetVersion::GfxGetVersion(GfxGetVersion&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();
}

GfxGetVersion& GfxGetVersion::operator=(GfxGetVersion const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(other);
    }
    return *this;
}

GfxGetVersion& GfxGetVersion::operator=(GfxGetVersion&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        GfxObject::operator=(std::move(other));
    }
    return *this;
}

GfxGetVersion::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGetVersion::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxVersion GfxGetVersion::getVersion(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxVersion::SdlType v;

    sdl2::SDL_GetVersion(&v);
    return GfxVersion(v);
}

std::string GfxGetVersion::getRevision(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * chptr;
    std::string str = "";

    chptr = sdl2::SDL_GetRevision();
    if (chptr != nullptr)
    {
        str = chptr;
    }
    return str;
}

int32_t GfxGetVersion::getRevisionNumber(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::SDL_GetRevisionNumber();
}

}  // namespace version

}  // namespace gfx

/* EOF */
