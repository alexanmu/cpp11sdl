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

#ifndef GControl_hpp
#define GControl_hpp

#include <stdexcept>
#include <cstdint>
#include <vector>
#include <string>

#include "GTypes.hpp"
#include "GComponent.hpp"
#include "GfxRect.hpp"

namespace gto
{

namespace gobj
{

class GControl : public GComponent
{
public:
    GControl() = delete;

    GControl(const GControl& other) = delete;
    GControl(GControl&& other) = delete;

    GControl& operator=(const GControl& other) = delete;
    GControl& operator=(GControl&& other) = delete;

    explicit GControl(const std::string& vname, GComponent* owner);
    virtual ~GControl();

    void setBounds(const gfx::rect::GfxRect& bounds) noexcept;
    const gfx::rect::GfxRect& getBounds(void) const noexcept;
    const gfx::rect::GfxRect& getClientBounds(void) const noexcept;

    void setEnabled(void) noexcept;
    bool getEnabled(void) const noexcept;

    void setBorderThikness(const GBorderThikness& borderthikness) noexcept;
    GBorderThikness getBorderThikness(void) const noexcept;

    void setBorderStyle(const GBorderStyle& borderstyle) noexcept;
    GBorderStyle getBorderStyle(void) const noexcept;

    void setBackgroundStyle(const GBackgroundStyle& backgroundstyle) noexcept;
    GBackgroundStyle getBackgroundStyle(void) const noexcept;

    void setHint(const std::string& hint) noexcept;
    const std::string& getHint(void) const noexcept;
    bool hasHint(void) const noexcept;

    void showHint(void) noexcept;
    void hideHint(void) noexcept;
    bool getShowHint(void) const noexcept;

    void hide(void) noexcept;
    void show(void) noexcept;
    bool isVisible(void) const noexcept;

    int32_t getWidth(void) const noexcept;
    int32_t getHeight(void) const noexcept;
protected:
    // Properties
    gfx::rect::GfxRect bounds_;
    gfx::rect::GfxRect clientBounds_;
    bool enabled_;
    GBorderThikness borderThikness_;
    GBorderStyle borderStyle_;
    GBackgroundStyle backgroundStyle_;
    std::string hint_;
    bool showHint_;
    bool visible_;
private:
    static const GBorderThikness kDefaultBorderThikness = GBorderThikness::noBorder;
    static const GBorderStyle kDefaultBorderStyle = GBorderStyle::flatBorder;
    static const GBackgroundStyle kDefaultBackgroundStyle = GBackgroundStyle::transparentColor;

    void adjustClientBounds(void) noexcept;
};

}  // namespace gobj

}  // namespace gto

#endif /* GControl_hpp */
