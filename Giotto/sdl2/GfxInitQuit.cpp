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

#include "GfxInitQuit.hpp"

namespace gfx
{

const char GfxInitQuit::ClassName[] = "GfxInitQuit";

GfxInitQuit::GfxInitQuit(GfxInitFlags const& flags) :
                GfxRootClass(ClassName), flags_(flags), errorCode_(0)
{
    assert(flags);

    errorCode_ = sdl2::SDL_Init(flags.getAsSdlType());
}

GfxInitQuit::~GfxInitQuit()
{
    sdl2::SDL_Quit();
}

GfxInitQuit::operator bool() const
{
    return (errorCode_ != 0);
}

void GfxInitQuit::initSubSystem(GfxInitFlags const& flags)
{
    assert(flags);

    errorCode_ = sdl2::SDL_InitSubSystem(flags.getAsSdlType());
}

void GfxInitQuit::quitSubSystem(GfxInitFlags const& flags)
{
    assert(flags);

    sdl2::SDL_QuitSubSystem(flags.getAsSdlType());
}

GfxInitFlags * GfxInitQuit::wasInit(GfxInitFlags const& flags)
{
    assert(flags);

    int32_t ret;

    ret = sdl2::SDL_WasInit(flags.getAsSdlType());
    return new GfxInitFlags(ret);
}

void GfxInitQuit::quitRequested(void)
{
    // sdl2::SDL_QuitRequested();
    sdl2::SDL_PumpEvents();
    sdl2::SDL_PeepEvents(NULL, 0, sdl2::SDL_PEEKEVENT, sdl2::SDL_QUIT, sdl2::SDL_QUIT);
}

// Return error code after init call
int32_t GfxInitQuit::getErrorCode() const
{
    return errorCode_;
}

}  // namespace gfx

/* EOF */
