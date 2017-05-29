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

#ifndef GfxCpuInfo_hpp
#define GfxCpuInfo_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"

namespace gfx
{

class GfxCpuInfo final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxCpuInfo();

    GfxCpuInfo(GfxCpuInfo const&) = delete;
    GfxCpuInfo(GfxCpuInfo&&) = delete;

    GfxCpuInfo& operator=(GfxCpuInfo const&) = delete;
    GfxCpuInfo& operator=(GfxCpuInfo&&) = delete;

    virtual explicit operator bool() const;

    void queryCpuInfo(void);

    int32_t getCpuCount(void) const;
    int32_t getCpuCacheLineSize(void) const;
    bool hasRdtsc(void) const;
    bool hasAltiVec(void) const;
    bool hasMmx(void) const;
    bool hasSse(void) const;
    bool hasSse2(void) const;
    bool hasSse3(void) const;
    bool hasSse41(void) const;
    bool hasSse42(void) const;
    bool hasAvx(void) const;
    bool hasAvx2(void) const;
    int32_t getSystemRam(void) const;

    const std::string getAsString(void) const;
private:
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
    int32_t systemRam_;
};

}  // namespace gfx

#endif /* GfxCpuInfo_hpp */
