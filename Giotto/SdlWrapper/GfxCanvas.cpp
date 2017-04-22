/*
  CPP11SDL
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/
#include <cmath>

#include "GfxCanvas.hpp"
#include "GfxConstants.hpp"

GfxCanvas::GfxCanvas(GfxSurface& surf) : surf_(surf)
{
    bgi_.setCanvas(static_cast<uint32_t *>(surf_.surf_->pixels),surf_.surf_->w,surf_.surf_->h);
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
            surf_.putPixelPrv(i,j,GfxConstants::vga16GetColorByIndex(static_cast<GfxConstants::GfxVga16ColorIndex>(c)));
        }
}

void GfxCanvas::Circle(const GfxPoint& pt, const GfxRadius& r, const GfxColor& clr)
{
    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.circle(pt.getX(),pt.getY(),r.getValue());
}

void GfxCanvas::Arc(const GfxPoint& pt, const GfxAngle& stangle,const GfxAngle& endangle,const GfxRadius& radius,const GfxColor& clr)
{
    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.arc(pt.getX(),pt.getY(),stangle.getValue(),endangle.getValue(),radius.getValue());
}

void GfxCanvas::OutText(const GfxPoint& pt,const GfxString& text,const GfxColor& clr,const GfxBitmapFont& font)
{
    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.setCustomFont(font.getFontData(),font.getFontWidth(),font.getFontHeight());
    bgi_.outtextxy(pt.getX(),pt.getY(),(char *)text.getValue().c_str());
    bgi_.setDefaultFont();
}

void GfxCanvas::OutText(const GfxPoint& pt,const GfxString& text,const GfxColor& clr)
{
    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.outtextxy(pt.getX(),pt.getY(),(char *)text.getValue().c_str());
}

void GfxCanvas::Bar(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr)
{
    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar(pt1.getX(),pt1.getY(),pt2.getX(),pt2.getY());
}

void GfxCanvas::Bar(const GfxRect& r, const GfxColor& clr)
{
    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar(r.getX(),r.getY(),r.getWidth() + 1,r.getHeight() + 1);
}

void GfxCanvas::PutPixel(const GfxPoint& pt, const GfxColor& clr)
{
    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_._putpixel(pt.getX(), pt.getY());
}

void GfxCanvas::Rect(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr)
{
    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.rectangle(pt1.getX(),pt1.getY(),pt2.getX(), pt2.getY());
}

void GfxCanvas::Rect(const GfxRect& r, const GfxColor& clr)
{
    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.rectangle(r.getX(),r.getY(),r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Line(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr)
{
    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.line(pt1.getX(),pt1.getY(),pt2.getX(), pt2.getY());
}