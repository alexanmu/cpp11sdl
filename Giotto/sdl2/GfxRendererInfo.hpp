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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxRendererInfo final : public GfxRootClass
{
public:
    typedef SDL_RendererInfo SdlType;
    typedef SDL_RendererInfo* SdlTypePtr;

    static const std::string ClassName;

    static constexpr int kTextureFormatsArrayLength = 16;

    struct GfxTextureFormats
    {
        uint32_t formats[kTextureFormatsArrayLength];
        uint32_t& operator[](int index)
        {
            return formats[index];
        }
    };

    GfxRendererInfo();

    explicit GfxRendererInfo(const SdlType info);

    GfxRendererInfo(const GfxRendererInfo& other);
    GfxRendererInfo(GfxRendererInfo&& other);

    GfxRendererInfo& operator=(const GfxRendererInfo& other);
    GfxRendererInfo& operator=(GfxRendererInfo&& other);

    std::string getName(void) const;
    uint32_t getFlags(void) const;
    uint32_t getNumTextureFormats(void) const;
    GfxTextureFormats getTextureFormats(void) const;
    int32_t getMaxTextureWidth(void) const;
    int32_t getMaxTextureHeight(void) const;

    void set(const SdlType info);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType info_;
};

#endif /* GfxRendererInfo_hpp */
