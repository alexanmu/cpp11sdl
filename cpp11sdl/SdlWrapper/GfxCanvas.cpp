//
//  GfxCanvas.cpp
//  cpp11sdl
//
//  Created by Familia Oros on 14/04/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxCanvas.hpp"

GfxCanvas::GfxCanvas(GfxSurface& surf) : surf_(surf)
{
    //
}

void GfxCanvas::paint(void)
{
    for(int i = 0; i < 960; i++)
        for(int j = 0; j < 480; j++)
            surf_.putPixelPrv(i,j,GfxConstants::clrVGA16Black());
}
