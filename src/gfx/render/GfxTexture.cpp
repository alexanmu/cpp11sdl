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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxTexture.hpp"
#include "GfxRenderer.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxtexture::render::gfx");

namespace gfx
{

namespace render
{

const char GfxTexture::ClassName[] = "GfxTexture";

GfxTexture::GfxTexture() : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    tex_ = nullptr;
    texName_ = "";
}

GfxTexture::GfxTexture(std::string const& texname, void * rend, pixels::GfxPixelFormatEnum const& format,
                       GfxTextureAccess const& acc, const int32_t w, const int32_t h) throw(std::runtime_error) :
                       GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(texname.length() > 0);
    assert(rend != nullptr);
    assert(format);
    assert(acc);
    assert(w >= 0);
    assert(h >= 0);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = SDL_CreateTexture(rendptr->getAsSdlTypePtr(),
                                     format.getAsSdlType(),
                                     acc.getAsSdlType(),
                                     w, h);
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
    texName_ = texname;
}

GfxTexture::GfxTexture(std::string const& texname, void * rend, surface::GfxSurface const& surf)
                       throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(texname.length() > 0);
    assert(rend != nullptr);
    assert(surf);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(), surf.getAsSdlTypePtr());
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
    texName_ = texname;
}

GfxTexture::GfxTexture(GfxTexture&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    tex_ = other.tex_;
    // Destroy other's data
    other.tex_ = nullptr;
}

GfxTexture& GfxTexture::operator=(GfxTexture&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        if (tex_ != nullptr)
        {
            SDL_DestroyTexture(tex_);
        }
        tex_ = other.tex_;
        // Destroy other's data
        other.tex_ = nullptr;
    }
    return *this;
}

GfxTexture::~GfxTexture() noexcept
{
    LOG_TRACE_PRIO_MED();

    if (tex_ != nullptr)
    {
        SDL_DestroyTexture(tex_);
    }
    tex_ = nullptr;
}

GfxTexture::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (tex_ != nullptr);
}

std::string GfxTexture::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxTexture::createTexture(std::string const& texname, void * rend, pixels::GfxPixelFormatEnum const& format,
                               GfxTextureAccess const& acc, const int32_t w, const int32_t h)
                               throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(texname.length() > 0);
    assert(rend != nullptr);
    assert(format);
    assert(acc);
    assert(w >= 0);
    assert(h >= 0);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    if (tex_ != nullptr)
    {
        throw std::runtime_error("Texture already created");
    }
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = SDL_CreateTexture(rendptr->getAsSdlTypePtr(),
                                     format.getAsSdlType(),
                                     acc.getAsSdlType(),
                                     w, h);
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
    texName_ = texname;
}

void GfxTexture::createTexture(std::string const& texname, void * rend, surface::GfxSurface const& surf)
                               throw(std::runtime_error)
{
    LOG_TRACE_PRIO_MED();

    assert(texname.length() > 0);
    assert(rend != nullptr);
    assert(surf);

    GfxRenderer * rendptr;
    SdlTypePtr texptr;

    if (tex_ != nullptr)
    {
        throw std::runtime_error("Texture already created");
    }
    rendptr = reinterpret_cast<GfxRenderer *>(rend);
    texptr = SDL_CreateTextureFromSurface(rendptr->getAsSdlTypePtr(), surf.getAsSdlTypePtr());
    if (texptr == nullptr)
    {
        throw std::runtime_error("Unable to create texture");
    }
    tex_ = texptr;
    texName_ = texname;
}

void GfxTexture::queryTexture(pixels::GfxPixelFormatEnum ** format, GfxTextureAccess ** acc, int32_t * w,
                              int32_t * h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(format != nullptr);
    assert(acc != nullptr);
    assert(w != nullptr);
    assert(h != nullptr);

    pixels::GfxPixelFormatEnum::SdlType sdlfmt;
    int32_t u32sdlacc;

    if (tex_ != nullptr)
    {
        SDL_QueryTexture(tex_, &sdlfmt, &u32sdlacc, w, h);
        *format = new pixels::GfxPixelFormatEnum(sdlfmt);
        *acc = new GfxTextureAccess(u32sdlacc);
    }
}

void GfxTexture::setTextureColorMod(const uint8_t r, const uint8_t g, const uint8_t b) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_SetTextureColorMod(tex_, r, g, b);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::setTextureColorMod(pixels::GfxColor const& color) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_SetTextureColorMod(tex_, color.getRed(), color.getGreen(), color.getBlue());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::getTextureColorMod(uint8_t * r, uint8_t * g, uint8_t * b) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(r != nullptr);
    assert(g != nullptr);
    assert(b != nullptr);

    int32_t ret = 1;

    *r = 0;
    *g = 0;
    *b = 0;
    if (tex_ != nullptr)
    {
        ret = SDL_GetTextureColorMod(tex_, r, g, b);
        assert((ret == -1) || (ret == 0));
    }
}

pixels::GfxColor GfxTexture::getTextureColorMod(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    uint8_t r;
    uint8_t g;
    uint8_t b;

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_GetTextureColorMod(tex_ , &r, &g, &b);
        assert((ret == -1) || (ret == 0));
        if (ret == 0)
        {
            return pixels::GfxColor(r, g, b);
        }
    }
    return pixels::GfxColor();
}

void GfxTexture::setTextureAlphaMod(const uint8_t a) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_SetTextureAlphaMod(tex_, a);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::getTextureAlphaMod(uint8_t * a) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(a != nullptr);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_GetTextureAlphaMod(tex_, a);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::setBlendMode(blendmode::GfxBlendMode const& blendmode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(blendmode);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_SetTextureBlendMode(tex_, blendmode.getAsSdlType());
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::setBlendMode(const blendmode::GfxBlendMode::ValueType blendmode) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_SetTextureBlendMode(tex_, static_cast<blendmode::GfxBlendMode::SdlType>(blendmode));
        assert((ret == -1) || (ret == 0));
    }
}

blendmode::GfxBlendMode GfxTexture::getBlendMode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    blendmode::GfxBlendMode::SdlType bm;

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_GetTextureBlendMode(tex_, &bm);
        assert((ret == -1) || (ret == 0));
        if (ret == 0)
        {
            return blendmode::GfxBlendMode(bm);
        }
    }
    return blendmode::GfxBlendMode();
}

void GfxTexture::updateTexture(rect::GfxRect const& rect, const void * pixels, const int32_t pitch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);
    assert(pixels != nullptr);
    assert(pitch > 0);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_UpdateTexture(tex_, rect.getAsSdlTypePtr(), pixels, pitch);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::updateYUVTexture(rect::GfxRect const& rect,
                                  const uint8_t * Yplane, const int32_t Ypitch,
                                  const uint8_t * Uplane, const int32_t Upitch,
                                  const uint8_t * Vplane, const int32_t Vpitch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);
    assert(Yplane != nullptr);
    assert(Ypitch > 0);
    assert(Uplane != nullptr);
    assert(Upitch > 0);
    assert(Vplane != nullptr);
    assert(Vpitch > 0);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_UpdateYUVTexture(tex_, rect.getAsSdlTypePtr(), Yplane, Ypitch,
                                         Uplane, Upitch, Vplane, Vpitch);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::lockTexture(rect::GfxRect const& rect, void ** pixels, int32_t * pitch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(rect);
    assert(pixels != nullptr);
    assert(pitch != nullptr);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_LockTexture(tex_, rect.getAsSdlTypePtr(), pixels, pitch);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::lockTexture(void ** pixels, int * pitch) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(pixels != nullptr);
    assert(pitch != nullptr);

    int32_t ret = 1;

    if (tex_ != nullptr)
    {
        ret = SDL_LockTexture(tex_, NULL, pixels, pitch);
        assert((ret == -1) || (ret == 0));
    }
}

void GfxTexture::unlockTexture(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    if (tex_ != nullptr)
    {
        SDL_UnlockTexture(tex_);
    }
}

void GfxTexture::destroyTexture(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (tex_ != nullptr)
    {
        SDL_DestroyTexture(tex_);
        tex_ = nullptr;
    }
}

GfxTexture::SdlTypePtr GfxTexture::getAsSdlTypePtr(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return tex_;
}

}  // namespace render

}  // namespace gfx

/* EOF */
