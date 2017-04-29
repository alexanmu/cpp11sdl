/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/

#include "GfxInitQuit.hpp"

GfxInitQuit::GfxInitQuit(const GfxInitComponent gfxInitComp) :
                GfxRootClass("GfxInitQuit"), gfxInitComp_(gfxInitComp), errorcode_(0)
{
    int initParam;

    initParam = 0;
    if (gfxInitComp == GfxInitComponent::initVideo)
    {
        initParam = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    }
    if (gfxInitComp == GfxInitComponent::initAudio)
    {
        initParam = SDL_INIT_AUDIO | SDL_INIT_EVENTS;
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

void GfxInitQuit::quitRequested(void)
{
    SDL_QuitRequested();
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

/* EOF */
