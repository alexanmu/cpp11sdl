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

#include <cassert>
#include <string>

#include "GfxControlledSurface.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxPixelFormat.hpp"
#include "GfxPixelFormatEnum.hpp"

namespace gfx
{

namespace xtra
{

const char GfxControlledSurface::ClassName[] = "GfxControlledSurface";
const pixels::GfxPixelFormatEnum::ValueType GfxControlledSurface::kDefaultSurfaceColorFormatValue =
    pixels::GfxPixelFormatEnum::ValueType::pixelFormatARGB8888;

GfxControlledSurface::GfxControlledSurface() noexcept : gfx::GfxObject(ClassName)
{
    surf_ = nullptr;
    surfaceConstructed_ = false;
}

GfxControlledSurface::GfxControlledSurface(const uint16_t w, const uint16_t h) noexcept
{
    assert((w > 1) && (w < 8192));
    assert((h > 1) && (h < 8192));

    surface::GfxSurface * tmpsurf;

    pixels::GfxPixelFormatEnum pixFmtEn(kDefaultSurfaceColorFormatValue);

    tmpsurf = new surface::GfxSurface("GfxControlledSurface::createSurface 1", surface::GfxSurfaceFlags(), w, h,
                                    kDefaultSurfaceColorDepth, pixFmtEn);
    if (tmpsurf != nullptr)
    {
        surf_ = tmpsurf;
        surfaceConstructed_ = true;
    }
    else
    {
        surf_ = tmpsurf;
        surfaceConstructed_ = false;
    }
}

GfxControlledSurface::GfxControlledSurface(std::string const& filename) noexcept
{
    assert(filename.length() > 0);

    surface::GfxSurface * tmpsurf;

    tmpsurf = new surface::GfxSurface("GfxControlledSurface::createSurface 2", filename);
    if (tmpsurf != nullptr)
    {
        surf_ = tmpsurf;
        surfaceConstructed_ = true;
    }
    else
    {
        surf_ = nullptr;
        surfaceConstructed_ = false;
    }
}

GfxControlledSurface::~GfxControlledSurface() noexcept
{
    if (surfaceConstructed_ == true)
    {
        delete surf_;
        surfaceConstructed_ = false;
        surf_ = nullptr;
    }
}

GfxControlledSurface::operator bool() const noexcept
{
    return (surf_ != nullptr);
}

void GfxControlledSurface::createSurface(const uint16_t w, const uint16_t h) throw(std::runtime_error)
{
    assert((w > 1) && (w < 8192));
    assert((h > 1) && (h < 8192));

    surface::GfxSurface * tmpsurf;

    pixels::GfxPixelFormatEnum pixFmtEn(kDefaultSurfaceColorFormatValue);

    if (surfaceConstructed_ == false)
    {
        tmpsurf = new surface::GfxSurface("GfxControlledSurface::createSurface 1+", surface::GfxSurfaceFlags(), w, h,
                                          kDefaultSurfaceColorDepth, pixFmtEn);
        if (tmpsurf != nullptr)
        {
            surf_ = tmpsurf;
            surfaceConstructed_ = true;
        }
        return;
    }
    throw std::runtime_error("Object already constructed");
}

void GfxControlledSurface::createSurface(std::string const& filename) throw(std::runtime_error)
{
    assert(filename.length() > 0);

    surface::GfxSurface * tmpsurf;

    if (surfaceConstructed_ == false)
    {
        tmpsurf = new surface::GfxSurface("GfxControlledSurface::createSurface 2+", filename);
        if (tmpsurf != nullptr)
        {
            surf_ = tmpsurf;
            surfaceConstructed_ = true;
        }
        return;
    }
    throw std::runtime_error("Object already constructed");
}

void GfxControlledSurface::freeSurface(void) noexcept
{
    if (surfaceConstructed_ == true)
    {
        delete surf_;
        surfaceConstructed_ = false;
        surf_ = nullptr;
    }
}

surface::GfxSurface& GfxControlledSurface::operator()(void) const throw(std::runtime_error)
{
    if (surfaceConstructed_ == false)
    {
        throw std::runtime_error("Object not constructed");
    }
    return *surf_;
}

}  // namespace xtra

}  // namespace gfx

/* EOF */
