// Music.cpp

// Project Includes
#include <SDL2Cpp\Mixer\Music.hpp>

namespace SDL2
{
	namespace Mixer
	{
		Music::Music()
		{
			mMusic = NULL;
		}

		Music::~Music()
		{
			Mix_FreeMusic(mMusic);
		}

		int Music::SetVolume(int pVolume)
		{
			if(pVolume < 0)
				pVolume = 0;

			if(pVolume > MIX_MAX_VOLUME)
				pVolume = MIX_MAX_VOLUME;

			return Mix_VolumeMusic(pVolume);
		}
		
		bool Music::SetPosition(double pSeconds)
		{
			return Mix_SetMusicPosition(pSeconds) == 0;
		}

		void Music::Pause()
		{
			Mix_PauseMusic();
		}

		void Music::Resume()
		{
			Mix_ResumeMusic();
		}

		void Music::Rewind()
		{
			Mix_RewindMusic();
		}

		bool Music::Stop()
		{
			return Mix_HaltMusic() == 0;
		}

		bool Music::FadeOut(int pMilliseconds)
		{
			return Mix_FadeOutMusic(pMilliseconds) == 1;
		}

		bool Music::IsPlaying()
		{
			return Mix_PlayingMusic() == 1;
		}

		bool Music::IsPaused()
		{
			return Mix_PausedMusic() == 1;
		}

		bool Music::IsFadingIn()
		{
			return Mix_FadingMusic() == MIX_FADING_IN;
		}

		bool Music::IsFadingOut()
		{
			return Mix_FadingMusic() == MIX_FADING_OUT;
		}


		bool Music::Load(const char* pFilename)
		{
			mMusic = Mix_LoadMUS(pFilename);

			return mMusic != NULL;
		}

		bool Music::Play(int pLoops)
		{
			int code = Mix_PlayMusic(mMusic, pLoops);

			return code == 0;
		}

		bool Music::PlayFadeIn(int pMilliseconds, int pLoops)
		{
			int code = Mix_FadeInMusic(mMusic, pLoops, pMilliseconds);

			return code == 0;
		}

		bool Music::IsCMD()
		{
			return Mix_GetMusicType(mMusic) == MUS_CMD;
		}

		bool Music::IsWAV()
		{
			return Mix_GetMusicType(mMusic) == MUS_WAV;
		}

		bool Music::IsMOD()
		{
			return Mix_GetMusicType(mMusic) == MUS_MOD;
		}

		bool Music::IsMIDI()
		{
			return Mix_GetMusicType(mMusic) == MUS_MID;
		}

		bool Music::IsOGG()
		{
			return Mix_GetMusicType(mMusic) == MUS_OGG;
		}

		bool Music::IsMP3()
		{
			return Mix_GetMusicType(mMusic) == MUS_MP3;
		}
	}
}
