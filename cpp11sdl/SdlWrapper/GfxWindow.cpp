//
//  GfxWindow.cpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxWindow.hpp"

GfxWindow::GfxWindow(std::string title,int width,int height) :
    title_(title)
{
    window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height, 0);
}

GfxWindow::GfxWindow(GfxWindow&& win)
{
    window_ = win.window_;
    title_ = win.title_;
    
    win.window_ = nullptr;
    win.title_ = "";
}

GfxWindow::~GfxWindow()
{
    if (window_)
        SDL_DestroyWindow(window_);
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
    if (window_)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

GfxSurface* GfxWindow::getWindowSurface(void)
{
    if (window_)
    {
        SDL_Surface* surf = SDL_GetWindowSurface(window_);
        return new GfxSurface(surf);
    }
    return nullptr;
}

std::string GfxWindow::getTitle() const
{
    return title_;
}

int GfxWindow::getWidth() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_,&w,&h);
    return w;
}

int GfxWindow::getHeight() const
{
    int w;
    int h;

    SDL_GetWindowSize(window_,&w,&h);
    return h;
}

void GfxWindow::setTitle(std::string title)
{
    title_ = title;
    SDL_SetWindowTitle(window_,title_.c_str());
}
                       
GfxWindow::SdlTypePtr GfxWindow::getAsSdlTypePtr() const
{
    return window_;
}
