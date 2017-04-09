//
//  GfxInitQuit.hpp
//  cpp11sdl
//
//  Created by George Oros on 4/2/17.
//  Copyright � 2017 George Oros. All rights reserved.
//

#ifndef SdlInitQuit_hpp
#define SdlInitQuit_hpp

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"

class GfxInitQuit final : public GfxRootClass
{
public:
    // Init Video, Audio or Everything ...
    enum class GfxInitComponent
    {
        initVideo,
        initAudio,
        initEverything
    };
    
    // No default constructor
    GfxInitQuit() = delete;
    
    GfxInitQuit(GfxInitComponent gfxInitComp);

    // Copy/Move constructors don't make sense
    GfxInitQuit(const GfxInitQuit&) = delete;
    GfxInitQuit(GfxInitQuit&&) = delete;
    
    // Forbid copy/move assignements
    GfxInitQuit& operator=(const GfxInitQuit&) = delete;
    GfxInitQuit& operator=(GfxInitQuit&&) = delete;
    
    // Explicit destructor to de-init SDL lib
    ~GfxInitQuit();
    
    int getErrorCode() const;
    GfxInitComponent getInitedComponent() const;
private:
    GfxInitComponent gfxInitComp_;
    int errorcode_;
};

#endif /* GfxInitQuit_hpp */
