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

#ifndef GfxMessageBoxFlags_hpp
#define GfxMessageBoxFlags_hpp

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxMessageBoxFlags final : public GfxRootClass
{
public:
    typedef sdl2::SDL_MessageBoxFlags SdlType;
    typedef sdl2::SDL_MessageBoxFlags* SdlTypePtr;

    static const char ClassName[];

    enum class ValueType : int32_t
    {
        flagError = sdl2::SDL_MESSAGEBOX_ERROR,
        flagWarning = sdl2::SDL_MESSAGEBOX_WARNING,
        flagInformation = sdl2::SDL_MESSAGEBOX_INFORMATION
    };

    GfxMessageBoxFlags();

    explicit GfxMessageBoxFlags(const ValueType flag);
    explicit GfxMessageBoxFlags(const SdlType flag);

    GfxMessageBoxFlags(const GfxMessageBoxFlags& other);
    GfxMessageBoxFlags(GfxMessageBoxFlags&& other);

    GfxMessageBoxFlags& operator=(const GfxMessageBoxFlags& other);
    GfxMessageBoxFlags& operator=(GfxMessageBoxFlags&& other);

    bool operator==(const GfxMessageBoxFlags& other);

    virtual explicit operator bool() const;

    ValueType getFlag(void) const;

    bool isError(void) const;
    bool isWarning(void) const;
    bool isInformation(void) const;

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flag_;
};

}  // namespace gfx

#endif /* GfxMessageBoxFlags_hpp */
