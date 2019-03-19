/*
  Giotto
  Copyright (C) 2019 George Oros

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

#ifndef GfxGetRendererInfo_hpp
#define GfxGetRendererInfo_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxRendererInfo.hpp"

namespace gfx
{

namespace render
{

class GfxGetRendererInfo final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    GfxGetRendererInfo() noexcept;

    GfxGetRendererInfo(const GfxGetRendererInfo& other) noexcept;
    GfxGetRendererInfo(GfxGetRendererInfo&& other) noexcept;

    GfxGetRendererInfo& operator=(const GfxGetRendererInfo& other) noexcept;
    GfxGetRendererInfo& operator=(GfxGetRendererInfo&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    int32_t getNumRenderDrivers(void) noexcept;
    const GfxRendererInfo getRenderDriverInfo(const int32_t index) noexcept;
private:
    int32_t numRenderDrivers_;
};

}  // namespace render

}  // namespace gfx

#endif /* GfxGetRendererInfo_hpp */
