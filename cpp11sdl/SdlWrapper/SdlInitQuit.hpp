//
//  SdlInitQuit.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef SdlInitQuit_hpp
#define SdlInitQuit_hpp

#include "SDL2/SDL.h"

class SdlInitQuit final
{
public:
    // Init Video, Audio or Everything ...
    enum class SdlInitComponent
    {
        initVideo,
        initAudio,
        initEverything
    };
    
    SdlInitQuit(SdlInitComponent sdlInitComp) : sdlInitComp_(sdlInitComp), errorcode_(0)
    {
        int initParam;
        
        initParam = 0;
        if (sdlInitComp_ == SdlInitComponent::initVideo)
            initParam = SDL_INIT_VIDEO;
        if (sdlInitComp_ == SdlInitComponent::initAudio)
            initParam = SDL_INIT_AUDIO;
        if (sdlInitComp_ == SdlInitComponent::initEverything)
            initParam = SDL_INIT_EVERYTHING;
        errorcode_ = SDL_Init(initParam);
    }
    
    ~SdlInitQuit()
    {
        SDL_Quit();
    }
    
    // No default constructor
    SdlInitQuit() = delete;
    // Copy/Move constructors don't make sense
    SdlInitQuit(const SdlInitQuit&) = delete;
    SdlInitQuit(SdlInitQuit&&) = delete;
    
    // Forbid copy/move assignements
    SdlInitQuit& operator=(const SdlInitQuit&) = delete;
    SdlInitQuit& operator=(SdlInitQuit&&) = delete;
    
    // Return error code after init call
    int getErrorCode() const
    {
        return errorcode_;
    }
    
    // Returns the requested component
    SdlInitComponent getInitedComponent() const
    {
        return sdlInitComp_;
    }
private:
    int errorcode_;
    SdlInitComponent sdlInitComp_;
};

#endif /* SdlInitQuit_hpp */
