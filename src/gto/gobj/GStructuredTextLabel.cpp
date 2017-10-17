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

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <map>
#include <regex>

#include "GStructuredTextLabel.hpp"
#include "GLabel.hpp"
#include "GTypes.hpp"
#include "GfxBgiConstants.hpp"

namespace gto
{

namespace gobj
{

/* Regular expressions taken from here:
    https://stackoverflow.com/questions/36903985/email-validation-in-c
    https://stackoverflow.com/questions/161738/what-is-the-best-regular-expression-to-check-if-a-string-is-a-valid-url
    https://stackoverflow.com/questions/5284147/validating-ipv4-addresses-with-regexp */

const std::map<GStructuredTextType, std::string> GStructuredTextLabel::exprMapObject = {
    { GStructuredTextType::emailAddress,
        R"((\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+)" },
    { GStructuredTextType::hyperLink,
        R"((([\w]+:)?//)?(([\d\w]|%[a-fA-F\d]{2,2})+(:([\d\w]|%[a-fA-f\d]{2,2})+)?@)?([\d\w][-\d\w]{0,253}[\d\w]\.)+\
        [\w]{2,4}(:[\d]+)?(/([-+_~.\d\w]|%[a-fA-f\d]{2,2})*)*(\?(&?([-+_~.\d\w]|%[a-fA-f\d]{2,2})=?)*)?(#([-+_~.\d\w]|%[a-fA-f\d]{2,2})*)?)" },
    { GStructuredTextType::ipAddress,
        R"(^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)" }
};

GStructuredTextLabel::GStructuredTextLabel(std::string const& vname, GComponent* owner, const uint16_t width,
                                           const uint16_t height, std::string const& text, const uint8_t textsize,
                                           const GStructuredTextType sttexttype) :
        GLabel(vname, owner, width, height, text, textsize)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);

    if (stTextType_ == GStructuredTextType::customRegex)
    {
        throw std::runtime_error("Use custom regex constructor");
    }
    stTextType_ = sttexttype;
    regExp_ = "";
}

GStructuredTextLabel::GStructuredTextLabel(std::string const& vname, GComponent* owner, const uint16_t width,
                                           const uint16_t height, std::string const& text, const uint8_t textsize,
                                           const GStructuredTextType sttexttype, std::string const& regexp) :
        GLabel(vname, owner, width, height, text, textsize)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);

    if (stTextType_ != GStructuredTextType::customRegex)
    {
        throw std::runtime_error("Use standard constructor");
    }

    assert(regexp.length() > 0);

    stTextType_ = sttexttype;
    regExp_ = regexp;
}

void GStructuredTextLabel::draw(void) throw(std::runtime_error)
{
    std::string actregexp = "";

    if (stTextType_ == GStructuredTextType::customRegex)
    {
        actregexp = regExp_;
    }
    else
    {
        actregexp = exprMapObject.at(stTextType_);
    }
    if (actregexp.length() > 0)
    {
        if (evalRegExp(actregexp, GLabel::getText()) == false)
        {
            GLabel::setText("regExp failed!");
        }
    }
    else
    {
        GLabel::setText("regExp failed!");
    }
    setColorScheme();
    GLabel::draw();
}

bool GStructuredTextLabel::evalRegExp(std::string const& actregexp, std::string const& text)
{
    assert(actregexp.length() > 0);
    assert(text.length() > 0);

    bool result;

    try
    {
        std::regex self_regex = std::regex(actregexp, std::regex_constants::ECMAScript);
        result = std::regex_search(text, self_regex);
    }
    catch (std::regex_error)
    {
        result = false;
    };

    return result;
}

void GStructuredTextLabel::setColorScheme(void)
{
    switch (stTextType_)
    {
        case GStructuredTextType::emailAddress:
            setForegroundColor(gfx::bgi::kColorLightBlue());
            setBackgroundColor(gfx::bgi::kColorWhite());
            getFontInfo().clear();
            getFontInfo().setFontItalic(true);
            getFontInfo().setFontUnderline(false);
            break;
        case GStructuredTextType::hyperLink:
            setForegroundColor(gfx::bgi::kColorBlue());
            setBackgroundColor(gfx::bgi::kColorWhite());
            getFontInfo().clear();
            getFontInfo().setFontItalic(true);
            getFontInfo().setFontUnderline(true);
            break;
        case GStructuredTextType::ipAddress:
            setForegroundColor(gfx::bgi::kColorBlack());
            setBackgroundColor(gfx::bgi::kColorWhite());
            getFontInfo().clear();
            getFontInfo().setFontBold(true);
            break;
        case GStructuredTextType::customRegex:
            setForegroundColor(gfx::bgi::kColorBlack());
            setBackgroundColor(gfx::bgi::kColorWhite());
            getFontInfo().clear();
            getFontInfo().setFontUnderline(true);
            break;
    }
}

}  // namespace gobj

}  // namespace gto

/* EOF */
