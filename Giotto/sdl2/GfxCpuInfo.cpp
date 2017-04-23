//
//  GfxCpuInfo.cpp
//  Giotto
//
//  Created by George Oros on 4/23/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxCpuInfo.hpp"
#include "GfxSdlHeader.hpp"

GfxCpuInfo::GfxCpuInfo() : GfxRootClass("GfxCpuInfo")
{
    cpuCount_ = 0;
    cpuCacheLineSize_ = 0;
    hasRdtsc_ = false;
    hasAltiVec_= false;
    hasMmx_ = false;
    hasSse_ = false;
    hasSse2_ = false;
    hasSse3_ = false;
    hasSse41_ = false;
    hasSse42_ = false;
    hasAvx_ = false;
    hasAvx2_ = false;
    systemRam_ = 0;
}

void GfxCpuInfo::queryCpuInfo(void)
{
    cpuCount_ = SDL_GetCPUCount();
    cpuCacheLineSize_ = SDL_GetCPUCacheLineSize();
    hasRdtsc_ = SDL_HasRDTSC();
    hasAltiVec_ = SDL_HasAltiVec();
    hasMmx_ = SDL_HasMMX();
    hasSse_ = SDL_HasSSE();
    hasSse2_ = SDL_HasSSE2();
    hasSse3_ = SDL_HasSSE3();
    hasSse41_ = SDL_HasSSE41();
    hasSse42_ = SDL_HasSSE42();
    hasAvx_ = SDL_HasAVX();
    hasAvx2_ = SDL_HasAVX2();
    systemRam_ = SDL_GetSystemRAM();
}

int GfxCpuInfo::getCpuCount(void) const
{
    return cpuCount_;
}

int GfxCpuInfo::getCpuCacheLineSize(void) const
{
    return cpuCacheLineSize_;
}

bool GfxCpuInfo::hasRdtsc(void) const
{
    return hasRdtsc_;
}

bool GfxCpuInfo::hasAltiVec(void) const
{
    return hasAltiVec_;
}

bool GfxCpuInfo::hasMmx(void) const
{
    return hasMmx_;
}

bool GfxCpuInfo::hasSse(void) const
{
    return hasSse_;
}

bool GfxCpuInfo::hasSse2(void) const
{
    return hasSse2_;
}

bool GfxCpuInfo::hasSse3(void) const
{
    return hasSse3_;
}

bool GfxCpuInfo::hasSse41(void) const
{
    return hasSse41_;
}

bool GfxCpuInfo::hasSse42(void) const
{
    return hasSse42_;
}

bool GfxCpuInfo::hasAvx(void) const
{
    return hasAvx_;
}

bool GfxCpuInfo::hasAvx2(void) const
{
    return hasAvx2_;
}

int GfxCpuInfo::getSystemRam(void) const
{
    return systemRam_;
}

std::string GfxCpuInfo::getAsFormatedString(void) const
{
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
    str1 += "RAM=" + std::to_string(systemRam_) + "MB";
    return str1;
}

