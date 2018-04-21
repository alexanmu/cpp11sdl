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

#ifndef GfxYuvConversionMode_hpp
#define GfxYuvConversionMode_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace surface
{

class GfxYuvConversionMode final : public GfxObject
{
public:
    typedef SDL_YUV_CONVERSION_MODE SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        convModeJpeg = SDL_YUV_CONVERSION_JPEG,
        convModeBT601 = SDL_YUV_CONVERSION_BT601,
        convModeBT709 = SDL_YUV_CONVERSION_BT709,
        convModeAuto = SDL_YUV_CONVERSION_AUTOMATIC
    };

    GfxYuvConversionMode() noexcept;

    explicit GfxYuvConversionMode(const ValueType convMode) noexcept;
    explicit GfxYuvConversionMode(const SdlType convMode) noexcept;

    GfxYuvConversionMode(const GfxYuvConversionMode& other) noexcept;
    GfxYuvConversionMode(GfxYuvConversionMode&& other) noexcept;

    GfxYuvConversionMode& operator=(const GfxYuvConversionMode& other) noexcept;
    GfxYuvConversionMode& operator=(GfxYuvConversionMode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isConversionJPEG(void) const noexcept;
    bool isConversionBT601(void) const noexcept;
    bool isConversionBT709(void) const noexcept;
    bool isConversionAutomatic(void) const noexcept;

    void setModeJPEG(void) noexcept;
    void setModeBT601(void) noexcept;
    void setModeBT709(void) noexcept;
    void setModeAutomatic(void) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType convMode_;
};

}  // namespace surface

}  // namespace gfx

#endif /* GfxYuvConversionMode_hpp */
