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
    /* Copy structure; hope SDL_Color assignement operator works ... */
    clr_ = clr;
}

SdlColor::SdlColorSdlType SdlColor::getAsGfxColorSdlType() const
{
    return clr_;
}

SdlColor::SdlColorSdlType* SdlColor::getAsGfxColorSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlColorSdlType*)&clr_;
}
