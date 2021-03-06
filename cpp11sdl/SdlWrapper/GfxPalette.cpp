#include "GfxPalette.hpp"

GfxPalette::GfxPalette(int ncolors, GfxColorVector colors)
{
	int colorindex;

	pal_ = SDL_AllocPalette(ncolors);
	colorindex = 0;
	for(GfxColor clr : colors)
	{
		SDL_SetPaletteColors(pal_,clr.getAsSdlTypePtr(),colorindex,1);
		colorindex += 1;
	}
}

void GfxPalette::allocPalette(int ncolors)
{
	if (pal_ != nullptr)
		SDL_FreePalette(pal_);
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

int GfxPalette::setPaletteColors(GfxColorVector colors, int firstcolor)
{
	int errorcode;

	for(GfxColor clr : colors)
	{
		errorcode = SDL_SetPaletteColors(pal_,clr.getAsSdlTypePtr(),firstcolor,1);
		firstcolor += 1;
		if (errorcode != 0)
			break;
	}
	return errorcode;
}

int GfxPalette::getNumColors(void) const
{
	return pal_->ncolors;
}

GfxPalette::GfxColorVector GfxPalette::getColors(void) const
{
	GfxColorVector clrs(pal_->ncolors);

	for(int i = 0; i < pal_->ncolors; i++)
	{
		GfxColor c(pal_->colors[i]);
		clrs.push_back(c);
	}
	return clrs;
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
    return (SdlTypePtr)&pal_;
}
