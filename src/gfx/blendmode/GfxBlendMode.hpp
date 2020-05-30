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

#ifndef GfxBlendMode_hpp
#define GfxBlendMode_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBlendFactor.hpp"
#include "GfxBlendOperation.hpp"

namespace gfx
{

namespace blendmode
{

class GfxBlendMode final : public GfxObject
{
public:
    using SdlType = SDL_BlendMode;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        blendModeNone = SDL_BLENDMODE_NONE,
        blendModeBlend = SDL_BLENDMODE_BLEND,
        blendModeAdd = SDL_BLENDMODE_ADD,
        blendModeMod = SDL_BLENDMODE_MOD,
        blendModeInvalid = SDL_BLENDMODE_INVALID
    };

    GfxBlendMode() noexcept;

    explicit GfxBlendMode(const ValueType blendmode) noexcept;
    explicit GfxBlendMode(const SdlType blendmode) noexcept;

    GfxBlendMode(const GfxBlendMode& other) noexcept;
    GfxBlendMode(GfxBlendMode&& other) noexcept;

    GfxBlendMode& operator=(const GfxBlendMode& other) noexcept;
    GfxBlendMode& operator=(GfxBlendMode&& other) noexcept;

    bool operator==(const GfxBlendMode& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isNone(void) const noexcept;
    bool isBlend(void) const noexcept;
    bool isAdd(void) const noexcept;
    bool isMod(void) const noexcept;
    bool isInvalid(void) const noexcept;

    bool isCustom(void) const noexcept;

    void composeCustomBlendMode(
        const GfxBlendFactor& srcColorFactor,
        const GfxBlendFactor& dstColorFactor,
        const GfxBlendOperation& colorOperation,
        const GfxBlendFactor& srcAlphaFactor,
        const GfxBlendFactor& dstAlphaFactor,
        const GfxBlendOperation& alphaOperation) noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType blendmode_;
};

}  // namespace blendmode

}  // namespace gfx

#endif /* GfxBlendMode_hpp */
