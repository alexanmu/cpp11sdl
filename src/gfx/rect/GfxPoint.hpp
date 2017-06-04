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

#ifndef GfxPoint_hpp
#define GfxPoint_hpp

#include <cstdint>
#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

namespace gfx
{

namespace rect
{

class GfxPoint final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Point SdlType;
    typedef sdl2::SDL_Point* SdlTypePtr;

    static const char ClassName[];

    GfxPoint() noexcept;

    GfxPoint(const int32_t x, const int32_t y) noexcept;
    explicit GfxPoint(const SdlType pt) noexcept;

    GfxPoint(GfxPoint const& other) noexcept;
    GfxPoint(GfxPoint&& other) noexcept;

    GfxPoint& operator=(GfxPoint const& other) noexcept;
    GfxPoint& operator=(GfxPoint&& other) noexcept;

    bool operator==(GfxPoint const& other) const noexcept;

    virtual explicit operator bool() const noexcept;

    /* Getters */
    int32_t getX(void) const noexcept;
    int32_t getY(void) const noexcept;

    /* Setters */
    void setX(const int32_t x) noexcept;
    void setY(const int32_t y) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType pt_;
};

}  // namespace rect

}  // namespace gfx

#endif /* GfxPoint_hpp */
