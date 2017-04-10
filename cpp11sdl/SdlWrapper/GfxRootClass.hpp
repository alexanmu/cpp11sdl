//
//  GfxRootClass.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/8/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxRootClass_hpp
#define GfxRootClass_hpp

#include <string>

class GfxRootClass
{
public:
    GfxRootClass();
    GfxRootClass(std::string strClassName);
    
    GfxRootClass(const GfxRootClass& other);
    GfxRootClass(GfxRootClass&& other);
    
    virtual ~GfxRootClass();

    GfxRootClass& operator=(const GfxRootClass& other);
    GfxRootClass& operator=(GfxRootClass&& other);
    
    std::string getClassName(void) const;
    int getInstanceId(void) const;
private:
    std::string strClassName_;
    int intInstanceId_;
    
    static int intInstanceCounter_;
};

#endif /* GfxRootClass_hpp */
