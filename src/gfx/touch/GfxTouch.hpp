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

#ifndef GfxTouch_hpp
#define GfxTouch_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxTouchID.hpp"
#include "GfxFinger.hpp"

namespace gfx
{

namespace touch
{

class GfxTouch final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    static const uint32_t kTouchMouseID = -1;

    GfxTouch() noexcept;

    GfxTouch(const GfxTouch& other) noexcept;
    GfxTouch(GfxTouch&& other) noexcept;

    GfxTouch& operator=(const GfxTouch& other) noexcept;
    GfxTouch& operator=(GfxTouch&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t getNumTouchDevices(void) const noexcept;
    const GfxTouchID getTouchDevice(const int32_t index) const noexcept;
    int32_t getNumTouchFingers(const GfxTouchID& touchid) const noexcept;
    const GfxFinger getTouchFinger(const GfxTouchID& touchid, const int32_t index) const noexcept;
};

}  // namespace touch

}  // namespace gfx

#endif  // GfxTouch_hpp
