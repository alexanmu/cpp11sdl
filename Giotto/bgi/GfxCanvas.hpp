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

class GfxCanvas final : public GfxRootClass
{
public:
    GfxCanvas() = delete;
    GfxCanvas(GfxSurface& surf);

    void Circle(const GfxPoint& pt, const GfxRadius& r, const GfxColor& clr);
    void Arc(const GfxPoint& pt, const GfxAngle& stangle,const GfxAngle& endangle,const GfxRadius& radius,const GfxColor& clr);
    void OutText(const GfxPoint& pt,const GfxString& text,const GfxColor& clr);
    void OutText(const GfxPoint& pt,const GfxString& text,const GfxColor& clr,const GfxBitmapFont& font);
    void Bar(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr);
    void Bar(const GfxRect& r, const GfxColor& clr);
    void PutPixel(const GfxPoint& pt, const GfxColor& clr);
    void Rect(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr);
    void Rect(const GfxRect& r, const GfxColor& clr);
    void Line(const GfxPoint& pt1, const GfxPoint& pt2, const GfxColor& clr);
private:
    GfxCanvasBgi bgi_;
    GfxSurface& surf_;
};

#endif /* GfxCanvas_hpp */
