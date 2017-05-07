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

#include <memory>
#include <string>

#include "GfxWindow.hpp"

const std::string GfxWindow::ClassName = "GfxWindow";

GfxWindow::GfxWindow(const std::string& title, const uint16_t width, const uint16_t height) :
        GfxRootClass(ClassName)
{
    window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                        const uint16_t width, const uint16_t height, const GfxWindowFlags& flags) :
        GfxRootClass(ClassName)
{
    window_ = SDL_CreateWindow(title.c_str(), x.getCoordinate(), y.getCoordinate(),
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
        SDL_DestroyWindow(window_);
    }
}

void GfxWindow::destroyWindow()
{
    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

std::unique_ptr<GfxSurface> GfxWindow::getWindowSurface(void)
{
    if (window_ != nullptr)
    {
        SDL_Surface* surf = SDL_GetWindowSurface(window_);
        if (surf != nullptr)
        {
            std::unique_ptr<GfxSurface> ptr { new GfxSurface(surf) };
            
            return ptr;
        }
    }
    return nullptr;
}

void GfxWindow::updateWindowSurface(void)
{
    SDL_UpdateWindowSurface(window_);
}

std::string GfxWindow::getTitle() const
{
    const char * pch;

    pch = SDL_GetWindowTitle(window_);
    return std::string(pch);
}

void GfxWindow::setTitle(const std::string& title)
{
    SDL_SetWindowTitle(window_, title.c_str());
}

void GfxWindow::setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y)
{
    SDL_SetWindowPosition(window_, x.getCoordinate(), y.getCoordinate());
}

void GfxWindow::getWindowPosition(GfxWindowPosition* x, GfxWindowPosition* y)
{
    int xcoord;
    int ycoord;

    SDL_GetWindowPosition(window_, &xcoord, &ycoord);
    x->setPosition(GfxWindowPosition::GfxWindowPositionValues::positionSpecified);
    x->setCoordinate(xcoord);
    y->setPosition(GfxWindowPosition::GfxWindowPositionValues::positionSpecified);
    y->setCoordinate(ycoord);
}

void GfxWindow::setWindowSize(int32_t x, int32_t y)
{
    SDL_SetWindowSize(window_, x, y);
}

void GfxWindow::getWindowSize(int32_t* px, int32_t* py)
{
    SDL_GetWindowSize(window_, px, py);
}

uint16_t GfxWindow::getWidth() const
{
    int w;
    int h;

    if (window_ == nullptr)
    {
        return 0;
    }
    SDL_GetWindowSize(window_, &w, &h);
    return w;
}

uint16_t GfxWindow::getHeight() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_, &w, &h);
    return h;
}

GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}

/* EOF */
