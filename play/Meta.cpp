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

#include "Meta.hpp"

/******************************************************* Meta *******************************************************/
#include <iostream>
#include <cstdint>

#include "GfxMeta.hpp"

void _doMeta(void)
{
    gfx::_gfx::GfxMeta meta;
    gfx::_gfx::GfxMeta::ClassInfo classInfo;

    std::cout << "meta.getClassCount()=" << meta.getClassCount() << '\n';
    std::cout << "meta.getClassInfoTableSizeInBytes()=" << meta.getClassInfoTableSizeInBytes() << '\n';
	for (int32_t index = 0; index < meta.getClassCount(); index++)
	{
        classInfo = meta.getClassInfo(index);
	    std::cout << "Name=" << classInfo.className_ << ' ';
	    std::cout << "Size=" << classInfo.size_ << ' ';
        std::cout << "sdlResource=" << classInfo.sdlResource_ << ' ';
        std::cout << "CallsSdl=" << classInfo.callsSdl_ << '\n';
	    std::cout << "hasSdlType=" << classInfo.hasSdlType_ << ' ';
	    std::cout << "hasSdlTypePtr=" << classInfo.hasSdlTypePtr_ << ' ';
        std::cout << "hasValueType=" << classInfo.hasValueType_ << ' ';
        std::cout << "hasClear=" << classInfo.hasClearMethod_ << ' ';
        std::cout << "isAbstract=" << classInfo.isAbstract_ << ' ';
        std::cout << "isPolym=" << classInfo.isPolymorphic_ << ' ';
        std::cout << "isCopyCtor=" << classInfo.isCopyConstructible_ << ' ';
        std::cout << "isCopyAssign=" << classInfo.isCopyAssignable_ << ' ';
        std::cout << "isMoveCtor=" << classInfo.isMoveConstructible_ << ' ';
        std::cout << "isMoveAssign=" << classInfo.isMoveAssignable_ << ' ';
        std::cout << "isGfxObjChild=" << classInfo.isDerivedFromGfxObject_ << '\n';
	}
    std::cout << std::endl;
}
