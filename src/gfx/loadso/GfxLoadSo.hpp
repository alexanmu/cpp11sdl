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

#ifndef GfxLoadSo_hpp
#define GfxLoadSo_hpp

#include <string>

#include "GfxObject.hpp"

namespace gfx
{

namespace loadso
{

class GfxLoadSo final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxLoadSo() = delete;

    explicit GfxLoadSo(std::string const& objectname) noexcept;

    /* Copy ctor should not be used */
    GfxLoadSo(GfxLoadSo const&) = delete;
    GfxLoadSo(GfxLoadSo&& other) noexcept;

    virtual ~GfxLoadSo() noexcept;

    /* Copy operator should not be used */
    GfxLoadSo& operator=(GfxLoadSo const&) = delete;
    GfxLoadSo& operator=(GfxLoadSo&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isObjectLoaded(void) const noexcept;
    std::string const& getObjectName(void) const noexcept;
    void * loadFunction(std::string const& function) const noexcept;

    void unloadObject() noexcept;
private:
    std::string objectname_;
    void * handle_;
};

}  // namespace loadso

}  // namespace gfx

#endif /* GfxLoadSo_hpp */
