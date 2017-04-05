//
//  GfxWindow.cpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "GfxWindow.hpp"

GfxWindow::GfxWindow(std::string title,int width,int height) :
    title_(title), width_(width), height_(height)
{
    window_ = SDL_CreateWindow(title.c_str(), 100, 100, width_, height_, 0);
}

GfxWindow::GfxWindow(GfxWindow&& win)
{
    window_ = win.window_;
    title_ = win.title_;
    width_ = win.width_;
    height_ = win.height_;
    
    win.window_ = nullptr;
    win.title_ = "";
    win.width_ = -1;
    win.height_ = -1;
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
        width_ = win.width_;
        height_ = win.height_;
        
        win.window_ = nullptr;
        win.title_ = "";
        win.width_ = -1;
        win.height_ = -1;
    }
    return *this;
}

void GfxWindow::destroyWindow()
{
    if (window_)
        SDL_DestroyWindow(window_);
}

GfxSurface* GfxWindow::getWindowSurface(void)
{
    if (window_)
    {
        SDL_Surface* surf = SDL_GetWindowSurface(window_);
        return new GfxSurface(&surf);
    }
    return nullptr;
}

std::string GfxWindow::getTitle() const
{
    return title_;
}

int GfxWindow::getWidth() const
{
    return width_;
}

int GfxWindow::getHeight() const
{
    return height_;
}

void GfxWindow::setTitle(std::string title)
{
    title_ = title;
    SDL_SetWindowTitle(window_,title_.c_str());
}
                       
GfxWindow::GfxWindowSdlType* GfxWindow::getAsGfxWindowSdlTypePtr() const
{
    return window_;
}
