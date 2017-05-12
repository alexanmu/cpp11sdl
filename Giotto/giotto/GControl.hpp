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

#ifndef GControl_hpp
#define GControl_hpp

#include <cstdint>
#include <vector>
#include <string>
#include <stdexcept>

#include "GComponent.hpp"
#include "GfxRect.hpp"

namespace giotto
{

namespace objects
{

class GControl : public GComponent
{
public:
    enum class GBorderType : uint8_t
    {
        noBorder = 0,
        thinBorder = 1,
        thikBorder = 2
    };

    GControl() = delete;

    GControl(GControl const& other) = delete;
    GControl(GControl&& other) = delete;

    GControl& operator=(GControl const& other) = delete;
    GControl& operator=(GControl&& other) = delete;

    explicit GControl(std::string const& name, GComponent* owner);
    virtual ~GControl();

    void setBounds(gfx::GfxRect const& bounds) noexcept;
    gfx::GfxRect const& getBounds(void) const noexcept;
    gfx::GfxRect const& getClientBounds(void) const noexcept;

    void setEnabled(void) noexcept;
    bool getEnabled(void) const noexcept;

    void setBorder(GBorderType bordertype) noexcept;
    bool hasBorder(void) const noexcept;

    void setHint(std::string const& hint) noexcept;
    std::string const& getHint(void) const noexcept;
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
    gfx::GfxRect bounds_;
    gfx::GfxRect clientBounds_;
    bool enabled_;
    GBorderType borderType_;
    std::string hint_;
    bool showHint_;
    bool visible_;
private:
    static const GBorderType kDefaultBorderType = GBorderType::noBorder;

    void adjustClientBounds(void) noexcept;
};

}  // namespace objects

}  // namespace giotto

#endif /* GControl_hpp */
