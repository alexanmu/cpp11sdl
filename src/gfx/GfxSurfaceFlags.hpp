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

#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxSurfaceFlags final : public GfxRootClass
{
public:
    typedef uint32_t SdlType;
    typedef uint32_t* SdlTypePtr;

    static const char ClassName[];

    enum class GfxSurfaceFlagsValues : uint32_t
    {
        flagSwSurface = SDL_SWSURFACE,
        flagPreAlloc = SDL_PREALLOC,
        flagRLEAccel = SDL_RLEACCEL,
        flagDontFree = SDL_DONTFREE
    };

    GfxSurfaceFlags();

    explicit GfxSurfaceFlags(const GfxSurfaceFlagsValues flags);
    explicit GfxSurfaceFlags(const SdlType flags);

    GfxSurfaceFlags(GfxSurfaceFlags const& other);
    GfxSurfaceFlags(GfxSurfaceFlags&& other);

    GfxSurfaceFlags& operator=(GfxSurfaceFlags const& other);
    GfxSurfaceFlags& operator=(GfxSurfaceFlags&& other);

    virtual explicit operator bool() const;

    bool isSwSurface(void) const;
    bool isPreAlloc(void) const;
    bool isRLEAccel(void) const;
    bool isDontFree(void) const;

    void setSwSurface(void) throw();
    void setPreAlloc(void) throw();
    void setRLEAccel(void) throw();
    void setDontFree(void) throw();

    void clear(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flags_;
};

}  // namespace gfx

#endif /* GfxSurfaceFlags_hpp */
