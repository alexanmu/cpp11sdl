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

#ifndef GfxLog_hpp
#define GfxLog_hpp

#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <string>
#include <utility>
#include <tuple>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxLogCategory.hpp"
#include "GfxLogPriority.hpp"
#include "GfxLogOutputFunction.hpp"

namespace gfx
{

namespace log
{

class GfxLog final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    static const int32_t maxLogMessage = 4096;

    GfxLog() noexcept;

    GfxLog(const GfxLog&) = delete;
    GfxLog(GfxLog&& other) noexcept;

    GfxLog& operator=(const GfxLog&) = delete;
    GfxLog& operator=(GfxLog&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    void setAllPriority(const GfxLogPriority& prio) const noexcept;
    void setPriority(const GfxLogCategory& cat, const GfxLogPriority& prio) const noexcept;
    GfxLogPriority getPriority(const GfxLogCategory& cat) const noexcept;
    void resetPriorities(void) const noexcept;

    template <typename... Args>
    void log(const std::string& fmt, Args&&... args) const noexcept
    {
        assert(fmt.length() > 0);

        SDL_Log(fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logVerbose(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogVerbose(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logDebug(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogDebug(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logInfo(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogInfo(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logWarn(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogWarn(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logError(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogError(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logCritical(const GfxLogCategory& cat, const std::string& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        SDL_LogCritical(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logMessage(const GfxLogCategory& cat, const GfxLogPriority& prio, const std::string& fmt,
                    Args&&... args) const noexcept
    {
        assert(cat);
        assert(prio);
        assert(fmt.length() > 0);

        SDL_LogMessage(cat.getAsSdlType(), prio.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logMessageV(const GfxLogCategory& cat, const GfxLogPriority& prio, const std::string& fmt,
                     Args&&... args) const noexcept
    {
        assert(cat);
        assert(prio);
        assert(fmt.length() > 0);

        std::tuple<Args...> tup(std::forward<Args>(args)...);
        assert(tup.tupple_size() > 0);

        SDL_LogMessageV(cat.getAsSdlType(), prio.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    const GfxLogOutputFunction * logGetOutputFunction(void) const throw(std::runtime_error);
    void logSetOutputFunction(const GfxLogOutputFunction& callback) const throw(std::runtime_error);
private:
    void callCustomLogOutputFunctionObject(const int32_t category, const GfxLogPriority::SdlType& priority,
                                           const std::string& message) const noexcept;
    // Will be called from C by SDL
    static void logOutputFunction(void * userdata, int category, SDL_LogPriority priority, const char * message);

    mutable GfxLogOutputFunction * logOutputFunctionObject_ = nullptr;
};

}  // namespace log

}  // namespace gfx

#endif /* GfxLog_hpp */
