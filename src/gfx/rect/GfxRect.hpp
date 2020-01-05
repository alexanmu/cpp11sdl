/*
  Giotto
  Copyright (C) 2020 George Oros

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

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxPoint.hpp"

namespace gfx
{

namespace rect
{

class GfxRect final : public GfxObject
{
public:
    typedef SDL_Rect SdlType;
    typedef SDL_Rect * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxRect() noexcept;
    GfxRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h) noexcept;
    explicit GfxRect(const SdlType rect) noexcept;

    GfxRect(const GfxRect& other) noexcept;
    GfxRect(GfxRect&& other) noexcept;

    GfxRect& operator=(const GfxRect& other) noexcept;
    GfxRect& operator=(GfxRect&& other) noexcept;

    bool operator==(const GfxRect& other) const noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t getX(void) const noexcept;
    int32_t getY(void) const noexcept;
    int32_t getWidth(void) const noexcept;
    int32_t getHeight(void) const noexcept;

    void setX(const int32_t x) noexcept;
    void setY(const int32_t y) noexcept;
    void setWidth(const int32_t w) noexcept;
    void setHeight(const int32_t h) noexcept;

    const GfxBool pointInRect(const GfxPoint& p) const noexcept;
    const GfxBool rectEmpty(void) const noexcept;
    const GfxBool rectEquals(const GfxRect& r) const noexcept;
    const GfxBool hasIntersection(const GfxRect& r) const noexcept;
    const GfxBool intersectRect(const GfxRect &r, GfxRect ** result) const noexcept;
    void unionRect(const GfxRect &r, GfxRect ** result) const noexcept;
    const GfxBool enclosePoint(const std::vector<GfxPoint>& points, GfxRect ** result) const noexcept;
    const GfxBool intersectRectAndLine(int32_t * x1, int32_t * y1, int32_t * x2, int32_t * y2) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType() const noexcept;
    SdlTypePtr getAsSdlTypePtr() const noexcept;
private:
    SdlType rect_;
};

}  // namespace rect

}  // namespace gfx

#endif /* GfxRect_hpp */
