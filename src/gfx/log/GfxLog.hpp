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

#ifndef GfxLog_hpp
#define GfxLog_hpp

#include <cstdint>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxLogCategory.hpp"
#include "GfxLogPriority.hpp"

namespace gfx
{

namespace log
{

class GfxLog final : public GfxObject
{
public:
    static const char ClassName[];

    GfxLog() noexcept __attribute__((deprecated("SDL log deprecated, use gfx::_gfx::GfxLogger")));

    GfxLog(GfxLog const& other) = delete;
    GfxLog(GfxLog&& other) = delete;

    GfxLog& operator=(GfxLog const& other) = delete;
    GfxLog& operator=(GfxLog&& other) = delete;

    virtual explicit operator bool() const noexcept;

    void setAllPriority(GfxLogPriority const& prio) const noexcept;
    void setPriority(GfxLogCategory const& cat, GfxLogPriority const& prio) const noexcept;
    GfxLogPriority getPriority(GfxLogCategory const& cat) const noexcept;
    void resetPriorities(void) const noexcept;

    /*  -Wsuggest-attribute=const|pure */
};

}  // namespace log

}  // namespace gfx

#endif /* GfxLog_hpp */
