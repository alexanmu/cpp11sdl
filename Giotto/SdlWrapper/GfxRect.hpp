/*
  CPP11SDL
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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxRect final : public GfxRootClass
{
public:
    typedef SDL_Rect SdlType;
    typedef SDL_Rect* SdlTypePtr;
    
    GfxRect();
    GfxRect(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h);
    GfxRect(SdlType rect);
    GfxRect(SdlTypePtr rect);
    GfxRect(const GfxRect& other);
    GfxRect(GfxRect&& other);

    GfxRect& operator=(const GfxRect& other);
    GfxRect& operator=(GfxRect&& other);

    bool operator==(const GfxRect& other);

    uint16_t getX(void) const;
    uint16_t getY(void) const;
    uint16_t getWidth(void) const;
    uint16_t getHeight(void) const;
    
    void setX(const uint16_t x);
    void setY(const uint16_t y);
    void setWidth(const uint16_t w);
    void setHeight(const uint16_t h);
    
    SdlType getAsSdlType() const;
    SdlTypePtr getAsSdlTypePtr() const;
private:
    SDL_Rect rect_;
};

#endif /* GfxRect_hpp */
