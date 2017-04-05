//
//  main.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include <iostream>

#include "GfxInitQuit.hpp"
#include "Playground.hpp"

int main(int argc, const char * argv[]) {
    GfxInitQuit iq(GfxInitQuit::GfxInitComponent::initEverything);
    if (iq.getErrorCode() != 0)
        std::cout << "Init failed\n";
    else
    {
        // do stuff
        std::cout << "Doing stuff\n";
        Playground p;
        p.Play();
    }
    return 0;
}
