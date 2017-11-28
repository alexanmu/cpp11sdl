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

#ifndef GfxGesture_hpp
#define GfxGesture_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxTouchID.hpp"
#include "GfxGestureID.hpp"
#include "GfxRwOps.hpp"

namespace gfx
{

namespace gesture
{

class GfxGesture final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxGesture() noexcept;

    GfxGesture(GfxGesture const& other) noexcept;
    GfxGesture(GfxGesture&& other) noexcept;

    GfxGesture& operator=(GfxGesture const& other) noexcept;
    GfxGesture& operator=(GfxGesture&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t recordGesture(touch::GfxTouchID const& touchId) const noexcept;
    int32_t saveAllDollarTemplates(rwops::GfxRwOps const& rwops) const noexcept;
    int32_t saveDollarTemplate(GfxGestureID const& gestureId, rwops::GfxRwOps const& rwops) const noexcept;
    int32_t loadDollarTemplates(touch::GfxTouchID const& touchId, rwops::GfxRwOps const& rwops) const noexcept;
};

}  // namespace gesture

}  // namespace gfx

#endif  // GfxGesture_hpp
