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
#include <utility>

#include "GfxRwOps.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxrwops::rwops::gfx");

namespace gfx
{

namespace rwops
{

const char GfxRwOps::ClassName[] = "GfxRwOps";

GfxRwOps::GfxRwOps() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxRwOps::GfxRwOps(const SdlTypePtr rwops) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    if (rwops == nullptr)
    {
        throw std::runtime_error("rwops is nullptr");
    }
    rwOps_ = rwops;
}

GfxRwOps::GfxRwOps(GfxRwOps&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    rwOps_ = other.rwOps_;
    // Delete other's data
    other.clear();
}

GfxRwOps& GfxRwOps::operator=(GfxRwOps&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Free owned resources
        if (rwOps_ != nullptr)
        {
            SDL_FreeRW(rwOps_);
        }
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        rwOps_ = other.rwOps_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxRwOps::~GfxRwOps() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (rwOps_ != nullptr)
    {
        SDL_FreeRW(rwOps_);
        rwOps_ = nullptr;
    }
}

GfxRwOps::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxRwOps::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxRwOps GfxRwOps::rwFromFile(const std::string& file, const std::string& mode)
{
    assert(file.length() > 0);
    assert(mode.length() > 0);

    GfxRwOps::SdlTypePtr rwops = nullptr;

    rwops = SDL_RWFromFile(file.c_str(), mode.c_str());
    if (rwops != nullptr)
    {
        return GfxRwOps(rwops);
    }
    return GfxRwOps();
}

const GfxRwOps GfxRwOps::rwFromFP(void * fp, GfxBool const& autoclose)
{
    assert(fp != nullptr);
    assert(autoclose);

    GfxRwOps::SdlTypePtr rwops = nullptr;

#warning Find a smart way to avoid conditional compilation here.

#ifdef HAVE_STDIO_H
    rwops = SDL_RWFromFP(static_cast<FILE *>(fp), autoclose.getAsSdlType());
#else
    rwops = SDL_RWFromFP(static_cast<void *>(fp), autoclose.getAsSdlType());
#endif
    if (rwops != nullptr)
    {
        return GfxRwOps(rwops);
    }
    return GfxRwOps();
}

const GfxRwOps GfxRwOps::rwFromMem(void * mem, const int32_t size)
{
    assert(mem != nullptr);
    assert(size > 0);

    GfxRwOps::SdlTypePtr rwops = nullptr;

    rwops = SDL_RWFromMem(mem, size);
    if (rwops != nullptr)
    {
        return GfxRwOps(rwops);
    }
    return GfxRwOps();
}

const GfxRwOps GfxRwOps::rwFromConstMem(const void * mem, const int32_t size)
{
    assert(mem != nullptr);
    assert(size > 0);

    GfxRwOps::SdlTypePtr rwops = nullptr;

    rwops = SDL_RWFromConstMem(mem, size);
    if (rwops != nullptr)
    {
        return GfxRwOps(rwops);
    }
    return GfxRwOps();
}

void GfxRwOps::allocRw(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    if (rwOps_ != nullptr)
    {
        throw std::runtime_error("RWops already in use");
    }
    rwOps_ = SDL_AllocRW();
}

void GfxRwOps::freeRw(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    if (rwOps_ == nullptr)
    {
        throw std::runtime_error("RWops not in use");
    }
    SDL_FreeRW(rwOps_);
    rwOps_ = nullptr;
}

void GfxRwOps::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    rwOps_ = nullptr;
}

GfxRwOps::SdlTypePtr GfxRwOps::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rwOps_;
}

}  // namespace rwops

}  // namespace gfx

/* EOF */
