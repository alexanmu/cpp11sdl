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

#include <stdexcept>
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

    GfxLog(GfxLog const& other) = delete;
    GfxLog(GfxLog&& other) = delete;

    GfxLog& operator=(GfxLog const& other) = delete;
    GfxLog& operator=(GfxLog&& other) = delete;

    virtual explicit operator bool() const noexcept;

    void setAllPriority(GfxLogPriority const& prio) const noexcept;
    void setPriority(GfxLogCategory const& cat, GfxLogPriority const& prio) const noexcept;
    GfxLogPriority getPriority(GfxLogCategory const& cat) const noexcept;
    void resetPriorities(void) const noexcept;

    template <typename... Args>
    void log(std::string const& fmt, Args&&... args) const noexcept
    {
        assert(fmt.length() > 0);

        sdl2::SDL_Log(fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logVerbose(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogVerbose(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logDebug(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogDebug(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logInfo(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogInfo(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logWarn(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogWarn(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logError(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogError(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logCritical(GfxLogCategory const& cat, std::string const& fmt, Args&&... args) const noexcept
    {
        assert(cat);
        assert(fmt.length() > 0);

        sdl2::SDL_LogCritical(cat.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logMessage(GfxLogCategory const& cat, GfxLogPriority const& prio, std::string const& fmt,
                    Args&&... args) const noexcept
    {
        assert(cat);
        assert(prio);
        assert(fmt.length() > 0);

        sdl2::SDL_LogMessage(cat.getAsSdlType(), prio.getAsSdlType(), fmt.c_str(), std::forward<Args>(args)...);
    }

    template <typename... Args>
    void logMessageV(GfxLogCategory const& cat, GfxLogPriority const& prio, std::string const& fmt,
                        Args&&... args) throw(std::runtime_error)
    {
        assert(cat);
        assert(prio);
        assert(fmt.length() > 0);

        std::tuple<Args...> tup(std::forward<Args>(args)...);
        assert(tup.tupple_size() > 0);

        throw std::runtime_error("Use method logMessage(...)");
    }

    GfxLogOutputFunction * logGetOutputFunction(void ** userdata) const noexcept;
    void logSetOutputFunction(GfxLogOutputFunction * callback, void * userdata) const throw(std::runtime_error);
};

}  // namespace log

}  // namespace gfx

#endif /* GfxLog_hpp */
