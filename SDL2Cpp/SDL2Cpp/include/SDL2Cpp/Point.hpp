// Point.hpp

#ifndef __SDL2_POINT_H__
#define __SDL2_POINT_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Point
	{
		public:
			Point(int pX, int pY);
			~Point();

		private:
			SDL_Point mPoint;
	};
}

#endif
