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
    New features, not yet present in SDL release-2.0.6; must be removed when 2.0.7 (or SDL 2.1) will be relased!
    Compiler error expected here in case on conflicts.
*/
namespace gfx
{

namespace sdl2
{

/* Empty for now */

}  // namespace sdl2

}  // namespace gfx

#endif /* GfxSdlHeader_hpp */
