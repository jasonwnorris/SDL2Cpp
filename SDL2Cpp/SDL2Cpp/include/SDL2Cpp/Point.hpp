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

			bool operator==(const Point& pOther);

			SDL_Point GetC() const;
			int GetX() const;
			int GetY() const;

			void Set(int pX, int pY);
			void SetX(int pX);
			void SetY(int pY);

		public:
			static SDL_Point Zero;

		private:
			SDL_Point mPoint;
	};
}

#endif
