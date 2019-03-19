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

#ifndef GfxTtfInitQuit_hpp
#define GfxTtfInitQuit_hpp

#include <string>
#include <cstdint>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace ttf
{

class GfxTtfInitQuit final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxTtfInitQuit() noexcept;

    GfxTtfInitQuit(const GfxTtfInitQuit&) = delete;
    GfxTtfInitQuit(GfxTtfInitQuit&& other) noexcept;

    GfxTtfInitQuit& operator=(const GfxTtfInitQuit&) = delete;
    GfxTtfInitQuit& operator=(GfxTtfInitQuit&& other) noexcept;

    virtual ~GfxTtfInitQuit() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t wasInit(void) const noexcept;

    int32_t getErrorCode(void) const noexcept;
private:
    int32_t errorCode_;
};

}  // namespace ttf

}  // namespace gfx

#endif  // GfxTtfInitQuit_hpp
