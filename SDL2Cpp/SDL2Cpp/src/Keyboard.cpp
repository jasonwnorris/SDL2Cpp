// Keyboard.cpp

// Project Includes
#include <SDL2Cpp\Keyboard.hpp>

namespace SDL2
{
	Keyboard::Keyboard()
	{
	}

	Keyboard::~Keyboard()
	{
	}
	
	void SetKey(SDL_Keycode pKey, bool pState)
	{
		mKeys[pKey] = pState;
	}
}
