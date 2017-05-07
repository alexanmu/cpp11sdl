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

#ifndef GfxMessageBoxColorScheme_hpp
#define GfxMessageBoxColorScheme_hpp

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxColor.hpp"
#include "GfxMessageBoxColorType.hpp"

namespace gfx
{

class GfxMessageBoxColorScheme final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxColorScheme SdlType;
    typedef sdl2::SDL_MessageBoxColorScheme* SdlTypePtr;

    static const std::string ClassName;

    static constexpr int colorsArraySize = static_cast<int>(GfxMessageBoxColorType::GfxMessageBoxColorTypeValues::colorMax);

    GfxMessageBoxColorScheme();

    explicit GfxMessageBoxColorScheme(const GfxMessageBoxColor colors[colorsArraySize]);

    GfxMessageBoxColorScheme(GfxMessageBoxColorScheme const& other);
    GfxMessageBoxColorScheme(GfxMessageBoxColorScheme&& other);

    GfxMessageBoxColorScheme& operator=(GfxMessageBoxColorScheme const& other);
    GfxMessageBoxColorScheme& operator=(GfxMessageBoxColorScheme&& other);

    void setColor(GfxMessageBoxColorType const& type,GfxMessageBoxColor const& color);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType clrscheme_;
};

}  // namespace gfx

#endif /* GfxMessageBoxColorScheme_hpp */
