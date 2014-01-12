// Point.cpp

// Project Includes
#include <SDL2Cpp\Point.hpp>

namespace SDL2
{
	Point::Point(int pX, int pY)
	{
		mPoint.x = pX;
		mPoint.y = pY;
	}

	Point::~Point()
	{
	}
}
