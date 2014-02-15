// Thread.hpp

#ifndef __SDL2_THREAD_H__
#define __SDL2_THREAD_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Thread
	{
		public:
			Thread();
			virtual ~Thread();

			void Start(Uint32 pDelay = 0);
			void Stop();
			void Wait();
			void StopAndWait();
			void SetPriority(SDL_ThreadPriority pPriority);
			
			int GetID() const;
			const char* GetName() const;
			bool IsRunning() const;
			bool IsStopped() const;

		protected:
			virtual void Run() = 0;

		private:
			static int Execute(void* pData);

			volatile bool mRunning;
			volatile bool mStopped;
			SDL_Thread* mThread;
	};
}

#endif
