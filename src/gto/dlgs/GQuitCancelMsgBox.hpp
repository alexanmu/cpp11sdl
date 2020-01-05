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

#ifndef GQuitCancelMsgBox_hpp
#define GQuitCancelMsgBox_hpp

#include <string>

#include "GDialog.hpp"
#include "GDialogsConstants.hpp"

namespace gto
{

namespace dlgs
{

class GQuitCancelMsgBox : public GDialog
{
public:
    GQuitCancelMsgBox() = delete;

    explicit GQuitCancelMsgBox(const std::string& vname, GComponent* owner);

    GQuitCancelMsgBox(const std::string& vname, GComponent* owner, const std::string& title,
                        const std::string& message);

    GQuitCancelMsgBox(const GQuitCancelMsgBox&) = delete;
    GQuitCancelMsgBox(GQuitCancelMsgBox&&) = delete;

    GQuitCancelMsgBox& operator=(const GQuitCancelMsgBox&) = delete;
    GQuitCancelMsgBox& operator=(GQuitCancelMsgBox&&) = delete;

    void setTitle(const std::string& title) noexcept;
    void setMessage(const std::string& message) noexcept;

    virtual void showModal(void);
    GDialogsConstants getSelection(void) const;
private:
    std::string title_;
    std::string message_;
    GDialogsConstants selection_;
};

}  // namespace dlgs

}  // namespace gto

#endif /* GQuitCancelMsgBox_hpp */
