// Surface.hpp

#ifndef __SDL2_SURFACE_H__
#define __SDL2_SURFACE_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Surface
	{
		public:
			Surface(Uint32 pFlags, int pWidth, int pHeight, int pDepth, Uint32 pRedMask, Uint32 pGreenMask, Uint32 pBlueMask, Uint32 pAlphaMask);
			Surface(void* pPixels, int pWidth, int pHeight, int pDepth, int pPitch, Uint32 pRedMask, Uint32 pGreenMask, Uint32 pBlueMask, Uint32 pAlphaMask);
			Surface(const char* pFilename);
			~Surface();

			SDL_Surface* GetC() const;

			int SetColorKey(Uint32 pKey);

		private:
			SDL_Surface* mSurface;
	};
}

#endif
