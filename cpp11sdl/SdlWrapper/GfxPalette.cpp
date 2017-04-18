/*
  CPP11SDL
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

#include "GfxPalette.hpp"

GfxPalette::GfxPalette() : GfxRootClass("GfxPalette")
{
    pal_ = nullptr;
};

GfxPalette::GfxPalette(const GfxPalette& other) : GfxRootClass("GfxPalette")
{
	if (pal_ != nullptr)
    {
		SDL_FreePalette(pal_);
    }
	pal_ = SDL_AllocPalette(other.pal_->ncolors);
	SDL_SetPaletteColors(pal_,other.pal_->colors,0,other.pal_->ncolors);
}

GfxPalette::GfxPalette(GfxPalette&& other) : GfxRootClass("GfxPalette")
{
	if (pal_ != nullptr)
    {
		SDL_FreePalette(pal_);
    }
	pal_ = SDL_AllocPalette(other.pal_->ncolors);
	SDL_SetPaletteColors(pal_,other.pal_->colors,0,other.pal_->ncolors);
	/* free other's resources */
	SDL_FreePalette(other.pal_);
	other.pal_ = nullptr;
}

GfxPalette::GfxPalette(const uint16_t ncolors,const GfxColorVector& colors) : GfxRootClass("GfxPalette")
{
	int colorindex;

	if (pal_ != nullptr)
    {
		SDL_FreePalette(pal_);
    }
	pal_ = SDL_AllocPalette(ncolors);
	colorindex = 0;
	for(GfxColor clr : colors)
	{
		SDL_SetPaletteColors(pal_,clr.getAsSdlTypePtr(),colorindex,1);
		colorindex += 1;
	}
}

GfxPalette::~GfxPalette()
{
    if (pal_ != nullptr)
    {
        SDL_FreePalette(pal_);
    }
}

GfxPalette& GfxPalette::operator=(const GfxPalette& other)
{
	if(this != &other)
	{
		if (pal_ != nullptr)
        {
			SDL_FreePalette(pal_);
        }
		pal_ = SDL_AllocPalette(other.pal_->ncolors);
		SDL_SetPaletteColors(pal_,other.pal_->colors,0,other.pal_->ncolors);
	}
	return *this;
}

GfxPalette& GfxPalette::operator=(GfxPalette&& other)
{
	if(this != &other)
	{
		if (pal_ != nullptr)
        {
			SDL_FreePalette(pal_);
        }
		pal_ = SDL_AllocPalette(other.pal_->ncolors);
		SDL_SetPaletteColors(pal_,other.pal_->colors,0,other.pal_->ncolors);
		/* Free other's resources */
		SDL_FreePalette(other.pal_);
		other.pal_ = nullptr;
	}
	return *this;
}

void GfxPalette::allocPalette(const uint16_t ncolors)
{
	if (pal_ != nullptr)
    {
		SDL_FreePalette(pal_);
    }
	pal_ = SDL_AllocPalette(ncolors);
}

void GfxPalette::freePalette()
{
	if (pal_ != nullptr)
	{
		SDL_FreePalette(pal_);
		pal_ = nullptr;
	}
}

int GfxPalette::setPaletteColors(const GfxColorVector& colors,const uint16_t firstcolor)
{
	int errorcode = 0;
	int currentcolorindex = firstcolor;

	for(GfxColor clr : colors)
	{
		errorcode = SDL_SetPaletteColors(pal_,clr.getAsSdlTypePtr(),currentcolorindex,1);
		currentcolorindex += 1;
		if (errorcode != 0)
        {
			break;
        }
	}
	return errorcode;
}

uint16_t GfxPalette::getNumColors(void) const
{
	return pal_->ncolors;
}

std::unique_ptr<GfxPalette::GfxColorVector> GfxPalette::getColors(void) const
{
	GfxColorVector clrs(pal_->ncolors);

	for(int i = 0; i < pal_->ncolors; i++)
	{
		GfxColor c(pal_->colors[i]);
		clrs.push_back(c);
	}
    std::unique_ptr<GfxColorVector> ptr {new GfxColorVector(clrs)};
    return ptr;
}

uint32_t GfxPalette::getVersion(void) const
{
	return pal_->version;
}

int GfxPalette::getRefCount(void) const
{
	return pal_->refcount;
}

GfxPalette::SdlType GfxPalette::getAsSdlType() const
{
    return *pal_;
}

GfxPalette::SdlTypePtr GfxPalette::getAsSdlTypePtr(void) const
{
    /* This is dangerous; we allow access to object private data */
    return (SdlTypePtr)pal_;
}
