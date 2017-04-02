//
//  main.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include <iostream>

#include "SdlInitQuit.hpp"

int main(int argc, const char * argv[]) {
    SdlInitQuit iq(SdlInitQuit::SdlInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
        std::cout << "Init failed";
    else
    {
        // do stuff
    }
    return 0;
}
