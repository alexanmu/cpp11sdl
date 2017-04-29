//
//  GDemoApp.hpp
//  Giotto
//
//  Created by George Oros on 4/29/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GDemoApp_hpp
#define GDemoApp_hpp

#include <string>
#include <memory>

#include "GObject.hpp"
#include "GApplication.hpp"
#include "GForm.hpp"

class GDemoApp : public GApplication
{
public:
    GDemoApp();
    GDemoApp(const std::string& appName);

    virtual ~GDemoApp();

    void loadAppConfiguration(void);
    void run(void);
private:
    std::string appName_;
    std::shared_ptr<GForm> mainForm_;
};

#endif /* GDemoApp_hpp */
