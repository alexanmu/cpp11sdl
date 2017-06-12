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

#ifndef GfxRenderer_hpp
#define GfxRenderer_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

#include "GfxWindow.hpp"
#include "GfxRect.hpp"
#include "GfxPoint.hpp"
#include "GfxRendererFlip.hpp"
#include "GfxTexture.hpp"
#include "GfxRendererInfo.hpp"
#include "GfxRendererFlags.hpp"
#include "GfxSurface.hpp"
#include "GfxPixelFormatEnum.hpp"

namespace gfx
{

namespace render
{

class GfxRenderer final : public GfxObject
{
public:
    typedef sdl2::SDL_Renderer* SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;

    explicit GfxRenderer(video::GfxWindow const& win, GfxRendererFlags const& flags) throw(std::runtime_error);
    explicit GfxRenderer(surface::GfxSurface const& surf) throw(std::runtime_error);

    GfxRenderer() = delete;
    GfxRenderer(const GfxRenderer&) = delete;
    GfxRenderer(GfxRenderer&&) = delete;
    GfxRenderer& operator=(const GfxRenderer&) = delete;
    GfxRenderer& operator=(GfxRenderer&& rend) = delete;

    virtual ~GfxRenderer() noexcept;

    virtual explicit operator bool() const noexcept;

    SdlTypePtr getRenderer(video::GfxWindow const &win) const noexcept;
    GfxRendererInfo * getRendererInfo(void) const noexcept;
    void getRendererOutputSize(int32_t * w, int32_t * h) const noexcept;
    /* Todo */void setRenderTarget(GfxTexture const& tex) const noexcept;
    /* Todo */GfxTexture::SdlTypePtr getRenderTarget(void) const noexcept;
    /* Todo */void renderSetLogicalsSize(const int32_t w, const int32_t h) const noexcept;
    /* Todo */void renderGetLogicalSize(int32_t * w, int32_t * h) const noexcept;
    /* Todo */void renderSetIntegerScale(GfxBool const& enable) const noexcept;
    /* Todo */GfxBool renderGetIntegerScale(void) const noexcept;
    /* Todo */void renderSetViewport(rect::GfxRect const& rect) const noexcept;
    /* Todo */rect::GfxRect renderGetViewport(void) const noexcept;
    /* Todo */void renderSetClipRect(rect::GfxRect const& rect) const noexcept;
    /* Todo */rect::GfxRect renderGetClipRect(void) const noexcept;
    /* Todo */GfxBool renderIsClipEnabled(void) const noexcept;
    /* Todo */void renderSetScale(const float scaleX, const float scaleY) const noexcept;
    /* Todo */void renderGetScale(float * scaleX, float * scaleY) const noexcept;
    /* Todo */void renderSetDrawColor(const uint8_t r, const uint8_t g, const uint8_t b) const noexcept;
    /* Todo */void renderGetDrawColor(uint8_t * r, uint8_t * g, uint8_t * b) const noexcept;
    /* Todo */void setRenderDrawBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept;
    void renderClear(void) const noexcept;
    /* Todo */void renderDrawPoint(const int32_t x, const int32_t y) const noexcept;
    /* Todo */void renderDrawPoints(std::vector<rect::GfxPoint> const& points) const noexcept;
    /* Todo */void renderDrawLine(const int32_t x1, const int32_t y1, const int32_t x2,
                                    const int32_t y2) const noexcept;
    /* Todo */void renderDrawLines(std::vector<rect::GfxPoint> const& points) const noexcept;
    /* Todo */void renderDrawRect(rect::GfxRect const& rect) const noexcept;
    /* Todo */void renderDrawRects(std::vector<rect::GfxRect> const& rects) const noexcept;
    /* Todo */void renderFillRect(rect::GfxRect const& rect) const noexcept;
    /* Todo */void renderFillRects(std::vector<rect::GfxRect> const& rects) const noexcept;
    void renderCopy(GfxTexture const& tex, rect::GfxRect const& src, rect::GfxRect const& dest) const noexcept;
    void renderCopy(GfxTexture const& tex) const noexcept;
    void renderCopyEx(GfxTexture const& tex, rect::GfxRect const& src, rect::GfxRect const& dest,
                    const double angle, rect::GfxPoint const& pt, GfxRendererFlip const& flip) const noexcept;
    void renderCopyEx(GfxTexture const& tex, const double angle, rect::GfxPoint const& pt,
                        GfxRendererFlip const& flip) const noexcept;
    /* Todo */void renderReadPixels(rect::GfxRect const& rect, pixels::GfxPixelFormatEnum const& format,
                    void * pixels, const int32_t pitch) const noexcept;
    void renderPresent(void) const noexcept;
    void destroyRenderer(void) noexcept;

    SdlTypePtr getAsSdlTypePtr() const noexcept;
private:
    SdlTypePtr renderer_;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxRenderer_hpp */
