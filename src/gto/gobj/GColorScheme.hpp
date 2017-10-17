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

#ifndef GCOLORSCHEME_HPP
#define GCOLORSCHEME_HPP

#include "GObject.hpp"
#include "GfxColor.hpp"

namespace gto
{

namespace gobj
{

class GColorScheme : public GObject
{
public:
    GColorScheme();

    GColorScheme(GColorScheme const& other);
    GColorScheme(GColorScheme&& other);

    GColorScheme& operator=(GColorScheme const& other);
    GColorScheme& operator=(GColorScheme&& other);

    gfx::pixels::GfxColor const& getForegroundColor(void) const noexcept;
    void setForegroundColor(gfx::pixels::GfxColor const& color) noexcept;

    gfx::pixels::GfxColor const& getBackgroundColor(void) const noexcept;
    void setBackgroundColor(gfx::pixels::GfxColor const& color) noexcept;

    gfx::pixels::GfxColor const& getBorderColor(void) const noexcept;
    void setBorderColor(gfx::pixels::GfxColor const& color) noexcept;

    gfx::pixels::GfxColor const& getBorderShadowColor(void) const noexcept;
    void setBorderShadowColor(gfx::pixels::GfxColor const& color) noexcept;

    void setDefault(void) noexcept;

    void clear(void) noexcept;
private:
    gfx::pixels::GfxColor backgroundColor_;
    gfx::pixels::GfxColor foregroundColor_;
    gfx::pixels::GfxColor borderColor_;
    gfx::pixels::GfxColor borderShadowColor_;

    static const gfx::pixels::GfxColor kDefaultForegroundColor;
    static const gfx::pixels::GfxColor kDefaultBackgroundColor;
    static const gfx::pixels::GfxColor kDefaultBorderColor;
    static const gfx::pixels::GfxColor kDefaultBorderShadowColor;
};

}  // namespace gobj

}  // namespace gto

#endif  // GCOLORSCHEME_HPP
