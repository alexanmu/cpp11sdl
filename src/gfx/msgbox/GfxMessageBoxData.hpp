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

#ifndef GfxMessageBoxData_hpp
#define GfxMessageBoxData_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxWindow.hpp"
#include "GfxMessageBoxColorScheme.hpp"
#include "GfxMessageBoxButtonData.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxData final : public GfxObject
{
public:
    typedef sdl2::SDL_MessageBoxData SdlType;
    typedef sdl2::SDL_MessageBoxData * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxMessageBoxData() noexcept;

    GfxMessageBoxData(GfxMessageBoxFlags const& flags, GfxObject * win, std::string const& title,
                      std::string const& message, const int32_t numbuttons, const GfxMessageBoxButtonData buttons[],
                      GfxMessageBoxColorScheme const& colorScheme) noexcept;
    GfxMessageBoxData(GfxMessageBoxFlags const& flags, video::GfxWindow const& win, std::string const& title,
                      std::string const& message, const int32_t numbuttons,
                      const GfxMessageBoxButtonData buttons[]) noexcept;

    GfxMessageBoxData(GfxMessageBoxData const& other) noexcept;
    GfxMessageBoxData(GfxMessageBoxData&& other) noexcept;

    virtual ~GfxMessageBoxData() noexcept;

    GfxMessageBoxData& operator=(GfxMessageBoxData const& other) noexcept;
    GfxMessageBoxData& operator=(GfxMessageBoxData&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType data_;
    GfxMessageBoxButtonData::SdlType * btndataptr;
    std::string title_;
    std::string message_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxData_hpp */
