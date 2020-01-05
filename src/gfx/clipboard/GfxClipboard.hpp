/*
 Giotto
 Copyright (C) 2020 George Oros
 
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

#ifndef GfxClipboard_hpp
#define GfxClipboard_hpp

#include <string>

#include "GfxObject.hpp"
#include "GfxBool.hpp"

namespace gfx
{

namespace clipboard
{

class GfxClipboard final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxClipboard() noexcept;

    GfxClipboard(const GfxClipboard& other) noexcept;
    GfxClipboard(GfxClipboard&& other) noexcept;

    GfxClipboard& operator=(const GfxClipboard& other) noexcept;
    GfxClipboard& operator=(GfxClipboard&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setClipboardText(const std::string& str) const noexcept;
    const std::string getClipboardText(void) const noexcept;
    const GfxBool hasClipboardText(void) const noexcept;
};

}  // namespace clipboard

}  // namespace gfx

#endif /* GfxClipboard_hpp */
