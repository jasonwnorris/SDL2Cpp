// SDL2.hpp

#ifndef __SDL2_SDL2_H__
#define __SDL2_SDL2_H__

// Project Includes
#include <SDL2Cpp\Events.hpp>
#include <SDL2Cpp\Point.hpp>
#include <SDL2Cpp\Rectangle.hpp>
#include <SDL2Cpp\Renderer.hpp>
#include <SDL2Cpp\Surface.hpp>
#include <SDL2Cpp\Texture.hpp>
#include <SDL2Cpp\Timer.hpp>
#include <SDL2Cpp\Window.hpp>

namespace SDL2
{
	int Initialize(Uint32 pFlags)
	{
		int code = SDL_Init(pFlags);
		if(code < 0)
			SDL_Log("Failed initialize SDL2: %s", SDL_GetError());

		return code;
	}

	void Finalize()
	{
		SDL_Quit();
	}
}

#endif
