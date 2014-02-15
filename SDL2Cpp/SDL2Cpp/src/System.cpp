// System.cpp

// Project Includes
#include <SDL2Cpp\System.hpp>

namespace SDL2
{
	const char* System::GetPlatformName()
	{
		return SDL_GetPlatform();
	}

	int System::GetCPUCount()
	{
		return SDL_GetCPUCount();
	}

	int System::GetCacheSize()
	{
		return SDL_GetCPUCacheLineSize();
	}

	int System::GetRAMSize()
	{
		return SDL_GetSystemRAM();
	}
}
