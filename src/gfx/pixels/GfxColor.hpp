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

#ifndef GfxColor_hpp
#define GfxColor_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxColor final : public GfxObject
{
public:
    typedef SDL_Color SdlType;
    typedef SDL_Color* SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxColor() noexcept;

    GfxColor(const uint8_t r, const uint8_t g, const uint8_t b) noexcept;
    GfxColor(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
             noexcept;
    explicit GfxColor(const SdlType clr) noexcept;
    explicit GfxColor(const uint32_t clr) noexcept;

    GfxColor(const GfxColor& other) noexcept;
    GfxColor(GfxColor&& other) noexcept;

    GfxColor& operator=(const GfxColor& other) noexcept;
    GfxColor& operator=(GfxColor&& other) noexcept;

    bool operator==(const GfxColor& other) const noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    /* Getters ... */
    uint8_t getRed(void) const noexcept;
    uint8_t getGreen(void) const noexcept;
    uint8_t getBlue(void) const noexcept;
    uint8_t getAlpha(void) const noexcept;

    uint32_t getColor(void) const noexcept /*__attribute__((warning("Endianess")))*/;

    /* Setters ... */
    void setRed(const uint8_t r) noexcept;
    void setGreen(const uint8_t g) noexcept;
    void setBlue(const uint8_t b) noexcept;
    void setAlpha(const uint8_t a) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType clr_;

    static const uint8_t kDefaultRedValue = 0;
    static const uint8_t kDefaultGreenValue = 0;
    static const uint8_t kDefaultBlueValue = 0;
    static const uint8_t kDefaultAlphaValue = 0xFF;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxColor_hpp */
