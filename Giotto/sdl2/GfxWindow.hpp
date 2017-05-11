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

#include <string>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxSurface.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxWindowFlags.hpp"

namespace gfx
{

class GfxWindow final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Window SdlType;
    typedef sdl2::SDL_Window* SdlTypePtr;

    static const char ClassName[];

    GfxWindow(const std::string& title, const uint16_t width, const uint16_t height);
    GfxWindow(const std::string& title, const GfxWindowPosition& x, const GfxWindowPosition& y,
                const uint16_t width, const uint16_t height, const GfxWindowFlags& flags);

    GfxWindow() = delete;
    GfxWindow(const GfxWindow&) = delete;
    GfxWindow(GfxWindow&&) = delete;
    GfxWindow& operator=(const GfxWindow&) = delete;
    GfxWindow& operator=(GfxWindow&&) = delete;

    virtual ~GfxWindow();

    void destroyWindow();

    std::string getTitle() const;
    void setTitle(const std::string& title);

    int32_t getWidth() const;
    int32_t getHeight() const;

    void setWindowPosition(const GfxWindowPosition& x, const GfxWindowPosition& y);
    void getWindowPosition(GfxWindowPosition* x, GfxWindowPosition* y);

    void setWindowSize(const int32_t x, const int32_t y);
    void getWindowSize(int32_t* px, int32_t* py);

    GfxSurface* getWindowSurface(void);
    void updateWindowSurface(void);

    /*
    SDL_UpdateWindowSurface
    SDL_UpdateWindowSurfaceRects
    SDL_GetWindowFromID()

    SDL_SetWindowData()
    SDL_GetWindowData()

    SDL_GetWindowFlags()
    SDL_SetWindowFullscreen()

    SDL_HideWindow()
    SDL_ShowWindow()

    SDL_MaximizeWindow()
    SDL_MinimizeWindow()
    SDL_RestoreWindow()

    SDL_RaiseWindow()

    SDL_SetWindowGrab()
    SDL_GetWindowGrab()
*/
    void setWindowIcon(GfxSurface const& icon);

    /*SDL_SetWindowPosition()
    SDL_SetWindowBordered()
    SDL_GetWindowBordersSize
    SDL_SetWindowResizable()
    SDL_SetWindowMinimumSize
    SDL_GetWindowMinimumSize
    SDL_SetWindowMaximumSize
    SDL_GetWindowMaximumSize
    SDL_SetWindowBrightness
    SDL_GetWindowBrightness
    SDL_SetWindowOpacity
    SDL_GetWindowOpacity
    SDL_SetWindowModalFor
    SDL_SetWindowInputFocus
    SDL_SetWindowGammaRamp
    SDL_GetWindowGammaRamp
    static class method
    SDL_GetGrabbedWindow

     extern DECLSPEC int SDLCALL SDL_GetWindowDisplayIndex(SDL_Window * window);
     extern DECLSPEC int SDLCALL SDL_SetWindowDisplayMode(SDL_Window * window,
                                                         const SDL_DisplayMode
                                                         * mode);
     extern DECLSPEC Uint32 SDLCALL SDL_GetWindowPixelFormat(SDL_Window * window);
     etc.
     */

    SdlTypePtr getAsSdlTypePtr() const;
private:
    SdlTypePtr window_;
};

}  // namespace gfx

#endif /* GfxWindow_hpp */
