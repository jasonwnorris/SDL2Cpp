// Mouse.cpp

// Project Includes
#include <SDL2Cpp\Mouse.hpp>

namespace SDL2
{
	int Mouse::sPreviousX;
    int Mouse::sCurrentX;
    int Mouse::sPreviousY;
    int Mouse::sCurrentY;
    Uint32 Mouse::sPreviousState;
    Uint32 Mouse::sCurrentState;
    bool Mouse::sScrollUp;
    bool Mouse::sScrollDown;

	Mouse::Mouse()
	{
	}

	Mouse::~Mouse()
	{
	}

	void Mouse::GetPosition(int& pX, int& pY)
	{
		pX = sCurrentX;
		pY = sCurrentY;
	}

    void Mouse::GetMovement(int& pX, int& pY)
	{
        pX = sCurrentX - sPreviousX;
        pY = sCurrentY - sPreviousY;
	}

    bool Mouse::IsButtonDown(int pButton)
	{
		return (sCurrentState & SDL_BUTTON(pButton)) != 0;
	}

    bool Mouse::IsButtonUp(int pButton)
	{
		 return (sCurrentState & SDL_BUTTON(pButton)) == 0;
	}

    bool Mouse::IsButtonClicked(int pButton)
	{
		return (sCurrentState & SDL_BUTTON(pButton)) != 0 && (sPreviousState & SDL_BUTTON(pButton)) == 0;
	}

    bool Mouse::IsButtonReleased(int pButton)
	{
		return (sCurrentState & SDL_BUTTON(pButton)) == 0 && (sPreviousState & SDL_BUTTON(pButton)) != 0;
	}

    bool Mouse::IsScrolledUp()
	{
		return sScrollUp;
	}

    bool Mouse::IsScrolledDown()
	{
		return sScrollDown;
	}

	void Mouse::Clear()
	{
		sPreviousX = sCurrentX;
		sPreviousY = sCurrentY;
		sPreviousState = sCurrentState;
		sCurrentState = SDL_GetMouseState(NULL, NULL);
		sScrollUp = false;
		sScrollDown = false;
	}

	void Mouse::SetPosition(int pX, int pY)
	{
		sCurrentX = pX;
		sCurrentY = pY;
	}

	void Mouse::SetScroll(int pX, int pY)
	{
		if(pY > 0)
		{
			sScrollUp = true;
			sScrollDown = false;
		}
		else if(pY < 0)
		{
			sScrollUp = false;
			sScrollDown = true;
		}
	}
}
