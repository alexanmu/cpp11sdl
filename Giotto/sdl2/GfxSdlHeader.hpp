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

#ifndef GfxSdlHeader_hpp
#define GfxSdlHeader_hpp

#include "../platform/Linux.h"
#include "../platform/macOS.h"
#include "../platform/Windows.h"

#if defined(__linux_machine) && defined(__macosx_machine)
#error "Only one machine should be defined!"
#endif

namespace sdl2 {
#ifdef __linux_machine
#include "include/SDL.h"
#include "include/SDL_bits.h"
#endif

#ifdef __macosx_machine
#include "SDL2/SDL.h"
#include "SDL2/SDL_bits.h"
#endif

#ifdef __windows_machine
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_bits.h"
#endif
}

#endif
