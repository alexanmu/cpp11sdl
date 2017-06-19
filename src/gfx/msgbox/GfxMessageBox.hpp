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

#ifndef GfxMessageBox_hpp
#define GfxMessageBox_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxMessageBoxData.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxWindow.hpp"

namespace gfx
{

namespace msgbox
{

class GfxMessageBox final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxMessageBox() = delete;

    explicit GfxMessageBox(GfxMessageBoxData const& data) noexcept;
    GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title,
                  std::string const& message) noexcept;
    GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title,
                  std::string const& message, video::GfxWindow const& win) noexcept;

    GfxMessageBox(GfxMessageBox const&) = delete;
    GfxMessageBox(GfxMessageBox&&) = delete;

    GfxMessageBox& operator=(GfxMessageBox const&) = delete;
    GfxMessageBox& operator=(GfxMessageBox&&) = delete;

    virtual explicit operator bool() const noexcept;

    int32_t showModal(void) const noexcept;
private:
    int32_t showModalComplex(void) const noexcept;
    int32_t showModalSimple(void) const noexcept;

    enum class GfxMessageBoxType : int32_t
    {
        typeComplex,
        typeSimple
    };

    GfxMessageBoxType type_;
    GfxMessageBoxData data_;
    GfxMessageBoxFlags flag_;
    std::string title_;
    std::string message_;
    video::GfxWindow const* winptr_;
};

}  // namespace msgbox

}  // namespace gfx

#endif /* GfxMessageBox_hpp */
