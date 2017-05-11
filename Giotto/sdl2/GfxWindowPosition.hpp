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

#ifndef GfxWindowPosition_hpp
#define GfxWindowPosition_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxWindowPosition final : public GfxRootClass
{
public:
    static const char ClassName[];

    enum class GfxWindowPositionValues : int
    {
        positionUndefined = SDL_WINDOWPOS_UNDEFINED,
        positionCentered = SDL_WINDOWPOS_CENTERED,
        positionSpecified
    };

    GfxWindowPosition();

    explicit GfxWindowPosition(const GfxWindowPositionValues pos, const uint32_t coord = 0);

    GfxWindowPosition(GfxWindowPosition const& other);
    GfxWindowPosition(GfxWindowPosition&& other);

    GfxWindowPosition& operator=(GfxWindowPosition const& other);
    GfxWindowPosition& operator=(GfxWindowPosition&& other);

    void setPosition(const GfxWindowPositionValues pos);
    GfxWindowPositionValues getPosition(void) const;

    void setCoordinate(uint32_t coord = -1);
    uint32_t getCoordinate(void) const;
private:
    GfxWindowPositionValues pos_;
    uint32_t coord_;
};

}  // namespace gfx

#endif /* GfxWindowPosition_hpp */
