//
//  GfxFlip.cpp
//  FirstProject
//
//  Created by George Oros on 4/1/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxFlip.hpp"

GfxFlip::SdlType GfxFlip::getAsSdlType(void) const
{
    return (SdlType)flip_;
}

GfxFlip::SdlTypePtr GfxFlip::getAsSdlTypePtr(void)
{
    return (GfxFlip::SdlTypePtr)&flip_;
}
