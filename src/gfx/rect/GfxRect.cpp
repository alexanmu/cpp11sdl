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
#include <cstdlib>
#include <string>
#include <vector>

#include "GfxRect.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxrect::rect::gfx");

namespace gfx
{

namespace rect
{

const char GfxRect::ClassName[] = "GfxRect";

GfxRect::GfxRect() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    rect_.x = -1;
    rect_.y = -1;
    rect_.w = -1;
    rect_.h = -1;
}

GfxRect::GfxRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(x >= 0);
    assert(y >= 0);
    assert(w >= 0);
    assert(h >= 0);

    rect_.x = x;
    rect_.y = y;
    rect_.w = w;
    rect_.h = h;
}

GfxRect::GfxRect(const SdlType rect) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    rect_ = rect;
}

GfxRect::GfxRect(GfxRect const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    rect_ = other.rect_;
}

GfxRect::GfxRect(GfxRect&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    rect_ = other.rect_;
    // Delete other's data
    other.clear();
}

GfxRect& GfxRect::operator=(GfxRect const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        rect_ = other.rect_;
    }
    return *this;
}

GfxRect& GfxRect::operator=(GfxRect&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        rect_ = other.rect_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxRect::operator==(GfxRect const& other) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ((rect_.x == other.rect_.x) && (rect_.y == other.rect_.y) &&
            (rect_.w == other.rect_.w) && (rect_.h == other.rect_.h));
}

GfxRect::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxRect::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxRect::getX(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rect_.x;
}

int32_t GfxRect::getY(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rect_.y;
}

int32_t GfxRect::getWidth(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rect_.w;
}

int32_t GfxRect::getHeight(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rect_.h;
}

void GfxRect::setX(const int32_t x) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x >= 0);

    rect_.x = x;
}

void GfxRect::setY(const int32_t y) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(y >= 0);

    rect_.y = y;
}

void GfxRect::setWidth(const int32_t w) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(w >= 0);

    rect_.w = w;
}

void GfxRect::setHeight(const int32_t h) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(h >= 0);

    rect_.h = h;
}

void GfxRect::set(const SdlType r) noexcept
{
    LOG_TRACE_PRIO_LOW();

    rect_ = r;
};

GfxBool GfxRect::pointInRect(GfxPoint const& p) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(p);

    bool res;

    res = sdl2::SDL_PointInRect(p.getAsSdlTypePtr(), &rect_);
    return GfxBool(res);
}

GfxBool GfxRect::rectEmpty(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    bool res;

    res = sdl2::SDL_RectEmpty(&rect_);
    return GfxBool(res);
}

GfxBool GfxRect::rectEquals(GfxRect const& r) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(r);

    bool res;

    res = sdl2::SDL_RectEquals(r.getAsSdlTypePtr(), &rect_);
    return GfxBool(res);
}

GfxBool GfxRect::hasIntersection(GfxRect const& r) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(r);

    bool res;

    res = sdl2::SDL_HasIntersection(r.getAsSdlTypePtr(), &rect_);
    return GfxBool(res);
}

GfxBool GfxRect::intersectRect(GfxRect const &r, GfxRect ** result) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(r);
    assert(result == nullptr);

    bool res;
    GfxRect::SdlType rt;

    res = sdl2::SDL_IntersectRect(r.getAsSdlTypePtr(), &rect_, &rt);
    *result = new GfxRect(rt);
    return GfxBool(res);
}

void GfxRect::unionRect(GfxRect const &r, GfxRect ** result) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(r);
    assert(result == nullptr);

    GfxRect::SdlType rt;
    sdl2::SDL_UnionRect(r.getAsSdlTypePtr(), &rect_, &rt);
    *result = new GfxRect(rt);
}

GfxBool GfxRect::enclosePoint(std::vector<GfxPoint> const& points, GfxRect ** result) const noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(points.size() > 0);
    assert(result == nullptr);

    GfxPoint::SdlType ptarr[points.size()]; // NOLINT
    int32_t ptcount;
    int32_t index;
    GfxRect::SdlType rt;
    bool res;

    ptcount = static_cast<int32_t>(points.size());
    index = 0;
    for (auto& it : points)
    {
        ptarr[index] = it.getAsSdlType();
        index += 1;
    }
    res = sdl2::SDL_EnclosePoints(&ptarr[0], ptcount, &rect_, &rt);
    *result = new GfxRect(rt);
    return GfxBool(res);
}

GfxBool GfxRect::intersectRectAndLine(int32_t * x1, int32_t * y1, int32_t * x2, int32_t * y2) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(y1 != nullptr);
    assert(y2 != nullptr);

    bool res;

    res = sdl2::SDL_IntersectRectAndLine(&rect_, x1, y1, x2, y2);
    return GfxBool(res);
}

void GfxRect::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    rect_.x = -1;
    rect_.y = -1;
    rect_.w = -1;
    rect_.h = -1;
}

GfxRect::SdlType GfxRect::getAsSdlType() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return rect_;
}

GfxRect::SdlTypePtr GfxRect::getAsSdlTypePtr() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (SdlTypePtr)&rect_;
}

}  // namespace rect

}  // namespace gfx

/* EOF */
