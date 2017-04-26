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

#include "GfxWindowFlags.hpp"

GfxWindowFlags::GfxWindowFlags() : GfxRootClass("GfxWindowFlags")
{
    flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowFlagUnknown);
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlagsValues flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = static_cast<SdlType>(flag);
}

GfxWindowFlags::GfxWindowFlags(SdlType flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = flag;
}

GfxWindowFlags::GfxWindowFlags(SdlTypePtr flag) : GfxRootClass("GfxWindowFlags")
{
    flags_ = *flag;
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlags const& other) : GfxRootClass("GfxWindowFlags")
{
    flags_ = other.flags_;
}

GfxWindowFlags::GfxWindowFlags(GfxWindowFlags&& other) : GfxRootClass("GfxWindowFlags")
{
    flags_ = other.flags_;
    // Delete other's data
    other.flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowFlagUnknown);
}

GfxWindowFlags& GfxWindowFlags::operator=(GfxWindowFlags const& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxWindowFlags& GfxWindowFlags::operator=(GfxWindowFlags&& other)
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.flags_ = static_cast<SdlType>(GfxWindowFlagsValues::windowFlagUnknown);
    }
    return *this;
}

/* Getters ... */
bool GfxWindowFlags::isUnkown(void) const
{
    return (flags_ == 0);
}

bool GfxWindowFlags::isFullscreen(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_FULLSCREEN;

    return (r != 0);
}

bool GfxWindowFlags::isOpenGL(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_OPENGL;

    return (r != 0);
}

bool GfxWindowFlags::isShown(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_SHOWN;

    return (r != 0);
}

bool GfxWindowFlags::isHidden(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_HIDDEN;

    return (r != 0);
}

bool GfxWindowFlags::isBorderless(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_BORDERLESS;

    return (r != 0);
}

bool GfxWindowFlags::isResizable(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_RESIZABLE;

    return (r != 0);
}

bool GfxWindowFlags::isMinimized(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_MINIMIZED;

    return (r != 0);
}

bool GfxWindowFlags::isMaximized(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_MAXIMIZED;

    return (r != 0);
}

bool GfxWindowFlags::isInputGrabbed(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_INPUT_GRABBED;

    return (r != 0);
}

bool GfxWindowFlags::isInputFocus(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_INPUT_FOCUS;

    return (r != 0);
}

bool GfxWindowFlags::isMouseFocus(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_MOUSE_FOCUS;

    return (r != 0);
}

bool GfxWindowFlags::isFullscreenDesktop(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_FULLSCREEN_DESKTOP;

    return (r != 0);
}

bool GfxWindowFlags::isForeign(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_FOREIGN;

    return (r != 0);
}

bool GfxWindowFlags::allowHighDPI(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_ALLOW_HIGHDPI;

    return (r != 0);
}

bool GfxWindowFlags::mouseCapture(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_MOUSE_CAPTURE;

    return (r != 0);
}

// X11 only
bool GfxWindowFlags::isAlwaysOnTop(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_ALWAYS_ON_TOP;

    return (r != 0);
}

bool GfxWindowFlags::skipTaskbar(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_SKIP_TASKBAR;

    return (r != 0);
}

bool GfxWindowFlags::isUtility(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_UTILITY;

    return (r != 0);
}

bool GfxWindowFlags::isTooltip(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_TOOLTIP;

    return (r != 0);
}

bool GfxWindowFlags::isPopupMenu(void) const
{
    uint32_t r = flags_ & SDL_WINDOW_POPUP_MENU;

    return (r != 0);
}

/* Setters .. */
void GfxWindowFlags::setFullscreen(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_FULLSCREEN);
}

void GfxWindowFlags::resetFullscreen(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_FULLSCREEN);
}

void GfxWindowFlags::setOpenGL(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_OPENGL);
}

void GfxWindowFlags::resetOpenGL(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_OPENGL);
}

void GfxWindowFlags::setShown(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_SHOWN);
}

void GfxWindowFlags::resetShown(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_SHOWN);
}

void GfxWindowFlags::setHidden(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_HIDDEN);
}

void GfxWindowFlags::resetHidden(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_HIDDEN);
}

void GfxWindowFlags::setBorderless(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_BORDERLESS);
}

void GfxWindowFlags::resetBorderless(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_BORDERLESS);
}

void GfxWindowFlags::setResizable(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_RESIZABLE);
}

void GfxWindowFlags::resetResizable(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_RESIZABLE);
}

void GfxWindowFlags::setMinimized(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_MINIMIZED);
}

void GfxWindowFlags::resetMinimized(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_MINIMIZED);
}

void GfxWindowFlags::setMaximized(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_MAXIMIZED);
}

void GfxWindowFlags::resetMaximized(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_MAXIMIZED);
}

void GfxWindowFlags::setInputGrabbed(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_INPUT_GRABBED);
}

void GfxWindowFlags::resetInputGrabbed(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_INPUT_GRABBED);
}

void GfxWindowFlags::setInputFocus(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_INPUT_FOCUS);
}

void GfxWindowFlags::resetInputFocus(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_INPUT_FOCUS);
}

void GfxWindowFlags::setMouseFocus(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_MOUSE_FOCUS);
}

void GfxWindowFlags::resetMouseFocus(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_MOUSE_FOCUS);
}

void GfxWindowFlags::setFullscreenDesktop(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void GfxWindowFlags::resetFullscreenDesktop(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void GfxWindowFlags::setForeign(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_FOREIGN);
}

void GfxWindowFlags::resetForeign(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_FOREIGN);
}

void GfxWindowFlags::setAllowHighDPI(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_ALLOW_HIGHDPI);
}

void GfxWindowFlags::resetAllowHighDPI(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_ALLOW_HIGHDPI);
}

void GfxWindowFlags::setMouseCapture(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_MOUSE_CAPTURE);
}

void GfxWindowFlags::resetMouseCapture(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_MOUSE_CAPTURE);
}

// X11 only
void GfxWindowFlags::setAlwaysOnTop(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_ALWAYS_ON_TOP);
}

void GfxWindowFlags::resetAlwaysOnTop(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_ALWAYS_ON_TOP);
}

void GfxWindowFlags::setSkipTaskbar(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_SKIP_TASKBAR);
}
void GfxWindowFlags::resetSkipTaskbar(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_SKIP_TASKBAR);
}

void GfxWindowFlags::setUtility(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_UTILITY);
}

void GfxWindowFlags::resetUtility(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_UTILITY);
}

void GfxWindowFlags::setTooltip(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_TOOLTIP);
}

void GfxWindowFlags::resetTooltip(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_TOOLTIP);
}

void GfxWindowFlags::setPopupMenu(void)
{
    flags_ = static_cast<SdlType>(flags_ | SDL_WINDOW_POPUP_MENU);
}

void GfxWindowFlags::resetPopupMenu(void)
{
    flags_ = static_cast<SdlType>(flags_ & ~SDL_WINDOW_POPUP_MENU);
}

// SDL type access
GfxWindowFlags::SdlType GfxWindowFlags::getAsSdlType(void) const
{
    return flags_;
}

GfxWindowFlags::SdlTypePtr GfxWindowFlags::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&flags_;
}

/* EOF */
