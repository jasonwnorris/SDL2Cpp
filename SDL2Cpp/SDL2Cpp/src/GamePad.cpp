// GamePad.cpp

// Project Includes
#include <SDL2Cpp\GamePad.hpp>

namespace SDL2
{
	std::map<int, GamePad*> GamePad::sGamePads;

	GamePad::GamePad(int pIndex)
	{
		mIndex = pIndex;
		mController = SDL_GameControllerOpen(mIndex);
		mHaptic = SDL_HapticOpen(mIndex);
		SDL_HapticRumbleInit(mHaptic);
	}

	GamePad::~GamePad()
	{
		Close();
	}
	
	void GamePad::Close()
	{
		SDL_GameControllerClose(mController);
		SDL_HapticClose(mHaptic);
	}
	
	bool GamePad::IsButtonDown()
	{
		return false;
	}
	
	void GamePad::GetAxis()
	{
	}

	bool GamePad::RumbleStart(int pDuration, float pStrength)
	{
		if(pStrength < 0.0f) pStrength = 0.0f;
		if(pStrength > 1.0f) pStrength = 1.0f;

		return SDL_HapticRumblePlay(mHaptic, pStrength, pDuration) == 0;
	}

	bool GamePad::RumbleStop()
	{
		return SDL_HapticRumbleStop(mHaptic) == 0;
	}

	bool GamePad::RumblePause()
	{
		return SDL_HapticPause(mHaptic) == 0;
	}

	bool GamePad::RumbleResume()
	{
		return SDL_HapticUnpause(mHaptic) == 0;
	}
	
	void GamePad::Clear()
	{
	}

	void GamePad::SetAxis(Uint8 pAxis, Sint16 pValue, int pIndex)
	{
	}

	void GamePad::SetButton(Uint8 pButton, bool pState, int pIndex)
	{
		//sGamePads[pIndex]
	}

	void GamePad::Add(int pIndex)
	{
		sGamePads[pIndex] = new GamePad(pIndex);
	}

	void GamePad::Remove(int pIndex)
	{
		sGamePads[pIndex]->Close();
		sGamePads.erase(sGamePads.find(pIndex));
	}	
}
