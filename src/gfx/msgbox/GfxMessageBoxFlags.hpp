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

#ifndef GfxMessageBoxFlags_hpp
#define GfxMessageBoxFlags_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxFlags final : public GfxObject
{
public:
    typedef SDL_MessageBoxFlags SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        flagError = SDL_MESSAGEBOX_ERROR,
        flagWarning = SDL_MESSAGEBOX_WARNING,
        flagInformation = SDL_MESSAGEBOX_INFORMATION
    };

    GfxMessageBoxFlags() noexcept;

    explicit GfxMessageBoxFlags(const ValueType flag) noexcept;
    explicit GfxMessageBoxFlags(const SdlType flag) noexcept;

    GfxMessageBoxFlags(const GfxMessageBoxFlags& other) noexcept;
    GfxMessageBoxFlags(GfxMessageBoxFlags&& other) noexcept;

    GfxMessageBoxFlags& operator=(const GfxMessageBoxFlags& other) noexcept;
    GfxMessageBoxFlags& operator=(GfxMessageBoxFlags&& other) noexcept;

    bool operator==(const GfxMessageBoxFlags& other) const noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getFlag(void) const noexcept;

    bool isError(void) const noexcept;
    bool isWarning(void) const noexcept;
    bool isInformation(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType flag_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxFlags_hpp */
