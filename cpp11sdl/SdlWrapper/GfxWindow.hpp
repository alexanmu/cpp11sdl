//
//  GfxWindow.hpp
//  FirstProject
//
//  Created by George Oros on 3/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxWindow_hpp
#define GfxWindow_hpp

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"

class GfxWindow final
{
public:
    typedef SDL_Window GfxWindowSdlType;

    GfxWindow(std::string title,int width,int height);

    GfxWindow() = delete;
    GfxWindow(const GfxWindow&) = delete;
    GfxWindow& operator=(const GfxWindow&) = delete;
    
    GfxWindow(GfxWindow&& win);
    GfxWindow& operator=(GfxWindow&& win);
    
    ~GfxWindow();

    void destroyWindow();

    std::string getTitle() const;
    int getWidth() const;
    int getHeight() const;
    GfxSurface* getWindowSurface(void);

    void setTitle(std::string title);

    GfxWindowSdlType* getAsGfxWindowSdlTypePtr() const;
private:
    SDL_Window* window_;
    std::string title_;
    int width_;
    int height_;
};

#endif /* GfxWindow_hpp */
