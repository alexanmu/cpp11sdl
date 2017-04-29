//
//  GApplication.hpp
//  Giotto
//
//  Created by George Oros on 4/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GApplication_hpp
#define GApplication_hpp

#include <string>

#include "GObject.hpp"

class GApplication : public GObject
{
public:
    GApplication(std::string appName);

    void loadAppConfiguration(void);
    void run(void);
private:
    std::string appName_;
};

#endif /* GApplication_hpp */
