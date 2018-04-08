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
#include "GfxColor.hpp"

namespace gfx
{

namespace render
{

class GfxRenderer final : public GfxObject
{
public:
    typedef SDL_Renderer * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxRenderer();
    explicit GfxRenderer(std::string const& rendname, video::GfxWindow const& win, GfxRendererFlags const& flags)
                         throw(std::runtime_error);
    explicit GfxRenderer(std::string const& rendname, surface::GfxSurface const& surf) throw(std::runtime_error);

    GfxRenderer(GfxRenderer const&) = delete;
    GfxRenderer(GfxRenderer&& other) noexcept;
    GfxRenderer& operator=(GfxRenderer const&) = delete;
    GfxRenderer& operator=(GfxRenderer&& other) noexcept;

    virtual ~GfxRenderer() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createRenderer(std::string const& rendname, video::GfxWindow const& win, GfxRendererFlags const& flags)
                        throw(std::runtime_error);
    void createRenderer(std::string const& rendname, surface::GfxSurface const& surf) throw(std::runtime_error);

    SdlTypePtr getRenderer(video::GfxWindow const &win) const noexcept;
    GfxRendererInfo * getRendererInfo(void) const noexcept;
    void getRendererOutputSize(int32_t * w, int32_t * h) const noexcept;
    void setRenderTarget(GfxTexture const& tex) const noexcept;
    GfxTexture::SdlTypePtr getRenderTarget(void) const noexcept;
    void renderSetLogicalsSize(const int32_t w, const int32_t h) const noexcept;
    void renderGetLogicalSize(int32_t * w, int32_t * h) const noexcept;
    void renderSetIntegerScale(GfxBool const& enable) const noexcept;
    GfxBool renderGetIntegerScale(void) const noexcept;
    void renderSetViewport(rect::GfxRect const& rect) const noexcept;
    rect::GfxRect renderGetViewport(void) const noexcept;
    void renderSetClipRect(rect::GfxRect const& rect) const noexcept;
    rect::GfxRect renderGetClipRect(void) const noexcept;
    GfxBool renderIsClipEnabled(void) const noexcept;
    void renderSetScale(const float scaleX, const float scaleY) const noexcept;
    void renderGetScale(float * scaleX, float * scaleY) const noexcept;
    void setRenderDrawColor(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) const noexcept;
    void setRenderDrawColor(pixels::GfxColor const& color) const noexcept;
    void getRenderDrawColor(uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a) const noexcept;
    pixels::GfxColor getRenderDrawColor(void) const noexcept;
    void setRenderDrawBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept;
    blendmode::GfxBlendMode getRenderDrawBlendMode(void) const noexcept;
    void renderClear(void) const noexcept;
    void renderDrawPoint(const int32_t x, const int32_t y) const noexcept;
    void renderDrawPoint(rect::GfxPoint const& point) const noexcept;
    void renderDrawPoints(std::vector<rect::GfxPoint> const& points) const noexcept;
    void renderDrawLine(const int32_t x1, const int32_t y1, const int32_t x2,
                        const int32_t y2) const noexcept;
    void renderDrawLine(rect::GfxPoint const& pt1, rect::GfxPoint const& pt2) const noexcept;
    void renderDrawLines(std::vector<rect::GfxPoint> const& points) const noexcept;
    void renderDrawRect(rect::GfxRect const& rect) const noexcept;
    void renderDrawRects(std::vector<rect::GfxRect> const& rects) const noexcept;
    void renderFillRect(rect::GfxRect const& rect) const noexcept;
    void renderFillRects(std::vector<rect::GfxRect> const& rects) const noexcept;
    void renderCopy(GfxTexture const& tex, rect::GfxRect const& src, rect::GfxRect const& dest) const noexcept;
    void renderCopy(GfxTexture const& tex) const noexcept;
    void renderCopyEx(GfxTexture const& tex, rect::GfxRect const& src, rect::GfxRect const& dest,
                    const double angle, rect::GfxPoint const& pt, GfxRendererFlip const& flip) const noexcept;
    void renderCopyEx(GfxTexture const& tex, const double angle, rect::GfxPoint const& pt,
                      GfxRendererFlip const& flip) const noexcept;
    void renderReadPixels(rect::GfxRect const& rect, pixels::GfxPixelFormatEnum const& format,
                        void * pixels, const int32_t pitch) const noexcept;
    void renderPresent(void) const noexcept;
    void destroyRenderer(void) noexcept;
    void * getMetalLayer(void) const noexcept;
    void * getMetalCommandEncoder(void) const noexcept;

    SdlTypePtr getAsSdlTypePtr() const noexcept;
private:
    SdlTypePtr renderer_;
    std::string rendName_;

    static const pixels::GfxColor kDefaultRenderDrawColor;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxRenderer_hpp */
