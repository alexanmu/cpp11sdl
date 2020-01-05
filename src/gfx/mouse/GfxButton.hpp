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

#ifndef GfxButton_hpp
#define GfxButton_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace mouse
{

class GfxButton final : public GfxObject
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        buttonLeft = SDL_BUTTON_LEFT,
        buttonMiddle = SDL_BUTTON_MIDDLE,
        buttonRight = SDL_BUTTON_RIGHT,
        buttonX1 = SDL_BUTTON_X1,
        buttonX2 = SDL_BUTTON_X2,
        buttonLMask = SDL_BUTTON_LMASK,
        buttonMMask = SDL_BUTTON_MMASK,
        buttonRMask = SDL_BUTTON_RMASK,
        buttonX1Mask = SDL_BUTTON_X1MASK,
        buttonX2Mask = SDL_BUTTON_X2MASK
    };

    GfxButton() noexcept;
    explicit GfxButton(const ValueType button) noexcept;
    explicit GfxButton(const SdlType button) noexcept;

    GfxButton(const GfxButton& other) noexcept;
    GfxButton(GfxButton&& other) noexcept;

    GfxButton& operator=(const GfxButton& other) noexcept;
    GfxButton& operator=(GfxButton&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isLeftButton(void) const noexcept;
    bool isMiddleButton(void) const noexcept;
    bool isRightButton(void) const noexcept;
    bool isX1Button(void) const noexcept;
    bool isX2Button(void) const noexcept;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType button_;
};

}  // namespace mouse

}  // namespace gfx

#endif /* GfxButton_hpp */
