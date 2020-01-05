/*
  Giotto
  Copyright (C) 2020 George Oros

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
#include <vector>
#include <utility>

#include "GfxWindow.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxwindow::video::gfx");

namespace gfx
{

namespace video
{

const char GfxWindow::ClassName[] = "GfxWindow";

GfxWindow::GfxWindow() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    window_ = nullptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

GfxWindow::GfxWindow(const std::string& title, const int32_t width, const int32_t height)
    throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(width >= 0);
    assert(height >= 0);

    SdlTypePtr tmpwinptr;

    tmpwinptr = SDL_CreateWindow(title.c_str(), kDefaultWindowPositionX, kDefaultWindowPositionY,
                                 width, height, kDefaultFlagsValue);
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

GfxWindow::GfxWindow(const std::string& title, const int32_t width, const int32_t height,
                     const GfxWindowFlags& flags) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(width >= 0);
    assert(height >= 0);

    SdlTypePtr tmpwinptr;

    tmpwinptr = SDL_CreateWindow(title.c_str(), kDefaultWindowPositionX, kDefaultWindowPositionY,
                                 width, height, flags.getAsSdlType());
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

GfxWindow::GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                     const int32_t width, const int32_t height, const GfxWindowFlags& flags) throw(std::runtime_error) :
        GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(x);
    assert(y);
    assert(width >= 0);
    assert(height >= 0);
    assert(flags);

    SdlTypePtr tmpwinptr;

    tmpwinptr = SDL_CreateWindow(title.c_str(), x.getCoordinate(), y.getCoordinate(),
                                 width, height, flags.getAsSdlType());
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

GfxWindow::GfxWindow(const void * data) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_HIGH();

    assert(data != nullptr);

    SdlTypePtr tmpwinptr;

    tmpwinptr = SDL_CreateWindowFrom(data);
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

GfxWindow::GfxWindow(GfxWindow&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_HIGH();

    void * callback_data = static_cast<void *>(this);

    freeResources();

    window_ = other.window_;
    winSurface_ = other.winSurface_;
    hitTest_ = other.hitTest_;
    if (hitTest_ != nullptr)
    {
        SDL_SetWindowHitTest(window_, windowHitTestFunction, callback_data);
    }
    // Delete other's data
    other.window_ = nullptr;
    other.winSurface_ = nullptr;
    other.hitTest_ = nullptr;
}

GfxWindow& GfxWindow::operator=(GfxWindow&& other) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    void * callback_data = static_cast<void *>(this);

    if (this != &other)
    {
        freeResources();
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        window_ = other.window_;
        winSurface_ = other.winSurface_;
        hitTest_ = other.hitTest_;
        if (hitTest_ != nullptr)
        {
            SDL_SetWindowHitTest(window_, windowHitTestFunction, callback_data);
        }
        // Delete other's data
        other.window_ = nullptr;
        other.winSurface_ = nullptr;
        other.hitTest_ = nullptr;
    }
    return *this;
}

GfxWindow::~GfxWindow() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    freeResources();
}

GfxWindow::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (window_ != nullptr);
}

std::string GfxWindow::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxWindow::createWindow(const std::string& title, const int32_t width,
                             const int32_t height) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(width >= 0);
    assert(height >= 0);

    SdlTypePtr tmpwinptr;

    if (window_ != nullptr)
    {
        throw std::runtime_error("Window already created");
    }
    tmpwinptr = SDL_CreateWindow(title.c_str(), kDefaultWindowPositionX, kDefaultWindowPositionY,
                                       width, height, kDefaultFlagsValue);
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

void GfxWindow::createWindow(const std::string& title, const int32_t width, const int32_t height,
                             const GfxWindowFlags& flags) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(width >= 0);
    assert(height >= 0);

    SdlTypePtr tmpwinptr;

    if (window_ != nullptr)
    {
        throw std::runtime_error("Window already created");
    }
    tmpwinptr = SDL_CreateWindow(title.c_str(), kDefaultWindowPositionX, kDefaultWindowPositionY,
                                       width, height, flags.getAsSdlType());
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

void GfxWindow::createWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                             const int32_t width, const int32_t height,
                             const GfxWindowFlags& flags) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(title.length() > 0);
    assert(x);
    assert(y);
    assert(width >= 0);
    assert(height >= 0);
    assert(flags);

    SdlTypePtr tmpwinptr;

    if (window_ != nullptr)
    {
        throw std::runtime_error("Window already created");
    }
    tmpwinptr = SDL_CreateWindow(title.c_str(), x.getCoordinate(), y.getCoordinate(),
                                       width, height, flags.getAsSdlType());
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

void GfxWindow::createWindow(const void * data) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(data != nullptr);

    SdlTypePtr tmpwinptr;

    if (window_ != nullptr)
    {
        throw std::runtime_error("Window already created");
    }
    tmpwinptr = SDL_CreateWindowFrom(data);
    if (tmpwinptr == nullptr)
    {
        const std::string sdlErr = SDL_GetError();
        throw std::runtime_error("Unable to create window (" + sdlErr + ")");
    }
    window_ = tmpwinptr;
    winSurface_ = nullptr;
    hitTest_ = nullptr;
}

void GfxWindow::destroyWindow() noexcept
{
    LOG_TRACE_PRIO_HIGH();

    freeResources();
}

int32_t GfxWindow::getWindowDisplayIndex(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = -1;

    if (window_ != nullptr)
    {
        ret = SDL_GetWindowDisplayIndex(window_);
    }
    return ret;
}

const GfxDisplayMode GfxWindow::getWindowDisplayMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxDisplayMode::SdlType dm;

    if (window_ != nullptr)
    {
        SDL_GetWindowDisplayMode(window_, &dm);
        return gfx::video::GfxDisplayMode(dm);
    }
    return gfx::video::GfxDisplayMode();
}

const pixels::GfxPixelFormatEnum GfxWindow::getWindowPixelFormat(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t ret = SDL_PIXELFORMAT_UNKNOWN;

    if (window_ != nullptr)
    {
        ret = SDL_GetWindowPixelFormat(window_);
        return pixels::GfxPixelFormatEnum(ret);
    }
    return pixels::GfxPixelFormatEnum();
}

uint32_t GfxWindow::getWindowID(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t id = 0;

    if (window_ != nullptr)
    {
        id = SDL_GetWindowID(window_);
    }
    return id;
}

const GfxWindow * GfxWindow::getWindowFromID(const uint32_t id) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxWindow::SdlTypePtr wptr = nullptr;

    wptr = SDL_GetWindowFromID(id);
    if (wptr == window_)
    {
        return this;
    }
    else
    {
#warning I should find the associated GfxWindow object for wptr. For now just return NULL
    }
    return nullptr;
}

const GfxWindowFlags GfxWindow::getWindowFlags(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint32_t wf;

    if (window_ != nullptr)
    {
        wf = SDL_GetWindowFlags(window_);
        return GfxWindowFlags(wf);
    }
    return GfxWindowFlags();
}

void GfxWindow::setWindowTitle(const std::string& title) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(title.length() > 0);

    if (window_ != nullptr)
    {
        SDL_SetWindowTitle(window_, title.c_str());
    }
}

const std::string GfxWindow::getWindowTitle(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * pch;

    if (window_ != nullptr)
    {
        pch = SDL_GetWindowTitle(window_);
        return std::string(pch);
    }
    return "";
}

void GfxWindow::setWindowIcon(const surface::GfxSurface& icon) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(icon);

    if (window_ != nullptr)
    {
        SDL_SetWindowIcon(window_, icon.getAsSdlTypePtr());
    }
}

void * GfxWindow::setWindowData(const std::string& name, void * userdata) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);
    assert(userdata != nullptr);

    if (window_ != nullptr)
    {
        return SDL_SetWindowData(window_, name.c_str(), userdata);
    }
    return nullptr;
}

void * GfxWindow::getWindowData(const std::string& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    if (window_ != nullptr)
    {
        return SDL_GetWindowData(window_, name.c_str());
    }
    return nullptr;
}

void GfxWindow::setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x);
    assert(y);

    if (window_ != nullptr)
    {
        SDL_SetWindowPosition(window_, x.getCoordinate(), y.getCoordinate());
    }
}

void GfxWindow::getWindowPosition(GfxWindowPosition * x, GfxWindowPosition * y) noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(x != nullptr);
    assert(y != nullptr);

    int32_t xcoord;
    int32_t ycoord;

    x->setCoordinate(-1);
    y->setCoordinate(-1);
    if (window_ != nullptr)
    {
        SDL_GetWindowPosition(window_, &xcoord, &ycoord);
        x->setPosition(GfxWindowPosition::ValueType::positionSpecified);
        x->setCoordinate(xcoord);
        y->setPosition(GfxWindowPosition::ValueType::positionSpecified);
        y->setCoordinate(ycoord);
    }
}

void GfxWindow::setWindowSize(const int32_t w, const int32_t h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(w > 0);
    assert(h > 0);

    if (window_ != nullptr)
    {
        SDL_SetWindowSize(window_, w, h);
    }
}

void GfxWindow::getWindowSize(int32_t * pw, int32_t * ph) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(pw != nullptr);
    assert(ph != nullptr);

    *pw = -1;
    *ph = -1;
    if (window_ != nullptr)
    {
        SDL_GetWindowSize(window_, pw, ph);
    }
}

void GfxWindow::getWindowBordersSize(int32_t * top, int32_t * left, int32_t * bottom, int32_t * right) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(top != nullptr);
    assert(left != nullptr);
    assert(bottom != nullptr);
    assert(right != nullptr);

    int32_t ret;

    *top = 0;
    *left = 0;
    *bottom = 0;
    *right = 0;
    if (window_ != nullptr)
    {
        ret = SDL_GetWindowBordersSize(window_, top, left, bottom, right);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowMinimumSize(const int32_t min_w, const int32_t min_h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(min_w > 0);
    assert(min_h > 0);

    if (window_ != nullptr)
    {
        SDL_SetWindowMinimumSize(window_, min_w, min_h);
    }
}

void GfxWindow::getWindowMinimumSize(int32_t * min_w, int32_t * min_h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(min_w != nullptr);
    assert(min_h != nullptr);

    if (window_ != nullptr)
    {
        SDL_GetWindowMinimumSize(window_, min_w, min_h);
    }
}

void GfxWindow::setWindowMaximumSize(const int32_t max_w, const int32_t max_h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(max_w > 0);
    assert(max_h > 0);

    if (window_ != nullptr)
    {
        SDL_SetWindowMaximumSize(window_, max_w, max_h);
    }
}

void GfxWindow::getWindowMaximumSize(int32_t * max_w, int32_t * max_h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(max_w != nullptr);
    assert(max_h != nullptr);

    if (window_ != nullptr)
    {
        SDL_GetWindowMaximumSize(window_, max_w, max_h);
    }
}

void GfxWindow::setWindowBordered(const GfxBool& bordered) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(bordered);

    if (window_ != nullptr)
    {
        SDL_SetWindowBordered(window_, bordered.getAsSdlType());
    }
}

void GfxWindow::setWindowResizable(const GfxBool& resizable) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(resizable);

    if (window_ != nullptr)
    {
        SDL_SetWindowResizable(window_, resizable.getAsSdlType());
    }
}

void GfxWindow::showWindow(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    if (window_ != nullptr)
    {
        SDL_ShowWindow(window_);
    }
}

void GfxWindow::hideWindow(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    if (window_ != nullptr)
    {
        SDL_HideWindow(window_);
    }
}

void GfxWindow::raiseWindow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (window_ != nullptr)
    {
        SDL_RaiseWindow(window_);
    }
}

void GfxWindow::maximizeWindow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (window_ != nullptr)
    {
        SDL_MaximizeWindow(window_);
    }
}

void GfxWindow::minimizeWindow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (window_ != nullptr)
    {
        SDL_MinimizeWindow(window_);
    }
}

void GfxWindow::restoreWindow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (window_ != nullptr)
    {
        SDL_RestoreWindow(window_);
    }
}

void GfxWindow::setWindowFullscreen(const GfxWindowFlags& flags) const noexcept
{
    LOG_TRACE_PRIO_MED();

    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowFullscreen(window_, flags.getAsSdlType());
        assert((ret == -1) || (ret == 0));
    }
}

const surface::GfxSurface& GfxWindow::getWindowSurface(void) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    surface::GfxSurface::SdlTypePtr tmpsurf;

    if (window_ != nullptr)
    {
        // Window has been created; try-get assoc. surface
        tmpsurf = SDL_GetWindowSurface(window_);
        if (tmpsurf == nullptr)
        {
            throw std::runtime_error("Window surface not accessible");
        }
        // Win surface is valid;
        if (winSurface_ != nullptr)
        {
            if (winSurface_->getAsSdlTypePtr() != tmpsurf)
            {
                // Delete existing GfxSurface object
                delete winSurface_;
                // Create new GfxSurface object with new window surface
                winSurface_ = new surface::GfxSurface("GfxWindow::getWindowSurface", tmpsurf, true);
            }
            else
            {
                // Window surface unchanged; winSurface_ remains unchanged
            }
        }
        else
        {
            // Create new GfxSurface object with new window surface
            winSurface_ = new surface::GfxSurface("GfxWindow::getWindowSurface", tmpsurf, true);
        }
    }
    else
    {
        /* Window has been destroyed; winSurface_ is nullptr already; caller will have a problem */
        throw std::runtime_error("Window has already been destroyed");
    }
    return *winSurface_;
}

void GfxWindow::updateWindowSurface(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = SDL_UpdateWindowSurface(window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::updateWindowSurfaceRects(const std::vector<gfx::rect::GfxRect>& vec) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    rect::GfxRect::SdlTypePtr rects_ptr;
    int32_t rects_count;
    int32_t index;

    assert(vec.size() > 0);

    rects_count = static_cast<int32_t>(vec.size());
    rects_ptr = reinterpret_cast<rect::GfxRect::SdlTypePtr>(malloc(sizeof(rect::GfxRect::SdlType) * rects_count));
    if (!rects_ptr)
    {
        throw std::runtime_error("malloc error");
    }
    index = 0;
    for (auto& it : vec)
    {
        std::memcpy(&rects_ptr[index], it.getAsSdlTypePtr(), sizeof(rect::GfxRect::SdlType));
        index += 1;
    }
    if (window_ != nullptr)
    {
        ret = SDL_UpdateWindowSurfaceRects(window_, rects_ptr, rects_count);
        assert((ret == -1) || (ret == 0));
    }
    // Leaks if assert above fails
    free(rects_ptr);
}

void GfxWindow::setWindowGrab(const GfxBool& grabbed) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(grabbed);

    if (window_ != nullptr)
    {
        SDL_SetWindowGrab(window_, grabbed.getAsSdlType());
    }
}

const GfxBool GfxWindow::getWindowGrab(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxBool::SdlType grabbed;

    if (window_ != nullptr)
    {
        grabbed = SDL_GetWindowGrab(window_);
        return GfxBool(grabbed);
    }
    return GfxBool(GfxBool::ValueType::boolFalse);
}

const GfxWindow * GfxWindow::getGrabbedWindow(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    GfxWindow::SdlTypePtr win;

    win = SDL_GetGrabbedWindow();
    if (win != nullptr)
    {
        if (win == window_)
        {
            return this;
        }
    }
    return nullptr;
}

void GfxWindow::setWindowBrightness(const float brightness) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowBrightness(window_, brightness);
        assert((ret == -1) || (ret == 0));
    }
}

float GfxWindow::getWindowBrightness(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    float ret_value = 0.0f;

    if (window_ != nullptr)
    {
        ret_value = SDL_GetWindowBrightness(window_);
    }
    return ret_value;
}

void GfxWindow::setWindowOpacity(const float opacity) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowOpacity(window_, opacity);
        assert((ret == -1) || (ret == 0));
    }
}

float GfxWindow::getWindowOpacity(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;
    float ret_value = 0.0f;

    if (window_ != nullptr)
    {
        ret = SDL_GetWindowOpacity(window_, &ret_value);
        assert((ret == -1) || (ret == 0));
    }
    return ret_value;
}

void GfxWindow::setWindowModalFor(const GfxWindow& modal_window) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    assert(modal_window);

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowModalFor(modal_window.getAsSdlTypePtr(), window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowInputFocus(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowInputFocus(window_);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowGammaRamp(const xtra::GfxGammaRamp& red, const xtra::GfxGammaRamp& green,
                                   const xtra::GfxGammaRamp& blue) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    assert(red);
    assert(green);
    assert(blue);

    if (window_ != nullptr)
    {
        ret = SDL_SetWindowGammaRamp(window_, red.getAsSdlTypePtr(), green.getAsSdlTypePtr(),
                                           blue.getAsSdlTypePtr());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::getWindowGammaRamp(xtra::GfxGammaRamp * red, xtra::GfxGammaRamp * green,
                                   xtra::GfxGammaRamp * blue) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    assert(red != nullptr);
    assert(green != nullptr);
    assert(blue != nullptr);

    red->clear();
    green->clear();
    blue->clear();

    if (window_ != nullptr)
    {
        ret = SDL_GetWindowGammaRamp(window_, red->getAsSdlTypePtr(), green->getAsSdlTypePtr(),
                                           blue->getAsSdlTypePtr());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxWindow::setWindowHitTest(const GfxHitTest& callback) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(callback);

    int32_t ret = 1;
    void * callback_data = static_cast<void *>(const_cast<GfxWindow *>(this));

    if (window_ != nullptr)
    {
        if (callback)
        {
            hitTest_ = const_cast<GfxHitTest *>(&callback);
            ret = SDL_SetWindowHitTest(window_, windowHitTestFunction, callback_data);
            assert((ret == -1) || (ret == 0));
        }
        else
        {
            hitTest_ = nullptr;
            // if HitTest was enabled, disable it; don't care about the result
            (void)SDL_SetWindowHitTest(window_, NULL, NULL);
        }
    }
}

int32_t GfxWindow::getWidth() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t w = -1;

    if (window_ != nullptr)
    {
        SDL_GetWindowSize(window_, &w, NULL);
    }
    return w;
}

int32_t GfxWindow::getHeight() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t h = -1;

    if (window_ != nullptr)
    {
        SDL_GetWindowSize(window_, NULL, &h);
    }
    return h;
}

GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return window_;
}

// Private methods
void GfxWindow::freeResources(void) noexcept
{
    if (winSurface_ != nullptr)
    {
        delete winSurface_;
        winSurface_ = nullptr;
    }
    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

SDL_HitTestResult GfxWindow::windowHitTestFunction(SDL_Window * win,
                                                   const SDL_Point * area, void * data)
{
    assert(win != nullptr);
    assert(area != nullptr);
    assert(data != nullptr);

    gfx::video::GfxHitTestResult htr;
    gfx::video::GfxHitTestResult::SdlType htrsdl;
    rect::GfxPoint pt;

    GfxWindow * thisptr = static_cast<GfxWindow *>(data);

    htrsdl = SDL_HITTEST_NORMAL;
    if (thisptr != nullptr)
    {
        if (thisptr->hitTest_ != nullptr)
        {
            pt.setX(area->x);
            pt.setY(area->y);
            htr = (*(thisptr->hitTest_))(reinterpret_cast<void *>(win), &pt);
            htrsdl = htr.getAsSdlType();
        }
    }
    return htrsdl;
}

}  // namespace video

}  // namespace gfx

/* EOF */
