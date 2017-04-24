//
//  GfxWindowPosition.hpp
//  Giotto
//
//  Created by George Oros on 4/24/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef GfxWindowPosition_hpp
#define GfxWindowPosition_hpp

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

class GfxWindowPosition final : public GfxRootClass
{
public:
    enum class GfxWindowPositionValues : int
    {
        positionUndefined = SDL_WINDOWPOS_UNDEFINED,
        positionCentered = SDL_WINDOWPOS_CENTERED,
        positionSpecified
    };

    GfxWindowPosition();
    GfxWindowPosition(GfxWindowPositionValues pos,uint32_t coord = -1);
    GfxWindowPosition(GfxWindowPosition const& other);
    GfxWindowPosition(GfxWindowPosition&& other);
    
    GfxWindowPosition& operator=(GfxWindowPosition const& other);
    GfxWindowPosition& operator=(GfxWindowPosition&& other);

    void setPosition(GfxWindowPositionValues pos);
    GfxWindowPositionValues getPosition(void) const;

    void setCoordinate(uint32_t coord = -1);
    uint32_t getCoordinate(void) const;
private:
    GfxWindowPositionValues pos_;
    uint32_t coord_;
};

#endif /* GfxWindowPosition_hpp */
