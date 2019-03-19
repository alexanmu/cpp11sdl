/*
 Giotto
 Copyright (C) 2019 George Oros
 
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

#ifndef GStructuredTextLabel_hpp
#define GStructuredTextLabel_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <map>

#include "GComponent.hpp"
#include "GLabel.hpp"
#include "GTypes.hpp"
#include "GfxFontInfo.hpp"

namespace gto
{

namespace gobj
{

class GStructuredTextLabel : public GLabel
{
public:
    GStructuredTextLabel() = delete;

    GStructuredTextLabel(const GStructuredTextLabel& other) = delete;
    GStructuredTextLabel(GStructuredTextLabel&& other) = delete;

    GStructuredTextLabel& operator=(const GStructuredTextLabel& other) = delete;
    GStructuredTextLabel& operator=(GStructuredTextLabel&& other) = delete;

    explicit GStructuredTextLabel(const std::string& vname, GComponent* owner, const uint16_t width,
                                  const uint16_t height, const std::string& text, const uint8_t textsize,
                                  const GStructuredTextType sttexttype);
    explicit GStructuredTextLabel(const std::string& vname, GComponent* owner, const uint16_t width,
                                  const uint16_t height, const std::string& text, const uint8_t textsize,
                                  const GStructuredTextType sttexttype, const std::string& regexp);

    virtual void draw(void) throw(std::runtime_error);
private:
    bool evalRegExp(const std::string& actregexp, const std::string& text);
    void setColorScheme(void);

    GStructuredTextType stTextType_;
    std::string regExp_;

    static const std::map<GStructuredTextType, std::string> exprMapObject;
};

}  // namespace gobj

}  // namespace gto

#endif /* GStructuredTextLabel_hpp */
