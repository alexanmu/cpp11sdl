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

#ifndef GGraphicControl_hpp
#define GGraphicControl_hpp

#include <stdexcept>
#include <cstdint>
#include <vector>
#include <string>

#include "GComponent.hpp"
#include "GControl.hpp"
#include "GfxRect.hpp"
#include "GfxControlledSurface.hpp"
#include "GfxColor.hpp"

namespace giotto
{

namespace objects
{

class GGraphicControl : public GControl
{
public:
    GGraphicControl() = delete;

    GGraphicControl(GGraphicControl const& other) = delete;
    GGraphicControl(GGraphicControl&& other) = delete;

    GGraphicControl& operator=(GGraphicControl const& other) = delete;
    GGraphicControl& operator=(GGraphicControl&& other) = delete;

    explicit GGraphicControl(std::string const& vname, GComponent* owner, uint16_t width, uint16_t height);
    virtual ~GGraphicControl();

    gfx::supp::GfxControlledSurface const& getSurface(void) const noexcept;

    gfx::GfxColor const& getForegroundColor(void) const noexcept;
    void setForegroundColor(gfx::GfxColor const& color) noexcept;

    gfx::GfxColor const& getBackgroundColor(void) const noexcept;
    void setBackgroundColor(gfx::GfxColor const& color) noexcept;

    gfx::GfxColor const& getBorderColor(void) const noexcept;
    void setBorderColor(gfx::GfxColor const& color) noexcept;

    gfx::GfxColor const& getBorderShadowColor(void) const noexcept;
    void setBorderShadowColor(gfx::GfxColor const& color) noexcept;

    virtual void draw(void);
protected:
    gfx::supp::GfxControlledSurface surf_;
    gfx::GfxColor backgroundColor_;
    gfx::GfxColor foregroundColor_;
    gfx::GfxColor borderColor_;
    gfx::GfxColor borderShadowColor_;

private:
    void drawBorder(void) noexcept;
    void drawBackground(void) noexcept;

    static const gfx::GfxColor kDefaultForegroundColor;
    static const gfx::GfxColor kDefaultBackgroundColor;
    static const gfx::GfxColor kDefaultBorderColor;
    static const gfx::GfxColor kDefaultBorderShadowColor;
};

}  // namespace objects

}  // namespace giotto

#endif /* GGraphicControl_hpp */
