// SoundEffect.cpp

// Project Includes
#include <SDL2Cpp\Mixer\SoundEffect.hpp>

namespace SDL2
{
	namespace Mixer
	{
		SoundEffect::SoundEffect()
		{
			mChunk = NULL;
		}

		SoundEffect::~SoundEffect()
		{
			Mix_FreeChunk(mChunk);
		}

		bool SoundEffect::Load(const char* pFilename)
		{
			mChunk = Mix_LoadWAV(pFilename);

			return mChunk != NULL;
		}
		
		bool SoundEffect::Load(Uint8* pMemory)
		{
			mChunk = Mix_QuickLoad_WAV(pMemory);

			return mChunk != NULL;
		}

		int SoundEffect::SetVolume(int pVolume)
		{
			if(pVolume < 0)
				pVolume = 0;

			if(pVolume > MIX_MAX_VOLUME)
				pVolume = MIX_MAX_VOLUME;

			return Mix_VolumeChunk(mChunk, pVolume);
		}
	}
}
