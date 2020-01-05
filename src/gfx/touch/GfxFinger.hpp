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

#ifndef GfxFinger_hpp
#define GfxFinger_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxFingerID.hpp"

namespace gfx
{

namespace touch
{

class GfxFinger final : public GfxObject
{
public:
    typedef SDL_Finger SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxFinger() noexcept;
    explicit GfxFinger(const SdlType finger) noexcept;

    GfxFinger(const GfxFinger& other) noexcept;
    GfxFinger(GfxFinger&& other) noexcept;

    GfxFinger& operator=(const GfxFinger& other) noexcept;
    GfxFinger& operator=(GfxFinger&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxFingerID getId(void) const noexcept;
    float getX(void) const noexcept;
    float getY(void) const noexcept;
    float getPressure(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType finger_;
};

}  // namespace touch

}  // namespace gfx

#endif  // GfxFingerID_hpp
