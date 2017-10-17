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

#ifndef GfxHintCallback_hpp
#define GfxHintCallback_hpp

#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace hints
{

class GfxHintCallback : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHintCallback() noexcept;

    virtual ~GfxHintCallback() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual void operator()(std::string const& name, std::string const& oldvalue,
                            std::string const& newvalue) const noexcept = 0;
};

}  // namespace hints

}  // namespace gfx

#endif /* GfxHintCallback_hpp */
