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

#ifndef GOKCancelMsgBox_hpp
#define GOKCancelMsgBox_hpp

#include <string>

#include "GObject.hpp"
#include "GDialogsConstants.hpp"

namespace giotto
{

namespace dialogs
{

class GOKCancelMsgBox : public objects::GObject
{
public:
    explicit GOKCancelMsgBox(std::string const& vname, GObject* parent);

    GOKCancelMsgBox(std::string const& name, GObject* parent, const std::string& title,
                    const std::string& message);

    GOKCancelMsgBox(GOKCancelMsgBox const&) = delete;
    GOKCancelMsgBox(GOKCancelMsgBox&&) = delete;

    GOKCancelMsgBox& operator=(GOKCancelMsgBox const&) = delete;
    GOKCancelMsgBox& operator=(GOKCancelMsgBox&&) = delete;

    void showModal(void);
    GDialogsConstants getSelection(void) const;
private:
    std::string title_;
    std::string message_;
    GDialogsConstants selection_;
    GObject* parent_;
};

}  // namespace dialogs

}  // namespace giotto

#endif /* GOKCancelMsgBox_hpp */
