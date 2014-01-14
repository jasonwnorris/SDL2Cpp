// Surface.cpp

// SDL Includes
#include <SDL_image.h>
// Project Includes
#include <SDL2Cpp\Surface.hpp>

namespace SDL2
{
	Surface::Surface(Uint32 pFlags, int pWidth, int pHeight, int pDepth, Uint32 pRedMask, Uint32 pGreenMask, Uint32 pBlueMask, Uint32 pAlphaMask)
	{
		// Create the surface.
		mSurface = SDL_CreateRGBSurface(pFlags, pWidth, pHeight, pDepth, pRedMask, pGreenMask, pBlueMask, pAlphaMask);
	}
	
	Surface::Surface(void* pPixels, int pWidth, int pHeight, int pDepth, int pPitch, Uint32 pRedMask, Uint32 pGreenMask, Uint32 pBlueMask, Uint32 pAlphaMask)
	{
		// Create the surface.
		mSurface = SDL_CreateRGBSurfaceFrom(pPixels, pWidth, pHeight, pDepth, pPitch, pRedMask, pGreenMask, pBlueMask, pAlphaMask);
	}

	Surface::Surface(const char* pFilename)
	{
		// Create the surface from a loaded image file.
		mSurface = IMG_Load(pFilename);
	}

	Surface::~Surface()
	{
		SDL_FreeSurface(mSurface);
	}

	SDL_Surface* Surface::GetC() const
	{
		// Return C structure.
		return mSurface;
	}

	int Surface::SetColorKey(Uint32 pKey)
	{
		// Set a color key on the surface.
		int code = SDL_SetColorKey(mSurface, SDL_TRUE, pKey);
		if(code < 0)
			SDL_Log("[Surface::SetColorKey] Failed to set color key to surface: %s", SDL_GetError());

		return code;
	}
}
