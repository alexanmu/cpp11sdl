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

#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <string>
#include <vector>
#include <memory>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

namespace gfx
{

class GfxPalette final : public GfxRootClass
{
public:
    typedef sdl2::SDL_Palette SdlType;
    typedef sdl2::SDL_Palette* SdlTypePtr;

    static const char ClassName[];

    using GfxColorVector = std::vector<GfxColor>;

    GfxPalette();
    explicit GfxPalette(const uint16_t nColors);
    explicit GfxPalette(const SdlTypePtr pal);
    explicit GfxPalette(const GfxColorVector& colors);

    // No copy-ctor
    GfxPalette(const GfxPalette& other) = delete;
    GfxPalette(GfxPalette&& other);

    virtual ~GfxPalette();

    // No copy-oprtr
    GfxPalette& operator=(const GfxPalette& other) = delete;
    GfxPalette& operator=(GfxPalette&& other);

    /* Methods */
    void freePalette(void);

    void setPaletteColors(const GfxColorVector& vec, const uint16_t firstColor);
    GfxColorVector getPaletteColors(void) const;

    /* Getters */
    uint16_t getNumColors(void) const;
    uint32_t getVersion(void) const;
    int getRefCount(void) const;

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    static constexpr uint16_t kDefaultPaletteSize = 256;
    static constexpr uint8_t kDefaultPaletteColorRed = 0xFF;
    static constexpr uint8_t kDefaultPaletteColorGreen = 0xFF;
    static constexpr uint8_t kDefaultPaletteColorBlue = 0xFF;

    SdlTypePtr pal_;
};

}  // namespace gfx

#endif
