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

namespace giotto
{

namespace dialogs
{

GOKCancelMsgBox::GOKCancelMsgBox(std::string const& name, GObject* parent) :
        GObject(name), parent_(parent)
{
    title_ = "";
    message_ = "";
    selection_ = GDialogsConstants::kNoSelection;
}

GOKCancelMsgBox::GOKCancelMsgBox(std::string const& name, GObject* parent, const std::string& title,
        const std::string& message) : GObject(name), parent_(parent)
{
    title_ = title;
    message_ = message;
    selection_ = GDialogsConstants::kNoSelection;
}

void GOKCancelMsgBox::showModal(void)
{
    gfx::GfxMessageBoxFlags flags { gfx::GfxMessageBoxFlags::GfxMessageBoxFlagsValues::flagError };

    gfx::GfxMessageBoxButtonData buttons[2] {
        gfx::GfxMessageBoxButtonData(gfx::GfxMessageBoxButtonFlags(
                                        gfx::GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::noneDefault),
                                        1, "OK"),
        gfx::GfxMessageBoxButtonData(gfx::GfxMessageBoxButtonFlags(
                                        gfx::GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlagsValues::noneDefault),
                                        2, "Cancel"),
    };

    gfx::GfxMessageBoxColor colors[static_cast<uint32_t>(
                                    gfx::GfxMessageBoxColorType::GfxMessageBoxColorTypeValues::colorMax)] = {
        gfx::GfxMessageBoxColor(255, 0, 0),
        gfx::GfxMessageBoxColor(250, 220, 190),
        gfx::GfxMessageBoxColor(192, 92, 9),
        gfx::GfxMessageBoxColor(50, 100, 200),
        gfx::GfxMessageBoxColor(255, 255, 255)
    };

    gfx::GfxMessageBoxColorScheme colorScheme(colors);

    gfx::GfxMessageBoxData msgBoxData(flags, nullptr, title_, message_, 2, buttons, colorScheme);

    gfx::GfxMessageBox messageBox(msgBoxData);

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

}  // namespace dialogs

}  // namespace giotto

/* EOF */
