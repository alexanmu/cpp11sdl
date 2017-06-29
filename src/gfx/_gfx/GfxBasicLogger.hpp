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

#define _ENABLE_TRACE_PRIO_0 0
#define _ENABLE_TRACE_PRIO_1 0
#define _ENABLE_TRACE_PRIO_2 1
#define _ENABLE_TRACE_PRIO_3 1
#define _ENABLE_TRACE_PRIO_4 1

#if _ENABLE_TRACE_PRIO_0 == 1
#define TRACE_P0() (GfxBasicLogger::getInstance().logTrace(GfxBasicLogger::tracePriority::prioPrio0, \
                    __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define TRACE_P0()
#endif

#if _ENABLE_TRACE_PRIO_1 == 1
#define TRACE_P1() (GfxBasicLogger::getInstance().logTrace(GfxBasicLogger::tracePriority::prioPrio1, \
                    __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define TRACE_P1()
#endif

#if _ENABLE_TRACE_PRIO_2 == 1
#define TRACE_P2() (GfxBasicLogger::getInstance().logTrace(GfxBasicLogger::tracePriority::prioPrio2, \
                    __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define TRACE_P2()
#endif

#if _ENABLE_TRACE_PRIO_3 == 1
#define TRACE_P3() (GfxBasicLogger::getInstance().logTrace(GfxBasicLogger::tracePriority::prioPrio3, \
                    __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define TRACE_P3()
#endif

#if _ENABLE_TRACE_PRIO_4 == 1
#define TRACE_P4() (GfxBasicLogger::getInstance().logTrace(GfxBasicLogger::tracePriority::prioPrio4, \
                    __FILE__, __LINE__, __PRETTY_FUNCTION__, (getInstanceId())))
#else
#define TRACE_P4()
#endif

namespace gfx
{

namespace _gfx
{

class GfxBasicLogger
{
public:
    static GfxBasicLogger& getInstance(void) noexcept;

    enum class tracePriority : uint8_t
    {
        prioPrio0 = 0,
        prioPrio1 = 1,
        prioPrio2 = 2,
        prioPrio3 = 3,
        prioPrio4 = 4
    };

    void logTrace(const tracePriority prio, const char * file, const int32_t line,
                  const char * func, const int32_t instance) noexcept;
    void logMessage(const char * msg) noexcept;
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

    char getTextForPrio(const tracePriority prio) const noexcept;
    std::string getCurrentDateAsString(void) const noexcept;
    std::string getCurrentTimeAsString(void) const noexcept;
    std::string _lz(std::string const& str, const uint32_t elen) const noexcept;

    std::ofstream logFile_;

    static const char logFileName_[];
};

}  // namespace _gfx

using _gfx::GfxBasicLogger;

}  // namespace gfx

#endif  /* GfxBasicLogger_hpp */
