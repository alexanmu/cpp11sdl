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

#ifndef GDialog_hpp
#define GDialog_hpp

#include <stdexcept>
#include <cstdint>
#include <vector>
#include <string>

#include "GComponent.hpp"

namespace gto
{

namespace gobj
{

class GDialog : public GComponent
{
public:
    GDialog() = delete;

    GDialog(const GDialog& other) = delete;
    GDialog(GDialog&& other) = delete;

    GDialog& operator=(const GDialog& other) = delete;
    GDialog& operator=(GDialog&& other) = delete;

    explicit GDialog(const std::string& vname, GComponent * owner);
    virtual ~GDialog();

    virtual void showModal(void) = 0;
};

}  // namespace gobj

}  // namespace gto

#endif /* GDialog_hpp */
