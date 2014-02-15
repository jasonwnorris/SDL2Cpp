// Rectangle.hpp

#ifndef __SDL2_RECTANGLE_H__
#define __SDL2_RECTANGLE_H__

// Project Includes
#include "Point.hpp"

namespace SDL2
{
	class Rectangle
	{
		public:
			Rectangle(int pPositionX, int pPositionY, int pWidth, int pHeight);
			~Rectangle();
			
			bool operator==(const Rectangle& pOther);
			bool operator<(const Rectangle& pOther);
			bool operator>(const Rectangle& pOther);
			bool operator<=(const Rectangle& pOther);
			bool operator>=(const Rectangle& pOther);

			SDL_Rect GetC() const;
			int GetX() const;
			int GetY() const;
			int GetWidth() const;
			int GetHeight() const;
			int GetArea() const;
			
			void Set(int pX, int pY, int pWidth, int pHeight);
			void SetX(int pX);
			void SetY(int pY);
			void SetWidth(int pWidth);
			void SetHeight(int pHeight);
			
			bool IsEmpty();
			bool Contains(int pX, int pY) const;
			bool Contains(const Point& pPoint) const;
			bool Contains(const Rectangle& pRectangle) const;

		public:
			static SDL_Rect Empty;

		private:
			SDL_Rect mRect;
	};
}

#endif
