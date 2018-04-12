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
    explicit GfxCanvas(const surface::GfxSurface& surf) noexcept;

    GfxCanvas(const GfxCanvas&) = delete;
    GfxCanvas(GfxCanvas&&) = delete;

    GfxCanvas& operator=(const GfxCanvas&) = delete;
    GfxCanvas& operator=(GfxCanvas&&) = delete;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void Arc(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
             const GfxRadius& radius) noexcept;
    void Bar(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept;
    void Bar(const rect::GfxRect& r) noexcept;
    void Bar3D(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const int32_t depth,
               const bool topflag) noexcept;
    void Bar3D(const rect::GfxRect& r, const int32_t depth, const bool topflag) noexcept;
    void Circle(const rect::GfxPoint& pt, const GfxRadius& r) noexcept;
    void ClearDevice(void) noexcept;
    void ClearViewPort(void) noexcept;
    void DrawPoly(const std::vector<rect::GfxPoint>& polypoints) noexcept;
    void Ellipse(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                 const GfxRadius& xradius, const GfxRadius& yradius) noexcept;
    void FillEllipse(const rect::GfxPoint& pt, const GfxRadius& xradius, const GfxRadius& yradius) noexcept;
    void FillPoly(const std::vector<rect::GfxPoint>& polypoints) noexcept;
    void FloodFill(const rect::GfxPoint& pt, const GfxColors2& border) noexcept;
    void FreeImage(void * bitmap) noexcept;
    const GfxArcCoordsType GetArcCoords(void) noexcept;
    const GfxColors2& GetBkColor(void) noexcept;
    const GfxColors2& GetColor(void) noexcept;
    const GfxPaletteType GetDefaultPalette(void) noexcept;
    void GetFillPattern(char * pattern) noexcept;
    const GfxFillSettingsType GetFillSettings(void) noexcept;
    void GetImage(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, void * bitmap) noexcept;
    void GetImage(const rect::GfxRect& r, void * bitmap) noexcept;
    const GfxLineSettingsType GetLineSettings(void) noexcept;
    int32_t GetMaxColor(void) noexcept;
    int32_t GetMaxX(void) noexcept;
    int32_t GetMaxY(void) noexcept;
    const GfxPaletteType GetPalette(void) noexcept;
    int32_t GetPaletteSize(void) noexcept;
    const GfxColors2& GetPixel(const rect::GfxPoint& pt) noexcept;
    const GfxTextSettingsType GetTextSettings(void) noexcept;
    const GfxViewPortType GetViewSettings(void) noexcept;
    int32_t GetX(void) noexcept;
    int32_t GetY(void) noexcept;
    void GraphDefaults(void) noexcept;
    uint32_t ImageSize(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept;
    uint32_t ImageSize(const rect::GfxRect& r) noexcept;
    void Line(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept;
    void LineRel(const rect::GfxPoint& pt) noexcept;
    void LineTo(const rect::GfxPoint& pt) noexcept;
    void MoveRel(const rect::GfxPoint& pt) noexcept;
    void MoveTo(const rect::GfxPoint& pt) noexcept;
    void OutText(const GfxText& text) noexcept;
    void OutText(const GfxText& text, const fnt::GfxBitmapFont& font) noexcept;
    void OutTextXY(const rect::GfxPoint& pt, const GfxText& text) noexcept;
    void OutTextXY(const rect::GfxPoint& pt, const GfxText& text, const fnt::GfxBitmapFont& font) noexcept;
    void PieSlice(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                  const GfxRadius& radius) noexcept;
    void PutImage(const rect::GfxPoint& pt, void * bitmap, const GfxDrawingMode& dmode) noexcept;
    void PutPixel(const rect::GfxPoint& pt, const GfxColors2& clr) noexcept;
    void Rectangle(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept;
    void Rectangle(const rect::GfxRect& r) noexcept;
    void Sector(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                const GfxRadius& xradius, const GfxRadius& yradius) noexcept;
    void SetAllPalette(const GfxPaletteType& palette) noexcept;
    void SetBkColor(const GfxColors2& clr) noexcept;
    void SetColor(const GfxColors2& clr) noexcept;
    void SetFillPattern(uint8_t * upattern, const GfxColors2& clr) noexcept;
    void SetFillStyle(const GfxFillStyles& pattern, const GfxColors2& clr) noexcept;
    void SetLineStyle(const GfxLineStyle& linestyle, const GfxFillStyles& upattern,
                      const GfxLineThickness& thickness) noexcept;
    void SetPalette(int32_t colornum, const GfxColors2& clr) noexcept;
    void SetTextJustify(const GfxTextJustification& horiz, const GfxTextJustification& vert) noexcept;
    void SetTextStyle(const GfxFonts& font, const GfxDirection& direction, int32_t charsize) noexcept;
    void SetUserCharSize(const int32_t multx, const int32_t divx, const int32_t multy, const int32_t divy) noexcept;
    void SetViewPort(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const bool clip) noexcept;
    void SetViewPort(const rect::GfxRect& r, const bool clip) noexcept;
    void SetWriteMode(const GfxDrawingMode& dmode) noexcept;
    int32_t TextHeight(const GfxText& textstring) noexcept;
    int32_t TextWidth(const GfxText& textstring) noexcept;
private:
    prv::GfxCanvasBgi bgi_;
    GfxColors2 prvColor_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxCanvas_hpp */
