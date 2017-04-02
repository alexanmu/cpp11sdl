//
//  SdlColor.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "SdlColor.hpp"

SdlColor::SdlColor(SdlColorSdlType clr)
{
    clr_ = clr;
}

SdlColor::SdlColorSdlType SdlColor::getAsGfxColorSdlType() const
{
    return clr_;
}

SdlColor::SdlColorSdlType* SdlColor::getAsGfxColorSdlTypePtr(void)
{
    return &clr_;
}
