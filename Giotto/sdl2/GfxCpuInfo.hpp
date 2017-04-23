//
//  GfxCpuInfo.hpp
//  Giotto
//
//  Created by George Oros on 4/23/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxCpuInfo_hpp
#define GfxCpuInfo_hpp

#include <string>

#include "GfxRootClass.hpp"

class GfxCpuInfo final : public GfxRootClass
{
public:
    GfxCpuInfo();
    GfxCpuInfo(GfxCpuInfo const&) = delete;
    GfxCpuInfo(GfxCpuInfo&&) = delete;
    
    GfxCpuInfo& operator=(GfxCpuInfo const&) = delete;
    GfxCpuInfo& operator=(GfxCpuInfo&&) = delete;
    
    void queryCpuInfo(void);

    int getCpuCount(void) const;
    int getCpuCacheLineSize(void) const;
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
    int getSystemRam(void) const;
    
    std::string getAsFormatedString(void) const;
private:
    int cpuCount_;
    int cpuCacheLineSize_;
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
    int systemRam_;
};

#endif /* GfxCpuInfo_hpp */
