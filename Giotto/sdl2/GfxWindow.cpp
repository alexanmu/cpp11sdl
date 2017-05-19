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

#include <string>

#include "GfxWindow.hpp"

namespace gfx
{

const char GfxWindow::ClassName[] = "GfxWindow";

GfxWindow::GfxWindow(const std::string& title, const uint16_t width, const uint16_t height) :
        GfxRootClass(ClassName)
{
    window_ = sdl2::SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                        const uint16_t width, const uint16_t height, const GfxWindowFlags& flags) :
        GfxRootClass(ClassName)
{
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

GfxSurface* GfxWindow::getWindowSurface(void)
{
    if (window_ != nullptr)
    {
        sdl2::SDL_Surface* surf = sdl2::SDL_GetWindowSurface(window_);
        if (surf != nullptr)
        {
            GfxSurface* ptr { new GfxSurface(surf) };

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
    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowTitle(window_, title.c_str());
    }
}

int32_t GfxWindow::getWidth() const
{
    int w;
    int h;

    if (window_ == nullptr)
    {
        return -1;
    }
    sdl2::SDL_GetWindowSize(window_, &w, &h);
    return w;
}

int32_t GfxWindow::getHeight() const
{
    int w;
    int h;

    if (window_ == nullptr)
    {
        return -1;
    }
    sdl2::SDL_GetWindowSize(window_, &w, &h);
    return h;
}

void GfxWindow::setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y)
{
    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowPosition(window_, x.getCoordinate(), y.getCoordinate());
    }
}

void GfxWindow::getWindowPosition(GfxWindowPosition* x, GfxWindowPosition* y)
{
    int xcoord;
    int ycoord;

    if (window_ == nullptr)
    {
        return;
    }
    sdl2::SDL_GetWindowPosition(window_, &xcoord, &ycoord);
    x->setPosition(GfxWindowPosition::GfxWindowPositionValues::positionSpecified);
    x->setCoordinate(xcoord);
    y->setPosition(GfxWindowPosition::GfxWindowPositionValues::positionSpecified);
    y->setCoordinate(ycoord);
}

void GfxWindow::setWindowSize(int32_t x, int32_t y)
{
    if (window_ != nullptr)
    {
        sdl2::SDL_SetWindowSize(window_, x, y);
    }
}

void GfxWindow::getWindowSize(int32_t* px, int32_t* py)
{
    if (window_ == nullptr)
    {
        *px = -1;
        *py = -1;
        return;
    }
    sdl2::SDL_GetWindowSize(window_, px, py);
}

void GfxWindow::setWindowIcon(GfxSurface const& icon)
{
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
