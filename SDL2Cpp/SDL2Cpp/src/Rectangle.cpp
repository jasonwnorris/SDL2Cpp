// Rectangle.cpp

// Project Includes
#include <SDL2Cpp\Rectangle.hpp>

namespace SDL2
{
	Rectangle::Rectangle(int pPositionX, int pPositionY, int pWidth, int pHeight)
	{
		// Construct the texture.
		mRect.x = pPositionX;
		mRect.y = pPositionY;
		mRect.w = pWidth;
		mRect.h = pHeight;
	}

	Rectangle::~Rectangle()
	{
	}

	SDL_Rect Rectangle::GetC() const
	{
		// Return C structure.
		return mRect;
	}

	SDL_Rect Rectangle::Empty()
	{
		SDL_Rect empty;
		empty.x = 0;
		empty.y = 0;
		empty.w = 0;
		empty.h = 0;

		return empty;
	}
}
