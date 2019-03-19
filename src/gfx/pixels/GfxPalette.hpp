/*
  Giotto
  Copyright (C) 2019 George Oros

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

#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxColor.hpp"

namespace gfx
{

namespace pixels
{

class GfxPalette final : public GfxObject
{
public:
    typedef SDL_Palette * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxPalette() noexcept;
    explicit GfxPalette(const uint16_t nColors) throw(std::runtime_error);
    explicit GfxPalette(const SdlTypePtr pal) noexcept;
    explicit GfxPalette(const std::vector<GfxColor>& colors) throw(std::runtime_error);

    // No copy-ctor
    GfxPalette(const GfxPalette&) = delete;
    GfxPalette(GfxPalette&& other) noexcept;

    // No copy-oprtr
    GfxPalette& operator=(const GfxPalette&) = delete;
    GfxPalette& operator=(GfxPalette&& other) noexcept;

    virtual ~GfxPalette() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createPalette(const uint16_t nColors) throw(std::runtime_error);
    void createPalette(const SdlTypePtr pal) throw(std::runtime_error);
    void createPalette(const std::vector<GfxColor>& colors) throw(std::runtime_error);

    void freePalette(void) noexcept;

    /* Methods */
    void setPaletteColors(const std::vector<GfxColor>& vec, const uint16_t firstColor) noexcept;
    const std::vector<GfxColor> getPaletteColors(void) const noexcept;
    void setPaletteColor(const GfxColor& clr, const uint16_t index) noexcept;
    const GfxColor getPaletteColor(const uint16_t index) noexcept;

    /* Getters */
    uint16_t getNumColors(void) const noexcept;
    uint32_t getVersion(void) const noexcept;
    int32_t getRefCount(void) const noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    void clear(void) noexcept;

    SdlTypePtr pal_;

    static const uint16_t kDefaultPaletteSize = 256;
    static const uint8_t kDefaultPaletteColorRed = 0xFF;
    static const uint8_t kDefaultPaletteColorGreen = 0xFF;
    static const uint8_t kDefaultPaletteColorBlue = 0xFF;
};

}  // namespace pixels

}  // namespace gfx

#endif
