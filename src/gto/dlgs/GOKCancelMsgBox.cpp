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

#include <cassert>
#include <string>

#include "GOKCancelMsgBox.hpp"

#include "GfxMessageBoxFlags.hpp"
#include "GfxMessageBoxButtonData.hpp"
#include "GfxMessageBoxButtonFlags.hpp"
#include "GfxMessageBoxColor.hpp"
#include "GfxMessageBoxColorType.hpp"
#include "GfxMessageBoxColorScheme.hpp"
#include "GfxMessageBoxData.hpp"
#include "GfxMessageBox.hpp"

namespace gto
{

namespace dlgs
{

GOKCancelMsgBox::GOKCancelMsgBox(const std::string& vname, GComponent* owner) :
        GDialog(vname, owner)
{
    title_ = "";
    message_ = "";
    selection_ = GDialogsConstants::kNoSelection;
}

GOKCancelMsgBox::GOKCancelMsgBox(const std::string& vname, GComponent* owner, const std::string& title,
        const std::string& message) : GDialog(vname, owner)
{
    assert(title.length() > 0);
    assert(message.length() > 0);

    title_ = title;
    message_ = message;
    selection_ = GDialogsConstants::kNoSelection;
}

void GOKCancelMsgBox::setTitle(const std::string& title) noexcept
{
    assert(title.length() > 0);

    title_ = title;
}

void GOKCancelMsgBox::setMessage(const std::string& message) noexcept
{
    assert(message.length() > 0);

    message_ = message;
}

void GOKCancelMsgBox::showModal(void)
{
    gfx::msgbox::GfxMessageBoxFlags flags { gfx::msgbox::GfxMessageBoxFlags::ValueType::flagError };

    gfx::msgbox::GfxMessageBoxButtonData buttons[2] {
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                                        gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::noneDefault),
                                        1, "OK"),
        gfx::msgbox::GfxMessageBoxButtonData(gfx::msgbox::GfxMessageBoxButtonFlags(
                                        gfx::msgbox::GfxMessageBoxButtonFlags::ValueType::noneDefault),
                                        2, "Cancel"),
    };

    gfx::msgbox::GfxMessageBoxColor colors[static_cast<uint32_t>(
                                    gfx::msgbox::GfxMessageBoxColorType::ValueType::colorMax)] = {
        gfx::msgbox::GfxMessageBoxColor(255, 0, 0),
        gfx::msgbox::GfxMessageBoxColor(250, 220, 190),
        gfx::msgbox::GfxMessageBoxColor(192, 92, 9),
        gfx::msgbox::GfxMessageBoxColor(50, 100, 200),
        gfx::msgbox::GfxMessageBoxColor(255, 255, 255)
    };

    gfx::msgbox::GfxMessageBoxColorScheme colorScheme(colors);

    gfx::msgbox::GfxMessageBoxData msgBoxData(flags, title_, message_, 2, buttons, colorScheme);

    gfx::msgbox::GfxMessageBox messageBox(msgBoxData);

    int result = messageBox.showModal();
    switch (result) {
        case 1:
            selection_ = GDialogsConstants::kButtonOk;
            break;
        case 2:
            selection_ = GDialogsConstants::kButtonCancel;
        default:
            break;
    }
}

GDialogsConstants GOKCancelMsgBox::getSelection(void) const
{
    return selection_;
}

}  // namespace dlgs

}  // namespace gto

/* EOF */
