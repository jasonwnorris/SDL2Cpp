// Timer.cpp

// Project Includes
#include <SDL2Cpp\Timer.hpp>

namespace SDL2
{
	Timer::Timer()
	{
		Start();
	}

	Timer::~Timer()
	{
	}

	float Timer::GetDeltaTime()
	{
		if(!mStarted || mPaused)
			return 0.0f;

		Uint32 current = SDL_GetTicks();
		Uint32 difference = current - mLastTicks;
		mLastTicks = current;

		return (float)(difference / 1000.0f);
	}

	float Timer::GetElapsedTime()
	{
		if(!mStarted)
			return 0.0f;

		if(mPaused)
			return mPausedTicks;
		else
			return (float)((SDL_GetTicks() - mStartTicks) / 1000.0f);
	}

	void Timer::Start()
	{
		mStartTicks = SDL_GetTicks();
		mLastTicks = mStartTicks;
		mPausedTicks = 0;
		mStarted = true;
		mPaused = false;
	}

	void Timer::Stop()
	{
		mStarted = false;
		mPaused = false;
	}

	void Timer::Pause()
	{
		if(mStarted && !mPaused)
		{
			mPausedTicks = SDL_GetTicks() - mStartTicks;
			mPaused = true;
		}
	}

	void Timer::Resume()
	{
		if(mPaused)
		{
			mStartTicks = SDL_GetTicks() - mPausedTicks;
			mPausedTicks = 0;
			mPaused = false;
		}
	}
}
