// Rectangle.hpp

#ifndef __SDL2_RECTANGLE_H__
#define __SDL2_RECTANGLE_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Rectangle
	{
		public:
			Rectangle(int pPositionX, int pPositionY, int pWidth, int pHeight);
			~Rectangle();

			SDL_Rect GetC() const;

		public:
			static SDL_Rect Empty();

		private:
			SDL_Rect mRect;
	};
}

#endif
