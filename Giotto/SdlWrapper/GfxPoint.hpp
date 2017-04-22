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

#ifndef GfxPoint_hpp
#define GfxPoint_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxPoint final : public GfxRootClass
{
public:
    typedef SDL_Point SdlType;
    typedef SDL_Point* SdlTypePtr;
    
    GfxPoint();
    GfxPoint(const uint16_t x,const uint16_t y);
    GfxPoint(const SdlType pt);
    GfxPoint(const SdlTypePtr pt);
    GfxPoint(const GfxPoint& other);
    GfxPoint(GfxPoint&& other);

    GfxPoint& operator=(const GfxPoint& other);
    GfxPoint& operator=(GfxPoint&& other);

    bool operator==(const GfxPoint& other);

    /* Getters */
    int getX(void) const;
    int getY(void) const;
    
    /* Setters */
    void setX(const uint16_t x);
    void setY(const uint16_t y);
    
    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType pt_;
};


#endif /* GfxPoint_hpp */