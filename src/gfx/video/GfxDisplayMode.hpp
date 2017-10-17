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

#ifndef GfxDisplayMode_hpp
#define GfxDisplayMode_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxPixelFormatEnum.hpp"

namespace gfx
{

namespace video
{

class GfxDisplayMode final : public GfxObject
{
public:
    typedef sdl2::SDL_DisplayMode SdlType;
    typedef sdl2::SDL_DisplayMode * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxDisplayMode() noexcept;

    explicit GfxDisplayMode(const uint32_t format, const int32_t w, const int32_t h, const int32_t refresh) noexcept;
    explicit GfxDisplayMode(const SdlType mode) noexcept;

    // Copy Ctor not supported due to driver_data ptr
    GfxDisplayMode(GfxDisplayMode const&) = delete;
    GfxDisplayMode(GfxDisplayMode&& other) noexcept;

    // Copy operator not supported due to driver_data ptr
    GfxDisplayMode& operator=(GfxDisplayMode const&) = delete;
    GfxDisplayMode& operator=(GfxDisplayMode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    pixels::GfxPixelFormatEnum getFormat(void) const noexcept;
    int32_t getWidth(void) const noexcept;
    int32_t getHeight(void) const noexcept;
    int32_t getRefreshRate(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType dmode_;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxDisplayMode_hpp */
