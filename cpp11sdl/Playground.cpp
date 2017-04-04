//
//  Playground.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/4/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#include "Playground.hpp"

#include <iostream>

auto lambda = [](int a) -> int {
    return a*a;
};

int func(int a)
{
    return a*a;
}

int (*funcptr)(int) = func;

class functor
{
public:
    int operator()(int a)
    {
        return a*a;
    }
};

void Playground::Play(void)
{
    auto a1 = lambda(5);
    auto a2 = funcptr(5);
    auto a3 = functor()(5);
    
    std::cout << "a1=" << a1 << " " << sizeof(a1) << '\n';
    std::cout << "a2=" << a2 << " " << sizeof(a2) << '\n';
    std::cout << "a3=" << a3 << " " << sizeof(a3) << '\n';
    std::cout << sizeof(lambda) << '\n';
    std::cout << "sizeof(func)" << '\n';
    std::cout << sizeof(functor) << '\n';
}
