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

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace video
{

class GfxWindowPosition final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        positionUndefined = SDL_WINDOWPOS_UNDEFINED,
        positionCentered = SDL_WINDOWPOS_CENTERED,
        positionSpecified
    };

    GfxWindowPosition() noexcept;

    explicit GfxWindowPosition(const ValueType pos, const int32_t coord = -1) noexcept;

    GfxWindowPosition(GfxWindowPosition const& other) noexcept;
    GfxWindowPosition(GfxWindowPosition&& other) noexcept;

    GfxWindowPosition& operator=(GfxWindowPosition const& other) noexcept;
    GfxWindowPosition& operator=(GfxWindowPosition&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setPosition(const ValueType pos) noexcept;
    ValueType getPosition(void) const noexcept;

    void setCoordinate(const int32_t coord = 0) noexcept;
    int32_t getCoordinate(void) const noexcept;

    void clear(void) noexcept;
private:
    ValueType pos_;
    uint32_t coord_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxWindowPosition_hpp */
