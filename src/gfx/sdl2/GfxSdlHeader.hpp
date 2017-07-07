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

namespace gfx
{

namespace sdl2
{

#include "SDL.h"
#include "SDL_bits.h"
#include "SDL_ttf.h"

}  // namespace sdl2

}  // namespace gfx

/*
    New features, not yet present in SDL release-2.0.5; must be removed when 2.0.6 will be relased!
    Compiler error expected here in case on conflicts.
*/
namespace gfx
{

namespace sdl2
{

/* GfxJoystickType.hpp */
typedef enum
{
    SDL_JOYSTICK_TYPE_UNKNOWN,
    SDL_JOYSTICK_TYPE_GAMECONTROLLER,
    SDL_JOYSTICK_TYPE_WHEEL,
    SDL_JOYSTICK_TYPE_ARCADE_STICK,
    SDL_JOYSTICK_TYPE_FLIGHT_STICK,
    SDL_JOYSTICK_TYPE_DANCE_PAD,
    SDL_JOYSTICK_TYPE_GUITAR,
    SDL_JOYSTICK_TYPE_DRUM_KIT,
    SDL_JOYSTICK_TYPE_ARCADE_PAR,
    SDL_JOYSTICK_TYPE_THROTTLE
} SDL_JoystickType;

/* GfxHints.cpp */
#define SDL_HINT_RENDER_LOGICAL_SIZE_MODE "SDL_HINT_RENDER_LOGICAL_SIZE_MODE"
#define SDL_HINT_MOUSE_NORMAL_SPEED_SCALE "SDL_HINT_MOUSE_NORMAL_SPEED_SCALE"
#define SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE "SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE"
#define SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION "SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION"
#define SDL_HINT_QTWAYLAND_WINDOW_FLAGS "SDL_HINT_QTWAYLAND_WINDOW_FLAGS"
#define SDL_HINT_OPENGLES_VIDEO_DRIVER "SDL_HINT_OPENGLES_VIDEO_DRIVER"
#define SDL_HINT_AUDIO_RESAMPLING_MODE "SDL_HINT_AUDIO_RESAMPLING_MODE"

/* GfxJoystick.cpp */
inline int SDL_JoystickGetDeviceVendor(int) { return 0; }
inline int SDL_JoystickGetDeviceProduct(int) { return 0; }
inline int SDL_JoystickGetDeviceProductVersion(int) { return 0; }
inline SDL_JoystickType SDL_JoystickGetDeviceType(int) { return static_cast<SDL_JoystickType>(0); }
inline SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int) { return static_cast<SDL_JoystickID>(-1); }
inline Uint16 SDL_JoystickGetVendor(SDL_Joystick *) { return 0; }
inline Uint16 SDL_JoystickGetProduct(SDL_Joystick *) { return 0; }
inline Uint16 SDL_JoystickGetProductVersion(SDL_Joystick *) { return 0; }
inline SDL_JoystickType SDL_JoystickGetType(SDL_Joystick *) { return static_cast<SDL_JoystickType>(0); }
inline SDL_bool SDL_JoystickGetAxisInitialState(SDL_Joystick *, int, Sint16 *) { return static_cast<SDL_bool>(0); }

}  // namespace sdl2

}  // namespace gfx

#endif /* GfxSdlHeader_hpp */
