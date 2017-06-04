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

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxColor.hpp"
#include "GfxMessageBoxColorType.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxColorScheme final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxColorScheme SdlType;
    typedef sdl2::SDL_MessageBoxColorScheme* SdlTypePtr;

    static const char ClassName[];

    static constexpr int32_t colorsArraySize = static_cast<int32_t>(
                                            GfxMessageBoxColorType::ValueType::colorMax);

    GfxMessageBoxColorScheme() noexcept;

    explicit GfxMessageBoxColorScheme(const GfxMessageBoxColor colors[colorsArraySize]) noexcept;

    GfxMessageBoxColorScheme(GfxMessageBoxColorScheme const& other) noexcept;
    GfxMessageBoxColorScheme(GfxMessageBoxColorScheme&& other) noexcept;

    GfxMessageBoxColorScheme& operator=(GfxMessageBoxColorScheme const& other) noexcept;
    GfxMessageBoxColorScheme& operator=(GfxMessageBoxColorScheme&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    void setColor(GfxMessageBoxColorType const& type, GfxMessageBoxColor const& color) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType clrscheme_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxColorScheme_hpp */
