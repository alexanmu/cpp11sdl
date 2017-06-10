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

#ifndef GfxRendererInfo_hpp
#define GfxRendererInfo_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxTextureFormats.hpp"

namespace gfx
{

class GfxRendererInfo final : public GfxObject
{
public:
    typedef sdl2::SDL_RendererInfo SdlType;
    typedef sdl2::SDL_RendererInfo* SdlTypePtr;

    static const char ClassName[];

    GfxRendererInfo() noexcept;

    explicit GfxRendererInfo(const SdlType info) noexcept;

    GfxRendererInfo(const GfxRendererInfo& other) noexcept;
    GfxRendererInfo(GfxRendererInfo&& other) noexcept;

    GfxRendererInfo& operator=(const GfxRendererInfo& other) noexcept;
    GfxRendererInfo& operator=(GfxRendererInfo&& other) noexcept;

    virtual explicit operator bool() const noexcept;

    std::string getName(void) const noexcept;
    uint32_t getFlags(void) const noexcept;
    uint32_t getNumTextureFormats(void) const noexcept;
    GfxTextureFormats getTextureFormats(void) const noexcept;
    int32_t getMaxTextureWidth(void) const noexcept;
    int32_t getMaxTextureHeight(void) const noexcept;

    void set(const SdlType info) noexcept;
    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
    SdlTypePtr getAsSdlTypePtr(void) const noexcept;
private:
    SdlType info_;
};

}  // namespace gfx

#endif /* GfxRendererInfo_hpp */