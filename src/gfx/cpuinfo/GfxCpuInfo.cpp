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

#include "GfxCpuInfo.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcpuinfo::cpuinfo::gfx");

namespace gfx
{

namespace cpuinfo
{

const char GfxCpuInfo::ClassName[]  = "GfxCpuInfo";

GfxCpuInfo::GfxCpuInfo() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxCpuInfo::GfxCpuInfo(GfxCpuInfo const& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    assign(other);
}

GfxCpuInfo::GfxCpuInfo(GfxCpuInfo&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    assign(other);
    // Delete other's data
    other.clear();
}

GfxCpuInfo& GfxCpuInfo::operator=(GfxCpuInfo const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        assign(other);
    }
    return *this;
}

GfxCpuInfo& GfxCpuInfo::operator=(GfxCpuInfo&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        assign(other);
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxCpuInfo::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxCpuInfo::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxCpuInfo::queryCpuInfo(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cpuCount_ = sdl2::SDL_GetCPUCount();
    cpuCacheLineSize_ = sdl2::SDL_GetCPUCacheLineSize();
    hasRdtsc_ = sdl2::SDL_HasRDTSC();
    hasAltiVec_ = sdl2::SDL_HasAltiVec();
    hasMmx_ = sdl2::SDL_HasMMX();
    hasSse_ = sdl2::SDL_HasSSE();
    hasSse2_ = sdl2::SDL_HasSSE2();
    hasSse3_ = sdl2::SDL_HasSSE3();
    hasSse41_ = sdl2::SDL_HasSSE41();
    hasSse42_ = sdl2::SDL_HasSSE42();
    hasAvx_ = sdl2::SDL_HasAVX();
    hasAvx2_ = sdl2::SDL_HasAVX2();
    hasNeon_ = sdl2::SDL_HasNEON();
    systemRam_ = sdl2::SDL_GetSystemRAM();
}

int32_t GfxCpuInfo::getCpuCount(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return cpuCount_;
}

int32_t GfxCpuInfo::getCpuCacheLineSize(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return cpuCacheLineSize_;
}

bool GfxCpuInfo::hasRdtsc(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasRdtsc_;
}

bool GfxCpuInfo::hasAltiVec(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasAltiVec_;
}

bool GfxCpuInfo::hasMmx(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasMmx_;
}

bool GfxCpuInfo::hasSse(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasSse_;
}

bool GfxCpuInfo::hasSse2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasSse2_;
}

bool GfxCpuInfo::hasSse3(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasSse3_;
}

bool GfxCpuInfo::hasSse41(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasSse41_;
}

bool GfxCpuInfo::hasSse42(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasSse42_;
}

bool GfxCpuInfo::hasAvx(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasAvx_;
}

bool GfxCpuInfo::hasAvx2(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasAvx2_;
}

bool GfxCpuInfo::hasNeon(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return hasNeon_;
}

int32_t GfxCpuInfo::getSystemRam(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return systemRam_;
}

const std::string GfxCpuInfo::getAsString(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    std::string str1;

    str1 = "#CPU=" + std::to_string(cpuCount_) + "\n";
    str1 += "CacheLine=" + std::to_string(cpuCacheLineSize_) + "\n";
    str1 += "RDTSC:" + std::to_string(hasRdtsc_) + "\n";
    str1 += "Altivec:" + std::to_string(hasAltiVec_) + "\n";
    str1 += "MMX:" + std::to_string(hasMmx_) + "\n";
    str1 += "SSE:" + std::to_string(hasSse_) + "\n";
    str1 += "SSE2:" + std::to_string(hasSse2_) + "\n";
    str1 += "SSE3:" + std::to_string(hasSse3_) + "\n";
    str1 += "SSE4.1:" + std::to_string(hasSse41_) + "\n";
    str1 += "SSE4.2:" + std::to_string(hasSse42_) + "\n";
    str1 += "AVX:" + std::to_string(hasAvx_) + "\n";
    str1 += "AVX2:" + std::to_string(hasAvx2_) + "\n";
    str1 += "NEON:" + std::to_string(hasNeon_) + "\n";
    str1 += "RAM=" + std::to_string(systemRam_) + "MB";
    return str1;
}

void GfxCpuInfo::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    cpuCount_ = 0;
    cpuCacheLineSize_ = 0;
    hasRdtsc_ = false;
    hasAltiVec_ = false;
    hasMmx_ = false;
    hasSse_ = false;
    hasSse2_ = false;
    hasSse3_ = false;
    hasSse41_ = false;
    hasSse42_ = false;
    hasAvx_ = false;
    hasAvx2_ = false;
    hasNeon_ = false;
    systemRam_ = 0;
}

// Private methods
void GfxCpuInfo::assign(GfxCpuInfo const& other) noexcept
{
    cpuCount_ = other.cpuCount_;
    cpuCacheLineSize_ = other.cpuCacheLineSize_;
    hasRdtsc_ = other.hasRdtsc_;
    hasAltiVec_ = other.hasAltiVec_;
    hasMmx_ = other.hasMmx_;
    hasSse_ = other.hasSse_;
    hasSse2_ = other.hasSse2_;
    hasSse3_ = other.hasSse3_;
    hasSse41_ = other.hasSse41_;
    hasSse42_ = other.hasSse42_;
    hasAvx_ = other.hasAvx_;
    hasAvx2_ = other.hasAvx2_;
    hasNeon_ = other.hasNeon_;
    systemRam_ = other.systemRam_;
}

}  // namespace cpuinfo

}  // namespace gfx

/* EOF */
