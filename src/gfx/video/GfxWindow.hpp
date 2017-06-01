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

#include <cstdint>
#include <string>
#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxSurface.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxDisplayMode.hpp"
#include "GfxBool.hpp"
#include "GfxHitTestResult.hpp"
#include "GfxPoint.hpp"
#include "GfxGammaRamp.hpp"

namespace gfx
{

namespace video
{

class GfxWindow final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Window SdlType;
    typedef sdl2::SDL_Window* SdlTypePtr;

    typedef uint32_t fullscreenflags_t;
    typedef std::vector<gfx::GfxRect> GfxRectVector;
    typedef gfx::video::GfxHitTestResult (*GfxHitTest)(gfx::GfxPoint * area, void * data);

    static const char ClassName[];

    GfxWindow(const std::string& title, const int32_t width, const int32_t height);
    GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                const int32_t width, const int32_t height, const GfxWindowFlags& flags);
    explicit GfxWindow(void * data);

    GfxWindow() = delete;
    GfxWindow(const GfxWindow&) = delete;
    GfxWindow(GfxWindow&&) = delete;
    GfxWindow& operator=(const GfxWindow&) = delete;
    GfxWindow& operator=(GfxWindow&&) = delete;

    virtual ~GfxWindow();
    void destroyWindow(void);

    virtual explicit operator bool() const;

    int32_t getWindowDisplayIndex(void) const;
    GfxDisplayMode * getWindowDisplayMode(void) const;
    uint32_t getWindowPixelFormat(void) const;

    uint32_t getWindowID(void) const;
    GfxWindow const * getWindowFromID(const uint32_t id) const;
    GfxWindowFlags * getWindowFlags(void) const;
    void setWindowTitle(const std::string& title);
    std::string getWindowTitle() const;
    void setWindowIcon(GfxSurface const& icon);
    void * setWindowData(std::string const& name, void * userdata) const;
    void * getWindowData(std::string const& name) const;
    void setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y);
    void getWindowPosition(GfxWindowPosition * x, GfxWindowPosition * y);
    void setWindowSize(const int32_t w, const int32_t h) const;
    void getWindowSize(int32_t * pw, int32_t * ph) const;
    void getWindowBordersSize(int32_t * top, int32_t * left, int32_t * bottom, int32_t * right) const;
    void setWindowMinimumSize(const int32_t min_w, const int32_t min_h) const;
    void getWindowMinimumSize(int32_t * w, int32_t * h) const;
    void setWindowMaximumSize(const int32_t max_w, const int32_t max_h) const;
    void getWindowMaximumSize(int32_t * w, int32_t * h) const;
    void setWindowBordered(GfxBool const& bordered) const;
    void setWindowResizable(GfxBool const& resizable) const;
    void showWindow(void) const;
    void hideWindow(void) const;
    void raiseWindow(void) const;
    void maximizeWindow(void) const;
    void minimizeWindow(void) const;
    void restoreWindow(void) const;
    void setWindowFullscreen(const fullscreenflags_t flags) const;
    GfxSurface * getWindowSurface(void);
    void updateWindowSurface(void);
    void updateWindowSurfaceRects(GfxRectVector vec) const;
    void setWindowGrab(GfxBool const& grabbed) const;
    GfxBool getWindowGrab(void) const;
    GfxWindow const * getGrabbedWindow(void) const;
    void setWindowBrightness(const float brightness) const;
    float getWindowBrightness(void) const;
    void setWindowOpacity(const float opacity) const;
    float getWindowOpacity(void) const;
    void setWindowModalFor(GfxWindow const& modal_window) const;
    void setWindowInputFocus(void) const;
    void setWindowGammaRamp(supp::GfxGammaRamp const& red, supp::GfxGammaRamp const& green,
                            supp::GfxGammaRamp const& blue) const;
    void getWindowGammaRamp(supp::GfxGammaRamp * red, supp::GfxGammaRamp * green,
                            supp::GfxGammaRamp * blue) const;
    void setWindowHitTest(const GfxHitTest callback, void * callback_data) const;

    int32_t getWidth() const;
    int32_t getHeight() const;

    SdlTypePtr getAsSdlTypePtr() const;
private:
    SdlTypePtr window_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindow_hpp */
