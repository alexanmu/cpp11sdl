#include "RuntimeMeta.hpp"

/******************************************************* Meta *******************************************************/
#include <iostream>

#include "GfxRuntimeMeta.hpp"

#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxArrayOrder.hpp"

void _doRuntimeMeta(void)
{
    gfx::rect::GfxPoint pt1;
    gfx::rect::GfxRect rect1;

    gfx::_gfx::GfxRuntimeMeta& rmeta = gfx::_gfx::GfxRuntimeMeta::getInstance();

    std::cout << "rmeta.getClassCount()=" << rmeta.getClassCount() << std::endl;
    for (int32_t index = 0; index < rmeta.getClassCount(); index++)
    {
        auto cinfo = rmeta.getClassInfo(index);
        std::cout << "cinfo.objectInstanceCount_=" << cinfo.objectInstanceCount_ << std::endl;
        std::cout << "cinfo.firstInstanceId_=" << cinfo.firstInstanceId_ << std::endl;
        std::cout << "cinfo.lastInstanceId_=" << cinfo.lastInstanceId_ << std::endl;
    }
    // force scope for variable rect2
    {
        gfx::rect::GfxRect rect2 = rect1;
        rmeta.printToStream(std::cout) << std::endl;
    }
    gfx::_gfx::GfxRuntimeMeta::runtimeMetaActive = false;
    gfx::pixels::GfxArrayOrder ao1;
    gfx::_gfx::GfxRuntimeMeta::runtimeMetaActive = true;
    gfx::pixels::GfxArrayOrder ao2;
    gfx::pixels::GfxArrayOrder ao3;

    ao3.~GfxArrayOrder();
    rmeta.printToStream(std::cout) << std::endl;
}
