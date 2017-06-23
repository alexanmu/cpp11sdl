/*
  Giotto
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

#include <cassert>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

#include "GfxCanvas.hpp"
#include "GfxBgiConstants.hpp"

namespace gfx
{

namespace bgi
{

const char GfxCanvas::ClassName[] = "GfxCanvas";

GfxCanvas::GfxCanvas(surface::GfxSurface const& surf) noexcept : GfxObject(ClassName)
{
    assert(surf);

    bgi_.setCanvas(static_cast<uint32_t *>(surf.getAsSdlTypePtr()->pixels), surf.getAsSdlTypePtr()->w,
                    surf.getAsSdlTypePtr()->h);
}

GfxCanvas::operator bool() const noexcept
{
    return true;
}

void GfxCanvas::Arc(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                    GfxRadius const& radius, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(radius);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.arc(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), radius.getValue());
}

void GfxCanvas::Bar(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept
{
    assert(pt1);
    assert(pt2);
    assert(clr);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::Bar(rect::GfxRect const& r, pixels::GfxColor const& clr) noexcept
{
    assert(r);
    assert(clr);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Bar3D(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, const int32_t depth,
                        const bool topflag, pixels::GfxColor const& clr) noexcept
{
    assert(pt1);
    assert(pt2);
    assert(depth > 0);
    assert(clr);

    int32_t int_topflag = static_cast<int32_t>(topflag);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar3d(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), depth, int_topflag);
}

void GfxCanvas::Bar3D(rect::GfxRect const& r, const int32_t depth, const bool topflag,
                    pixels::GfxColor const& clr) noexcept
{
    assert(r);
    assert(depth > 0);
    assert(clr);

    int32_t int_topflag = static_cast<int32_t>(topflag);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.bar3d(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, depth, int_topflag);
}

void GfxCanvas::Circle(rect::GfxPoint const& pt, GfxRadius const& r, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(r);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.circle(pt.getX(), pt.getY(), r.getValue());
}

void GfxCanvas::ClearDevice(void) noexcept
{
    bgi_.cleardevice();
}

void GfxCanvas::ClearViewPort(void) noexcept
{
    bgi_.clearviewport();
}

void GfxCanvas::DrawPoly(std::vector<int32_t> const& polypoints, pixels::GfxColor const& clr) noexcept
{
    assert(polypoints.size() > 0);
    assert(clr);

    const int * points = &polypoints.front();

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.drawpoly(static_cast<int>(polypoints.size()), const_cast<int *>(points));
}

void GfxCanvas::Ellipse(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                    GfxRadius const& xradius, GfxRadius const& yradius, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(xradius);
    assert(yradius);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.ellipse(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), xradius.getValue(),
                yradius.getValue());
}

void GfxCanvas::FillEllipse(rect::GfxPoint const& pt, GfxRadius const& xradius, GfxRadius const& yradius,
                            pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(xradius);
    assert(yradius);
    assert(clr);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.fillellipse(pt.getX(), pt.getY(), xradius.getValue(), yradius.getValue());
}

void GfxCanvas::FillPoly(std::vector<int32_t> const& polypoints, pixels::GfxColor const& clr) noexcept
{
    assert(polypoints.size() > 0);
    assert(clr);

    const int * points = &polypoints.front();

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.fillpoly(static_cast<int>(polypoints.size()), const_cast<int *>(points));
}

void GfxCanvas::FloodFill(rect::GfxPoint const& pt, pixels::GfxColor const& border,
                        pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(border);
    assert(clr);

    bgi_.setCustomFillColor(clr.getColor());
    bgi_.floodfill(pt.getX(), pt.getY(), static_cast<prv::GfxCanvasBgi::bgiColors>(border.getColor()));
}

void GfxCanvas::FreeImage(void * bitmap) noexcept
{
    assert(bitmap != nullptr);

    bgi_.freeimage(bitmap);
}

GfxArcCoordsType GfxCanvas::GetArcCoords(void) noexcept
{
    struct prv::GfxCanvasBgi::arccoordstype arccoords;

    bgi_.getarccoords(&arccoords);
    return GfxArcCoordsType(arccoords);
}

pixels::GfxColor GfxCanvas::GetBkColor(void) noexcept
{
    // prv::GfxCanvasBgi::bgiColors clr = bgi_.getbkcolor();
    // return kGetColorByIndex(static_cast<GfxColorIndex>(clr));

    return pixels::GfxColor(bgi_.getCustomForegroundColor());
}

pixels::GfxColor GfxCanvas::GetColor(void) noexcept
{
    // prv::GfxCanvasBgi::bgiColors clr = bgi_.getcolor();
    // return kGetColorByIndex(static_cast<GfxColorIndex>(clr));

    return pixels::GfxColor(bgi_.getCustomBackgroundColor());
}

GfxPaletteType GfxCanvas::GetDefaultPalette(void) noexcept
{
    struct prv::GfxCanvasBgi::palettetype * palette_ptr;
    struct prv::GfxCanvasBgi::palettetype palette;

    palette_ptr = bgi_.getdefaultpalette();
    palette.size = palette_ptr->size;
    std::memcpy(palette.colors, palette_ptr->colors, prv::GfxCanvasBgi::kMaxColors + 1);
    return GfxPaletteType(palette);
}

void GfxCanvas::GetFillPattern(char * pattern) noexcept
{
    assert(pattern != nullptr);

    bgi_.getfillpattern(pattern);
}

GfxFillSettingsType GfxCanvas::GetFillSettings(void) noexcept
{
    struct prv::GfxCanvasBgi::fillsettingstype * fill_ptr = nullptr;
    struct prv::GfxCanvasBgi::fillsettingstype fill;

    bgi_.getfillsettings(fill_ptr);
    fill.pattern = fill_ptr->pattern;
    fill.color = fill_ptr->color;
    return GfxFillSettingsType(fill);
}

void GfxCanvas::GetImage(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, void * bitmap) noexcept
{
    assert(pt1);
    assert(pt2);
    assert(bitmap != nullptr);

    bgi_.getimage(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), bitmap);
}

void GfxCanvas::GetImage(rect::GfxRect const& r, void * bitmap) noexcept
{
    assert(r);
    assert(bitmap != nullptr);

    bgi_.getimage(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, bitmap);
}

GfxLineSettingsType GfxCanvas::GetLineSettings(void) noexcept
{
    struct prv::GfxCanvasBgi::linesettingstype linesettings;

    bgi_.getlinesettings(&linesettings);
    return GfxLineSettingsType(linesettings);
}

int32_t GfxCanvas::GetMaxColor(void) noexcept
{
    return bgi_.getmaxcolor();
}

int32_t GfxCanvas::GetMaxX(void) noexcept
{
    return bgi_.getmaxx();
}

int32_t GfxCanvas::GetMaxY(void) noexcept
{
    return bgi_.getmaxy();
}

GfxPaletteType GfxCanvas::GetPalette(void) noexcept
{
    struct prv::GfxCanvasBgi::palettetype palette;

    bgi_.getpalette(&palette);
    return GfxPaletteType(palette);
}

int32_t GfxCanvas::GetPaletteSize(void) noexcept
{
    return bgi_.getpalettesize();
}

pixels::GfxColor GfxCanvas::GetPixel(rect::GfxPoint const& pt) noexcept
{
    assert(pt);

    uint32_t clr;

    clr = bgi_.getpixel(pt.getX(), pt.getY());
    return pixels::GfxColor(clr);
}

GfxTextSettingsType GfxCanvas::GetTextSettings(void) noexcept
{
    struct prv::GfxCanvasBgi::textsettingstype textsettings;

    bgi_.gettextsettings(&textsettings);
    return GfxTextSettingsType(textsettings);
}

GfxViewPortType GfxCanvas::GetViewSettings(void) noexcept
{
    struct prv::GfxCanvasBgi::viewporttype viewport;

    bgi_.getviewsettings(&viewport);
    return GfxViewPortType(viewport);
}

int32_t GfxCanvas::GetX(void) noexcept
{
    return bgi_.getx();
}

int32_t GfxCanvas::GetY(void) noexcept
{
    return bgi_.gety();
}

void GfxCanvas::GraphDefaults(void) noexcept
{
    bgi_.graphdefaults();
}

uint32_t GfxCanvas::ImageSize(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2) noexcept
{
    assert(pt1);
    assert(pt2);

    return bgi_.imagesize(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

uint32_t GfxCanvas::ImageSize(rect::GfxRect const& r) noexcept
{
    assert(r);

    return bgi_.imagesize(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Line(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept
{
    assert(pt1);
    assert(pt2);
    assert(clr);

    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.line(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::LineRel(rect::GfxPoint const& pt) noexcept
{
    assert(pt);

    bgi_.linerel(pt.getX(), pt.getY());
}

void GfxCanvas::LineTo(rect::GfxPoint const& pt) noexcept
{
    assert(pt);

    bgi_.lineto(pt.getX(), pt.getY());
}

void GfxCanvas::MoveRel(rect::GfxPoint const& pt) noexcept
{
    bgi_.moverel(pt.getX(), pt.getY());
}

void GfxCanvas::MoveTo(rect::GfxPoint const& pt) noexcept
{
    assert(pt);

    bgi_.moveto(pt.getX(), pt.getY());
}

void GfxCanvas::OutText(GfxText const& text, pixels::GfxColor const& clr) noexcept
{
    assert(text);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.outtext(const_cast<char *>(text.getValue().c_str()));
}

void GfxCanvas::OutText(GfxText const& text, pixels::GfxColor const& clr, fnt::GfxBitmapFont const& font) noexcept
{
    assert(text);
    assert(clr);
    assert(font);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.setCustomFont(font.getFontData(), font.getFontWidth(), font.getFontHeight());
    bgi_.outtext(const_cast<char *>(text.getValue().c_str()));
    bgi_.setDefaultFont();
}

void GfxCanvas::OutTextXY(rect::GfxPoint const& pt, GfxText const& text, pixels::GfxColor const& clr,
                        fnt::GfxBitmapFont const& font) noexcept
{
    assert(pt);
    assert(text);
    assert(clr);
    assert(font);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.setCustomFont(font.getFontData(), font.getFontWidth(), font.getFontHeight());
    bgi_.outtextxy(pt.getX(), pt.getY(), const_cast<char *>(text.getValue().c_str()));
    bgi_.setDefaultFont();
}

void GfxCanvas::OutTextXY(rect::GfxPoint const& pt, GfxText const& text, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(text);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.outtextxy(pt.getX(), pt.getY(), const_cast<char *>(text.getValue().c_str()));
}

void GfxCanvas::PieSlice(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                        GfxRadius const& radius, GfxColors2 const& clr) noexcept
{
    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(radius);
    assert(clr);

    bgi_.setcolor(clr.getAsBgiType());
    bgi_.pieslice(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), radius.getValue());
}

void GfxCanvas::PutImage(rect::GfxPoint const& pt, void * bitmap, GfxDrawingMode const& dmode) noexcept
{
    assert(pt);
    assert(bitmap != nullptr);
    assert(dmode);

    bgi_.putimage(pt.getX(), pt.getY(), bitmap, dmode.getAsBgiType());
}

void GfxCanvas::PutPixel(rect::GfxPoint const& pt, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(clr);

    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_._putpixel(pt.getX(), pt.getY());
}

void GfxCanvas::Rectangle(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept
{
    assert(pt1);
    assert(pt2);
    assert(clr);

    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.rectangle(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::Rectangle(rect::GfxRect const& r, pixels::GfxColor const& clr) noexcept
{
    assert(r);
    assert(clr);

    uint32_t c = clr.getColor();

    bgi_.setCustomForegroundColor(c);
    bgi_.rectangle(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Sector(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                    GfxRadius const& xradius, GfxRadius const& yradius, pixels::GfxColor const& clr) noexcept
{
    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(xradius);
    assert(yradius);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.sector(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(),
                xradius.getValue(), yradius.getValue());
}

void GfxCanvas::SetAllPalette(GfxPaletteType const& palette) noexcept
{
    assert(palette);

    GfxPaletteType::BgiType pal;

    pal = palette.getAsBgiType();
    bgi_.setallpalette(&pal);
}

void GfxCanvas::SetBkColor(pixels::GfxColor const& clr) noexcept
{
    assert(clr);

    // bgi_.setbkcolor(clr.getColor());
    bgi_.setCustomBackgroundColor(clr.getColor());
}

void GfxCanvas::SetColor(pixels::GfxColor const& clr) noexcept
{
    assert(clr);

    // bgi_.setcolor(clr.getColor());
    bgi_.setCustomForegroundColor(clr.getColor());
}

void GfxCanvas::SetFillPattern(uint8_t * upattern, pixels::GfxColor const& clr) noexcept
{
    assert(upattern != nullptr);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.setfillpattern(upattern, prv::GfxCanvasBgi::bgiColors::BLACK);
}

void GfxCanvas::SetFillStyle(GfxFillStyles const& pattern, pixels::GfxColor const& clr) noexcept
{
    assert(pattern);
    assert(clr);

    bgi_.setCustomForegroundColor(clr.getColor());
    bgi_.setfillstyle(pattern.getAsBgiType(), prv::GfxCanvasBgi::bgiColors::BLACK);
}

void GfxCanvas::SetLineStyle(GfxLineStyle const& linestyle, GfxFillStyles const& upattern,
                           GfxLineThickness const& thickness) noexcept
{
    assert(linestyle);
    assert(upattern);
    assert(thickness);

    bgi_.setlinestyle(linestyle.getAsBgiType(), upattern.getAsBgiType(), thickness.getAsBgiType());
}

void GfxCanvas::SetPalette(int32_t colornum, GfxColors2 const& clr) noexcept
{
    assert(colornum >= 0);
    assert(clr);

    bgi_.setpalette(colornum, clr.getAsBgiType());
}

void GfxCanvas::SetTextJustify(GfxTextJustification const& horiz, GfxTextJustification const& vert) noexcept
{
    assert(horiz);
    assert(vert);

    bgi_.settextjustify(horiz.getAsBgiType(), vert.getAsBgiType());
}

void GfxCanvas::SetTextStyle(GfxFonts const& font, GfxDirection const& direction, int32_t charsize) noexcept
{
    assert(font);
    assert(direction);
    assert(charsize);

    bgi_.settextstyle(font.getAsBgiType(), direction.getAsBgiType(), charsize);
}

void GfxCanvas::SetUserCharSize(const int32_t multx, const int32_t divx, const int32_t multy,
                                const int32_t divy) noexcept
{
    assert(multx > 0);
    assert(divx > 0);
    assert(multy > 0);
    assert(multy > 0);

    bgi_.setusercharsize(multx, divx, multy, divy);
}

void GfxCanvas::SetViewPort(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, bool clip) noexcept
{
    assert(pt1);
    assert(pt2);

    int32_t int_clip = static_cast<int32_t>(clip);

    bgi_.setviewport(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), int_clip);
}

void GfxCanvas::SetViewPort(rect::GfxRect const& r, bool clip) noexcept
{
    assert(r);

    int32_t int_clip = static_cast<int32_t>(clip);

    bgi_.setviewport(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, int_clip);
}

void GfxCanvas::SetWriteMode(GfxDrawingMode const& dmode) noexcept
{
    assert(dmode);

    bgi_.setwritemode(dmode.getAsBgiType());
}

int32_t GfxCanvas::TextHeight(GfxText const& textstring) noexcept
{
    assert(textstring);

    return bgi_.textheight(const_cast<char *>(textstring.getValue().c_str()));
}

int32_t GfxCanvas::TextWidth(GfxText const& textstring) noexcept
{
    assert(textstring);

    return bgi_.textwidth(const_cast<char *>(textstring.getValue().c_str()));
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
