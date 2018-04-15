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

#ifndef GfxVersion_hpp
#define GfxVersion_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace version
{

class GfxVersion final : public GfxObject
{
public:
    typedef SDL_version SdlType;
    typedef SDL_version * SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxVersion() noexcept;

    GfxVersion(const uint8_t major, const uint8_t minor, const uint8_t patch) noexcept;
    explicit GfxVersion(const SdlType ver) noexcept;

    GfxVersion(GfxVersion const& other) noexcept;
    GfxVersion(GfxVersion&& other) noexcept;

    GfxVersion& operator=(GfxVersion const& other) noexcept;
    GfxVersion& operator=(GfxVersion&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    uint8_t getMajor(void) const noexcept;
    uint8_t getMinor(void) const noexcept;
    uint8_t getPatch(void) const noexcept;

    void clear(void) noexcept;

    const std::string getAsString(void) const noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType ver_;
};

}  // namespace version

}  // namespace gfx

#endif /* GfxVersion_hpp */
