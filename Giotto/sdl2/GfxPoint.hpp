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

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

namespace gfx
{

class GfxPoint final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Point SdlType;
    typedef sdl2::SDL_Point* SdlTypePtr;

    static const char ClassName[];

    GfxPoint();

    GfxPoint(const uint16_t x, const uint16_t y);
    explicit GfxPoint(const SdlType pt);

    GfxPoint(const GfxPoint& other);
    GfxPoint(GfxPoint&& other);

    GfxPoint& operator=(const GfxPoint& other);
    GfxPoint& operator=(GfxPoint&& other);

    bool operator==(const GfxPoint& other);

    virtual explicit operator bool() const;

    /* Getters */
    int getX(void) const;
    int getY(void) const;

    /* Setters */
    void setX(const uint16_t x);
    void setY(const uint16_t y);

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType pt_;
};

}  // namespace gfx

#endif /* GfxPoint_hpp */
