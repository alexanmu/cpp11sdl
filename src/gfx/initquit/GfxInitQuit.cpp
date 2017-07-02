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
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxinitquit::initquit::gfx");

namespace gfx
{

namespace initquit
{

const char GfxInitQuit::ClassName[] = "GfxInitQuit";

GfxInitQuit::GfxInitQuit() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_TOP();

    flags_.clear();
    errorCode_ = sdl2::SDL_Init(flags_.getAsSdlType());
}

GfxInitQuit::GfxInitQuit(GfxInitFlags const& flags) noexcept :
                GfxObject(ClassName), flags_(flags), errorCode_(0)
{
    LOG_TRACE_PRIO_TOP();

    assert(flags);

    errorCode_ = sdl2::SDL_Init(flags.getAsSdlType());
}

GfxInitQuit::GfxInitQuit(GfxInitQuit&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    flags_ = other.flags_;
    errorCode_ = other.errorCode_;
    // Delete other's data
    other.flags_.clear();
    other.errorCode_ = 0;
}

GfxInitQuit& GfxInitQuit::operator=(GfxInitQuit&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        flags_ = other.flags_;
        errorCode_ = other.errorCode_;
        // Delete other's data
        other.flags_.clear();
        other.errorCode_ = 0;
    }
    return *this;
}

GfxInitQuit::~GfxInitQuit() noexcept
{
    LOG_TRACE_PRIO_TOP();

    sdl2::SDL_Quit();
}

GfxInitQuit::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (errorCode_ != 0);
}

std::string GfxInitQuit::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxInitQuit::initSubSystem(GfxInitFlags const& flags) noexcept
{
    LOG_TRACE_PRIO_TOP();

    assert(flags);

    errorCode_ = sdl2::SDL_InitSubSystem(flags.getAsSdlType());
}

void GfxInitQuit::quitSubSystem(GfxInitFlags const& flags) const noexcept
{
    LOG_TRACE_PRIO_TOP();

    assert(flags);

    sdl2::SDL_QuitSubSystem(flags.getAsSdlType());
}

GfxInitFlags * GfxInitQuit::wasInit(GfxInitFlags const& flags) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(flags);

    int32_t ret;

    ret = sdl2::SDL_WasInit(flags.getAsSdlType());
    return new GfxInitFlags(ret);
}

void GfxInitQuit::quitRequested(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    // sdl2::SDL_QuitRequested();
    sdl2::SDL_PumpEvents();
    sdl2::SDL_PeepEvents(NULL, 0, sdl2::SDL_PEEKEVENT, sdl2::SDL_QUIT, sdl2::SDL_QUIT);
}

// Return error code after init call
int32_t GfxInitQuit::getErrorCode() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return errorCode_;
}

}  // namespace initquit

}  // namespace gfx

/* EOF */
