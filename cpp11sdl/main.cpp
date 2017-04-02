//
//  main.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include <iostream>

#include "SDL2/SDL.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int errorcode_ = SDL_Init(SDL_INIT_EVERYTHING);
    if (errorcode_ != 0) std::cout << "init error ...\n";
                    else std::cout << "init ok\n";
    SDL_Quit();
    return 0;
}
