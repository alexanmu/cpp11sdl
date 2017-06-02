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
#include <regex>

#include "GStructuredTextLabel.hpp"
#include "GLabel.hpp"
#include "GTypes.hpp"

namespace gto
{

namespace gobj
{

/* Regular expressions taken from here:
    https://code.tutsplus.com/tutorials/8-regular-expressions-you-should-know--net-6149 */
const std::map<GStructuredTextType, std::string> GStructuredTextLabel::exprMapObject = {
    { GStructuredTextType::hexValue, "/^#?([a-f0-9]{6}|[a-f0-9]{3})$/" },
    { GStructuredTextType::emailAddress, "/^([a-z0-9_\\.-]+)@([\\da-z\\.-]+)\\.([a-z\\.]{2,6})$/" },
    { GStructuredTextType::hyperLink, "/^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$/" },
    { GStructuredTextType::ipAddress, "/^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/" }
};

GStructuredTextLabel::GStructuredTextLabel(std::string const& vname, GComponent* owner, uint16_t width,
                                           uint16_t height, std::string const& text, uint8_t const& textsize,
                                           GStructuredTextType const& sttexttype, std::string regexp) :
        GLabel(vname, owner, width, height, text, textsize)
{
    assert(vname.length() > 0);
    assert(owner != nullptr);

    if (stTextType_ == GStructuredTextType::customRegex)
    {
        assert(regexp.length() > 0);
    }
    stTextType_ = sttexttype;
    regExp_ = regexp;
}

void GStructuredTextLabel::draw(void) throw(std::runtime_error)
{
    std::string actregexp;

    if (stTextType_ == GStructuredTextType::customRegex)
    {
        actregexp = regExp_;
    }
    else
    {
        actregexp = exprMapObject.at(stTextType_);
    }
    if (evalRegExp(actregexp) == false)
    {
        GLabel::setText("regExp failed!");
    }
    GLabel::draw();
}

bool GStructuredTextLabel::evalRegExp(std::string const& actregexp)
{
    assert(actregexp.length() > 0);

    bool result;

    std::regex self_regex = std::regex(actregexp, std::regex_constants::ECMAScript);
    result = std::regex_search(GLabel::getText(), self_regex);

    return result;
}

}  // namespace gobj

}  // namespace gto

/* EOF */
