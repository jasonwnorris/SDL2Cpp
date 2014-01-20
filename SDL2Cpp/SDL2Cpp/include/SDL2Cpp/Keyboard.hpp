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
			Keyboard();
			~Keyboard();

		private:
			static void SetKey(SDL_Keycode pKey, bool pState);

			static std::map<SDL_Keycode, bool> mKeys;

	};
}

#endif
