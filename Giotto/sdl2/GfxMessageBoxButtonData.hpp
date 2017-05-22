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

#ifndef GfxMessageBoxButtonData_hpp
#define GfxMessageBoxButtonData_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxButtonFlags.hpp"

namespace gfx
{

class GfxMessageBoxButtonData final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxButtonData SdlType;
    typedef sdl2::SDL_MessageBoxButtonData* SdlTypePtr;

    static const char ClassName[];

    GfxMessageBoxButtonData();

    GfxMessageBoxButtonData(GfxMessageBoxButtonFlags const& flags, const int32_t buttonid, const std::string& text);

    GfxMessageBoxButtonData(GfxMessageBoxButtonData const& other);
    GfxMessageBoxButtonData(GfxMessageBoxButtonData&& other);

    GfxMessageBoxButtonData& operator=(GfxMessageBoxButtonData const& other);
    GfxMessageBoxButtonData& operator=(GfxMessageBoxButtonData&& other);

    virtual explicit operator bool() const;

    int32_t getButtonId(void) const;
    const std::string getText(void) const;

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType data_;
};

}  // namespace gfx

#endif /* GfxMessageBoxButtonData_hpp */
