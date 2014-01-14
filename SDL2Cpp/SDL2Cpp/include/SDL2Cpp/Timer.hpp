// Timer.hpp

#ifndef __SDL2_TIMER_H__
#define __SDL2_TIMER_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Timer
	{
		public:
			Timer();
			~Timer();

			float GetDeltaTime();
			float GetElapsedTime();

			void Start();
			void Stop();
			void Pause();
			void Resume();

		private:
			Uint32 mStartTicks;
			Uint32 mLastTicks;
			Uint32 mPausedTicks;
			bool mStarted;
			bool mPaused;
	};
}

#endif
