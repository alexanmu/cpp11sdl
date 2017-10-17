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

#ifndef GfxRuntimeMetaTest_hpp
#define GfxRuntimeMetaTest_hpp

#include "GfxRuntimeMeta.hpp"

class GfxRuntimeMetaTest : public ::testing::Test
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

TEST_F(GfxRuntimeMetaTest, getInstance)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    // Value will change each time a new const class will be added to the project;
    // Class derived from GfxObject and not GfxColor, GfxColors2 !
    EXPECT_EQ(0, object.getClassCount());
}

TEST_F(GfxRuntimeMetaTest, getClassInfoWrongIndex)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EXIT(object.getClassInfo(-1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, getClassNameWrongIndex)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EXIT(object.getClassName(-1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, createOneStaticObject)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();
    gfx::_gfx::GfxObject gobj;

    EXPECT_EQ(1, object.getClassCount());
    EXPECT_EQ(1, object.getClassInfo(0).maxObjectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).objectInstanceCount_);
    EXPECT_EQ(16, object.getClassInfo(0).firstInstanceId_);
    EXPECT_EQ(-1, object.getClassInfo(0).lastInstanceId_);
}

TEST_F(GfxRuntimeMetaTest, createTwoStaticObjects)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();
    gfx::_gfx::GfxObject gobj;
    gfx::_gfx::GfxObject gobj2("O2");

    EXPECT_EQ(2, object.getClassCount());
    // Obj 1
    EXPECT_EQ(1, object.getClassInfo(0).maxObjectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).objectInstanceCount_);
    EXPECT_EQ(18, object.getClassInfo(0).firstInstanceId_);
    EXPECT_EQ(-1, object.getClassInfo(0).lastInstanceId_);
    EXPECT_STREQ("O2", object.getClassName(0).c_str());
    // Obj 2
    EXPECT_EQ(1, object.getClassInfo(1).maxObjectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(1).objectInstanceCount_);
    EXPECT_EQ(17, object.getClassInfo(1).firstInstanceId_);
    EXPECT_EQ(-1, object.getClassInfo(1).lastInstanceId_);
    EXPECT_STREQ("$init$", object.getClassName(1).c_str());
}

TEST_F(GfxRuntimeMetaTest, createOneDynamicObjectInvalidName)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    EXPECT_EXIT(object.constructObject(nullptr, 1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, createOneDynamicObjectInvalidInstanceId)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    EXPECT_EXIT(object.constructObject("O1", -1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, createOneDynamicObject)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    // Construct one object
    object.constructObject("O1", 1);
    EXPECT_EQ(1, object.getClassInfo(0).maxObjectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).objectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).firstInstanceId_);
    EXPECT_EQ(-1, object.getClassInfo(0).lastInstanceId_);
    EXPECT_STREQ("O1", object.getClassName(0).c_str());
}

TEST_F(GfxRuntimeMetaTest, destructDynamicObjectInvalidName)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    // Construct one object
    EXPECT_EXIT(object.destructObject(nullptr, 1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, destructDynamicObjectInvalidInstanceId)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    // Construct one object
    EXPECT_EXIT(object.destructObject("O1", -1), ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxRuntimeMetaTest, createDestructOneDynamicObject)
{
    gfx::_gfx::GfxRuntimeMeta& object = gfx::_gfx::GfxRuntimeMeta::getInstance();
    object.clear_map();

    EXPECT_EQ(0, object.getClassCount());
    // Construct one object
    object.constructObject("O1", 1);
    EXPECT_EQ(1, object.getClassInfo(0).maxObjectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).objectInstanceCount_);
    EXPECT_EQ(1, object.getClassInfo(0).firstInstanceId_);
    EXPECT_EQ(-1, object.getClassInfo(0).lastInstanceId_);
    EXPECT_STREQ("O1", object.getClassName(0).c_str());
    object.destructObject("O1", 1);
    EXPECT_EQ(1, object.getClassInfo(0).lastInstanceId_);
}

#endif  // GfxRuntimeMetaTest_hpp
