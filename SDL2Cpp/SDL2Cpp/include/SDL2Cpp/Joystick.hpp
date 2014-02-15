// Joystick.hpp

#ifndef __SDL2_JOYSTICK_H__
#define __SDL2_JOYSTICK_H__

// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	class Joystick
	{
		friend class Events;

		public:

		private:
			Joystick();
			~Joystick();

			static void Clear();
	};
}

#endif
