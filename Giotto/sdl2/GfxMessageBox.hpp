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

#include <string>

#include "GfxRootClass.hpp"
#include "GfxMessageBoxData.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxWindow.hpp"

class GfxMessageBox final : public GfxRootClass
{
public:
    static const std::string ClassName;

    GfxMessageBox() = delete;

    explicit GfxMessageBox(GfxMessageBoxData const& data);
    GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title, std::string const& message);
    GfxMessageBox(GfxMessageBoxFlags const& flag, std::string const& title,
                    std::string const& message, GfxWindow const& win);

    GfxMessageBox(GfxMessageBox const&) = delete;
    GfxMessageBox(GfxMessageBox&&) = delete;

    GfxMessageBox& operator=(GfxMessageBox const&) = delete;
    GfxMessageBox& operator=(GfxMessageBox&&) = delete;

    int showModal(void) const;
private:
    int showModalComplex(void) const;
    int showModalSimple(void) const;

    enum class GfxMessageBoxType : int
    {
        typeComplex,
        typeSimple
    };

    GfxMessageBoxType type_;
    GfxMessageBoxData data_;
    GfxMessageBoxFlags flag_;
    std::string title_;
    std::string message_;
    GfxWindow const* winptr_;
};

#endif /* GfxMessageBox_hpp */
