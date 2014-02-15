// Rectangle.cpp

// Project Includes
#include <SDL2Cpp\Rectangle.hpp>

namespace SDL2
{
	SDL_Rect Rectangle::Empty = { 0, 0, 0, 0 };

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
	
	bool Rectangle::operator==(const Rectangle& pOther)
	{
		return mRect.x == pOther.GetX() &&
			   mRect.y == pOther.GetY() &&
			   mRect.w == pOther.GetWidth() &&
			   mRect.h == pOther.GetHeight();
	}

	bool Rectangle::operator<(const Rectangle& pOther)
	{
		return GetArea() < pOther.GetArea();
	}

	bool Rectangle::operator>(const Rectangle& pOther)
	{
		return GetArea() > pOther.GetArea();
	}

	bool Rectangle::operator<=(const Rectangle& pOther)
	{
		return GetArea() <= pOther.GetArea();
	}

	bool Rectangle::operator>=(const Rectangle& pOther)
	{
		return GetArea() >= pOther.GetArea();
	}
	
	// Return C structure.
	SDL_Rect Rectangle::GetC() const
	{
		return mRect;
	}
	
	int Rectangle::GetX() const
	{
		return mRect.x;
	}
	
	int Rectangle::GetY() const
	{
		return mRect.y;
	}
	
	int Rectangle::GetWidth() const
	{
		return mRect.w;
	}
	
	int Rectangle::GetHeight() const
	{
		return mRect.h;
	}

	int Rectangle::GetArea() const
	{
		return mRect.w * mRect.h;
	}
			
	void Rectangle::Set(int pX, int pY, int pWidth, int pHeight)
	{
		SetX(pX);
		SetY(pY);
		SetWidth(pWidth);
		SetHeight(pHeight);
	}

	void Rectangle::SetX(int pX)
	{
		mRect.x = pX;
	}

	void Rectangle::SetY(int pY)
	{
		mRect.y = pY;
	}

	void Rectangle::SetWidth(int pWidth)
	{
		mRect.w = pWidth;
	}

	void Rectangle::SetHeight(int pHeight)
	{
		mRect.h = pHeight;
	}
			
	bool Rectangle::IsEmpty()
	{
		return mRect.w == 0 && mRect.h == 0;
	}
			
	bool Rectangle::Contains(int pX, int pY) const
	{
		return pX > mRect.x &&
			   pY > mRect.y &&
			   pX < mRect.x + mRect.w &&
			   pY < mRect.y + mRect.h;
	}

	bool Rectangle::Contains(const Point& pPoint) const
	{
		return pPoint.GetX() > mRect.x &&
			   pPoint.GetY() > mRect.y &&
			   pPoint.GetX() < mRect.x + mRect.w &&
			   pPoint.GetY() < mRect.y + mRect.h;
	}

	bool Rectangle::Contains(const Rectangle& pRectangle) const
	{
		return pRectangle.GetX() > mRect.x &&
			   pRectangle.GetY() > mRect.y &&
			   pRectangle.GetX() + pRectangle.GetWidth() < mRect.x + mRect.w &&
			   pRectangle.GetY() + pRectangle.GetHeight() < mRect.y + mRect.h;
	}
}
