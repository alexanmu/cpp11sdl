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

#define LOG_TRACE_MODULE_NAME(x) static const char * __log_module_name__ = (x)

#define LOG_TRACE_TRACE_MODULE(x) gfx::_gfx::GfxBasicLogger::getInstance().addTraceModule((x))

#define LOG_TRACE_SET_TRACE_TO_FILE_ON() gfx::_gfx::GfxBasicLogger::getInstance().setTraceToFileState(\
                                         gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceEnabled)
#define LOG_TRACE_SET_TRACE_TO_FILE_OFF() gfx::_gfx::GfxBasicLogger::getInstance().setTraceToFileState(\
                                          gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceDisabled)

#define LOG_TRACE_SET_TRACE_LVL_LOW_ON() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                         gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioLow, \
                                         gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceEnabled)
#define LOG_TRACE_SET_TRACE_LVL_LOW_OFF() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                          gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioLow, \
                                          gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceDisabled)

#define LOG_TRACE_SET_TRACE_LVL_MED_ON() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                         gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioMedium, \
                                         gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceEnabled)
#define LOG_TRACE_SET_TRACE_LVL_MED_OFF() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                          gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioMedium, \
                                          gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceDisabled)

#define LOG_TRACE_SET_TRACE_LVL_HIGH_ON() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                          gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioHigh, \
                                          gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceEnabled)
#define LOG_TRACE_SET_TRACE_LVL_HIGH_OFF() gfx::_gfx::GfxBasicLogger::getInstance().setTracePriority(\
                                           gfx::_gfx::GfxBasicLogger::logTracePriority::logTracePrioHigh, \
                                           gfx::_gfx::GfxBasicLogger::logTraceEnaDisState::logTraceDisabled)

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

#if _ENABLE_LOG_PRIO_PRIO_HIGH == 1
#define LOG_TRACE_PRIO_HIGH() (GfxBasicLogger::getInstance().logTrace(::__log_module_name__, \
                               GfxBasicLogger::logTracePriority::logTracePrioHigh, \
                               __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define LOG_TRACE_PRIO_HIGH()
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
        logTracePrioLow = 0,
        logTracePrioMedium = 1,
        logTracePrioHigh = 2
    };

    enum class logTraceEnaDisState : uint8_t
    {
        logTraceDisabled = 0,
        logTraceEnabled = 1
    };

    /* Trace */
    void logTrace(const char * module, const logTracePriority prio, const char * file, const int32_t line,
                  const char * func, const int32_t instance) noexcept;
    logTraceEnaDisState getTracePriority(const logTracePriority prio) const noexcept;
    void setTracePriority(const logTracePriority prio, const logTraceEnaDisState state) noexcept;
    logTraceEnaDisState getTraceToFileState(void) const noexcept;
    void setTraceToFileState(const logTraceEnaDisState state) noexcept;
    const std::vector<std::string>& getTraceModules(void) const noexcept;
    void addTraceModule(const std::string& module) noexcept;
    void clearTraceModules() noexcept;

    /* Log */
    void logMessage(const char * msg) noexcept;
    void logInfo(const char * msg) noexcept;
    void logWarning(const char * msg) noexcept;
    void logError(const char * msg) noexcept;
    void logFatal(const char * msg) noexcept;
private:
    GfxBasicLogger() noexcept;

    GfxBasicLogger(const GfxBasicLogger&) = delete;
    GfxBasicLogger(GfxBasicLogger&&) = delete;

    GfxBasicLogger& operator=(const GfxBasicLogger&) = delete;
    GfxBasicLogger& operator=(GfxBasicLogger&&) = delete;

    ~GfxBasicLogger() noexcept;

    char getTraceTextForPrio(const logTracePriority prio) const noexcept;
    const std::string getCurrentDateAsString(void) const noexcept;
    const std::string getCurrentTimeAsString(void) const noexcept;
    const std::string _lz(const std::string& str, const uint32_t elen) const noexcept;
    void createLogFile(void) noexcept;
    void closeLogFile(void) noexcept;
    bool doTrace(const std::string& module) const noexcept;

    std::ofstream logFile_;
    std::chrono::high_resolution_clock::time_point startTime_;

    logTraceEnaDisState logTraceLevels_[4];
    logTraceEnaDisState logTraceToFileState_;
    std::vector<std::string> logTraceFilterModules_;
    bool logTraceAllowAll_;

    static const char logFileName_[];
};

}  // namespace _gfx

using _gfx::GfxBasicLogger;

}  // namespace gfx

#endif  /* GfxBasicLogger_hpp */
