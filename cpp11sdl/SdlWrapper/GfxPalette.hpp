#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <vector>

#include "SDL/include/SDL.h"

#include "GfxColor.hpp"

class GfxPalette final
{
public:
	typedef SDL_Palette SdlType;
	typedef SDL_Palette* SdlTypePtr;

	using GfxColorVector = std::vector<GfxColor>;

	GfxPalette() = delete;
	GfxPalette(int ncolors, GfxColorVector colors);

	~GfxPalette()
	{
		if (pal_ != nullptr)
			SDL_FreePalette(pal_);
	}

	GfxPalette(const GfxPalette&) = delete;
	GfxPalette(GfxPalette&&) = delete;

	GfxPalette& operator=(const GfxPalette&) = delete;
	GfxPalette& operator=(GfxPalette&&) = delete;

	/* Methods */
	void allocPalette(int ncolors);
	void freePalette();
	int setPaletteColors(GfxColorVector vec, int firstcolor);

	/* Getters */
	int getNumColors(void) const;
	GfxColorVector getColors(void) const;
	uint32_t getVersion(void) const;
	int getRefCount(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
	SdlTypePtr pal_;
};

#endif
