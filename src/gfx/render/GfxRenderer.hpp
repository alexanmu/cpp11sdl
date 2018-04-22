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
    explicit GfxRenderer(const std::string& rendname, const video::GfxWindow& win, const GfxRendererFlags& flags)
                         throw(std::runtime_error);
    explicit GfxRenderer(const std::string& rendname, const surface::GfxSurface& surf) throw(std::runtime_error);

    GfxRenderer(const GfxRenderer&) = delete;
    GfxRenderer(GfxRenderer&& other) noexcept;
    GfxRenderer& operator=(const GfxRenderer&) = delete;
    GfxRenderer& operator=(GfxRenderer&& other) noexcept;

    virtual ~GfxRenderer() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createRenderer(const std::string& rendname, const video::GfxWindow& win, const GfxRendererFlags& flags)
                        throw(std::runtime_error);
    void createRenderer(const std::string& rendname, const surface::GfxSurface& surf) throw(std::runtime_error);

    SdlTypePtr getRenderer(const video::GfxWindow& win) const noexcept;
    const GfxRendererInfo getRendererInfo(void) const noexcept;
    void getRendererOutputSize(int32_t * w, int32_t * h) const noexcept;
    void setRenderTarget(const GfxTexture& tex) const noexcept;
    GfxTexture::SdlTypePtr getRenderTarget(void) const noexcept;
    void renderSetLogicalsSize(const int32_t w, const int32_t h) const noexcept;
    void renderGetLogicalSize(int32_t * w, int32_t * h) const noexcept;
    void renderSetIntegerScale(const GfxBool& enable) const noexcept;
    const GfxBool renderGetIntegerScale(void) const noexcept;
    void renderSetViewport(const rect::GfxRect& rect) const noexcept;
    const rect::GfxRect renderGetViewport(void) const noexcept;
    void renderSetClipRect(const rect::GfxRect& rect) const noexcept;
    const rect::GfxRect renderGetClipRect(void) const noexcept;
    const GfxBool renderIsClipEnabled(void) const noexcept;
    void renderSetScale(const float scaleX, const float scaleY) const noexcept;
    void renderGetScale(float * scaleX, float * scaleY) const noexcept;
    void setRenderDrawColor(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) const noexcept;
    void setRenderDrawColor(const pixels::GfxColor& color) const noexcept;
    void getRenderDrawColor(uint8_t * r, uint8_t * g, uint8_t * b, uint8_t * a) const noexcept;
    const pixels::GfxColor getRenderDrawColor(void) const noexcept;
    void setRenderDrawBlendMode(const blendmode::GfxBlendMode& blendmode) const noexcept;
    const blendmode::GfxBlendMode getRenderDrawBlendMode(void) const noexcept;
    void renderClear(void) const noexcept;
    void renderDrawPoint(const int32_t x, const int32_t y) const noexcept;
    void renderDrawPoint(const rect::GfxPoint& point) const noexcept;
    void renderDrawPoints(const std::vector<rect::GfxPoint>& points) const noexcept;
    void renderDrawLine(const int32_t x1, const int32_t y1, const int32_t x2,
                        const int32_t y2) const noexcept;
    void renderDrawLine(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) const noexcept;
    void renderDrawLines(const std::vector<rect::GfxPoint>& points) const noexcept;
    void renderDrawRect(const rect::GfxRect& rect) const noexcept;
    void renderDrawRects(const std::vector<rect::GfxRect>& rects) const noexcept;
    void renderFillRect(const rect::GfxRect& rect) const noexcept;
    void renderFillRects(const std::vector<rect::GfxRect>& rects) const noexcept;
    void renderCopy(const GfxTexture& tex, const rect::GfxRect& src, const rect::GfxRect& dest) const noexcept;
    void renderCopy(const GfxTexture& tex) const noexcept;
    void renderCopyEx(const GfxTexture& tex, const rect::GfxRect& src, const rect::GfxRect& dest,
                    const double angle, const rect::GfxPoint& pt, const GfxRendererFlip& flip) const noexcept;
    void renderCopyEx(const GfxTexture& tex, const double angle, const rect::GfxPoint& pt,
                      const GfxRendererFlip& flip) const noexcept;
    void renderReadPixels(const rect::GfxRect& rect, const pixels::GfxPixelFormatEnum& format,
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
