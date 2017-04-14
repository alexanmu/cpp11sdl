//
//  GfxCanvas.hpp
//  cpp11sdl
//
//  Created by Familia Oros on 14/04/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxCanvas_hpp
#define GfxCanvas_hpp

#include "GfxConstants.hpp"
#include "GfxRootClass.hpp"
#include "GfxSurface.hpp"

class GfxCanvas final : public GfxRootClass
{
public:
    GfxCanvas() = delete;
    GfxCanvas(GfxSurface& surf);
    
    void paint(void);
private:
    GfxSurface& surf_;
};

#endif /* GfxCanvas_hpp */
