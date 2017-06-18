#include "Log.hpp"

/******************************************************* log *******************************************************/
#include <cassert>
#include <iostream>

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
        virtual void operator()(void* userdata,gfx::log::GfxLogCategory const& cat,
                        gfx::log::GfxLogPriority const& prio, std::string const& message) const noexcept
        {
            assert(userdata != nullptr);
            assert(cat);
            assert(prio);

            std::cout << "<" << message << ">" << std::endl;
        }
    };
}

void _doLog(void)
{
    gfx::log::GfxLog log;
    prv::LogOutFunc lofunc;
    char ch = 'c';
    char * usrdata = &ch;

    using gfx::log::GfxLogCategory;
    using gfx::log::GfxLogPriority;

    // test Get
    prv::LogOutFunc * tst_lofuncptr = nullptr;
    void * tst_userdata = nullptr;
    tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction(&tst_userdata));
    if (tst_lofuncptr == nullptr)
    {
        std::cout << "nullptr; as expected" << std::endl;
    }

    log.setPriority(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityVerbose));
    log.log("char=%c", 'a');
    log.log("value=%d", 128);
    log.log("float1=%f float2=%f", 1.5, 2.6);
    log.log("str=%s char=%c int=%d", "string", ';', 5);
    // Set new output function
    log.logSetOutputFunction(&lofunc, static_cast<void *>(usrdata));
    // test new output function
    tst_lofuncptr = reinterpret_cast<prv::LogOutFunc *>(log.logGetOutputFunction(&tst_userdata));
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
        log.logSetOutputFunction(nullptr, static_cast<void *>(usrdata));
    }
    catch (std::runtime_error ex)
    {
        std::cout << "Exception: " << ex.what() << "; as expected; libSDL bugzilla issue #3666" << std::endl;
    }
    log.logMessage(GfxLogCategory(GfxLogCategory::ValueType::logCategoryApplication),
                    GfxLogPriority(GfxLogPriority::ValueType::logPriorityCritical),
                    "logMessage=%s",":-)");
}
