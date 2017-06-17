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

#ifndef GfxGetError_hpp
#define GfxGetError_hpp

#include <string>

#include "GfxObject.hpp"
#include "GfxError.hpp"

namespace gfx
{

namespace error
{

class GfxGetError final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxGetError() = delete;

    GfxGetError(GfxGetError const&) = delete;
    GfxGetError(GfxGetError&&) = delete;

    GfxGetError& operator=(GfxGetError const &) = delete;
    GfxGetError& operator=(GfxGetError&&) = delete;

    static GfxError getErrorObject(void) noexcept;
    static void clearSDL2Error(void) noexcept;
};

}  // namespace error

}  // namespace gfx

#endif /* GfxGetError_hpp */

