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

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxInitFlags.hpp"

namespace gfx
{

namespace initquit
{

class GfxInitQuit final : public GfxRootClass
{
public:
    static const char ClassName[];

    // No default constructor
    GfxInitQuit() = delete;

    explicit GfxInitQuit(GfxInitFlags const& flags);

    // Copy/Move constructors don't make sense
    GfxInitQuit(const GfxInitQuit&) = delete;
    GfxInitQuit(GfxInitQuit&&) = delete;

    // Forbid copy/move assignements
    GfxInitQuit& operator=(const GfxInitQuit&) = delete;
    GfxInitQuit& operator=(GfxInitQuit&&) = delete;

    // Explicit destructor to de-init SDL lib
    virtual ~GfxInitQuit();

    virtual explicit operator bool() const;

    void initSubSystem(GfxInitFlags const& flags);
    void quitSubSystem(GfxInitFlags const& flags);

    GfxInitFlags * wasInit(GfxInitFlags const& flags);

    void quitRequested(void);

    int32_t getErrorCode() const;
private:
    GfxInitFlags flags_;
    int32_t errorCode_;
};

}  // namespace initquit

}  // namespace gfx

#endif /* GfxInitQuit_hpp */
