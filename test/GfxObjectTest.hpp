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

#include <string>

#include "GfxObject.hpp"

class GfxObjectTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        //
    }

    virtual void TearDown()
    {
        //
    }

    gfx::_gfx::GfxObject object;
    gfx::_gfx::GfxObject object2 {"object2"};
};

TEST_F(GfxObjectTest, emptyConstructor)
{
    // will fail if value != 32; all const classes are initialized by now
    EXPECT_EQ(32, object.getInstanceId());
    EXPECT_EQ("$init$", object.getClassName());
}

TEST_F(GfxObjectTest, ConstructorWithString)
{
    // will fail if value != 35; all const classes are initialized by now
    EXPECT_EQ(35, object2.getInstanceId());
    EXPECT_EQ("object2", object2.getClassName());
}


#endif  // GfxObjectTest_hpp

