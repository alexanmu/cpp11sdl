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

#include "RuntimeMeta.hpp"

/******************************************************* Meta *******************************************************/
#include <iostream>

#include "GfxRuntimeMeta.hpp"

#include "GfxColor.hpp"
#include "GfxRect.hpp"
#include "GfxArrayOrder.hpp"

void _doRuntimeMeta(void)
{
    gfx::_gfx::GfxRuntimeMeta::runtimeMetaActive = true;

    gfx::rect::GfxPoint pt1;
    gfx::rect::GfxRect rect1;

    gfx::_gfx::GfxRuntimeMeta& rmeta = gfx::_gfx::GfxRuntimeMeta::getInstance();

    std::cout << "rmeta.getClassCount()=" << rmeta.getClassCount() << std::endl;
    for (int32_t index = 0; index < rmeta.getClassCount(); index++)
    {
        auto cinfo = rmeta.getClassInfo(index);
        std::cout << "cinfo.maxObjectInstanceCount_=" << cinfo.maxObjectInstanceCount_ << std::endl;
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
