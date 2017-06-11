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

    GfxClipboard() noexcept;

    GfxClipboard(GfxClipboard const&) = delete;
    GfxClipboard(GfxClipboard&&) = delete;

    GfxClipboard& operator=(GfxClipboard const&) = delete;
    GfxClipboard& operator=(GfxClipboard&&) = delete;

    virtual explicit operator bool() const noexcept;

    void setClipboardText(std::string const& str) const noexcept;
    std::string getClipboardText(void) const noexcept;
    GfxBool hasClipboardText(void) const noexcept;
};

}  // namespace clipboard

}  // namespace gfx

#endif /* GfxClipboard_hpp */
