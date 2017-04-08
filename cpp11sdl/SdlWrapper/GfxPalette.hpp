#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <vector>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

class GfxPalette final : public GfxRootClass
{
public:
	typedef SDL_Palette SdlType;
	typedef SDL_Palette* SdlTypePtr;

	using GfxColorVector = std::vector<GfxColor>;

    GfxPalette() : GfxRootClass("GfxPalette")
	{
		pal_ = nullptr;
	};
	GfxPalette(int ncolors, GfxColorVector colors);

	GfxPalette(const GfxPalette& other);
	GfxPalette(GfxPalette&& other);

    ~GfxPalette()
    {
        if (pal_ != nullptr)
            SDL_FreePalette(pal_);
    }

	GfxPalette& operator=(const GfxPalette& other);
	GfxPalette& operator=(GfxPalette&& other);

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
