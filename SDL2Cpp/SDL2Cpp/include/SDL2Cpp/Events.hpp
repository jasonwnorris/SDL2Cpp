// Events.hpp

#ifndef __SDL2_EVENTS_H__
#define __SDL2_EVENTS_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Events
	{
		public:
			Events();
			~Events();

			bool Poll();

		private:
			SDL_Event mEvent;
	};
}

#endif
