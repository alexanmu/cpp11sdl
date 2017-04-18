/*
  CPP11SDL
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

#include "GfxWindow.hpp"

GfxWindow::GfxWindow(const std::string& title,const uint16_t width,const uint16_t height) : GfxRootClass("GfxWindow"), title_(title)
{
    window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
    if (window_ == nullptr)
    {
        // error handling here
    }
}

GfxWindow::GfxWindow(GfxWindow&& win) : GfxRootClass("GfxWindow")
{
    window_ = win.window_;
    title_ = win.title_;
    
    win.window_ = nullptr;
    win.title_ = "";
}

GfxWindow::~GfxWindow()
{
    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
    }
}

GfxWindow& GfxWindow::operator=(GfxWindow&& win)
{
    if (this != &win)
    {
        window_ = win.window_;
        title_ = win.title_;
        
        win.window_ = nullptr;
        win.title_ = "";
    }
    return *this;
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
            std::unique_ptr<GfxSurface> ptr {new GfxSurface(surf)};
            return ptr;
        }
    }
    return nullptr;
}

std::string GfxWindow::getTitle() const
{
    return title_;
}

uint16_t GfxWindow::getWidth() const
{
    int w;
    int h;

    if (window_ == nullptr)
    {
        return 0;
    }
    SDL_GetWindowSize(window_,&w,&h);
    return w;
}

uint16_t GfxWindow::getHeight() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_,&w,&h);
    return h;
}

void GfxWindow::setTitle(const std::string& title)
{
    title_ = title;
    SDL_SetWindowTitle(window_,title_.c_str());
}
                       
GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}
