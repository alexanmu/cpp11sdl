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

#ifndef GfxMessageBoxColorType_hpp
#define GfxMessageBoxColorType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxColorType final : public GfxObject
{
public:
    typedef SDL_MessageBoxColorType SdlType;
    typedef SDL_MessageBoxColorType * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        colorBackground = SDL_MESSAGEBOX_COLOR_BACKGROUND,
        colorText = SDL_MESSAGEBOX_COLOR_TEXT,
        colorButtonBorder = SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
        colorButtonBackground = SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
        colorButtonSelected = SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
        colorMax = SDL_MESSAGEBOX_COLOR_MAX
    };

    GfxMessageBoxColorType() noexcept;

    explicit GfxMessageBoxColorType(const SdlType type) noexcept;
    explicit GfxMessageBoxColorType(const ValueType type) noexcept;

    GfxMessageBoxColorType(const GfxMessageBoxColorType& other) noexcept;
    GfxMessageBoxColorType(GfxMessageBoxColorType&& other) noexcept;

    GfxMessageBoxColorType& operator=(const GfxMessageBoxColorType& other) noexcept;
    GfxMessageBoxColorType& operator=(GfxMessageBoxColorType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isBackground(void) const noexcept;
    bool isText(void) const noexcept;
    bool isButtonBorder(void) const noexcept;
    bool isButtonBackground(void) const noexcept;
    bool isButtonSelected(void) const noexcept;
    bool isMax(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdllType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType type_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxColorType_hpp */
