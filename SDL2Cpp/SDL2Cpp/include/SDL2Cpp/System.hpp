// System.hpp

#ifndef __SDL2_SYSTEM_H__
#define __SDL2_SYSTEM_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class System
	{
		public:
			const char* GetPlatformName();
			int GetCPUCount();
			int GetCacheSize();
			int GetRAMSize();

			// SDL_GetPowerInfo(int*, int*);

		private:

	};
}

#endif
