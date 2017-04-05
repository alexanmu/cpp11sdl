//
//  GfxColor.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxColor.hpp"

GfxColor::GfxColor(SdlType clr)
{
    /* Copy structure; hope SDL_Color assignement operator works ... */
    clr_ = clr;
}

GfxColor::SdlType GfxColor::getAsSdlType() const
{
    return clr_;
}

GfxColor::SdlTypePtr GfxColor::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)&clr_;
}
