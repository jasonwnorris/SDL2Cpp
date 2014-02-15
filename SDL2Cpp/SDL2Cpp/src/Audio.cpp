// Audio.cpp

// Project Includes
#include <SDL2Cpp\Mixer\Audio.hpp>

namespace SDL2
{
	namespace Mixer
	{
		bool Audio::Initialize()
		{
			if(!sInitialized)
			{
				int code = Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
				if(code < 0)
					SDL_Log("[Audio::Initialize] Failed to initialize SDL2_Mixer: %s", Mix_GetError());
				else
					sInitialized = true;

				return code == 0;
			}
			
			return true;
		}

		void Audio::Finalize()
		{
			if(sInitialized)
			{
				Mix_Quit();
				sInitialized = false;
			}
		}

		bool Audio::Open(int pFrequency, Uint16 pFormat, int pChannels, int pChuckSize)
		{
			if(!sOpened)
			{
				int code = Mix_OpenAudio(pFrequency, pFormat, pChannels, pChuckSize);
				if(code < 0)
					SDL_Log("[Audio::Open] Failed to open audio: %s", Mix_GetError());
				else
					sOpened = true;

				return code == 0;
			}
			
			return true;
		}

		void Audio::Close()
		{
			if(sOpened)
			{
				Mix_CloseAudio();
				sOpened = false;
			}
		}
	}
}