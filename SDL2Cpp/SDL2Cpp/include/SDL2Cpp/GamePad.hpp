// GamePad.hpp

#ifndef __SDL2_GAMEPAD_H__
#define __SDL2_GAMEPAD_H__

// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	class GamePad
	{
		friend class Events;

		public:
			GamePad();
			~GamePad();

		private:

	};
}

#endif
