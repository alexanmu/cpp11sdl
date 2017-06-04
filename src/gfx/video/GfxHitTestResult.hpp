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

#ifndef GfxHitTestResult_hpp
#define GfxHitTestResult_hpp

#include <string>
#include <cstdint>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace video
{

class GfxHitTestResult final : public GfxRootClass
{
public:
    typedef sdl2::SDL_HitTestResult SdlType;

    static const char ClassName[];

    enum class ValueType : int32_t
    {
        hittestNormal = sdl2::SDL_HITTEST_NORMAL,
        hittestDraggable = sdl2::SDL_HITTEST_DRAGGABLE,
        hittestResizeTopLeft = sdl2::SDL_HITTEST_RESIZE_TOPLEFT,
        hittestResizeTop = sdl2::SDL_HITTEST_RESIZE_TOP,
        hittestResizeTopRight = sdl2::SDL_HITTEST_RESIZE_TOPRIGHT,
        hittestResizeRight = sdl2::SDL_HITTEST_RESIZE_RIGHT,
        hittestResizeBottomRight = sdl2::SDL_HITTEST_RESIZE_BOTTOMRIGHT,
        hittestResizeBottom = sdl2::SDL_HITTEST_RESIZE_BOTTOM,
        hittestResizeBottomLeft = sdl2::SDL_HITTEST_RESIZE_BOTTOMLEFT,
        hittestResizeLeft = sdl2::SDL_HITTEST_RESIZE_LEFT
    };

    GfxHitTestResult() noexcept;
    explicit GfxHitTestResult(const ValueType value) noexcept;
    explicit GfxHitTestResult(const SdlType value) noexcept;

    GfxHitTestResult(GfxHitTestResult const& other) noexcept;
    GfxHitTestResult(GfxHitTestResult&& other) noexcept;

    GfxHitTestResult& operator=(GfxHitTestResult const& other) noexcept;
    GfxHitTestResult& operator=(GfxHitTestResult&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    void set(const ValueType value) noexcept;
    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxHitTestResult_hpp */
