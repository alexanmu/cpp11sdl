//
//  GfxPixelFormat.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxPixelFormat.hpp"

GfxPixelFormat::GfxPixelFormat(GfxPixelFormatSdlType pix)
{
    pix_ = pix;
}

GfxPixelFormat::GfxPixelFormatSdlType GfxPixelFormat::getAsGfxPixelFormatSdlType(void)
{
    return pix_;
}

GfxPixelFormat::GfxPixelFormatSdlType* GfxPixelFormat::getAsGfxPixelFormatSdlTypePtr(void)
{
    return &pix_;
}
