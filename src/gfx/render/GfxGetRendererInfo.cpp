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

#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxGetRendererInfo.hpp"
#include "GfxRendererInfo.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxgetrendererinfo::render::gfx");

namespace gfx
{

namespace render
{

const char GfxGetRendererInfo::ClassName[] = "GfxGetRendererInfo";

GfxGetRendererInfo::GfxGetRendererInfo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    numRenderDrivers_ = -1;
}

GfxGetRendererInfo::GfxGetRendererInfo(const GfxGetRendererInfo& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    numRenderDrivers_ = other.numRenderDrivers_;
}

GfxGetRendererInfo::GfxGetRendererInfo(GfxGetRendererInfo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    numRenderDrivers_ = other.numRenderDrivers_;
    // Delete other's data
    other.numRenderDrivers_ = -1;
}

GfxGetRendererInfo& GfxGetRendererInfo::operator=(const GfxGetRendererInfo& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        numRenderDrivers_ = other.numRenderDrivers_;
    }
    return *this;
}

GfxGetRendererInfo& GfxGetRendererInfo::operator=(GfxGetRendererInfo&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        numRenderDrivers_ = other.numRenderDrivers_;
        // Delete other's data
        other.numRenderDrivers_ = -1;
    }
    return *this;
}

GfxGetRendererInfo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxGetRendererInfo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxGetRendererInfo::getNumRenderDrivers(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t nrd;

    nrd = SDL_GetNumRenderDrivers();
    if (nrd >= 0)
    {
        numRenderDrivers_ = nrd + 1;
    }
    return nrd;
}

const GfxRendererInfo GfxGetRendererInfo::getRenderDriverInfo(const int32_t index) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(index >= 0);

    GfxRendererInfo::SdlType rdi;

    if (index < numRenderDrivers_)
    {
        SDL_GetRenderDriverInfo(index, &rdi);
        return GfxRendererInfo(rdi);
    }
    return GfxRendererInfo();
}

}  // namespace render

}  // namespace gfx

/* EOF */
