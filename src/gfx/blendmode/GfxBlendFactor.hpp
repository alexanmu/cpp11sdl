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

#ifndef GfxBlendFactor_hpp
#define GfxBlendFactor_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace blendmode
{

class GfxBlendFactor final : public GfxObject
{
public:
    using SdlType = SDL_BlendFactor;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        blendFactorZero = SDL_BLENDFACTOR_ZERO,
        blendFactorOne = SDL_BLENDFACTOR_ONE,
        blendFactorSrcColor = SDL_BLENDFACTOR_SRC_COLOR,
        blendFactorOneMinusSrcColor = SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR,
        blendFactorSrcAlpha = SDL_BLENDFACTOR_SRC_ALPHA,
        blendFactorOneMinusSrcAlpha = SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
        blendFactorDstColor = SDL_BLENDFACTOR_DST_COLOR,
        blendFactorOneMinusDstColor = SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR,
        blendFactorDstAlpha = SDL_BLENDFACTOR_DST_ALPHA,
        blendFactorOneMinusDstAlpha = SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA
    };

    GfxBlendFactor() noexcept;

    explicit GfxBlendFactor(const ValueType blendFactor) noexcept;
    explicit GfxBlendFactor(const SdlType blendFactor) noexcept;

    GfxBlendFactor(const GfxBlendFactor& other) noexcept;
    GfxBlendFactor(GfxBlendFactor&& other) noexcept;

    GfxBlendFactor& operator=(const GfxBlendFactor& other) noexcept;
    GfxBlendFactor& operator=(GfxBlendFactor&& other) noexcept;

    bool operator==(const GfxBlendFactor& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isZero(void) const noexcept;
    bool isOne(void) const noexcept;
    bool isSrcColor(void) const noexcept;
    bool isOneMinusSrcColor(void) const noexcept;
    bool isSrcAlpha(void) const noexcept;
    bool isOneMinusSrcAlpha(void) const noexcept;
    bool isDstColor(void) const noexcept;
    bool isOneMinusDstColor(void) const noexcept;
    bool isDstAlpha(void) const noexcept;
    bool isOneMinusDstAlpha(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType blendFactor_;
};

}  // namespace blendmode

}  // namespace gfx

#endif /* GfxBlendFactor_hpp */
