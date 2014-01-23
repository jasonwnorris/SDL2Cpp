// Keyboard.hpp

#ifndef __SDL2_KEYBOARD_H__
#define __SDL2_KEYBOARD_H__

// STD Includes
#include <map>
// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	class Keyboard
	{
		friend class Events;

		public:
			static bool IsKeyDown(SDL_Keycode pKey);
			static bool IsKeyUp(SDL_Keycode pKey);
			static bool IsKeyPressed(SDL_Keycode pKey);
			static bool IsKeyReleased(SDL_Keycode pKey);

		private:
			Keyboard();
			~Keyboard();

			static void Clear();
			static void SetKey(SDL_Keycode pKey, bool pState);
			
			static std::map<SDL_Keycode, bool> sCurrentKeys;
			static std::map<SDL_Keycode, bool> sPreviousKeys;

	};
}

#endif
