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

#ifndef GfxBlendOperation_hpp
#define GfxBlendOperation_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace blendmode
{

class GfxBlendOperation final : public GfxObject
{
public:
    typedef SDL_BlendOperation SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        blendOperationAdd = SDL_BLENDOPERATION_ADD,
        blendOperationSubstract = SDL_BLENDOPERATION_SUBTRACT,
        blendOperationRevSubstract = SDL_BLENDOPERATION_REV_SUBTRACT,
        blendOperationMinimum = SDL_BLENDOPERATION_MINIMUM,
        blendOperationMaximum = SDL_BLENDOPERATION_MAXIMUM
    };

    GfxBlendOperation() noexcept;

    explicit GfxBlendOperation(const ValueType blendOp) noexcept;
    explicit GfxBlendOperation(const SdlType blendOp) noexcept;

    GfxBlendOperation(const GfxBlendOperation& other) noexcept;
    GfxBlendOperation(GfxBlendOperation&& other) noexcept;

    GfxBlendOperation& operator=(const GfxBlendOperation& other) noexcept;
    GfxBlendOperation& operator=(GfxBlendOperation&& other) noexcept;

    bool operator==(const GfxBlendOperation& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isAdd(void) const noexcept;
    bool isSubstract(void) const noexcept;
    bool isRevSubstract(void) const noexcept;
    bool isMinimum(void) const noexcept;
    bool isMaximum(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType blendOperation_;
};

}  // namespace blendmode

}  // namespace gfx

#endif /* GfxBlendOperation_hpp */
