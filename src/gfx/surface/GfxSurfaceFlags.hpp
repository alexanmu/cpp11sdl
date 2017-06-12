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

#ifndef GfxSurfaceFlags_hpp
#define GfxSurfaceFlags_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace surface
{

class GfxSurfaceFlags final : public GfxObject
{
public:
    typedef uint32_t SdlType;
    typedef uint32_t* SdlTypePtr;

    static const char ClassName[];
    static const bool SdlResource = false;

    enum class ValueType : uint32_t
    {
        flagSwSurface = SDL_SWSURFACE,
        flagPreAlloc = SDL_PREALLOC,
        flagRLEAccel = SDL_RLEACCEL,
        flagDontFree = SDL_DONTFREE
    };

    GfxSurfaceFlags() noexcept;

    explicit GfxSurfaceFlags(const ValueType flags) noexcept;
    explicit GfxSurfaceFlags(const SdlType flags) noexcept;

    GfxSurfaceFlags(GfxSurfaceFlags const& other) noexcept;
    GfxSurfaceFlags(GfxSurfaceFlags&& other) noexcept;

    GfxSurfaceFlags& operator=(GfxSurfaceFlags const& other) noexcept;
    GfxSurfaceFlags& operator=(GfxSurfaceFlags&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    bool isSwSurface(void) const noexcept;
    bool isPreAlloc(void) const noexcept;
    bool isRLEAccel(void) const noexcept;
    bool isDontFree(void) const noexcept;

    void setSwSurface(void) const throw(std::runtime_error);
    void setPreAlloc(void) const throw(std::runtime_error);
    void setRLEAccel(void) const throw(std::runtime_error);
    void setDontFree(void) const throw(std::runtime_error);

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType flags_;
};

}  // namespace surface

}  // namespace gfx

#endif /* GfxSurfaceFlags_hpp */
