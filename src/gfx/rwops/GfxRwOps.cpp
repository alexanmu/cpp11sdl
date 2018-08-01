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

const GfxRwOps GfxRwOps::rwFromFP(void * fp, const GfxBool& autoclose)
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

void * GfxRwOps::loadFileRw(std::size_t * datasize, const int32_t freesrc) const
{
    LOG_TRACE_PRIO_LOW();

    assert(datasize != nullptr);
    assert((freesrc == 0) || (freesrc == 1));

    void * ret = nullptr;

    if (rwOps_ != nullptr)
    {
        ret = SDL_LoadFile_RW(rwOps_, datasize, freesrc);
        assert(ret != nullptr);
    }
    return ret;
}

uint8_t GfxRwOps::readU8(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint8_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadU8(rwOps_);
    }
    return ret;
}

uint16_t GfxRwOps::readLE16(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint16_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadLE16(rwOps_);
    }
    return ret;
}

uint16_t GfxRwOps::readBE16(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint16_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadBE16(rwOps_);
    }
    return ret;
}

uint32_t GfxRwOps::readLE32(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadLE32(rwOps_);
    }
    return ret;
}

uint32_t GfxRwOps::readBE32(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadBE32(rwOps_);
    }
    return ret;
}

uint64_t GfxRwOps::readLE64(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint64_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadLE64(rwOps_);
    }
    return ret;
}

uint64_t GfxRwOps::readBE64(void) const
{
    LOG_TRACE_PRIO_LOW();

    uint64_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_ReadBE64(rwOps_);
    }
    return ret;
}

std::size_t GfxRwOps::writeU8(const uint8_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteU8(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeLE16(const uint16_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteLE16(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeBE16(const uint16_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteBE16(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeLE32(const uint32_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteLE32(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeBE32(const uint32_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteBE32(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeLE64(const uint64_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteLE64(rwOps_, value);
    }
    return ret;
}

std::size_t GfxRwOps::writeBE64(const uint64_t value) const
{
    LOG_TRACE_PRIO_LOW();

    std::size_t ret = 0;

    if (rwOps_ != nullptr)
    {
        ret = SDL_WriteBE64(rwOps_, value);
    }
    return ret;
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
