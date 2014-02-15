// Music.hpp

#ifndef __SDL2_AUDIO_MUSIC_H__
#define __SDL2_AUDIO_MUSIC_H__

// SDL Includes
#include <SDL_mixer.h>

namespace SDL2
{
	namespace Mixer
	{
		class Music
		{
			public:
				Music();
				~Music();
				
				static int SetVolume(int pVolume);
				static bool SetPosition(double pSeconds);
				static void Pause();
				static void Resume();
				static void Rewind();
				static bool Stop();
				static bool FadeOut(int pMilliseconds);

				static bool IsPlaying();
				static bool IsPaused();
				static bool IsFadingIn();
				static bool IsFadingOut();

				bool Load(const char* pFilename);
				bool Play(int pLoops = -1);
				bool PlayFadeIn(int pMilliseconds, int pLoops = -1);

				bool IsCMD();
				bool IsWAV();
				bool IsMOD();
				bool IsMIDI();
				bool IsOGG();
				bool IsMP3();

			private:
				Mix_Music* mMusic;
		};
	}
}

#endif
