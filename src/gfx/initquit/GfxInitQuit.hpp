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

#ifndef GfxInitQuit_hpp
#define GfxInitQuit_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxInitFlags.hpp"

namespace gfx
{

namespace initquit
{

class GfxInitQuit final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = true;
    static const bool CallsSdl = true;

    GfxInitQuit() noexcept;
    explicit GfxInitQuit(GfxInitFlags const& flags) noexcept;

    GfxInitQuit(GfxInitQuit const&) = delete;
    GfxInitQuit(GfxInitQuit&& other) noexcept;

    // Forbid copy/move assignements
    GfxInitQuit& operator=(GfxInitQuit const&) = delete;
    GfxInitQuit& operator=(GfxInitQuit&& other) noexcept;

    // Explicit destructor to de-init SDL lib
    virtual ~GfxInitQuit() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void initSubSystem(GfxInitFlags const& flags) noexcept;
    void quitSubSystem(GfxInitFlags const& flags) const noexcept;

    const GfxInitFlags wasInit(GfxInitFlags const& flags) const noexcept;

    void quitRequested(void) const noexcept;

    int32_t getErrorCode() const noexcept;
private:
    GfxInitFlags flags_;
    int32_t errorCode_;
};

}  // namespace initquit

}  // namespace gfx

#endif /* GfxInitQuit_hpp */
