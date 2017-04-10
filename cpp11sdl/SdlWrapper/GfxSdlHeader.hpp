#ifndef GfxSdlHeader_hpp
#define GfxSdlHeader_hpp

//#define __linux_machine
#define __macosx_machine

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
