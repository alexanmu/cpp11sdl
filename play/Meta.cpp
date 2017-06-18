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

	for (int32_t index = 0; index < meta.getClassCount(); index++)
	{
	    classInfo = meta.getClassInfo(index);
	    std::cout << "Name=" << classInfo.className_ << "\t\t";
	    std::cout << "Size[bytes]=" << classInfo.size_ << '\t';
	    std::cout << "hasSdlType=" << classInfo.hasSdlType_ << '\t';
	    std::cout << "hasSdlTypePtr=" << classInfo.hasSdlTypePtr_ << '\t';
        std::cout << "isAbstract<>=" << classInfo.isAbstract_ << '\t';
        std::cout << "isPolym<>=" << classInfo.isPolymorphic_ << '\t';
        std::cout << "isMoveCtor<>=" << classInfo.isMoveConstructible_ << '\t';
        std::cout << "isMoveAssign<>=" << classInfo.isMoveAssignable_ << '\t';
        std::cout << "isGfxObjChild<>=" << classInfo.isDerivedFromGfxObject_ << '\t';
        std::cout << "sdlResource=" << classInfo.sdlResource_ << '\t';
        std::cout << "hasValueType<>=" << classInfo.hasValueType_ << '\n';
        std::cout << "CallsSdl=" << classInfo.callsSdl_ << '\n';
	}
    std::cout << std::endl;
}
