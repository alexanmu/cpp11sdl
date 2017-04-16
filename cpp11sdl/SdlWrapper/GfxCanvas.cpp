//
//  GfxCanvas.cpp
//  cpp11sdl
//
//  Created by Familia Oros on 14/04/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxCanvas.hpp"
#include <iostream>
#include <cmath>

GfxCanvas::GfxCanvas(GfxSurface& surf) : surf_(surf)
{
	bgi_.setCanvas(static_cast<uint32_t*>(surf_.surf_->pixels),surf_.surf_->w,surf_.surf_->h);
}

uint8_t compute1(int x, int y)
{
	double dx = (double)x * M_PI / 180.0;
	double dy = (double)y * M_PI / 180.0;
	double r;
	int ic;

    dx += 50.0;
    dy += 50.0;
    r = dx * std::sin(dy) + dy * std::cos(dx) + dx * std::sin(dx) + dy * std::cos(dy);
    r = r * 2.55 + std::tan(r);
    ic = (int)r;
	return ic % 4;
}

uint8_t compute2(int x, int y)
{
    double dx = (double)x * M_PI / 180.0;
    double dy = (double)y * M_PI / 180.0;
    double r;
    int ic;
    
    dx += -50.0;
    dy += -50.0;
    r = std::log(dx * dy) + 2.0 * std::cos(dy * dx) + 2.0 * std::sin(dx * dy);
    ic = (int)r;
    return (ic % 16);
}


void GfxCanvas::paint(void)
{
    for(int i = 0; i < 960; i++)
        for(int j = 0; j < 480; j++)
        {
        	uint8_t c = compute2(i,j);
            surf_.putPixelPrv(i,j,GfxConstants::vga16GetColorByIndex(c));
        }
}

void GfxCanvas::circle(const uint16_t x, const uint16_t y, const uint16_t radius,const GfxColor& clr)
{
    bgi_.setCustomColor(clr.getColor());
	bgi_.circle(x,y,radius);
}

void GfxCanvas::arc(const uint16_t x,const uint16_t y, const int stangle,const int endangle,const uint16_t radius,const GfxColor& clr)
{
	bgi_.setCustomColor(clr.getColor());
	bgi_.arc(x,y,stangle,endangle,radius);
}

void GfxCanvas::outtextxy(const uint16_t x, const uint16_t y,std::string text,const GfxColor& clr)
{
	bgi_.setCustomColor(clr.getColor());
	bgi_.outtextxy(x,y,(char *)text.c_str());
}

void GfxCanvas::bar(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const GfxColor& clr)
{
    bgi_.setCustomColor(clr.getColor());
    bgi_.bar(x1,y1,x2,y2);
}

void GfxCanvas::putpixel(const uint16_t x, const uint16_t y, const GfxColor& clr)
{
    int c = clr.getAlpha();
    bgi_.setcolor(static_cast<GfxCanvasBgi::bgiColors>(c));
    bgi_._putpixel(x, y);
}
