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

#ifndef GfxMessageBoxColorType_hpp
#define GfxMessageBoxColorType_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxMessageBoxColorType final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxColorType SdlType;
    typedef sdl2::SDL_MessageBoxColorType* SdlTypePtr;

    static const std::string ClassName;

    enum class GfxMessageBoxColorTypeValues : uint32_t
    {
        colorBackground = sdl2::SDL_MESSAGEBOX_COLOR_BACKGROUND,
        colorText = sdl2::SDL_MESSAGEBOX_COLOR_TEXT,
        colorButtonBorder = sdl2::SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
        colorButtonBackground = sdl2::SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
        colorButtonSelected = sdl2::SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
        colorMax = sdl2::SDL_MESSAGEBOX_COLOR_MAX
    };

    GfxMessageBoxColorType();

    explicit GfxMessageBoxColorType(const SdlType type);
    explicit GfxMessageBoxColorType(const GfxMessageBoxColorTypeValues type);

    GfxMessageBoxColorType(GfxMessageBoxColorType const& other);
    GfxMessageBoxColorType(GfxMessageBoxColorType&& other);

    GfxMessageBoxColorType& operator=(GfxMessageBoxColorType const& other);
    GfxMessageBoxColorType& operator=(GfxMessageBoxColorType&& other);

    GfxMessageBoxColorTypeValues getType(void) const;

    SdlType getAsSdllType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType type_;
};

}  // namespace gfx

#endif /* GfxMessageBoxColorType_hpp */
