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

#include <cassert>
#include <cstdint>
#include <cstring>
#include <string>

#include "GfxWindow.hpp"

namespace gfx
{

namespace video
{

const char GfxWindow::ClassName[] = "GfxWindow";

static GfxWindow::GfxHitTest hitTest_ = nullptr;

static gfx::sdl2::SDL_HitTestResult WindowHitTestFunction(gfx::sdl2::SDL_Window * win,
        const gfx::sdl2::SDL_Point * area, void * data)
{
    assert(win != nullptr);
    assert(area != nullptr);
    assert(data != nullptr);

    gfx::video::GfxHitTestResult htr;
    gfx::video::GfxHitTestResult::SdlType htrsdl;
    gfx::GfxPoint pt;

    htrsdl = sdl2::SDL_HITTEST_NORMAL;
    if (hitTest_ != nullptr)
    {
        pt.setX(area->x);
        pt.setY(area->y);
        htr = hitTest_(&pt, data);
        htrsdl = htr.getAsSdlType();
    }
    return htrsdl;
}

GfxWindow::GfxWindow(const std::string& title, const int32_t width, const int32_t height) :
        GfxRootClass(ClassName)
{
    assert(title.length() > 0);
    assert(width >= 0);
    assert(height >= 0);

    window_ = sdl2::SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                        const int32_t width, const int32_t height, const GfxWindowFlags& flags) :
        GfxRootClass(ClassName)
{
    assert(title.length() > 0);
    assert(x);
    assert(y);
    assert(width >= 0);
    assert(height >= 0);
    assert(flags);

    window_ = sdl2::SDL_CreateWindow(title.c_str(), x.getCoordinate(), y.getCoordinate(),
                                     width, height, flags.getAsSdlType());
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(void * data) : GfxRootClass(ClassName)
{
    assert(data != nullptr);

    window_ = sdl2::SDL_CreateWindowFrom(data);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::~GfxWindow()
{
    if (window_ != nullptr)
    {
        sdl2::SDL_DestroyWindow(window_);
    }
}

void GfxWindow::destroyWindow()
{
    if (window_ != nullptr)
    {
        sdl2::SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

GfxWindow::operator bool() const
{
    return (window_ != nullptr);
}

int32_t GfxWindow::getWindowDisplayIndex(void) const
{
    int32_t ret = -1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_GetWindowDisplayIndex(window_);
    }
    return ret;
}

GfxDisplayMode * GfxWindow::getWindowDisplayMode(void) const
{
    GfxDisplayMode::SdlType dm;
    GfxDisplayMode * dmptr = nullptr;

    if (window_ != nullptr)
    {
        sdl2::SDL_GetWindowDisplayMode(window_, &dm);
        dmptr = new gfx::video::GfxDisplayMode();
        dmptr->set(dm);
    }
    return dmptr;
}

uint32_t GfxWindow::getWindowPixelFormat(void) const
{
    uint32_t ret = 0;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_GetWindowPixelFormat(window_);
    }
    return ret;
}

/**************************************** Window methods ****************************************/
uint32_t GfxWindow::getWindowID(void) const
{
    uint32_t id = 0;

    if (window_ != nullptr)
    {
        id = sdl2::SDL_GetWindowID(window_);
    }
    return id;
}

GfxWindow const * GfxWindow::getWindowFromID(const uint32_t id) const
{
    GfxWindow::SdlTypePtr wptr = nullptr;

    wptr = sdl2::SDL_GetWindowFromID(id);
    if (wptr == window_)
    {
        return this;
    }
    else
    {
        /* I should find the associated GfxWindow object for wptr.
           For now just return NULL */
    }
    return nullptr;
}

GfxWindowFlags * GfxWindow::getWindowFlags(void) const
{
    uint32_t wf;

    if (window_ != nullptr)
    {
        wf = sdl2::SDL_GetWindowFlags(window_);
        return new GfxWindowFlags(wf);
    }
    return nullptr;
}

void GfxWindow::setWindowTitle(const std::string& title)
{
    assert(title.length() > 0);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowTitle(window_, title.c_str());
    }
}

std::string GfxWindow::getWindowTitle() const
{
    const char * pch;

    if (window_ == nullptr)
    {
        return "";
    }
    pch = sdl2::SDL_GetWindowTitle(window_);
    return std::string(pch);
}

void GfxWindow::setWindowIcon(GfxSurface const& icon)
{
    assert(icon);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowIcon(window_, icon.getAsSdlTypePtr());
    }
}

void * GfxWindow::setWindowData(std::string const& name, void * userdata) const
{
    assert(name.length() > 0);
    assert(userdata != nullptr);

    return sdl2::SDL_SetWindowData(window_, name.c_str(), userdata);
}

void * GfxWindow::getWindowData(std::string const& name) const
{
    assert(name.length() > 0);

    return sdl2::SDL_GetWindowData(window_, name.c_str());
}

void GfxWindow::setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y)
{
    assert(x);
    assert(y);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowPosition(window_, x.getCoordinate(), y.getCoordinate());
    }
}

void GfxWindow::getWindowPosition(GfxWindowPosition * x, GfxWindowPosition * y)
{
    assert(x != nullptr);
    assert(y != nullptr);

    int32_t xcoord;
    int32_t ycoord;

    if (window_ == nullptr)
    {
        return;
    }
    sdl2::SDL_GetWindowPosition(window_, &xcoord, &ycoord);
    x->setPosition(GfxWindowPosition::ValueType::positionSpecified);
    x->setCoordinate(xcoord);
    y->setPosition(GfxWindowPosition::ValueType::positionSpecified);
    y->setCoordinate(ycoord);
}

void GfxWindow::setWindowSize(const int32_t w, const int32_t h) const
{
    assert(w >= 0);
    assert(h >= 0);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowSize(window_, w, h);
    }
}

void GfxWindow::getWindowSize(int32_t * pw, int32_t * ph) const
{
    assert(pw != nullptr);
    assert(ph != nullptr);

    if (window_ == nullptr)
    {
        *pw = -1;
        *ph = -1;
        return;
    }
    sdl2::SDL_GetWindowSize(window_, pw, ph);
}

void GfxWindow::getWindowBordersSize(int32_t * top, int32_t * left, int32_t * bottom, int32_t * right) const
{
    assert(top != nullptr);
    assert(left != nullptr);
    assert(bottom != nullptr);
    assert(right != nullptr);

    int ret;

    ret = sdl2::SDL_GetWindowBordersSize(window_, top, left, bottom, right);
    assert((ret == -1) || (ret == 0));
}

void GfxWindow::setWindowMinimumSize(int32_t min_w, int32_t min_h) const
{
    assert(min_w > 0);
    assert(min_h > 0);

    sdl2::SDL_SetWindowMinimumSize(window_, min_w, min_h);
}

void GfxWindow::getWindowMinimumSize(int32_t * w, int32_t * h) const
{
    assert(w != nullptr);
    assert(h != nullptr);

    sdl2::SDL_GetWindowMinimumSize(window_, w, h);
}

void GfxWindow::setWindowMaximumSize(int32_t max_w, int32_t max_h) const
{
    assert(max_w > 0);
    assert(max_h > 0);

    sdl2::SDL_SetWindowMaximumSize(window_, max_w, max_h);
}

void GfxWindow::getWindowMaximumSize(int32_t * w, int32_t * h) const
{
    assert(w != nullptr);
    assert(h != nullptr);

    sdl2::SDL_GetWindowMaximumSize(window_, w, h);
}

void GfxWindow::setWindowBordered(GfxBool const& bordered) const
{
    assert(bordered);

    sdl2::SDL_SetWindowBordered(window_, bordered.getAsSdlType());
}

void GfxWindow::setWindowResizable(GfxBool const& resizable) const
{
    assert(resizable);

    sdl2::SDL_SetWindowResizable(window_, resizable.getAsSdlType());
}

void GfxWindow::showWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_ShowWindow(window_);
    }
}

void GfxWindow::hideWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_HideWindow(window_);
    }
}

void GfxWindow::raiseWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_RaiseWindow(window_);
    }
}

void GfxWindow::maximizeWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_MaximizeWindow(window_);
    }
}

void GfxWindow::minimizeWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_MinimizeWindow(window_);
    }
}

void GfxWindow::restoreWindow(void) const
{
    if (window_ != nullptr)
    {
        sdl2::SDL_RestoreWindow(window_);
    }
}

void GfxWindow::setWindowFullscreen(fullscreenflags_t flags) const
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowFullscreen(window_, flags);
        assert((ret == -1) || (ret == 0));
    }
}

GfxSurface * GfxWindow::getWindowSurface(void)
{
    if (window_ != nullptr)
    {
        sdl2::SDL_Surface* surf = sdl2::SDL_GetWindowSurface(window_);
        if (surf != nullptr)
        {
            GfxSurface * ptr { new GfxSurface(surf) };

            return ptr;
        }
    }
    return nullptr;
}

void GfxWindow::updateWindowSurface(void)
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_UpdateWindowSurface(window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::updateWindowSurfaceRects(GfxRectVector vec) const
{
    int32_t ret = 1;
    GfxRect::SdlTypePtr rects_ptr;
    int32_t rects_count;
    int32_t index;

    assert(vec.size() > 0);

    rects_count = vec.size();
    rects_ptr = reinterpret_cast<GfxRect::SdlTypePtr>(std::malloc(sizeof(GfxRect::SdlType) * rects_count));
    index = 0;
    for (auto& it : vec)
    {
        std::memcpy(&rects_ptr[index], it.getAsSdlTypePtr(), sizeof(GfxRect::SdlType));
        index += 1;
    }
    if (window_ != nullptr)
    {
        ret = sdl2::SDL_UpdateWindowSurfaceRects(window_, rects_ptr, rects_count);
        assert((ret == -1) || (ret == 0));
    }
    std::free(rects_ptr);
}

void GfxWindow::setWindowGrab(GfxBool const& grabbed) const
{
    assert(grabbed);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowGrab(window_, grabbed.getAsSdlType());
    }
}

GfxBool GfxWindow::getWindowGrab(void) const
{
    GfxBool::SdlType grabbed;

    if (window_ != nullptr)
    {
        grabbed = sdl2::SDL_GetWindowGrab(window_);
        return GfxBool(grabbed);
    }
    return GfxBool(GfxBool::ValueType::boolFalse);
}

GfxWindow const * GfxWindow::getGrabbedWindow(void) const
{
    GfxWindow::SdlTypePtr win;

    win = sdl2::SDL_GetGrabbedWindow();
    if (win != nullptr)
    {
        if (win == window_)
        {
            return this;
        }
    }
    return nullptr;
}

void GfxWindow::setWindowBrightness(float brightness) const
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowBrightness(window_, brightness);
        assert((ret == -1) || (ret == 0));
    }
}

float GfxWindow::getWindowBrightness(void) const
{
    float ret_value = 0.0f;

    if (window_ != nullptr)
    {
        ret_value = sdl2::SDL_GetWindowBrightness(window_);
    }
    return ret_value;
}

void GfxWindow::setWindowOpacity(float opacity) const
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowOpacity(window_, opacity);
        assert((ret == -1) || (ret == 0));
    }
}

float GfxWindow::getWindowOpacity(void) const
{
    int32_t ret = 1;
    float ret_value = 0.0f;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_GetWindowOpacity(window_, &ret_value);
        assert((ret == -1) || (ret == 0));
    }
    return ret_value;
}

void GfxWindow::setWindowModalFor(GfxWindow const& modal_window) const
{
    int32_t ret = 1;

    assert(modal_window);

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowModalFor(modal_window.getAsSdlTypePtr(), window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowInputFocus(void) const
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowInputFocus(window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowGammaRamp(uint16_t * red, uint16_t * green, uint16_t * blue) const
{
    int32_t ret = 1;

    assert(red != nullptr);
    assert(green != nullptr);
    assert(blue != nullptr);

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_SetWindowGammaRamp(window_, red, green, blue);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::getWindowGammaRamp(uint16_t * red, uint16_t * green, uint16_t * blue) const
{
    int32_t ret = 1;

    assert(red != nullptr);
    assert(green != nullptr);
    assert(blue != nullptr);

    std::memset(red, 0, 256 * sizeof(uint16_t));
    std::memset(green, 0, 256 * sizeof(uint16_t));
    std::memset(blue, 0, 256 * sizeof(uint16_t));

    if (window_ != nullptr)
    {
        ret = sdl2::SDL_GetWindowGammaRamp(window_, red, green, blue);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowHitTest(GfxHitTest callback, void * callback_data) const
{
    int32_t ret = 1;

    if (window_ != nullptr)
    {
        if (callback != nullptr)
        {
            hitTest_ = callback;
            ret = sdl2::SDL_SetWindowHitTest(window_, WindowHitTestFunction, callback_data);
            assert((ret == -1) || (ret == 0));
        }
        else
        {
            hitTest_ = nullptr;
            // if HitTest was enabled, disable it; don't care about the result
            (void)sdl2::SDL_SetWindowHitTest(window_, NULL, NULL);
        }
    }
}

/**************************************** Custom ****************************************/
int32_t GfxWindow::getWidth() const
{
    int32_t w;
    int32_t h;

    if (window_ == nullptr)
    {
        return -1;
    }
    sdl2::SDL_GetWindowSize(window_, &w, &h);
    return w;
}

int32_t GfxWindow::getHeight() const
{
    int32_t w;
    int32_t h;

    if (window_ == nullptr)
    {
        return -1;
    }
    sdl2::SDL_GetWindowSize(window_, &w, &h);
    return h;
}

GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}

}  // namespace video

}  // namespace gfx

/* EOF */
