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

#include "Log.hpp"

/******************************************************* log *******************************************************/
#include <cassert>
#include <iostream>
#include <string>

#include "GfxLog.hpp"
#include "GfxLogCategory.hpp"
#include "GfxLogPriority.hpp"
#include "GfxLogOutputFunction.hpp"

namespace prv
{
class LogOutFunc : public gfx::log::GfxLogOutputFunction
{
public:
    LogOutFunc() : GfxLogOutputFunction()
    {
        // nothing to do
    }
    virtual void operator()(gfx::log::GfxLogCategory const& cat, gfx::log::GfxLogPriority const& prio,
                            std::string const& message) const noexcept
    {
        assert(cat);
        assert(prio);

        int32_t icat = static_cast<int32_t>(cat.getCategory());
        int32_t iprio = static_cast<int32_t>(prio.getPriority());
        std::cout << "<" << icat << "," << iprio << " " << message << ">" << std::endl;
    }
};
}  // namespace prv

void _doLog(void)
{
    gfx::log::GfxLog log;
    prv::LogOutFunc lofunc;

    using gfx::log::GfxLogCategory;
    using gfx::log::GfxLogPriority;

    // test Get
    prv::LogOutFunc * tst_lofuncptr = nullptr;
    try
    {
        tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction());
        if (tst_lofuncptr == nullptr)
        {
            std::cout << "nullptr; as expected" << std::endl;
        }
    }
    catch (...)
    {
        std::cout << "expected throw; function not set" << std::endl;
    }

    log.setPriority(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityVerbose));
    log.log("char=%c", 'a');
    log.log("value=%d", 128);
    log.log("float1=%f float2=%f", 1.5, 2.6);
    log.log("str=%s char=%c int=%d", "string", ';', 5);
    // Set new output function
    log.logSetOutputFunction(&lofunc);
    // test new output function
    tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction());
    if (tst_lofuncptr == nullptr)
    {
        std::cout << "nullptr; NOT expected!" << std::endl;
    }
    else
    {
        std::cout << "I'm ok!" << std::endl;
        if (tst_lofuncptr == &lofunc)
        {
            std::cout << "equal" << std::endl;
        }
        else
        {
            std::cout << "NOT Equal!" << std::endl;
        }
    }
    log.logVerbose(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "verbose=0x%x", 127);
    log.logDebug(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "debug=0x%x", 127);
    log.logInfo(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "info=0x%x", 127);
    log.logWarn(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "warn=0x%x", 127);
    log.logError(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "error=0x%x", 127);
    log.logCritical(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication), "critical=0x%x", 127);
    // Try to stop own logging function
    try
    {
        log.logSetOutputFunction(nullptr);
    }
    catch (std::runtime_error& ex)
    {
        std::cout << "Exception: " << ex.what() << "; as expected; libSDL bugzilla issue #3666" << std::endl;
    }
    log.logMessage(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityCritical),
                    "logMessage=%s", ":-)");
}
