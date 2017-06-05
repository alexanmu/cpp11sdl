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

#ifndef GfxWindowFlags_hpp
#define GfxWindowFlags_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace video
{

class GfxWindowFlags final : public GfxObject
{
public:
    typedef sdl2::SDL_WindowFlags SdlType;
    typedef sdl2::SDL_WindowFlags* SdlTypePtr;

    static const char ClassName[];

    enum class ValueType : uint32_t
    {
        windowFlagUnknown = 0,
        windowFlagFullscreen = sdl2::SDL_WINDOW_FULLSCREEN,
        windowFlagOpenGL = sdl2::SDL_WINDOW_OPENGL,
        windowFlagShown = sdl2::SDL_WINDOW_SHOWN,
        windowFlagHidden = sdl2::SDL_WINDOW_HIDDEN,
        windowFlagBorderless = sdl2::SDL_WINDOW_BORDERLESS,
        windowFlagResizable = sdl2::SDL_WINDOW_RESIZABLE,
        windowFlagMinimized = sdl2::SDL_WINDOW_MINIMIZED,
        windowFlagMaximized = sdl2::SDL_WINDOW_MAXIMIZED,
        windowFlagInputGrabbed = sdl2::SDL_WINDOW_INPUT_GRABBED,
        windowFlagInputFocus = sdl2::SDL_WINDOW_INPUT_FOCUS,
        windowFlagMouseFocus = sdl2::SDL_WINDOW_MOUSE_FOCUS,
        windowFlagFullscreenDesktop = sdl2::SDL_WINDOW_FULLSCREEN_DESKTOP,
        windowFlagForeign = sdl2::SDL_WINDOW_FOREIGN,
        windowFlagAllowHighDPI = sdl2::SDL_WINDOW_ALLOW_HIGHDPI,
        windowFlagMouseCapture = sdl2::SDL_WINDOW_MOUSE_CAPTURE,
        // X11 only
        windowAlwaysOnTop = sdl2::SDL_WINDOW_ALWAYS_ON_TOP,
        windowSkipTaskbar = sdl2::SDL_WINDOW_SKIP_TASKBAR,
        windowUtility = sdl2::SDL_WINDOW_UTILITY,
        windowTooltip = sdl2::SDL_WINDOW_TOOLTIP,
        windowPopupMenu = sdl2::SDL_WINDOW_POPUP_MENU
    };

    GfxWindowFlags() noexcept;

    explicit GfxWindowFlags(const ValueType flags) noexcept;
    explicit GfxWindowFlags(const SdlType flags) noexcept;
    explicit GfxWindowFlags(const uint32_t flags) noexcept;

    GfxWindowFlags(GfxWindowFlags const& other) noexcept;
    GfxWindowFlags(GfxWindowFlags&& other) noexcept;

    GfxWindowFlags& operator=(GfxWindowFlags const& other) noexcept;
    GfxWindowFlags& operator=(GfxWindowFlags&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isUnkown(void) const noexcept;
    bool isFullscreen(void) const noexcept;
    bool isOpenGL(void) const noexcept;
    bool isShown(void) const noexcept;
    bool isHidden(void) const noexcept;
    bool isBorderless(void) const noexcept;
    bool isResizable(void) const noexcept;
    bool isMinimized(void) const noexcept;
    bool isMaximized(void) const noexcept;
    bool isInputGrabbed(void) const noexcept;
    bool isInputFocus(void) const noexcept;
    bool isMouseFocus(void) const noexcept;
    bool isFullscreenDesktop(void) const noexcept;
    bool isForeign(void) const noexcept;
    bool allowHighDPI(void) const noexcept;
    bool mouseCapture(void) const noexcept;
    // X11 only
    bool isAlwaysOnTop(void) const noexcept;
    bool skipTaskbar(void) const noexcept;
    bool isUtility(void) const noexcept;
    bool isTooltip(void) const noexcept;
    bool isPopupMenu(void) const noexcept;

    void setFullscreen(void) noexcept;
    void resetFullscreen(void) noexcept;
    void setOpenGL(void) noexcept;
    void resetOpenGL(void) noexcept;
    void setShown(void) noexcept;
    void resetShown(void) noexcept;
    void setHidden(void) noexcept;
    void resetHidden(void) noexcept;
    void setBorderless(void) noexcept;
    void resetBorderless(void) noexcept;
    void setResizable(void) noexcept;
    void resetResizable(void) noexcept;
    void setMinimized(void) noexcept;
    void resetMinimized(void) noexcept;
    void setMaximized(void) noexcept;
    void resetMaximized(void) noexcept;
    void setInputGrabbed(void) noexcept;
    void resetInputGrabbed(void) noexcept;
    void setInputFocus(void) noexcept;
    void resetInputFocus(void) noexcept;
    void setMouseFocus(void) noexcept;
    void resetMouseFocus(void) noexcept;
    void setFullscreenDesktop(void) noexcept;
    void resetFullscreenDesktop(void) noexcept;
    void setForeign(void) noexcept;
    void resetForeign(void) noexcept;
    void setAllowHighDPI(void) noexcept;
    void resetAllowHighDPI(void) noexcept;
    void setMouseCapture(void) noexcept;
    void resetMouseCapture(void) noexcept;
    // X11 only
    void setAlwaysOnTop(void) noexcept;
    void resetAlwaysOnTop(void) noexcept;
    void setSkipTaskbar(void) noexcept;
    void resetSkipTaskbar(void) noexcept;
    void setUtility(void) noexcept;
    void resetUtility(void) noexcept;
    void setTooltip(void) noexcept;
    void resetTooltip(void) noexcept;
    void setPopupMenu(void) noexcept;
    void resetPopupMenu(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType flags_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindowFlags_hpp */
