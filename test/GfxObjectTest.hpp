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

#ifndef GfxObjectTest_hpp
#define GfxObjectTest_hpp

#include <utility>

#include "GfxObject.hpp"

class GfxObjectTest : public ::testing::Test
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

TEST_F(GfxObjectTest, emptyConstructor)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object;

    EXPECT_EQ(ctrOrg + 1, object.getInstanceId());
    EXPECT_STREQ("$init$", object.getClassName());
}

TEST_F(GfxObjectTest, ConstructorWithStringAssertFail)
{
    // Expect assert failure here in class constructor
    EXPECT_EXIT(gfx::_gfx::GfxObject object2 { nullptr }, ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(GfxObjectTest, ConstructorWithString)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object2 { "object2" };

    EXPECT_EQ(ctrOrg + 1, object2.getInstanceId());
    EXPECT_STREQ("object2", object2.getClassName());
}

TEST_F(GfxObjectTest, CopyConstructor)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object2 { "object2" };
    gfx::_gfx::GfxObject object3 = object2;

    EXPECT_EQ(ctrOrg + 2, object3.getInstanceId());
    EXPECT_STREQ("object2", object3.getClassName());
    EXPECT_STREQ("object2", object2.getClassName());
    EXPECT_EQ(ctrOrg + 1, object2.getInstanceId());
}

TEST_F(GfxObjectTest, MoveConstructor)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object2 { "object2" };
    gfx::_gfx::GfxObject object3 = std::move(object2);

    EXPECT_EQ(ctrOrg + 2, object3.getInstanceId());
    EXPECT_STREQ("object2", object3.getClassName());
    EXPECT_STREQ("$null$", object2.getClassName());
    EXPECT_EQ(-1, object2.getInstanceId());
}

TEST_F(GfxObjectTest, EqualOperator)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object { "object" };
    gfx::_gfx::GfxObject object2 { "object2" };

    EXPECT_STREQ("object", object.getClassName());
    EXPECT_EQ(ctrOrg + 1, object.getInstanceId());
    EXPECT_STREQ("object2", object2.getClassName());
    EXPECT_EQ(ctrOrg + 2, object2.getInstanceId());
    
    // Move objects
    gfx::_gfx::GfxObject object3 = std::move(object);
    gfx::_gfx::GfxObject object4 = std::move(object2);

    EXPECT_EQ(ctrOrg + 3, object3.getInstanceId());
    EXPECT_EQ(ctrOrg + 4, object4.getInstanceId());
    EXPECT_STREQ("$null$", object.getClassName());
    EXPECT_STREQ("$null$", object2.getClassName());
    EXPECT_STREQ("object", object3.getClassName());
    EXPECT_STREQ("object2", object4.getClassName());
    // Expect empty object to be equal
    EXPECT_EQ(true, object.operator==(object2));
    // Expect objects that have been moved to ... to not be equal
    EXPECT_EQ(false, object3.operator==(object4));
}

TEST_F(GfxObjectTest, MoveOperator)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object;
    gfx::_gfx::GfxObject object2 { "object2" };

    EXPECT_EQ(ctrOrg + 2, object2.getInstanceId());
    EXPECT_EQ(ctrOrg + 1, object.getInstanceId());

    object = std::move(object2);

    // ctrOrg + 3 ... after std::move -> new InstanceId will be generated
    EXPECT_EQ(ctrOrg + 3, object.getInstanceId());
    EXPECT_STREQ("object2", object.getClassName());
    EXPECT_STREQ("$null$", object2.getClassName());
    EXPECT_EQ(-1, object2.getInstanceId());
}

TEST_F(GfxObjectTest, BoolOperator)
{
    int32_t ctrOrg = gfx::_gfx::GfxObject::getInstanceCounter();
    gfx::_gfx::GfxObject object;

    EXPECT_EQ(ctrOrg + 1, object.getInstanceId());
    EXPECT_EQ(true, object.operator bool());
}

#endif  // GfxObjectTest_hpp

