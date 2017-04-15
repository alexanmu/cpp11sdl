#ifndef GfxSdlHeader_hpp
#define GfxSdlHeader_hpp

#include "../Linux/Linux.h"
#include "../macOS/macOS.h"

#if defined(__linux_machine) && defined(__macosx_machine)
#error "Only one machine should be defined!"
#endif

#ifdef __linux_machine
#include "include/SDL.h"
#endif

#ifdef __macosx_machine
#include "SDL2/SDL.h"
#endif

#endif
