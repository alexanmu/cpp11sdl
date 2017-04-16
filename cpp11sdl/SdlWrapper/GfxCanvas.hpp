//
//  GfxCanvas.hpp
//  cpp11sdl
//
//  Created by Familia Oros on 14/04/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxCanvas_hpp
#define GfxCanvas_hpp

#include "GfxRootClass.hpp"
#include "GfxConstants.hpp"
#include "GfxSurface.hpp"
#include "GfxCanvasBgi.hpp"

class GfxCanvas final : public GfxRootClass
{
public:
    GfxCanvas() = delete;
    GfxCanvas(GfxSurface& surf);
    
    void paint(void);
    void circle(const uint16_t x, const uint16_t y, const uint16_t r);
    void arc(const uint16_t x,const uint16_t y, const int stangle,const int endangle,const uint16_t radius);
    void outtextxy(const uint16_t x, const uint16_t y,std::string text);
private:
    GfxCanvasBgi bgi_;
    GfxSurface& surf_;
};

#endif /* GfxCanvas_hpp */
