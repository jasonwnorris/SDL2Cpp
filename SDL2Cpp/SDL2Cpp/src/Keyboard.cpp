// Keyboard.cpp

// Project Includes
#include <SDL2Cpp\Keyboard.hpp>

namespace SDL2
{
	std::map<SDL_Keycode, bool> Keyboard::mKeys;

	Keyboard::Keyboard()
	{
	}

	Keyboard::~Keyboard()
	{
	}
	
	void Keyboard::SetKey(SDL_Keycode pKey, bool pState)
	{
		mKeys[pKey] = pState;
	}
}
