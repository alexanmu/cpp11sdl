//
//  GfxInitQuit.cpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#include "GfxInitQuit.hpp"

GfxInitQuit::GfxInitQuit(GfxInitComponent gfxInitComp) : GfxRootClass("GfxInitQuit"), gfxInitComp_(gfxInitComp), errorcode_(0)
{
    int initParam;
    
    initParam = 0;
    if (gfxInitComp == GfxInitComponent::initVideo)
    {
        initParam = SDL_INIT_VIDEO;
    }
    if (gfxInitComp == GfxInitComponent::initAudio)
    {
        initParam = SDL_INIT_AUDIO;
    }
    if (gfxInitComp == GfxInitComponent::initEverything)
    {
        initParam = SDL_INIT_EVERYTHING;
    }
    errorcode_ = SDL_Init(initParam);
}

GfxInitQuit::~GfxInitQuit()
{
    SDL_Quit();
}

// Return error code after init call
int GfxInitQuit::getErrorCode() const
{
    return errorcode_;
}

// Returns the requested component
GfxInitQuit::GfxInitComponent GfxInitQuit::getInitedComponent() const
{
    return gfxInitComp_;
}
