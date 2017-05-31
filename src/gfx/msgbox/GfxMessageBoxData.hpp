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

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxWindow.hpp"
#include "GfxMessageBoxColorScheme.hpp"
#include "GfxMessageBoxButtonData.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxData final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxData SdlType;
    typedef sdl2::SDL_MessageBoxData* SdlTypePtr;

    static const char ClassName[];

    GfxMessageBoxData();

    GfxMessageBoxData(const GfxMessageBoxFlags& flags, GfxRootClass* win, const std::string& title,
                      const std::string& message, const int32_t numbuttons, GfxMessageBoxButtonData buttons[],
                      const GfxMessageBoxColorScheme& colorScheme);
    GfxMessageBoxData(const GfxMessageBoxFlags& flags, const video::GfxWindow& win, const std::string& title,
                      const std::string& message, const int32_t numbuttons, GfxMessageBoxButtonData buttons[]);

    GfxMessageBoxData(GfxMessageBoxData const& other);
    GfxMessageBoxData(GfxMessageBoxData&& other);

    virtual ~GfxMessageBoxData();

    GfxMessageBoxData& operator=(GfxMessageBoxData const& other);
    GfxMessageBoxData& operator=(GfxMessageBoxData&& other);

    virtual explicit operator bool() const;

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType data_;
    GfxMessageBoxButtonData::SdlTypePtr btndataptr;
    std::string title_;
    std::string message_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxData_hpp */
