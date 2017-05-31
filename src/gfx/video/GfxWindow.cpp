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
#include <string>

#include "GfxWindow.hpp"

namespace gfx
{

const char GfxWindow::ClassName[] = "GfxWindow";

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

GfxWindow::~GfxWindow()
{
    if (window_ != nullptr)
    {
        sdl2::SDL_DestroyWindow(window_);
    }
}

GfxWindow::operator bool() const
{
    return (window_ != nullptr);
}

void GfxWindow::destroyWindow()
{
    if (window_ != nullptr)
    {
        sdl2::SDL_DestroyWindow(window_);
        window_ = nullptr;
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
    if (window_ != nullptr)
    {
        sdl2::SDL_UpdateWindowSurface(window_);
    }
}

std::string GfxWindow::getTitle() const
{
    const char * pch;

    if (window_ == nullptr)
    {
        return "";
    }
    pch = sdl2::SDL_GetWindowTitle(window_);
    return std::string(pch);
}

void GfxWindow::setTitle(const std::string& title)
{
    assert(title.length() > 0);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowTitle(window_, title.c_str());
    }
}

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

void GfxWindow::setWindowSize(int32_t w, int32_t h)
{
    assert(w >= 0);
    assert(h >= 0);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowSize(window_, w, h);
    }
}

void GfxWindow::getWindowSize(int32_t * pw, int32_t * ph)
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

void GfxWindow::setWindowIcon(GfxSurface const& icon)
{
    assert(icon);

    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowIcon(window_, icon.getAsSdlTypePtr());
    }
}

GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}

}  // namespace gfx

/* EOF */
