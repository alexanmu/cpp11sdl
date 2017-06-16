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

#ifndef GfxHints_hpp
#define GfxHints_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <map>
#include <utility>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxHintPriority.hpp"
#include "GfxHintCallback.hpp"

namespace gfx
{

namespace hints
{

class GfxHints final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;

    enum class ValueType : int32_t
    {
        hintFramebufferAcceleration = 0
    };

    GfxHints() noexcept;

    GfxHints(GfxHints const&) = delete;
    GfxHints(GfxHints&&) = delete;

    GfxHints& operator=(GfxHints const&) = delete;
    GfxHints& operator=(GfxHints&&) = delete;

    virtual explicit operator bool() const noexcept;

    GfxBool setHintWithPriority(std::string const& name, std::string const& value,
                                GfxHintPriority const& prio) const noexcept;
    GfxBool setHint(std::string const& name, std::string const& value) const noexcept;
    std::string getHint(std::string const& name) const noexcept;
    GfxBool getHintBoolean(std::string const& name, GfxBool const& defvalue) const noexcept;
    void addHintCallback(std::string const& name, GfxHintCallback const& callback, void * userdata) noexcept;
    void delHintCallback(std::string const& name, GfxHintCallback const& callback, void * userdata)
                        throw(std::runtime_error);
    void clearHints(void) const noexcept;
private:
    std::map<std::string, std::pair<GfxHintCallback *, void *>> callbackMap_;
};

}  // namespace hints

}  // namespace gfx

#endif /* GfxHints_hpp */
