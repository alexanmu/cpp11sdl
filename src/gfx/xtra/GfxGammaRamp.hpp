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

#ifndef GfxGammaRamp_hpp
#define GfxGammaRamp_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GfxRootClass.hpp"

namespace gfx
{

namespace xtra
{

class GfxGammaRamp final : public GfxRootClass
{
public:
    typedef uint16_t * SdlTypePtr;

    static const char ClassName[];

    GfxGammaRamp();
    explicit GfxGammaRamp(SdlTypePtr gammaRamp);

    GfxGammaRamp(GfxGammaRamp const& other);
    GfxGammaRamp(GfxGammaRamp&& other);

    GfxGammaRamp& operator=(GfxGammaRamp const& other);
    GfxGammaRamp& operator=(GfxGammaRamp&& other);

    virtual explicit operator bool() const;

    uint16_t& operator [](int32_t index) throw(std::runtime_error);

    void clear(void);

    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    static const int32_t kGammaRampNumberOfElements = 256;
    static const uint16_t kInvalidValue = 0xFFFF;

    uint16_t gammaRamp_[kGammaRampNumberOfElements];
};

}  // namespace xtra

}  // namespace gfx

#endif /* GfxGammaRamp_hpp */
