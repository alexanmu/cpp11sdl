//
//  Playground.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/4/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef Playground_hpp
#define Playground_hpp

#include <cstdint>

class Playground
{
public:
    void Play(void);
private:
	void DoAlgo(int algo_index);

	double Algo0(std::uint32_t* ptr);
	double Algo1(std::uint32_t* ptr);
	double Algo2(std::uint32_t* ptr);
};

#endif /* Playground_hpp */
