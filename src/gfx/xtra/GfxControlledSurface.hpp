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

#ifndef GfxControlledSurface_hpp
#define GfxControlledSurface_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxSurface.hpp"
#include "GfxPixelFormatEnum.hpp"
#include "GfxWindow.hpp"

namespace gfx
{

namespace xtra
{

class GfxControlledSurface final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;

    GfxControlledSurface() noexcept;
    explicit GfxControlledSurface(const uint16_t w, const uint16_t h) noexcept;
    explicit GfxControlledSurface(std::string const& filename) noexcept;
    explicit GfxControlledSurface(video::GfxWindow const& win) noexcept;

    GfxControlledSurface(const GfxControlledSurface&) = delete;
    GfxControlledSurface(GfxControlledSurface&& surf) = delete;

    GfxControlledSurface& operator=(const GfxControlledSurface&) = delete;
    GfxControlledSurface& operator=(GfxControlledSurface&& surf) = delete;

    virtual ~GfxControlledSurface() noexcept;

    virtual explicit operator bool() const noexcept;

    void createSurface(const uint16_t w, const uint16_t h) throw(std::runtime_error);
    void createSurface(std::string const& filename) throw(std::runtime_error);
    void createSurface(video::GfxWindow const& win) throw(std::runtime_error);

    void freeSurface(void) noexcept;

    surface::GfxSurface& operator()(void) const throw(std::runtime_error);
private:
    static const int32_t kDefaultSurfaceColorDepth = 32;
    static const pixels::GfxPixelFormatEnum::ValueType kDefaultSurfaceColorFormatValue;

    surface::GfxSurface * surf_;
    bool surfaceConstructed_;
};

}  // namespace xtra

}  // namespace gfx

#endif /* GfxControledSurface_hpp */
