// Events.cpp

// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	Events::Events()
	{
	}

	Events::~Events()
	{
	}

	bool Events::Poll()
	{
		return SDL_PollEvent(&mEvent);
	}
}
