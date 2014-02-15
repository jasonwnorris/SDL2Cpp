// Point.cpp

// Project Includes
#include <SDL2Cpp\Point.hpp>

namespace SDL2
{
	SDL_Point Point::Zero = { 0, 0 };

	Point::Point(int pX, int pY)
	{
		mPoint.x = pX;
		mPoint.y = pY;
	}

	Point::~Point()
	{
	}

	bool Point::operator==(const Point& pOther)
	{
		return mPoint.x == pOther.GetX() && mPoint.y == pOther.GetY();
	}
	
	// Return C structure.
	SDL_Point Point::GetC() const
	{
		return mPoint;
	}
	
	int Point::GetX() const
	{
		return mPoint.x;
	}
	
	int Point::GetY() const
	{
		return mPoint.y;
	}
			
	void Point::Set(int pX, int pY)
	{
		SetX(pX);
		SetY(pY);
	}

	void Point::SetX(int pX)
	{
		mPoint.x = pX;
	}

	void Point::SetY(int pY)
	{
		mPoint.y = pY;
	}
}
