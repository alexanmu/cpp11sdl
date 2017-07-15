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

#ifndef GfxSystemCursor_hpp
#define GfxSystemCursor_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace mouse
{

class GfxSystemCursor final : public GfxObject
{
public:
    typedef sdl2::SDL_SystemCursor SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        sysCursorArrow = sdl2::SDL_SYSTEM_CURSOR_ARROW,
        sysCursorIBeam = sdl2::SDL_SYSTEM_CURSOR_IBEAM,
        sysCursorWait = sdl2::SDL_SYSTEM_CURSOR_WAIT,
        sysCursorCrosshair = sdl2::SDL_SYSTEM_CURSOR_CROSSHAIR,
        sysCursorWaitArrow = sdl2::SDL_SYSTEM_CURSOR_WAITARROW,
        sysCursorSizeNorthWestSouthEast = sdl2::SDL_SYSTEM_CURSOR_SIZENWSE,
        sysCursorSizeNortheEastSouthWest = sdl2::SDL_SYSTEM_CURSOR_SIZENESW,
        sysCursorSizeWestEast = sdl2::SDL_SYSTEM_CURSOR_SIZEWE,
        sysCursorSizeNorthSouth = sdl2::SDL_SYSTEM_CURSOR_SIZENS,
        sysCursorSizeAll = sdl2::SDL_SYSTEM_CURSOR_SIZEALL,
        sysCursorNo = sdl2::SDL_SYSTEM_CURSOR_NO,
        sysCursorHand = sdl2::SDL_SYSTEM_CURSOR_HAND
    };

    GfxSystemCursor() noexcept;
    explicit GfxSystemCursor(const ValueType cursor) noexcept;
    explicit GfxSystemCursor(const SdlType cursor) noexcept;

    GfxSystemCursor(GfxSystemCursor const& other) noexcept;
    GfxSystemCursor(GfxSystemCursor&& other) noexcept;

    GfxSystemCursor& operator=(GfxSystemCursor const& other) noexcept;
    GfxSystemCursor& operator=(GfxSystemCursor&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType cursor_;
};

}  // namespace mouse

}  // namespace gfx

#endif /* GfxSystemCursor_hpp */
