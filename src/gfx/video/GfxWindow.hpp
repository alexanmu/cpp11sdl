/*
  Giotto
  Copyright (C) 2019 George Oros

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
#include "GfxPixelFormatEnum.hpp"

namespace gfx
{

namespace video
{

class GfxWindow final : public GfxObject
{
public:
    typedef SDL_Window * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxWindow() noexcept;
    GfxWindow(const std::string& title, const int32_t width, const int32_t height) throw(std::runtime_error);
    GfxWindow(const std::string& title, const int32_t width, const int32_t height,
              const GfxWindowFlags& flags) throw(std::runtime_error);
    GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
              const int32_t width, const int32_t height, const GfxWindowFlags& flags) throw(std::runtime_error);
    explicit GfxWindow(const void * data) throw(std::runtime_error);

    GfxWindow(const GfxWindow&) = delete;
    GfxWindow(GfxWindow&& other) noexcept;

    GfxWindow& operator=(const GfxWindow&) = delete;
    GfxWindow& operator=(GfxWindow&& other) noexcept;

    virtual ~GfxWindow() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createWindow(const std::string& title, const int32_t width, const int32_t height) throw(std::runtime_error);
    void createWindow(const std::string& title, const int32_t width, const int32_t height,
                      const GfxWindowFlags& flags) throw(std::runtime_error);
    void createWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                      const int32_t width, const int32_t height, const GfxWindowFlags& flags) throw(std::runtime_error);
    void createWindow(const void * data) throw(std::runtime_error);
    void destroyWindow(void) noexcept;

    int32_t getWindowDisplayIndex(void) const noexcept;
    const GfxDisplayMode getWindowDisplayMode(void) const noexcept;
    const pixels::GfxPixelFormatEnum getWindowPixelFormat(void) const noexcept;

    uint32_t getWindowID(void) const noexcept;
    const GfxWindow * getWindowFromID(const uint32_t id) const noexcept;
    const GfxWindowFlags getWindowFlags(void) const noexcept;
    void setWindowTitle(const std::string& title) noexcept;
    const std::string getWindowTitle(void) const noexcept;
    void setWindowIcon(const surface::GfxSurface& icon) noexcept;
    void * setWindowData(const std::string& name, void * userdata) const noexcept;
    void * getWindowData(const std::string& name) const noexcept;
    void setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y) noexcept;
    void getWindowPosition(GfxWindowPosition * x, GfxWindowPosition * y) noexcept;
    void setWindowSize(const int32_t w, const int32_t h) const noexcept;
    void getWindowSize(int32_t * pw, int32_t * ph) const noexcept;
    void getWindowBordersSize(int32_t * top, int32_t * left, int32_t * bottom, int32_t * right) const noexcept;
    void setWindowMinimumSize(const int32_t min_w, const int32_t min_h) const noexcept;
    void getWindowMinimumSize(int32_t * min_w, int32_t * min_h) const noexcept;
    void setWindowMaximumSize(const int32_t max_w, const int32_t max_h) const noexcept;
    void getWindowMaximumSize(int32_t * max_w, int32_t * max_h) const noexcept;
    void setWindowBordered(const GfxBool& bordered) const noexcept;
    void setWindowResizable(const GfxBool& resizable) const noexcept;
    void showWindow(void) const noexcept;
    void hideWindow(void) const noexcept;
    void raiseWindow(void) const noexcept;
    void maximizeWindow(void) const noexcept;
    void minimizeWindow(void) const noexcept;
    void restoreWindow(void) const noexcept;
    void setWindowFullscreen(const GfxWindowFlags& flags) const noexcept;
    const surface::GfxSurface& getWindowSurface(void) throw(std::runtime_error);
    void updateWindowSurface(void) const noexcept;
    void updateWindowSurfaceRects(const std::vector<gfx::rect::GfxRect>& vec) const throw(std::runtime_error);
    void setWindowGrab(const GfxBool& grabbed) const noexcept;
    const GfxBool getWindowGrab(void) const noexcept;
    const GfxWindow * getGrabbedWindow(void) const noexcept;
    void setWindowBrightness(const float brightness) const noexcept;
    float getWindowBrightness(void) const noexcept;
    void setWindowOpacity(const float opacity) const noexcept;
    float getWindowOpacity(void) const noexcept;
    void setWindowModalFor(const GfxWindow& modal_window) const noexcept;
    void setWindowInputFocus(void) const noexcept;
    void setWindowGammaRamp(const xtra::GfxGammaRamp& red, const xtra::GfxGammaRamp& green,
                            const xtra::GfxGammaRamp& blue) const noexcept;
    void getWindowGammaRamp(xtra::GfxGammaRamp * red, xtra::GfxGammaRamp * green,
                            xtra::GfxGammaRamp * blue) const noexcept;
    void setWindowHitTest(const GfxHitTest& callback) const noexcept;

    int32_t getWidth() const noexcept;
    int32_t getHeight() const noexcept;

    SdlTypePtr getAsSdlTypePtr() const noexcept;
private:
    void freeResources(void) noexcept;
    // Will be called from C by SDL
    static SDL_HitTestResult windowHitTestFunction(SDL_Window * win,
                                                   const SDL_Point * area, void * data);

    static const int32_t kDefaultWindowPositionX = 100;
    static const int32_t kDefaultWindowPositionY = 100;
    static const int32_t kDefaultFlagsValue = 0;

    SdlTypePtr window_;
    surface::GfxSurface * winSurface_;
    mutable GfxHitTest * hitTest_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindow_hpp */
