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

#ifndef GfxRect_hpp
#define GfxRect_hpp

#include <cstdint>
#include <string>
#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxBool.hpp"
#include "GfxPoint.hpp"

namespace gfx
{

namespace rect
{

class GfxRect final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Rect SdlType;
    typedef sdl2::SDL_Rect* SdlTypePtr;

    static const char ClassName[];

    GfxRect();

    GfxRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h);
    explicit GfxRect(const SdlType rect);

    GfxRect(GfxRect const& other);
    GfxRect(GfxRect&& other);

    GfxRect& operator=(GfxRect const& other);
    GfxRect& operator=(GfxRect&& other);

    bool operator==(GfxRect const& other);

    virtual explicit operator bool() const;

    int32_t getX(void) const;
    int32_t getY(void) const;
    int32_t getWidth(void) const;
    int32_t getHeight(void) const;

    void setX(const int32_t x);
    void setY(const int32_t y);
    void setWidth(const int32_t w);
    void setHeight(const int32_t h);
    void set(SdlType r);

    GfxBool pointInRect(GfxPoint const& p) const;
    GfxBool rectEmpty(void) const;
    GfxBool rectEquals(GfxRect const& r) const;
    GfxBool hasIntersection(GfxRect const& r) const;
    GfxBool intersectRect(GfxRect const &r, GfxRect * result) const;
    void unionRect(GfxRect const &r, GfxRect * result) const;
    GfxBool enclosePoint(std::vector<GfxPoint> const& points, GfxRect * result) const;
    GfxBool intersectRectAndLine(int32_t * x1, int32_t * y1, int32_t * x2, int32_t * y2) const;

    void clear(void);

    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr() const;
private:
    SdlType rect_;
};

}  // namespace rect

}  // namespace gfx

#endif /* GfxRect_hpp */
