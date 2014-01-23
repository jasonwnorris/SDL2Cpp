// Keyboard.cpp

// Project Includes
#include <SDL2Cpp\Keyboard.hpp>

namespace SDL2
{
	std::map<SDL_Keycode, bool> Keyboard::sCurrentKeys;
	std::map<SDL_Keycode, bool> Keyboard::sPreviousKeys;

	Keyboard::Keyboard()
	{
	}

	Keyboard::~Keyboard()
	{
	}

	bool Keyboard::IsKeyDown(SDL_Keycode pKey)
	{
		return sCurrentKeys[pKey];
	}

	bool Keyboard::IsKeyUp(SDL_Keycode pKey)
	{
		return !sCurrentKeys[pKey];
	}

	bool Keyboard::IsKeyPressed(SDL_Keycode pKey)
	{
		return sCurrentKeys[pKey] && !sPreviousKeys[pKey];
	}

	bool Keyboard::IsKeyReleased(SDL_Keycode pKey)
	{
		return !sCurrentKeys[pKey] && sPreviousKeys[pKey];
	}
	
	void Keyboard::Clear()
	{
		for(int i = 0; i < 322; ++i)
			sPreviousKeys[i] = sCurrentKeys[i];
	}
	
	void Keyboard::SetKey(SDL_Keycode pKey, bool pState)
	{
		sCurrentKeys[pKey] = pState;
	}
}
