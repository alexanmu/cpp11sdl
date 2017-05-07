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

#ifndef GfxSurface_hpp
#define GfxSurface_hpp

#include <string>
#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

#include "GfxPixelFormat.hpp"
#include "GfxRect.hpp"
#include "GfxColor.hpp"
#include "GfxSurfaceFlags.hpp"

class GfxCanvas;

class GfxSurface final : public GfxRootClass
{
public:
    typedef SDL_Surface SdlType;
    typedef SDL_Surface* SdlTypePtr;

    static const std::string ClassName;

    GfxSurface() = delete;

    explicit GfxSurface(const GfxSurfaceFlags& flags, const uint16_t w, const uint16_t h);
    explicit GfxSurface(const SdlTypePtr surf);
    explicit GfxSurface(const std::string& filename);

    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& surf);

    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& surf);

    virtual ~GfxSurface();

    int getWidth(void) const;
    int getHeight(void) const;
    int getDepth(void) const;

    GfxPixelFormat getFormat(void);

    void fillRect(const GfxRect& rect, const GfxColor& color);
    void fillRect(const GfxColor& color);

    void fillRects(const std::vector<GfxRect>& rects, const GfxColor& color);

    void blitSurface(const GfxSurface& src, const GfxRect& srcr, const GfxRect& dstr);
    void blitSurface(const GfxSurface& src);

    void putPixel(const uint16_t x, const uint16_t y, const GfxColor& clr);
    GfxColor getPixel(const uint16_t x, const uint16_t y);

    void destroySurface(void);

    /*SDL_Set{/Get}ColorKey(…)
    Set/Get RLE
    Set/Get ColorMod
    SDL_CreateRGBSurfaceFrom(…)*/

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    friend class GfxCanvas;

    void putPixelPrv(const uint16_t x, const uint16_t y, const GfxColor& clr);
    GfxColor getPixelPrv(const uint16_t x, const uint16_t y);

    SdlTypePtr surf_;
};

#endif /* GfxSurface_hpp */
