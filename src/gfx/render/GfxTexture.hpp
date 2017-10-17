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

#ifndef GfxTexture_hpp
#define GfxTexture_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxSurface.hpp"
#include "GfxBlendMode.hpp"
#include "GfxTextureModulate.hpp"
#include "GfxTextureAccess.hpp"
#include "GfxPixelFormatEnum.hpp"

namespace gfx
{

namespace render
{

class GfxTexture final : public GfxObject
{
public:
    typedef sdl2::SDL_Texture * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxTexture();
    explicit GfxTexture(std::string const& texname, void * rend, pixels::GfxPixelFormatEnum const& format,
                        GfxTextureAccess const& acc, const int32_t w, const int32_t h) throw(std::runtime_error);
    explicit GfxTexture(std::string const& texname, void * rend, surface::GfxSurface const& surf)
                        throw(std::runtime_error);

    virtual ~GfxTexture() noexcept;

    GfxTexture(const GfxTexture&) = delete;
    GfxTexture(GfxTexture&& other) noexcept;

    GfxTexture& operator=(const GfxTexture&) = delete;
    GfxTexture& operator=(GfxTexture&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void createTexture(std::string const& texname, void * rend, pixels::GfxPixelFormatEnum const& format,
                       GfxTextureAccess const& acc, const int32_t w, const int32_t h) throw(std::runtime_error);
    void createTexture(std::string const& texname, void * rend, surface::GfxSurface const& surf)
                       throw(std::runtime_error);

    void queryTexture(pixels::GfxPixelFormatEnum ** format, GfxTextureAccess ** acc, int32_t * w,
                      int32_t * h) const noexcept;
    void setTextureColorMod(const uint8_t r, const uint8_t g, const uint8_t b) const noexcept;
    void setTextureColorMod(pixels::GfxColor const& color) const noexcept;
    void getTextureColorMod(uint8_t * r, uint8_t * g, uint8_t * b) const noexcept;
    pixels::GfxColor getTextureColorMod(void) const noexcept;
    void setTextureAlphaMod(const uint8_t a) const noexcept;
    void getTextureAlphaMod(uint8_t * a) const noexcept;
    void setBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept;
    void setBlendMode(const blendmode::GfxBlendMode::ValueType blendmode) const noexcept;
    blendmode::GfxBlendMode getBlendMode(void) const noexcept;
    void updateTexture(rect::GfxRect const& rect, const void * pixels, const int32_t pitch) const noexcept;
    void updateYUVTexture(rect::GfxRect const& rect, const uint8_t * Yplane, const int32_t Ypitch,
                          const uint8_t * Uplane, const int32_t Upitch,
                          const uint8_t * Vplane, const int32_t Vpitch) const noexcept;
    void lockTexture(rect::GfxRect const& rect, void ** pixels, int32_t * pitch) const noexcept;
    void lockTexture(void ** pixels, int32_t * pitch) const noexcept;
    void unlockTexture(void) const noexcept;
    void destroyTexture(void) noexcept;

    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlTypePtr tex_;
    std::string texName_;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxTexture_hpp */
