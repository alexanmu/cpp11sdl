#ifndef GfxPalette_hpp
#define GfxPalette_hpp

#include <vector>
#include <memory>

#include "GfxSdlHeader.hpp"
#include "GfxRootClass.hpp"
#include "GfxColor.hpp"

class GfxPalette final : public GfxRootClass
{
public:
	typedef SDL_Palette SdlType;
	typedef SDL_Palette* SdlTypePtr;

	using GfxColorVector = std::vector<GfxColor>;

    GfxPalette();
	GfxPalette(const uint16_t ncolors,const GfxColorVector& colors);

	GfxPalette(const GfxPalette& other);
	GfxPalette(GfxPalette&& other);

    ~GfxPalette();

	GfxPalette& operator=(const GfxPalette& other);
	GfxPalette& operator=(GfxPalette&& other);

	/* Methods */
	void allocPalette(const uint16_t ncolors);
	void freePalette();
	int setPaletteColors(const GfxColorVector& vec,const uint16_t firstcolor);

	/* Getters */
	uint16_t getNumColors(void) const;
    std::unique_ptr<GfxColorVector> getColors(void) const;
	uint32_t getVersion(void) const;
	int getRefCount(void) const;

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
	SdlTypePtr pal_;
};

#endif
