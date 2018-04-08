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

#ifndef GfxLogPriority_hpp
#define GfxLogPriority_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace log
{

class GfxLogPriority final : public GfxObject
{
public:
    typedef SDL_LogPriority SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        logPriorityVerbose = SDL_LOG_PRIORITY_VERBOSE,
        logPriorityDebug = SDL_LOG_PRIORITY_DEBUG,
        logPriorityInfo = SDL_LOG_PRIORITY_INFO,
        logPriorityWarn = SDL_LOG_PRIORITY_WARN,
        logPriorityError = SDL_LOG_PRIORITY_ERROR,
        logPriorityCritical = SDL_LOG_PRIORITY_CRITICAL,
        logPriorityNumLogPriorities = SDL_NUM_LOG_PRIORITIES
    };

    GfxLogPriority() noexcept;

    explicit GfxLogPriority(const ValueType value) noexcept;
    explicit GfxLogPriority(const SdlType value) noexcept;
    explicit GfxLogPriority(const int32_t value) noexcept;

    GfxLogPriority(GfxLogPriority const& other) noexcept;
    GfxLogPriority(GfxLogPriority&& other) noexcept;

    GfxLogPriority& operator=(GfxLogPriority const& other) noexcept;
    GfxLogPriority& operator=(GfxLogPriority&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    bool isVerbose(void) const noexcept;
    bool isDebug(void) const noexcept;
    bool isInfo(void) const noexcept;
    bool isWarn(void) const noexcept;
    bool isError(void) const noexcept;
    bool isCritical(void) const noexcept;
    bool isNumLogPriorities(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace log

}  // namespace gfx

#endif /* GfxLogPriority_hpp */
