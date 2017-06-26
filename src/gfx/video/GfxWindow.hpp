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

#ifndef GfxWindow_hpp
#define GfxWindow_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxDisplayMode.hpp"
#include "GfxBool.hpp"
#include "GfxHitTestResult.hpp"
#include "GfxPoint.hpp"
#include "GfxGammaRamp.hpp"
#include "GfxHitTest.hpp"

namespace gfx
{

namespace video
{

class GfxWindow final : public GfxObject
{
public:
    typedef sdl2::SDL_Window * SdlTypePtr;

    typedef uint32_t fullscreenflags_t;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxWindow(std::string const& title, const int32_t width, const int32_t height) throw(std::runtime_error);
    GfxWindow(std::string const& title, const int32_t width, const int32_t height,
            GfxWindowFlags const& flags) throw(std::runtime_error);
    GfxWindow(std::string const& title, GfxWindowPosition const& x, GfxWindowPosition const& y,
                const int32_t width, const int32_t height, GfxWindowFlags const& flags) throw(std::runtime_error);
    explicit GfxWindow(void * data) throw(std::runtime_error);

    GfxWindow() = delete;
    GfxWindow(GfxWindow const&) = delete;
    GfxWindow(GfxWindow&&) = delete;
    GfxWindow& operator=(GfxWindow const&) = delete;
    GfxWindow& operator=(GfxWindow&&) = delete;

    virtual ~GfxWindow() noexcept;
    void destroyWindow(void) noexcept;

    virtual explicit operator bool() const noexcept;

    int32_t getWindowDisplayIndex(void) const noexcept;
    GfxDisplayMode * getWindowDisplayMode(void) const noexcept;
    uint32_t getWindowPixelFormat(void) const noexcept;

    uint32_t getWindowID(void) const noexcept;
    GfxWindow const * getWindowFromID(const uint32_t id) const noexcept;
    GfxWindowFlags * getWindowFlags(void) const noexcept;
    void setWindowTitle(std::string const& title) noexcept;
    std::string getWindowTitle(void) const noexcept;
    void setWindowIcon(surface::GfxSurface const& icon) noexcept;
    void * setWindowData(std::string const& name, void * userdata) const noexcept;
    void * getWindowData(std::string const& name) const noexcept;
    void setWindowPosition(GfxWindowPosition const& x, GfxWindowPosition const& y) noexcept;
    void getWindowPosition(GfxWindowPosition * x, GfxWindowPosition * y) noexcept;
    void setWindowSize(const int32_t w, const int32_t h) const noexcept;
    void getWindowSize(int32_t * pw, int32_t * ph) const noexcept;
    void getWindowBordersSize(int32_t * top, int32_t * left, int32_t * bottom, int32_t * right) const noexcept;
    void setWindowMinimumSize(const int32_t min_w, const int32_t min_h) const noexcept;
    void getWindowMinimumSize(int32_t * w, int32_t * h) const noexcept;
    void setWindowMaximumSize(const int32_t max_w, const int32_t max_h) const noexcept;
    void getWindowMaximumSize(int32_t * w, int32_t * h) const noexcept;
    void setWindowBordered(GfxBool const& bordered) const noexcept;
    void setWindowResizable(GfxBool const& resizable) const noexcept;
    void showWindow(void) const noexcept;
    void hideWindow(void) const noexcept;
    void raiseWindow(void) const noexcept;
    void maximizeWindow(void) const noexcept;
    void minimizeWindow(void) const noexcept;
    void restoreWindow(void) const noexcept;
    void setWindowFullscreen(const fullscreenflags_t flags) const noexcept;
    surface::GfxSurface * getWindowSurface(void) const noexcept;
    void updateWindowSurface(void) const noexcept;
    void updateWindowSurfaceRects(std::vector<gfx::rect::GfxRect> const& vec) const noexcept;
    void setWindowGrab(GfxBool const& grabbed) const noexcept;
    GfxBool getWindowGrab(void) const noexcept;
    GfxWindow const * getGrabbedWindow(void) const noexcept;
    void setWindowBrightness(const float brightness) const noexcept;
    float getWindowBrightness(void) const noexcept;
    void setWindowOpacity(const float opacity) const noexcept;
    float getWindowOpacity(void) const noexcept;
    void setWindowModalFor(GfxWindow const& modal_window) const noexcept;
    void setWindowInputFocus(void) const noexcept;
    void setWindowGammaRamp(xtra::GfxGammaRamp const& red, xtra::GfxGammaRamp const& green,
                            xtra::GfxGammaRamp const& blue) const noexcept;
    void getWindowGammaRamp(xtra::GfxGammaRamp * red, xtra::GfxGammaRamp * green,
                            xtra::GfxGammaRamp * blue) const noexcept;
    void setWindowHitTest(GfxHitTest const& callback, void * callback_data) const noexcept;

    int32_t getWidth() const noexcept;
    int32_t getHeight() const noexcept;

    SdlTypePtr getAsSdlTypePtr() const noexcept;
private:
    static const int32_t kDefaultWindowPositionX = 100;
    static const int32_t kDefaultWindowPositionY = 100;
    static const int32_t kDefaultFlagsValue = 0;

    SdlTypePtr window_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindow_hpp */
