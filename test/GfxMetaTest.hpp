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

#ifndef GfxMetaTest_hpp
#define GfxMetaTest_hpp

#include "GfxMeta.hpp"

class GfxMetaTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        // nothing to do; yet
    }

    virtual void TearDown()
    {
        // nothing to do; yet
    }
};

TEST_F(GfxMetaTest, emptyConstructor)
{
    gfx::_gfx::GfxMeta object;

    // Value will change each time a new class is added to gfx!
    EXPECT_EQ(110, object.getClassCount());
}

TEST_F(GfxMetaTest, wrongClassIndexNegativeValue)
{
    gfx::_gfx::GfxMeta object;

    // Expect assert failure here in class constructor
    EXPECT_EXIT(object.getClassInfo(-1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxMetaTest, wrongClassIndexPositiveValue)
{
    gfx::_gfx::GfxMeta object;

    EXPECT_EQ(nullptr, object.getClassInfo(object.getClassCount()).className_);
    EXPECT_EQ(-1, object.getClassInfo(object.getClassCount()).size_);
    EXPECT_EQ(-1, object.getClassInfo(object.getClassCount()).sizeOfThis_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).sdlResource_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).callsSdl_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).hasSdlType_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).hasSdlTypePtr_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).hasValueType_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).hasPublicClearMethod_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isAbstract_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isPolymorphic_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isDefaultConstructible_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isCopyConstructible_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isCopyAssignable_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isMoveConstructible_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isMoveAssignable_);
    EXPECT_EQ(false, object.getClassInfo(object.getClassCount()).isDerivedFromGfxObject_);
}

TEST_F(GfxMetaTest, wrongClassNameNullLengthString)
{
    gfx::_gfx::GfxMeta object;

    // Expect assert failure here in class constructor
    EXPECT_EXIT(object.getClassInfo(""), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxMetaTest, wrongClassNameValidString)
{
    gfx::_gfx::GfxMeta object;

    EXPECT_EQ(nullptr, object.getClassInfo("GfxWrongClassName").className_);
    EXPECT_EQ(-1, object.getClassInfo("GfxWrongClassName").size_);
    EXPECT_EQ(-1, object.getClassInfo("GfxWrongClassName").sizeOfThis_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").sdlResource_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").callsSdl_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").hasSdlType_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").hasSdlTypePtr_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").hasValueType_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").hasPublicClearMethod_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isAbstract_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isPolymorphic_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isDefaultConstructible_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isCopyConstructible_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isCopyAssignable_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isMoveConstructible_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isMoveAssignable_);
    EXPECT_EQ(false, object.getClassInfo("GfxWrongClassName").isDerivedFromGfxObject_);
}

TEST_F(GfxMetaTest, validClassIndex)
{
    gfx::_gfx::GfxMeta object;

    EXPECT_STREQ("GfxBits", object.getClassInfo(0).className_);
    EXPECT_EQ(32, object.getClassInfo(0).size_);
    EXPECT_EQ(0, object.getClassInfo(0).sizeOfThis_);
    EXPECT_EQ(false, object.getClassInfo(0).sdlResource_);
    EXPECT_EQ(true, object.getClassInfo(0).callsSdl_);
    EXPECT_EQ(false, object.getClassInfo(0).hasSdlType_);
    EXPECT_EQ(false, object.getClassInfo(0).hasSdlTypePtr_);
    EXPECT_EQ(false, object.getClassInfo(0).hasValueType_);
    EXPECT_EQ(false, object.getClassInfo(0).hasPublicClearMethod_);
    EXPECT_EQ(false, object.getClassInfo(0).isAbstract_);
    EXPECT_EQ(true, object.getClassInfo(0).isPolymorphic_);
    EXPECT_EQ(true, object.getClassInfo(0).isDefaultConstructible_);
    EXPECT_EQ(false, object.getClassInfo(0).isCopyConstructible_);
    EXPECT_EQ(false, object.getClassInfo(0).isCopyAssignable_);
    EXPECT_EQ(false, object.getClassInfo(0).isMoveConstructible_);
    EXPECT_EQ(false, object.getClassInfo(0).isMoveAssignable_);
    EXPECT_EQ(true, object.getClassInfo(0).isDerivedFromGfxObject_);
}

TEST_F(GfxMetaTest, validClassName)
{
    gfx::_gfx::GfxMeta object;

    EXPECT_STREQ("GfxBlendMode", object.getClassInfo("GfxBlendMode").className_);
    EXPECT_EQ(40, object.getClassInfo("GfxBlendMode").size_);
    EXPECT_EQ(8, object.getClassInfo("GfxBlendMode").sizeOfThis_);
    EXPECT_EQ(false, object.getClassInfo("GfxBlendMode").sdlResource_);
    EXPECT_EQ(false, object.getClassInfo("GfxBlendMode").callsSdl_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").hasSdlType_);
    EXPECT_EQ(false, object.getClassInfo("GfxBlendMode").hasSdlTypePtr_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").hasValueType_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").hasPublicClearMethod_);
    EXPECT_EQ(false, object.getClassInfo("GfxBlendMode").isAbstract_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isPolymorphic_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isDefaultConstructible_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isCopyConstructible_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isCopyAssignable_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isMoveConstructible_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isMoveAssignable_);
    EXPECT_EQ(true, object.getClassInfo("GfxBlendMode").isDerivedFromGfxObject_);
}

TEST_F(GfxMetaTest, metaTableSize)
{
    gfx::_gfx::GfxMeta object;

    EXPECT_EQ(32 * object.getClassCount(), object.getClassInfoTableSizeInBytes());
}

#endif  // GfxMetaTest_hpp

