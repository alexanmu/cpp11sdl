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

#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxMessageBoxButtonFlags.hpp"

class GfxMessageBoxButtonData final : public GfxRootClass
{
public:
    typedef SDL_MessageBoxButtonData SdlType;
    typedef SDL_MessageBoxButtonData* SdlTypePtr;

    GfxMessageBoxButtonData();
    GfxMessageBoxButtonData(GfxMessageBoxButtonFlags const& flags, const int buttonid, const std::string& text);
    GfxMessageBoxButtonData(GfxMessageBoxButtonData const& other);
    GfxMessageBoxButtonData(GfxMessageBoxButtonData&& other);

    GfxMessageBoxButtonData& operator=(GfxMessageBoxButtonData const& other);
    GfxMessageBoxButtonData& operator=(GfxMessageBoxButtonData&& other);

    int getButtonId(void) const;
    std::string getText(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType data_;
};

#endif /* GfxMessageBoxButtonData_hpp */
