// SoundEffect.hpp

#ifndef __SDL2_AUDIO_SOUNDEFFECT_H__
#define __SDL2_AUDIO_SOUNDEFFECT_H__

// SDL Includes
#include <SDL_mixer.h>

namespace SDL2
{
	namespace Mixer
	{
		class SoundEffect
		{
			public:
				SoundEffect();
				~SoundEffect();
				
				bool Load(const char* pFilename);
				bool Load(Uint8* pMemory);

				int SetVolume(int pVolume);

			private:
				Mix_Chunk* mChunk;
		};
	}
}

#endif
