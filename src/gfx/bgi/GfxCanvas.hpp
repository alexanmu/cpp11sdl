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

#ifndef GfxCanvas_hpp
#define GfxCanvas_hpp

#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxSurface.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxPoint.hpp"
#include "GfxRect.hpp"
#include "GfxRadius.hpp"
#include "GfxAngle.hpp"
#include "GfxString.hpp"
#include "GfxBitmapFont.hpp"
#include "GfxDrawingMode.hpp"

namespace gfx
{

namespace bgi
{

class GfxCanvas final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxCanvas() = delete;
    explicit GfxCanvas(surface::GfxSurface const& surf) noexcept;

    GfxCanvas(GfxCanvas const&) = delete;
    GfxCanvas(GfxCanvas&&) = delete;

    GfxCanvas& operator=(GfxCanvas const&) = delete;
    GfxCanvas& operator=(GfxCanvas&&) = delete;

    virtual explicit operator bool() const noexcept;

    void Arc(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
             GfxRadius const& radius, pixels::GfxColor const& clr) noexcept;
    void Bar(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept;
    void Bar(rect::GfxRect const& r, pixels::GfxColor const& clr) noexcept;
    void Bar3D(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, const int32_t depth,
                const int32_t topflag, pixels::GfxColor const& clr) noexcept;
    void Bar3D(rect::GfxRect const& r, const int32_t depth, const int32_t topflag,
                pixels::GfxColor const& clr) noexcept;
    void Circle(rect::GfxPoint const& pt, GfxRadius const& r, pixels::GfxColor const& clr) noexcept;
    void ClearDevice(void) noexcept;
    void ClearViewPort(void) noexcept;
    void DrawPoly(std::vector<int32_t> const& polypoints, pixels::GfxColor const& clr) noexcept;
    void Ellipse(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                GfxRadius const& xradius, GfxRadius const& yradius, pixels::GfxColor const& clr) noexcept;
    void FillEllipse(rect::GfxPoint const& pt, GfxRadius const& xradius, GfxRadius const& yradius,
                    pixels::GfxColor const& clr) noexcept;
    void FillPoly(std::vector<int32_t> const& polypoints, pixels::GfxColor const& clr) noexcept;
    void FloodFill(rect::GfxPoint const& pt, pixels::GfxColor const& border, pixels::GfxColor const& clr) noexcept;
    void FreeImage(void * bitmap) noexcept;
    /* TODO void GetArcCoords(struct arccoordstype * arccoords) noexcept; */
    pixels::GfxColor getBkColor(void) noexcept;
    pixels::GfxColor getColor(void) noexcept;
    /* TODO struct palettetype * GetDefaultPalette(void) noexcept; */
    void GetFillPattern(char * pattern) noexcept;
    /* TODO void GetFillSettings(struct fillsettingstype * fillinfo) noexcept; */
    void GetImage(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, void * bitmap) noexcept;
    void GetImage(rect::GfxRect const& r, void * bitmap) noexcept;
    /* TODO void GetLineSettings(struct linesettingstype * lineinfo) noexcept; */
    int32_t GetMaxColor(void) noexcept;
    int32_t GetMaxX(void) noexcept;
    int32_t GetMaxY(void) noexcept;
    /* TODO void GetPalette(struct palettetype *) noexcept; */
    /* TODO int32_t GetPaletteSize(struct palettetype *) noexcept; */
    pixels::GfxColor GetPixel(rect::GfxPoint const& pt) noexcept;
    /* TODO void GetTextSettings(struct textsettingstype *) noexcept; */
    /* TODO void GetViewSettings(struct viewporttype *) noexcept; */
    int32_t GetX(void) noexcept;
    int32_t GetY(void) noexcept;
    void GraphDefaults(void) noexcept;
    uint32_t ImageSize(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2) noexcept;
    uint32_t ImageSize(rect::GfxRect const& r) noexcept;
    void Line(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept;
    void LineRel(rect::GfxPoint const& pt) noexcept;
    void LineTo(rect::GfxPoint const& pt) noexcept;
    void MoveRel(rect::GfxPoint const& pt) noexcept;
    void MoveTo(rect::GfxPoint const& pt) noexcept;
    void OutText(GfxString const& text, pixels::GfxColor const& clr) noexcept;
    void OutText(GfxString const& text, pixels::GfxColor const& clr, fnt::GfxBitmapFont const& font) noexcept;
    void OutTextXY(rect::GfxPoint const& pt, GfxString const& text, pixels::GfxColor const& clr) noexcept;
    void OutTextXY(rect::GfxPoint const& pt, GfxString const& text, pixels::GfxColor const& clr,
                  fnt::GfxBitmapFont const& font) noexcept;
    void PieSlice(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                GfxRadius const& radius, pixels::GfxColor const& clr) noexcept;
    void PutImage(rect::GfxPoint const& pt, void * bitmap, GfxDrawingMode const& dmode) noexcept;
    void PutPixel(rect::GfxPoint const& pt, pixels::GfxColor const& clr) noexcept;
    void Rectangle(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept;
    void Rectangle(rect::GfxRect const& r, pixels::GfxColor const& clr) noexcept;
    /*void Sector(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                GfxRadius const& xradius, GfxRadius const& yradius) noexcept;
    void SetAllPalette(struct palettetype *palette) noexcept;
    void SetBkColor(pixels::GfxColor const& clr) noexcept;
    void SetColor(pixels::GfxColor const& clr) noexcept;
    void SetFillPattern(uint8_t * upattern, pixels::GfxColor const& clr) noexcept;
    void setfillstyle(bgiFillStyles pattern, pixels::GfxColor const& clr);
    void setlinestyle(bgiLineStyle linestyle, bgiFillStyles upattern, bgiLineThickness thickness);
    void setpalette(int colornum, int color);
    void settextjustify(bgiTextJustification horiz, bgiTextJustification vert);
    void settextstyle(int font, bgiDirection direction, int charsize);
    void setusercharsize(int multx, int divx, int multy, int divy);
    void setviewport(int left, int top, int right, int bottom, int clip);
    void SetWriteMode(GfxDrawingMode const& dmode);*/
    int32_t TextHeight(GfxString const& textstring) noexcept;
    int32_t TextWidth(GfxString const& textstring) noexcept;
private:
    prv::GfxCanvasBgi bgi_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxCanvas_hpp */
