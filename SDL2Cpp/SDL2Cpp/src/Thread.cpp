// Thread.cpp

// Project Includes
#include <SDL2Cpp\Thread.hpp>

namespace SDL2
{
	Thread::Thread()
	{
	}

	Thread::~Thread()
	{
	}

	void Thread::Start(Uint32 pDelay)
	{
		if(!mRunning)
		{
			mThread = SDL_CreateThread(Execute, "Thread", this);
			SDL_Delay(pDelay);
		}
	}
	
	void Thread::Stop()
	{
		mStopped = true;
	}

	void Thread::Wait()
	{
		if(mRunning)
		{
			SDL_WaitThread(mThread, NULL);
		}
	}

	void Thread::StopAndWait()
	{
		Stop();
		Wait();
	}
	
	int Thread::GetID() const
	{
		return SDL_GetThreadID(mThread);
	}
	
	const char* Thread::GetName() const
	{
		return SDL_GetThreadName(mThread);
	}

	bool Thread::IsRunning() const
	{
		return mRunning;
	}

	bool Thread::IsStopped() const
	{
		return mStopped;
	}
}
