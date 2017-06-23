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
#include "GfxText.hpp"
#include "GfxBitmapFont.hpp"
#include "GfxDrawingMode.hpp"
#include "GfxArcCoordsType.hpp"
#include "GfxPaletteType.hpp"
#include "GfxFillSettingsType.hpp"
#include "GfxLineSettingsType.hpp"
#include "GfxTextSettingsType.hpp"
#include "GfxViewPortType.hpp"
#include "GfxLineStyle.hpp"
#include "GfxFillStyles.hpp"
#include "GfxLineThickness.hpp"
#include "GfxTextJustification.hpp"
#include "GfxDirection.hpp"
#include "GfxFonts.hpp"
#include "GfxColors2.hpp"

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
                const bool topflag, pixels::GfxColor const& clr) noexcept;
    void Bar3D(rect::GfxRect const& r, const int32_t depth, const bool topflag,
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
    GfxArcCoordsType GetArcCoords(void) noexcept;
    pixels::GfxColor GetBkColor(void) noexcept;
    pixels::GfxColor GetColor(void) noexcept;
    GfxPaletteType GetDefaultPalette(void) noexcept;
    void GetFillPattern(char * pattern) noexcept;
    GfxFillSettingsType GetFillSettings(void) noexcept;
    void GetImage(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, void * bitmap) noexcept;
    void GetImage(rect::GfxRect const& r, void * bitmap) noexcept;
    GfxLineSettingsType GetLineSettings(void) noexcept;
    int32_t GetMaxColor(void) noexcept;
    int32_t GetMaxX(void) noexcept;
    int32_t GetMaxY(void) noexcept;
    GfxPaletteType GetPalette(void) noexcept;
    int32_t GetPaletteSize(void) noexcept;
    pixels::GfxColor GetPixel(rect::GfxPoint const& pt) noexcept;
    GfxTextSettingsType GetTextSettings(void) noexcept;
    GfxViewPortType GetViewSettings(void) noexcept;
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
    void OutText(GfxText const& text, pixels::GfxColor const& clr) noexcept;
    void OutText(GfxText const& text, pixels::GfxColor const& clr, fnt::GfxBitmapFont const& font) noexcept;
    void OutTextXY(rect::GfxPoint const& pt, GfxText const& text, pixels::GfxColor const& clr) noexcept;
    void OutTextXY(rect::GfxPoint const& pt, GfxText const& text, pixels::GfxColor const& clr,
                  fnt::GfxBitmapFont const& font) noexcept;
    /* HERE */
    void PieSlice(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                GfxRadius const& radius, GfxColors2 const& clr) noexcept;
    /* HERE */
    void PutImage(rect::GfxPoint const& pt, void * bitmap, GfxDrawingMode const& dmode) noexcept;
    void PutPixel(rect::GfxPoint const& pt, pixels::GfxColor const& clr) noexcept;
    void Rectangle(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, pixels::GfxColor const& clr) noexcept;
    void Rectangle(rect::GfxRect const& r, pixels::GfxColor const& clr) noexcept;
    void Sector(rect::GfxPoint const& pt, GfxAngle const& stangle, GfxAngle const& endangle,
                GfxRadius const& xradius, GfxRadius const& yradius, pixels::GfxColor const& clr) noexcept;
    void SetAllPalette(GfxPaletteType const& palette) noexcept;
    void SetBkColor(pixels::GfxColor const& clr) noexcept;
    void SetColor(pixels::GfxColor const& clr) noexcept;
    void SetFillPattern(uint8_t * upattern, pixels::GfxColor const& clr) noexcept;
    void SetFillStyle(GfxFillStyles const& pattern, pixels::GfxColor const& clr) noexcept;
    void SetLineStyle(GfxLineStyle const& linestyle, GfxFillStyles const& upattern,
                    GfxLineThickness const& thickness) noexcept;
    void SetPalette(int32_t colornum, pixels::GfxColor const& clr) noexcept;
    void SetTextJustify(GfxTextJustification const& horiz, GfxTextJustification const& vert) noexcept;
    void SetTextStyle(GfxFonts const& font, GfxDirection const& direction, int32_t charsize) noexcept;
    void SetUserCharSize(const int32_t multx, const int32_t divx, const int32_t multy, const int32_t divy) noexcept;
    void SetViewPort(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2, const bool clip) noexcept;
    void SetViewPort(rect::GfxRect const& r, const bool clip) noexcept;
    void SetWriteMode(GfxDrawingMode const& dmode) noexcept;
    int32_t TextHeight(GfxText const& textstring) noexcept;
    int32_t TextWidth(GfxText const& textstring) noexcept;
private:
    prv::GfxCanvasBgi bgi_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxCanvas_hpp */
