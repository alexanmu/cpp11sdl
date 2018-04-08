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

#ifndef GfxMessageBoxButtonFlags_hpp
#define GfxMessageBoxButtonFlags_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBoxButtonFlags final : public GfxObject
{
public:
    typedef SDL_MessageBoxButtonFlags SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : uint32_t
    {
        noneDefault = 0,
        returnKeyDefault = SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,
        escKeyDefault = SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT
    };

    GfxMessageBoxButtonFlags() noexcept;

    explicit GfxMessageBoxButtonFlags(const ValueType flags) noexcept;
    explicit GfxMessageBoxButtonFlags(const SdlType flags) noexcept;

    GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags const& other) noexcept;
    GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags&& other) noexcept;

    GfxMessageBoxButtonFlags& operator=(GfxMessageBoxButtonFlags const& other) noexcept;
    GfxMessageBoxButtonFlags& operator=(GfxMessageBoxButtonFlags&& other) noexcept;

    bool operator==(GfxMessageBoxButtonFlags const& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool isReturnDefault(void) const noexcept;
    bool isEscDefault(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType flags_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBoxButtonFlags_hpp */
