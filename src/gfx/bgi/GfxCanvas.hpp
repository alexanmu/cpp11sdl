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

#include <string>

#include "GfxRootClass.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxSurface.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxPoint.hpp"
#include "GfxRect.hpp"
#include "GfxRadius.hpp"
#include "GfxAngle.hpp"
#include "GfxString.hpp"
#include "GfxBitmapFont.hpp"

namespace gfx
{
namespace bgi
{

class GfxCanvas final : public GfxRootClass
{
public:
    static const char ClassName[];

    GfxCanvas() = delete;
    explicit GfxCanvas(GfxSurface const& surf);

    GfxCanvas(GfxCanvas const&) = delete;
    GfxCanvas(GfxCanvas&&) = delete;

    GfxCanvas& operator=(GfxCanvas const&) = delete;
    GfxCanvas& operator=(GfxCanvas&&) = delete;

    virtual explicit operator bool() const;

    void Circle(const rect::GfxPoint& pt, const GfxRadius& r, const pixels::GfxColor& clr);
    void Arc(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
             const GfxRadius& radius, const pixels::GfxColor& clr);
    void OutText(const rect::GfxPoint& pt, const GfxString& text, const pixels::GfxColor& clr);
    void OutText(const rect::GfxPoint& pt, const GfxString& text, const pixels::GfxColor& clr,
                  const fnt::GfxBitmapFont& font);
    void Bar(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const pixels::GfxColor& clr);
    void Bar(const rect::GfxRect& r, const pixels::GfxColor& clr);
    void PutPixel(const rect::GfxPoint& pt, const pixels::GfxColor& clr);
    void Rect(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const pixels::GfxColor& clr);
    void Rect(const rect::GfxRect& r, const pixels::GfxColor& clr);
    void Line(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const pixels::GfxColor& clr);
private:
    GfxCanvasBgi bgi_;
};

}  // namespace bgi
}  // namespace gfx

#endif /* GfxCanvas_hpp */
