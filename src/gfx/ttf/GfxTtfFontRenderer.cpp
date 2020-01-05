/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#include <cassert>
#include <cstdint>
#include <string>
#include <utility>

#include "GfxTtfFontRenderer.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttffontrenderer::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfFontRenderer::ClassName[] = "GfxTtfFontRenderer";

GfxTtfFontRenderer::GfxTtfFontRenderer() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    ttf_ = nullptr;
}

GfxTtfFontRenderer::GfxTtfFontRenderer(GfxTtfFont * ttf) throw(std::runtime_error) : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    if (ttf == nullptr)
    {
        throw std::runtime_error("nullptr");
    }
    ttf_ = ttf;
}

GfxTtfFontRenderer::GfxTtfFontRenderer(const GfxTtfFontRenderer& other) noexcept : GfxObject(other)
{
    LOG_TRACE_PRIO_MED();

    ttf_ = other.ttf_;
}

GfxTtfFontRenderer::GfxTtfFontRenderer(GfxTtfFontRenderer&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    ttf_ = other.ttf_;
    // Delete other's data
    other.ttf_ = nullptr;
}

GfxTtfFontRenderer& GfxTtfFontRenderer::operator=(const GfxTtfFontRenderer& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Copy base
        GfxObject::operator=(other);
        // Copy this
        ttf_ = other.ttf_;
    }
    return *this;
}

GfxTtfFontRenderer& GfxTtfFontRenderer::operator=(GfxTtfFontRenderer&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        ttf_ = other.ttf_;
        // Delete other's data
        other.ttf_ = nullptr;
    }
    return *this;
}

GfxTtfFontRenderer::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxTtfFontRenderer::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxTtfFont * GfxTtfFontRenderer::getFont(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return ttf_;
}

void GfxTtfFontRenderer::setFont(GfxTtfFont * ttf) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    if (ttf == nullptr)
    {
        throw std::runtime_error("nullptr");
    }
    ttf_ = ttf;
}

bool GfxTtfFontRenderer::sizeText(const std::string& text, int32_t * w, int32_t * h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    if (ttf_ != nullptr)
    {
        return (TTF_SizeText(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
    }
    return false;
}

bool GfxTtfFontRenderer::sizeUtf8(const std::string& text, int32_t * w, int32_t * h) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    if (ttf_ != nullptr)
    {
        return (TTF_SizeUTF8(ttf_->getAsSdlTypePtr(), text.c_str(), w, h) == 0);
    }
    return false;
}

bool GfxTtfFontRenderer::sizeUnicode(const std::string& text, int32_t * w, int32_t * h) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(w != nullptr);
    assert(h != nullptr);

    throw std::runtime_error("Not supported");
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextSolid(const std::string& text,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderText_Solid(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextSolid", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Solid(const std::string& text,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderUTF8_Solid(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextUtf8Solid", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeSolid(const std::string& text,
            const gfx::pixels::GfxColor& fg) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(fg);

    throw std::runtime_error("Not implemented");
}

surface::GfxSurface * GfxTtfFontRenderer::renderGlyphSolid(const uint16_t ch,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderGlyph_Solid(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderGlyphSolid", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextShaded(const std::string& text, const gfx::pixels::GfxColor& fg,
            const gfx::pixels::GfxColor& bg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderText_Shaded(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType(), bg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextShaded", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Shaded(const std::string& text, const gfx::pixels::GfxColor& fg,
            const gfx::pixels::GfxColor& bg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderUTF8_Shaded(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType(), bg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextUtf8Shaded", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeShaded(const std::string& text,
            const gfx::pixels::GfxColor& fg, const gfx::pixels::GfxColor& bg) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(fg);
    assert(bg);

    throw std::runtime_error("Not implemented");
}

surface::GfxSurface * GfxTtfFontRenderer::renderGlyphShaded(const uint16_t ch, const gfx::pixels::GfxColor& fg,
            const gfx::pixels::GfxColor& bg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderGlyph_Shaded(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType(), bg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderGlyphShaded", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextBlended(const std::string& text,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderText_Blended(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextBlended", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUtf8Blended(const std::string& text,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderUTF8_Blended(ttf_->getAsSdlTypePtr(), text.c_str(), fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderTextUtf8Blended", surf, false);
        }
    }
    return nullptr;
}

surface::GfxSurface * GfxTtfFontRenderer::renderTextUnicodeBlended(const std::string& text,
            const gfx::pixels::GfxColor& fg) const throw(std::runtime_error)
{
    LOG_TRACE_PRIO_LOW();

    assert(text.length() > 0);
    assert(fg);

    throw std::runtime_error("Not implemented");
}

surface::GfxSurface * GfxTtfFontRenderer::renderGlyphBlended(const uint16_t ch,
            const gfx::pixels::GfxColor& fg) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    surface::GfxSurface::SdlTypePtr surf;

    if (ttf_ != nullptr)
    {
        surf = TTF_RenderGlyph_Blended(ttf_->getAsSdlTypePtr(), ch, fg.getAsSdlType());
        if (surf != nullptr)
        {
            return new surface::GfxSurface("GfxTtfFontRenderer::renderGlyphBlended", surf, false);
        }
    }
    return nullptr;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
