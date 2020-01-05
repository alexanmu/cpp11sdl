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

#ifndef GfxCpuInfo_hpp
#define GfxCpuInfo_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace cpuinfo
{

class GfxCpuInfo final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxCpuInfo() noexcept;

    GfxCpuInfo(const GfxCpuInfo& other) noexcept;
    GfxCpuInfo(GfxCpuInfo&& other) noexcept;

    GfxCpuInfo& operator=(const GfxCpuInfo& other) noexcept;
    GfxCpuInfo& operator=(GfxCpuInfo&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void queryCpuInfo(void) noexcept;

    int32_t getCpuCount(void) const noexcept;
    int32_t getCpuCacheLineSize(void) const noexcept;
    bool hasRdtsc(void) const noexcept;
    bool hasAltiVec(void) const noexcept;
    bool hasMmx(void) const noexcept;
    bool hasSse(void) const noexcept;
    bool hasSse2(void) const noexcept;
    bool hasSse3(void) const noexcept;
    bool hasSse41(void) const noexcept;
    bool hasSse42(void) const noexcept;
    bool hasAvx(void) const noexcept;
    bool hasAvx2(void) const noexcept;
    bool hasNeon(void) const noexcept;
    int32_t getSystemRam(void) const noexcept;

    const std::string getAsString(void) const noexcept;

    void clear(void) noexcept;
private:
    void assign(const GfxCpuInfo& other) noexcept;

    int32_t cpuCount_;
    int32_t cpuCacheLineSize_;
    bool hasRdtsc_;
    bool hasAltiVec_;
    bool hasMmx_;
    bool hasSse_;
    bool hasSse2_;
    bool hasSse3_;
    bool hasSse41_;
    bool hasSse42_;
    bool hasAvx_;
    bool hasAvx2_;
    bool hasNeon_;
    int32_t systemRam_;
};

}  // namespace cpuinfo

}  // namespace gfx

#endif /* GfxCpuInfo_hpp */
