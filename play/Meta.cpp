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
