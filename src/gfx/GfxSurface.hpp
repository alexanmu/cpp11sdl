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

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

#include "GfxPixelFormat.hpp"
#include "GfxRect.hpp"
#include "GfxColor.hpp"
#include "GfxSurfaceFlags.hpp"

namespace gfx
{

class GfxSurface final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Surface SdlType;
    typedef sdl2::SDL_Surface* SdlTypePtr;

    static const char ClassName[];

    GfxSurface() = delete;

    explicit GfxSurface(const GfxSurfaceFlags& flags, const int32_t w, const int32_t h) throw(std::runtime_error);
    explicit GfxSurface(const SdlTypePtr surf) throw(std::runtime_error);
    explicit GfxSurface(const std::string& filename) throw(std::runtime_error);
    explicit GfxSurface(void * pixels, const int32_t width, const int32_t height, const int32_t depth,
                        const int32_t pitch, const uint32_t rmask, const uint32_t gmask, const uint32_t bmask,
                        const uint32_t amask) throw(std::runtime_error);
    GfxSurface(const GfxSurface&) = delete;
    GfxSurface(GfxSurface&& surf);

    GfxSurface& operator=(const GfxSurface&) = delete;
    GfxSurface& operator=(GfxSurface&& surf);

    virtual ~GfxSurface();

    virtual explicit operator bool() const;

    int32_t getWidth(void) const;
    int32_t getHeight(void) const;
    int32_t getDepth(void) const;

    pixels::GfxPixelFormat * getFormat(void);

    void fillRect(const GfxRect& rect, const GfxColor& color);
    void fillRect(const GfxColor& color);

    void fillRects(const std::vector<GfxRect>& rects, const GfxColor& color);

    void blitSurface(const GfxSurface& src, const GfxRect& srcr, const GfxRect& dstr);
    void blitSurface(const GfxSurface& src);

    void blitScaled(const GfxSurface& src, const GfxRect& srcr, const GfxRect& dstr);

    void putPixel(const int32_t x, const int32_t y, const GfxColor& clr);
    GfxColor getPixel(const int32_t x, const int32_t y);

    void destroySurface(void);

    /*SDL_Set{/Get}ColorKey(…)
    Set/Get RLE
    Set/Get ColorMod
    SDL_CreateRGBSurfaceFrom(…)*/

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    void putPixelPrv(const int32_t x, const int32_t y, const GfxColor& clr);
    GfxColor getPixelPrv(const int32_t x, const int32_t y);

    SdlTypePtr surf_;
};

}  // namespace gfx

#endif /* GfxSurface_hpp */
