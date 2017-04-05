//
//  GfxInitQuit.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef SdlInitQuit_hpp
#define SdlInitQuit_hpp

#include "GfxSdlHeader.hpp"

class GfxInitQuit final
{
public:
    // Init Video, Audio or Everything ...
    enum class GfxInitComponent
    {
        initVideo,
        initAudio,
        initEverything
    };
    
    GfxInitQuit(GfxInitComponent gfxInitComp) : gfxInitComp_(gfxInitComp), errorcode_(0)
    {
        int initParam;
        
        initParam = 0;
        if (gfxInitComp == GfxInitComponent::initVideo)
            initParam = SDL_INIT_VIDEO;
        if (gfxInitComp == GfxInitComponent::initAudio)
            initParam = SDL_INIT_AUDIO;
        if (gfxInitComp == GfxInitComponent::initEverything)
            initParam = SDL_INIT_EVERYTHING;
        errorcode_ = SDL_Init(initParam);
    }
    
    ~GfxInitQuit()
    {
        SDL_Quit();
    }
    
    // No default constructor
    GfxInitQuit() = delete;
    // Copy/Move constructors don't make sense
    GfxInitQuit(const GfxInitQuit&) = delete;
    GfxInitQuit(GfxInitQuit&&) = delete;
    
    // Forbid copy/move assignements
    GfxInitQuit& operator=(const GfxInitQuit&) = delete;
    GfxInitQuit& operator=(GfxInitQuit&&) = delete;
    
    // Return error code after init call
    int getErrorCode() const
    {
        return errorcode_;
    }
    
    // Returns the requested component
    GfxInitComponent getInitedComponent() const
    {
        return gfxInitComp_;
    }
private:
    GfxInitComponent gfxInitComp_;
    int errorcode_;
};

#endif /* GfxInitQuit_hpp */
