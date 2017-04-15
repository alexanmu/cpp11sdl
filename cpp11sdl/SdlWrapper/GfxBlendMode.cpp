//
//  GfxBlendMode.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/9/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxBlendMode.hpp"

GfxBlendMode::GfxBlendMode()
{
    blendmode_ = GfxBlendModeValues::blendNone;
}

GfxBlendMode::GfxBlendMode(GfxBlendModeValues blendmode)
{
    blendmode_ = blendmode;
}

GfxBlendMode::GfxBlendMode(SdlType blendmode)
{
    blendmode_ = static_cast<GfxBlendModeValues>(blendmode);
}

GfxBlendMode::GfxBlendMode(SdlTypePtr blendmode)
{
    blendmode_ = static_cast<GfxBlendModeValues>(*blendmode);
}

GfxBlendMode::GfxBlendMode(const GfxBlendMode& other)
{
    blendmode_ = other.blendmode_;
}

GfxBlendMode::GfxBlendMode(GfxBlendMode&& other)
{
    blendmode_ = other.blendmode_;
    // Destroy other's data
    other.blendmode_ = GfxBlendModeValues::blendNone;
}

GfxBlendMode& GfxBlendMode::operator=(const GfxBlendMode& other)
{
    if (this != &other)
    {
        blendmode_ = other.blendmode_;
    }
    return *this;
}

GfxBlendMode& GfxBlendMode::operator=(GfxBlendMode&& other)
{
    if (this != &other)
    {
        blendmode_ = other.blendmode_;
        // Destroy other's data
        other.blendmode_ = GfxBlendModeValues::blendNone;
    }
    return *this;
}

bool GfxBlendMode::operator==(const GfxBlendMode& other)
{
    return (blendmode_ == other.blendmode_);
}

GfxBlendMode::GfxBlendModeValues GfxBlendMode::getBlendMode(void) const
{
    return blendmode_;
}

GfxBlendMode::SdlType GfxBlendMode::getAsSdlType(void) const
{
    return (SdlType)blendmode_;
}

GfxBlendMode::SdlTypePtr GfxBlendMode::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)blendmode_;
}

