//
//  GApplication.hpp
//  Giotto
//
//  Created by George Oros on 4/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GApplication_hpp
#define GApplication_hpp

#include <memory>
#include <string>

#include "GObject.hpp"
#include "GForm.hpp"

class GApplication : public GObject
{
public:
    virtual void loadAppConfiguration(void) = 0;
    virtual void run(void) = 0;
};

#endif /* GApplication_hpp */
