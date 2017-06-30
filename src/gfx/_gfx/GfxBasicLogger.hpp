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

#ifndef GfxBasicLogger_hpp
#define GfxBasicLogger_hpp

#include <cstdint>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>

#define _ENABLE_LOG_PRIO_PRIO_LOW 1
#define _ENABLE_LOG_PRIO_PRIO_MED 1
#define _ENABLE_LOG_PRIO_PRIO_HIGH 1
#define _ENABLE_LOG_PRIO_PRIO_TOP 1

#define LOG_TRACE_MODULE_NAME(x) static const char * __log_module_name__ = (x)
#define LOG_TRACE_ADD_MODULE(x) gfx::_gfx::GfxBasicLogger::getInstance().addTraceModule((x))
#define LOG_TRACE_SET_TRACE_TO_FILE_ON() gfx::_gfx::GfxBasicLogger::getInstance().setTraceToFileState(\
                                         gfx::_gfx::GfxBasicLogger::logTraceToFileState::logTraceEnabled)
#define LOG_TRACE_SET_TRACE_TO_FILE_OFF() gfx::_gfx::GfxBasicLogger::getInstance().setTraceToFileState(\
                                          gfx::_gfx::gfx::_gfx::GfxBasicLogger::logTraceToFileState::logTraceDisabled)
#define LOG_TRACE_SET_TRACE_MIN_LOW() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                      gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioLow)
#define LOG_TRACE_SET_TRACE_MIN_MED() gfx::_gfx::gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                      gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioMedium)
#define LOG_TRACE_SET_TRACE_MIN_HIGH() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                       gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioHigh)
#define LOG_TRACE_SET_TRACE_MIN_TOP() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                      gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioTop)

#if _ENABLE_LOG_PRIO_PRIO_LOW == 1
#define LOG_TRACE_PRIO_LOW() (GfxBasicLogger::getInstance().logTrace(::__log_module_name__, \
                              GfxBasicLogger::logTracePriority::logTracePrioLow, \
                              __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define LOG_TRACE_PRIO_LOW()
#endif

#if _ENABLE_LOG_PRIO_PRIO_MED == 1
#define LOG_TRACE_PRIO_MED() (GfxBasicLogger::getInstance().logTrace(::__log_module_name__, \
                              GfxBasicLogger::logTracePriority::logTracePrioMedium, \
                              __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define LOG_TRACE_PRIO_MED()
#endif

#if _ENABLE_LOG_PRIO_PRIO_HIG == 1
#define LOG_TRACE_PRIO_HIGH() (GfxBasicLogger::getInstance().logTrace(::__log_module_name__, \
                               GfxBasicLogger::logTracePriority::logTracePrioHigh, \
                               __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define LOG_TRACE_PRIO_HIGH()
#endif

#if _ENABLE_LOG_PRIO_PRIO_TOP == 1
#define LOG_TRACE_PRIO_TOP() (GfxBasicLogger::getInstance().logTrace(::__log_module_name__, \
                              GfxBasicLogger::logTracePriority::logTracePrioTop, \
                              __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define LOG_TRACE_PRIO_TOP()
#endif

#define LOG_MESSAGE(x) (gfx::_gfx::GfxBasicLogger::getInstance().logMessage(x))

namespace gfx
{

namespace _gfx
{

class GfxBasicLogger
{
public:
    static GfxBasicLogger& getInstance(void) noexcept;

    enum class logPriority : uint8_t
    {
        logPrioMessage = 0x01,
        logPrioInfo = 0x02,
        logPrioWarning = 0x04,
        logPrioError = 0x08,
        logPrioFatal = 0x10
    };

    enum class logTracePriority : uint8_t
    {
        logTracePrioLow = 0x01,
        logTracePrioMedium = 0x02,
        logTracePrioHigh = 0x04,
        logTracePrioTop = 0x08
    };

    enum class logTraceToFileState : bool
    {
        logTraceDisabled = false,
        logTraceEnabled = true
    };

    /* Trace */
    void logTrace(const char * module, const logTracePriority prio, const char * file, const int32_t line,
                  const char * func, const int32_t instance) noexcept;
    logTracePriority getTracePriority(void) const noexcept;
    void setTracePriority(const logTracePriority prio) noexcept;
    logTraceToFileState getTraceToFileState(void) const noexcept;
    void setTraceToFileState(const logTraceToFileState state) noexcept;
    std::vector<std::string> const& getTraceModules(void) const noexcept;
    void addTraceModule(std::string const& module) noexcept;
    void clearTraceModules() noexcept;

    /* Log */
    void logMessage(const char * msg) noexcept;
    void logInfo(const char * msg) noexcept;
    void logWarning(const char * msg) noexcept;
    void logError(const char * msg) noexcept;
    void logFatal(const char * msg) noexcept;
private:
    GfxBasicLogger() noexcept;

    GfxBasicLogger(GfxBasicLogger const&) = delete;
    GfxBasicLogger(GfxBasicLogger&&) = delete;

    GfxBasicLogger& operator=(GfxBasicLogger const&) = delete;
    GfxBasicLogger& operator=(GfxBasicLogger&&) = delete;

    ~GfxBasicLogger() noexcept;

    char getTraceTextForPrio(const logTracePriority prio) const noexcept;
    std::string getCurrentDateAsString(void) const noexcept;
    std::string getCurrentTimeAsString(void) const noexcept;
    std::string _lz(std::string const& str, const uint32_t elen) const noexcept;
    void createLogFile(void) noexcept;
    void closeLogFile(void) noexcept;

    std::ofstream logFile_;
    std::chrono::high_resolution_clock::time_point startTime_;

    logTracePriority logMinTracePrio_;
    logTraceToFileState logTraceToFileState_;
    std::vector<std::string> logTraceFilterModules_;

    static const char logFileName_[];
};

}  // namespace _gfx

using _gfx::GfxBasicLogger;

}  // namespace gfx

#endif  /* GfxBasicLogger_hpp */
